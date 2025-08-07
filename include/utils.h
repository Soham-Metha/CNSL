#pragma once
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

typedef enum Params {
	PARAM_FILE_NAME,
	PARAM_INPUT_FILE,
	PARAM_OUTPUT_FILE,
	PARAM_EXP_NO,
	PARAM_CNT,
} Params;

extern char *in;
extern FILE *outF;

long getFiles(int *argc, char ***argv);