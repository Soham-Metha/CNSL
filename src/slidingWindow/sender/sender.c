#include <GBN.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("\n================= SENDER =================\n");
    long fileSize = getFiles(&argc, &argv);

    printf("\n┌─────┬──────────────┐\n");
    for (long i = 0; i < fileSize; i++)
    {
    }

    printf("└─────┴──────────────┘"
           "\n\n================= SENDER =================\n\n");
    return 0;
}