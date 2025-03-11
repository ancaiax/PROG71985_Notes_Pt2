#pragma once

// person interface
// madisont - prog7195 - week09

#ifndef PERSON_LIBRARY_H
#define PERSON_LIBRARY_H
#include "guest.h"
#include "student.h"
#include "professor.h"
#include <stdbool.h>
#include <stdio.h>

//private
typedef union personKind {
	STUDENT student;
	PROFESSOR professor;
	GUEST guest;
} PERSONKIND;

// mostly private 
typedef enum type { STUD, PROF, GST } TYPE;

//public
typedef struct person {
	TYPE type;
	PERSONKIND kind;
} PERSON;

PERSON CreatePersonFromStudent(STUDENT s);
PERSON CreatePersonFromProfessor(PROFESSOR p);
PERSON CreatePersonFromGuest(GUEST g);

void PrintPerson(PERSON p);

bool ComparePerson(PERSON lhs, PERSON rhs);

bool SavePersonToDisk(PERSON p, FILE* fp);
//bool LoadPersonFromDisk(PERSON* p, FILE* fp);
PERSON LoadPersonFromDisk(FILE* fp);

void DisposePerson(PERSON p);

#endif //PERSON_LIBRARY_H