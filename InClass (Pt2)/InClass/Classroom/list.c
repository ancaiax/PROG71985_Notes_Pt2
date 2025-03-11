#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//madisont - prog71985 - week10 - list implementation

void Add(PLISTNODE* list, ITEM i) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (newNode == NULL) {
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}
	else {
		newNode->data = copyItem(i);
		newNode->next = *list;
		*list = newNode;
	}
}

void Remove(PLISTNODE* list, ITEM i) {
	PLISTNODE current = *list;
	if (current != NULL && compareItem(current->data, i)) {
		*list = current->next;
		free(current);
		return 0;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !compareItem(current->data, i)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		return 0;
	}
	else {
		prev->next = current->next;
		free(current);
	}

}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	
	if (current == NULL) {
		return 0;
	}

	do {
		printItem(current->data);
		current = current->next;
	} while (current != NULL);
}

int GetCount(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void Dispose(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		disposeItem(current->data);
		current = current->next;
		free(tmp);
	}
}