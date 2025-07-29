#pragma once
#include <hamming.h>
#include <stdio.h>

typedef unsigned char i8;
typedef unsigned short int i16;
typedef unsigned int i32;
typedef unsigned long long int i64;

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