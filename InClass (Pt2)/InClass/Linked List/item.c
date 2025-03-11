#include "item.h"

//madisont - prog71985 - week10 - item object implementation

ITEM createItem(int i) {
	ITEM I = { 0 };
	I.value = i;
	return I;
}

ITEM copyItem(ITEM src) {
	return createItem(src.value);
}

bool compareItem(ITEM lhs, ITEM rhs) {
	return (lhs.value == rhs.value);
}

void printItem(ITEM i) {
	printf("ITEM: %d\n", i.value);
}

void disposeItem(ITEM i) {
	//nothing yet
}