#include <fileOps.h>
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
    if (!in)
    {
        printf("Memory allocation failed");
        fclose(inF);
        exit(1);
    }
    if (!fread(in, 1, size, inF))
    {
        printf("COULDN'T READ THE INPUT FILE");
    }
    in[size] = '\0';

    fclose(inF);
    return size;
}

long getFiles(int *argc, char ***argv)
{
    (void)argc;
    printf("\nIN  : %s"
           "\nOUT : %s\n",
           (*argv)[1], (*argv)[2]);
    inF = fopen((*argv)[1], "r");
    outF = fopen((*argv)[2], "w+b");

    return readInFile();
}

void dumpHexToFile(HammingSymbol wrd[], unsigned char len, FILE *f)
{
    fwrite(&len, sizeof(unsigned char), 1, f);
    for (unsigned char i = 0; i < len; i++)
    {
        fwrite(&(wrd[i].encodedValue), sizeof(unsigned short), 1, f);
    }
}