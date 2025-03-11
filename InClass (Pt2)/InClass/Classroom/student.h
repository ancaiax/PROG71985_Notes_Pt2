#pragma once

// student object - interface
// madisont - prog71985 - week09

#ifndef STUDENT_LIBRARY_H
#define STUDENT_LIBRARY_H
#define MAXSIZE 50
#include <stdio.h>
#include <stdbool.h>

typedef struct student {
    char name[MAXSIZE];
    int number;
} STUDENT;

STUDENT CreateStudent(char* name, int number);

void PrintStudent(STUDENT s);

bool CompareStudent(STUDENT lhs, STUDENT rhs);

void SaveStudentToDisk(STUDENT s, FILE* fp);

STUDENT LoadStudentFromDisk(FILE* fp);

void DisposeStudent(STUDENT s);

#endif //STUDENT_LIBRARY_H