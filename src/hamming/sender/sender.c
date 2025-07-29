#include <fileOps.h>
#include <hamming.h>

int main(int argc, char **argv)
{
    printf("\n================= SENDER =================\n"
           "\nIN  : %s\nOUT : %s\n"
           "\n┌─────┬──────────────┐\n",
           argv[1], argv[2]);

    int8 fileSize = (int8)getFiles(&argc, &argv);
    fwrite(&fileSize, sizeof(int8), 1, outF);

    for (int8 i = 0; i < fileSize; i++)
    {
        int16 code = getCodeFor(in[i]);

        printf("│  %c  │ ", char_val(in[i]));
        PRINT_BITS(MESSAGE_SIZE - 1, 0, code)
        printf(" │\n");

        // code |= 2;
        fwrite(&(code), sizeof(unsigned short), 1, outF);
    }

    printf("└─────┴──────────────┘"
           "\n\n================= SENDER =================\n\n");
    return 0;
}