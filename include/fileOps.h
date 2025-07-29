#pragma once
#include <hamming.h>
#include <stdio.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

extern char *in;
extern FILE *outF;

long getFiles(int *argc, char ***argv);

void dumpHexToFile(HammingSymbol wrd[], unsigned char len, FILE *f);