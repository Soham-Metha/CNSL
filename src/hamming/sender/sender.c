#include <assert.h>
#include <fileOps.h>
#include <hamming.h>

//  1   2   3   4   5   6   7   8   9   10  11  12
//  P1  P2  1   P3  2   3   4   P4  5   6   7   8

//  P1 = P1, 1, 2, 4, 5, 7      | 1, 3, 5, 7, 9, 11
//  P2 = P2, 1, 3, 4, 6, 7      | 2, 3, 6, 7, 10, 11
//  P3 = P3, 2, 3, 4, 8         | 4, 5, 6, 7, 12
//  P4 = P4, 5, 6, 7, 8         | 8, 9, 10, 11, 12

//  1:  P1, P2          |   1100    |   0011    |   3
//  2:  P1,     P3      |   1010    |   0101    |   5
//  3:      P2, P3      |   0110    |   0110    |   6
//  4:  P1, P2, P3      |   1110    |   0111    |   7
//  5:  P1,         P4  |   1001    |   1001    |   9
//  6:      P2,     P4  |   0101    |   1010    |   10
//  7:  P1, P2,     P4  |   1101    |   1011    |   11
//  8:          P3, P4  |   0011    |   1100    |   12

int main(int argc, char **argv)
{
    assert(argc >= 3);
    int8 fileSize = (int8)getFiles(&argc, &argv);
    fwrite(&fileSize, sizeof(int8), 1, outF);

    printf("\n================= SENDER =================\n"
           "\nIN  : %s\nOUT : %s\n"
           "\n┌─────┬──────────────┐\n",
           argv[1], argv[2]);

    for (int8 i = 0; i < fileSize; i++)
    {
        int16 code = getCodeFor(in[i]);

        printf("│  %c  │ ", char_val(in[i]));
        PRINT_BITS(MESSAGE_SIZE - 1, 0, code)
        printf(" │\n");

        // code |= 2;
        fwrite(&(code), sizeof(int16), 1, outF);
    }

    printf("└─────┴──────────────┘"
           "\n\n================= SENDER =================\n\n");
    return 0;
}