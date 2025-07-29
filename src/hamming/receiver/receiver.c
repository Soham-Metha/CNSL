#include <assert.h>
#include <fileOps.h>
#include <hamming.h>

int main(int argc, char **argv)
{
    assert(getFiles(&argc, &argv));
    printf("\n================ RECEIVER ================\n"
           "\nIN  : %s\nOUT : %s\n",
           argv[1], argv[2]);

    int8 *encodedText = (int8 *)(&in[1]);

    printf("\n┌───────────────────┬─────┬──────────────┐");
    for (unsigned char i = 0; i < in[0]; i++)
    {
        printf("\n│  ");
        char ch = getDecodedCharFrom(encodedText[i]);

        printf("  │  %c  │ ", (ch == '\n') ? '\\' : ch);
        PRINT_BITS(MESSAGE_SIZE - 1, 0, encodedText[i])
        printf(" │");

        fprintf(outF, "%c", ch);
    }

    printf("\n└───────────────────┴─────┴──────────────┘"
           "\n\n================ RECEIVER ================\n\n");
    return 0;
}
