#pragma once
#include <hamming.h>
#include <stdio.h>

extern char *in;
extern FILE *outF;

long getFiles(int *argc, char ***argv);

void dumpHexToFile(HammingSymbol wrd[], unsigned char len, FILE *f);