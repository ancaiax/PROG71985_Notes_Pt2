#pragma once
#include "item.h"
#include <stdio.h>

//madisont - prog71985 - week10 - list interface

#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H

typedef struct listnode {
	ITEM data;
	struct listnode* next;
}LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, ITEM i);

void Remove(PLISTNODE* list, ITEM i);

void Display(PLISTNODE list);

void Dispose(PLISTNODE* list);

#endif //LIST_LIBRARY_H