#define _CRT_SECURE_NO_WARNINGS
#include "classroom.h"
#include "person.h"

// classroom object implementation
// madisont - prog71985 - week10

CLASSROOM CreateClassroom(char* name, int Capacity) {
	CLASSROOM c = { 0 };
	c.capacity = Capacity;
	c.people = NULL;
	strncpy(c.name, name, MAXSIZE);
	return c;
}

bool AddPersonToClassroom(CLASSROOM* c, PERSON p) {

	for (int i = 0; i < GetCapacityOfClassroom(*c); i++) {
		if (c->seatStatus[i] == EMPTY) 
		{
			c->people[i] = p;
			c->seatStatus[i] = FILLED;
			return true;
		}
			
	}
		return false;
}

bool RemovePersonFromClassroom(CLASSROOM* c, PERSON p) {
	for (int i = 0; i < GetCapacityOfClassroom(*c); i++) {
		if (ComparePerson(c->people[i], p))
		{
			c->seatStatus[i] = EMPTY;
			return true;
		}
	}
	return false;
}

int GetCapacityOfClassroom(CLASSROOM c) {
	return c.capacity;
}

int GetCurrentCount(CLASSROOM c) {
	return GetCount(c.people);
}

bool SaveClassroomToDisk(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "error writing to file\n");
		return false;
	}
	
	fprintf(fp, "%s\n", c.name);
	fprintf(fp, "%d\n", GetCapacityOfClassroom(c));
	fprintf(fp, "%d\n", GetCurrentCount(c));
	
	SaveListToDisk(c.people, fp);

	fclose(fp);
	return true;
}

bool LoadClassroomFromDisk(CLASSROOM* classroom, char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "error reading from file\n");
		return false;
	}
	else {
		char buffer[MAXSIZE] = { 0 };
		fgets(buffer, MAXSIZE, fp);
		strncpy(classroom->name, buffer, MAXSIZE);
		int unused_capacity;
		fscanf(fp, "%d\n", &unused_capacity);

		int current_count;
		fscanf(fp, "%d\n", &current_count);

		//this is where we need to start class#1 of week12 - and this is why i
		// don't really like this set up.

		for (int i = 0; i < current_count; i++) {
			PERSON newPerson = LoadPersonFromDisk(fp);
			AddPersonToClassroom(classroom, newPerson);
		}
		fclose(fp);
		return true;
	}
}

void PrintClassroom(CLASSROOM c) {						// add #5 - just useful for testing
	printf("Name: %s\n", c.name);
	printf("Capacity: %d\n", GetCapacityOfClassroom(c));
	printf("Current Count: %d\n", GetCurrentCount(c));

	for (int i = 0; i < GetCapacityOfClassroom(c); i++)
		if (c.seatStatus[i] == FILLED)
			PrintPerson(c.people[i]);
}

void DisposeClassroom(CLASSROOM c) {
	//nothing to be done
}