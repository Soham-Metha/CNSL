#include <fileOps.h>
#include <hamming.h>

// 01 00 00 01
// 10 00 00 10
// 1 0 0 0 1 0 0 1 0 0 0 1
// 1 2 3 4 5 6 7 8 9 0 1 2

int main(int argc, char **argv)
{
    printf("\n================= SENDER =================\n");
    unsigned char fileSize = (unsigned char)getFiles(&argc, &argv);
    HammingSymbol out[fileSize];

    printf("\n┌─────┬──────────────┐\n");
    fwrite(&fileSize, sizeof(unsigned char), 1, outF);
    for (unsigned char i = 0; i < fileSize; i++)
    {
        out[i] = getCodeFor(in[i]);

        printf("│  %c  │ ", (out[i].charValue == '\n') ? '\\' : out[i].charValue);
        PRINT_BITS(MESSAGE_SIZE - 1, 0, out[i].encodedValue)
        printf(" │\n");

        out[i].encodedValue |= 2;
        fwrite(&(out[i].encodedValue), sizeof(unsigned short), 1, outF);
    }

    dumpHexToFile(out, fileSize, outF);

    printf("└─────┴──────────────┘"
           "\n\n================= SENDER =================\n\n");
    return 0;
}