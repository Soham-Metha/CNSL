#include <utils.h>
#include <stdlib.h>

FILE *inF, *outF;
char *in;

long getInFileSize()
{
	fseek(inF, 0, SEEK_END);
	long size = ftell(inF);
	rewind(inF);
	return size;
}

long readInFile()
{
	long size = getInFileSize();
	in = malloc(size + 1);
	if (!in) {
		printf("Memory allocation failed");
		fclose(inF);
		exit(1);
	}
	if (!fread(in, 1, size, inF)) {
		printf("COULDN'T READ THE INPUT FILE");
	}
	in[size] = '\0';

	fclose(inF);
	return size;
}

long getFiles(int *argc, char ***argv)
{
	(void)argc;
	inF = fopen((*argv)[1], "r");
	outF = fopen((*argv)[2], "w+b");

	return readInFile();
}