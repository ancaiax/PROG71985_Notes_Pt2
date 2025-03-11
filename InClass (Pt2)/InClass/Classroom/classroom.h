#pragma once
#include "person.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

// classroom interface
// madisont - prog71985 - week10

#ifndef CLASSROOM_LIBRARY_H
#define CLASSROOM_LIBRARY_H

typedef struct classroom {
	char name[MAXSIZE];
	int capacity;
	PLISTNODE people;
}CLASSROOM;

CLASSROOM CreateClassroom(char* name, int Capacity);

bool AddPersonToClassroom(CLASSROOM* c, PERSON p);

bool RemovePersonFromClassroom(CLASSROOM* c, PERSON p);

int GetCapacityOfClassroom(CLASSROOM c);

int GetCurrentCount(CLASSROOM c);

bool SaveClassroomToDisk(CLASSROOM c, char* filename);

bool LoadClassroomFromDisk(CLASSROOM* c, char* filename);

void PrintClassroom(CLASSROOM c);		// add #4 - just useful for testing

void DisposeClassroom(CLASSROOM c);

#endif //CLASSROOM_LIBRARY_H