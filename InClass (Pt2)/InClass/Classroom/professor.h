#pragma once

// professor object - interface
// madisont - prog71985 - week09

#ifndef PROFESSOR_LIBRARY_H
#define PROFESSOR_LIBRARY_H
#define MAXSIZE 50
#include <stdio.h>
#include <stdbool.h>

typedef struct professor {
    char name[MAXSIZE];
    char dept[MAXSIZE];
} PROFESSOR;

PROFESSOR CreateProfessor(char* Name, char* Dept);

void PrintProfessor(PROFESSOR p);

bool CompareProfessor(PROFESSOR lhs, PROFESSOR rhs);

void SaveProfessorToDisk(PROFESSOR p, FILE* fp);

PROFESSOR LoadProfessorFromDisk(FILE* fp);

void DisposeProfessor(PROFESSOR p);

#endif //PROFESSOR_LIBRARY_H