#pragma once
#include <stdbool.h>
#include <stdio.h>

//madisont - prog71985 - week10 - item object interface

#ifndef ITEM_LIBRARY_H
#define ITEM_LIBRARY_H

typedef struct item {
	int value;
}ITEM;

ITEM createItem(int i);

ITEM copyItem(ITEM src);

bool compareItem(ITEM lhs, ITEM rhs);

void printItem(ITEM i);

void disposeItem(ITEM i);

#endif //ITEM_LIBRARY_H