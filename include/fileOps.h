#pragma once
#include <hamming.h>
#include <stdio.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (i8 *)
#define $2 (i16)
#define $4 (i32)
#define $8 (i64)
#define $c (char *)
#define $i (int)

extern char *in;
extern FILE *outF;

long getFiles(int *argc, char ***argv);

void dumpHexToFile(HammingSymbol wrd[], unsigned char len, FILE *f);