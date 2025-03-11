#include <stdio.h>

//madisont - prog71985 - week12

//Recursion is a mechanism by which we solve problems by re-using
//an algorithm but with a smaller version of the problem

//Important when you need it, but never ideal in C
//Our looping strategy will always be better than recursion

//When considering a recursive solution, we will need to identify our 2 cases:
// - Base case: when am I done?
// - Recursive step: the stuff that is repeated.

//In C, recursion has 3 disadvantages:
// - Stack overflow problems
// - Performance problems
// - Error-prone and complicated (especially compared to a loop)

//Factorial			calc button ! =>	4! = 4 * 3 * 2 * 1
//										   = 1 * 2 * 3 * 4
//										   = 4 * 3!
//										   = num * (num-1)!
//												   = 3 * 2!
//										defined 0! = 1

int factorial(int num) {
	
	int total = 1;

	for (int i = num; i > 0; i--)
	{
		total = total * i;
		//total *= i; (equivalent)
	}
	return total;
}

int rfactorial(int num) {
	if (num == 0)
		return 1;
	else
		return (num * rfactorial(num-1));
}

int main(void) {
	
	int num = 4;

	printf("%d! is %d\n", num, factorial(num));

	printf("%d! is %d\n", num, rfactorial(num));

	return 0;
}

// (5+4) - (2/5) * (4 + (3*2))