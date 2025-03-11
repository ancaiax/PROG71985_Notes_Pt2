#include "item.h"
#include "list.h"
#include <stdio.h>

//madisont - prog71985 - week10 - linkedlist main test harness

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, createItem(5));
	Add(&list, createItem(3));
	Add(&list, createItem(1));

	Display(list);

	Remove(&list, createItem(3));

	Display(list);

	Dispose(&list);

	/*ITEM one = createItem(1);
	printItem(one);

	ITEM onePrime = copyItem(one);

	if (compareItem(one, onePrime)) {
		printf("matched!\n");
	}

	disposeItem(one);
	disposeItem(onePrime);*/

	return 0;
}