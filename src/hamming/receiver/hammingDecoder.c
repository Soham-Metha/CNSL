#include <hamming.h>
#include <stdio.h>
#include <stdlib.h>
unsigned char arr[MESSAGE_SIZE + 1];

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
    for (unsigned char i = 0; i <= MESSAGE_SIZE; i++)
        arr[i] = 0;

    for (int i = 1; i <= MESSAGE_SIZE; i++)
    {
        arr[i] = !!(code & (1 << (MESSAGE_SIZE - i)));
        for (unsigned char j = 0; j < PARITY_COUNT; j++)
            // arr[1 << j] ^= !!(i & (1 << j));
            if (i & (1 << j))
                arr[(1 << j)] = !arr[(1 << j)];
    }

    unsigned char ParityVal = 0;
    for (unsigned char j = 0; j < MESSAGE_SIZE; j = j << 1)
        ParityVal = j * arr[j];

    if (ParityVal)
    {
        printf(" ERROR AT : %d ", ParityVal);
        arr[ParityVal] = !arr[ParityVal];
    }
    else
        printf(" NO ERROR HERE ");
    // checkParity();

    int i = MESSAGE_SIZE;
    for (char chLen = 0, powOf2 = 1 << (PARITY_COUNT - 1); chLen < DATA_BIT_CNT; i--)
    {
        if (i == powOf2)
        {
            powOf2 = powOf2 >> 1;
            continue;
        }

        res = res | ((arr[i] == 1) ? (1 << (chLen)) : 0);
        chLen++;
    }
    return res;
}
