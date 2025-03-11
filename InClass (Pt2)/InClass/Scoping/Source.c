#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#define MAXSTRING 4000000

//madisont - prog71985 - week 11
//scoping stuff

//* = everything steve has taught, will keep future you happier

//Duration: (how long does it live?)
// - static: from the beginning to the end
// - automatic: create it when necessary and destroy when done *
// - allocated: manually done by dev (malloc, calloc, realloc)

//Scope: (how far is it seen?)
// - file: the whole file
// - block: between the braces *

//Linkage: (whether translation units (TU) can see it)
//translation unit is your c file
// - none *
// - internal: anywhere in this file (TU)
// - external: anywhere in any TU (in this project)

//-------------------------------------------
// - register variables: not used much anymore, but pins a variable (loop counter) to a register
// - volatile variables - 
// - restrict(ed) pointers - 

//-------------------------------------------
//malloc: trusty old malloc
//		char* string = (char*)malloc(sizeof(char) * number)
//			//gives me back an uninitialized allocation
//			//memset(string, 0, SIZE); //this line is what calloc does automatically
//calloc: 
//		char* string = (char*)calloc(char, number)
//			//gives me back a 0 initialized allocation - disadvantage (ISO)
//realloc: "nothing but evil" - malloc or calloc needs to have happened prior
//		char* string = (char*)realloc(string, new_size);
//results in dangling pointers (pointers pointing at nothing)

//restrict means nothing is going to be touched by anybody
void restrict_use(int* a, int* b, int* /*restrict*/ c) {

	//in assembly
	//LEA ebx, [address of c]
	//LEA eax, [address of a]
	//ADD eax, ebx
	//LEA [address of a], eax
	*a += *c;

	//there could be some time

	//in assembly
	//LEA eax, [address of b]
	//ADD eax, ebx
	//LEA [address of b], eax
	*b += *c;

}

//globally scoped variables are the root of all evil!!!
//variables defined outside of a function
int yearborn = 1997; //duration: static, scope: file, linkage: half of external

//dont do this
//ROOM hotel[10];
//void function();

static int actual_internal = 2000; //duration: static, scope: file, linkage: internal

//proves that password in main is block scope
//void function(char* password) {
//	strncpy(password, "steve", 5);
//}

//static in front of function means function can only be executed by functions in this TU
static void function(char* password) {
	strncpy(password, "steve", 5);
}

int main(void) {

	int age = 27;	//duration: automatic, scope: block, linkage: none
	char* password = (char*)malloc(sizeof(char) * MAXSTRING); //duration: allocated, scope: block, linkage: none

	if (password == NULL)
		exit(1);
	
	//encryption pieces
	// steve\005849gfdhjk\046327567\0
	// bool isAuthenticated = AuthenticateMe(username, password): //sensitive information in memory
	//volatile means "yes I know this seems useless, dont touch"
	for (volatile int i = 0; i < MAXSTRING; i++)
		password[i] = '\0';

	//the for loop in assembly language
	//storing the counter in a memory address
	//		 LEA eax, [memory address]
	// loop:
	//		 password[EAX] = '\0';
	//		 INC eax
	//		 LEA [memory address], eax
	
	//		 CMP eax, MAXSTRING
	//       je done:
	//       jmp loop
	for (register int i = 0; i < MAXSTRING; i++)
	{
		password[i] = '\0';
	}

	printf("my age today is %d\n", age);

	function2();
	function2();
	function2();
	function2();

	return 0;
}
