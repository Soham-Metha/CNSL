#include <hamming.h>
#include <stdio.h>
unsigned char arr[MESSAGE_SIZE + 1];

void getPrePriorityChangeValue(char ch)
{
    unsigned char i = 1;
    for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; i++)
    {
        if (i == powOf2)
        {
            powOf2 = powOf2 << 1;
            continue;
        }

        if (ch & (1 << (chLen)))
        {
            arr[i] = 1;
            for (char j = 0; j < PARITY_COUNT; j++)
                // if (i & (1 << j))
                //     arr[(1 << j)] = !arr[(1 << j)];
                arr[1 << j] ^= !!(i & (1 << j));
        }

        chLen--;
    }
}

unsigned short getCodeFor(char ch)
{
    for (unsigned char i = 0; i <= MESSAGE_SIZE; i++)
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