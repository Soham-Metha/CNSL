#include <hamming.h>
#include <stdio.h>
unsigned char arr[MESSAGE_SIZE + 1];

void getPrePriorityChangeValue(char ch)
{
    int i = 1;

    for (char chLen = DATA_BIT_CNT, powOf2 = 1; chLen > 0;)
    {
        if (i == powOf2)
        {
            powOf2 = powOf2 << 1;
        }
        else
        {
            // arr[i] = (ch & (1 << (chLen - 1))) ? 1 : 0;
            // printf("%d", arr[i]);
            if (ch & (1 << (chLen - 1)))
            {
                arr[i] = 1;
                printf("\nval %c %d ", ch, ch);
                if (i & (1 << 0))
                {
                    arr[(1 << 0)] = !arr[(1 << 0)];
                    printf("pos %d ", 1 << 0);
                }
                if (i & (1 << 1))
                {
                    arr[(1 << 1)] = !arr[(1 << 1)];
                    printf("pos %d ", 1 << 1);
                }
                if (i & (1 << 2))
                {
                    arr[(1 << 2)] = !arr[(1 << 2)];
                    printf("pos %d ", 1 << 2);
                }
                if (i & (1 << 3))
                {
                    arr[(1 << 3)] = !arr[(1 << 3)];
                    printf("pos %d ", 1 << 3);
                }
            }
            chLen--;
        }
        i++;
    }
}

unsigned short getCodeFor(char ch)
{
    for (unsigned char i = 0; i < MESSAGE_SIZE; i++)
    {
        arr[i] = 0;
    }

    getPrePriorityChangeValue(ch);
    unsigned short result = 0;

    // for (unsigned char powOf2 = 1; powOf2 <= MESSAGE_SIZE; powOf2 = powOf2 << 1)
    // {
    //     char parity = 0;

    //     for (int j = powOf2; j <= MESSAGE_SIZE; j = j + 2 * powOf2)
    //         for (unsigned char k = j; k < j + powOf2 && k <= MESSAGE_SIZE; k++)
    //         {
    //             if (arr[k])
    //             {
    //                 parity = !parity;
    //             }
    //         }
    //     arr[powOf2] = parity;
    // }
    for (int i = 1; i <= MESSAGE_SIZE; i++)
    {
        result |= arr[i] << (MESSAGE_SIZE - i);
    }
    return result;
}