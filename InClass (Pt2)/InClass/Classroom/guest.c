#define _CRT_SECURE_NO_WARNINGS
#include "guest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// guest object - implementation
// madisont - prog71985 - week09

GUEST CreateGuest(char* name) {
	GUEST g;
	strncpy(g.name, name, MAXSIZE);
	return g;
}

void PrintGuest(GUEST g) {
	printf("GUEST: %s\n", g.name);
}

bool CompareGuest(GUEST lhs, GUEST rhs) {
	return (strncmp(lhs.name, rhs.name, MAXSIZE) == 0);
}

void SaveGuestToDisk(GUEST g, FILE* fp) {
	fprintf(fp, "GUEST\n");
	fprintf(fp, "%s\n", g.name);
}

GUEST LoadGuestFromDisk(FILE* fp) {
	char namebuffer[MAXSIZE] = { 0 };
	fgets(namebuffer, MAXSIZE, fp);
	return CreateGuest(namebuffer);
}

void DisposeGuest(GUEST g) {
	//nothing
}