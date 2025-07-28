#include <hamming.h>
#include <stdio.h>
#include <stdlib.h>

// void getLen()
// {
//     while (wrd->encodedValue >> len)
//     {
//         len++;
//     }
// }

void checkParity()
{
    int parityPosition = 0;
    for (unsigned char powOf2 = 1; powOf2 <= MESSAGE_SIZE; powOf2 = powOf2 << 1)
    {
        char parity = 0;

        for (int j = powOf2; j <= MESSAGE_SIZE; j = j + 2 * powOf2)
            for (unsigned char k = j; k < (j + powOf2) && k <= MESSAGE_SIZE; k++)
                if (arr[k])
                    parity = !parity;

        parityPosition += powOf2 * parity;
    }
    if (parityPosition)
    {
        printf(" ERROR AT : %d ", parityPosition);
        arr[parityPosition] = !arr[parityPosition];
    }
    else
        printf(" NO ERROR HERE ");
}

char getDecodedCharFrom(unsigned short code)
{
    char res = 0;
    for (unsigned char i = 0; i < MESSAGE_SIZE; i++)
    {
        arr[i] = 0;
    }

    // getLen();
    for (int j = 1; j <= MESSAGE_SIZE; j++)
    {
        arr[j] = (code & (1 << (MESSAGE_SIZE - j))) ? 1 : 0;
    }
    checkParity();

    char powOf2 = 1 << (PARITY_COUNT - 1);
    char chLen = 0;
    int i = MESSAGE_SIZE;
    while (chLen < DATA_BIT_CNT)
    {
        if (i == powOf2)
        {
            powOf2 = powOf2 >> 1;
        }
        else
        {
            res = res | ((arr[i] == 1) ? (1 << (chLen)) : 0);
            chLen++;
        }
        i--;
    }
    return res;
}
