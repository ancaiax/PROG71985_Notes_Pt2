#include "library.h"
#include <stdio.h>
#include <string.h>

//if you HAVE to use them put them at the top
//but dont use them
extern int yearborn;

void function2() {
	//int yearborn = 1998;
	//static ints need to be initialized
	static int counter = 0;
	counter++;	//duration: static, scope: block, linkage: none
	printf("yearborn = %d (%d)\n", yearborn, counter);
	//strncpy(password, "steve", 5);
}