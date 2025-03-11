#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// professor object - implementation
// madisont - prog71985 - week09

PROFESSOR CreateProfessor(char* Name, char* Dept) {
	PROFESSOR p;
	strncpy(p.name, Name, MAXSIZE);
	strncpy(p.dept, Dept, MAXSIZE);
	return p;
}

void PrintProfessor(PROFESSOR p) {
	printf("PROFESSOR: %s, %s\n", p.name, p.dept);
}

bool CompareProfessor(PROFESSOR lhs, PROFESSOR rhs) {
	return (strncmp(lhs.name, rhs.name, MAXSIZE) == 0);
}

void SaveProfessorToDisk(PROFESSOR p, FILE* fp) {
	fprintf(fp, "PROFESSOR\n");
	fprintf(fp, "%s\n", p.name);
	fprintf(fp, "%s\n", p.dept);
}

PROFESSOR LoadProfessorFromDisk(FILE* fp) {
	char namebuffer[MAXSIZE] = { 0 };
	fgets(namebuffer, MAXSIZE, fp); 
	char deptbuffer[MAXSIZE] = { 0 };
	fgets(deptbuffer, MAXSIZE, fp);
	return CreateProfessor(namebuffer, deptbuffer);
}

void DisposeProfessor(PROFESSOR p) {
	// nothing
}