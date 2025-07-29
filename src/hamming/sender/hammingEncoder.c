#include <hamming.h>
#include <stdio.h>
unsigned char arr[MESSAGE_SIZE + 1];

// void getMsbPosition(HammingSymbol *wrd)
// {
//     while (wrd->charValue >> wrd->dataBitCnt)
//     {
//         wrd->dataBitCnt++;
//     }
//     wrd->dataBitCnt = 8;
// }

// void getPriorityBitCnt(HammingSymbol *wrd)
// {
//     unsigned char bits = 1;
//     while ((bits << wrd->parityBitCnt) < (wrd->dataBitCnt + 1 + wrd->parityBitCnt))
//     {
//         wrd->parityBitCnt++;
//     }
// }

void getPrePriorityChangeValue(char ch)
{
    int i = 1;

    for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; chLen > 0)
    {
        if (i == powOf2)
            powOf2 = powOf2 << 1;
        else
        {
            arr[i] = (ch & (1 << (chLen))) ? 1 : 0;
            // printf("%d", arr[i]);
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

    // getMsbPosition(&wrd);
    // getPriorityBitCnt(&wrd);
    getPrePriorityChangeValue(ch);
    unsigned short result = 0;

    for (unsigned char powOf2 = 1; powOf2 <= MESSAGE_SIZE; powOf2 = powOf2 << 1)
    {
        char parity = 0;

        for (int j = powOf2; j <= MESSAGE_SIZE; j = j + 2 * powOf2)
            for (unsigned char k = j; k < j + powOf2 && k <= MESSAGE_SIZE; k++)
            {
                if (arr[k])
                {
                    parity = !parity;
                }
            }
        arr[powOf2] = parity;
    }
    for (int i = 1; i <= MESSAGE_SIZE; i++)
    {
        result |= arr[i] << (MESSAGE_SIZE - i);
    }
    return result;
}