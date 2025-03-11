#pragma once

// guest object - interface
// madisont - prog71985 - week09

#ifndef GUEST_LIBRARY_H
#define GUEST_LIBRARY_H
#define MAXSIZE 50
#include <stdio.h>
#include <stdbool.h>

typedef struct guest {
    char name[MAXSIZE];
} GUEST;

GUEST CreateGuest(char* name);

void PrintGuest(GUEST g);

bool CompareGuest(GUEST lhs, GUEST rhs);

void SaveGuestToDisk(GUEST g, FILE* fp);

GUEST LoadGuestFromDisk(FILE* fp);

void DisposeGuest(GUEST g);

#endif //GUEST_LIBRARY_H