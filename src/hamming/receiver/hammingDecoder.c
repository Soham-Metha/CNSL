#include <hamming.h>

char getDecodedCharFrom(unsigned short code)
{
    unsigned char arr[MESSAGE_SIZE + 1];
    unsigned char ParityVal = 0;
    for (int i = 1; i <= MESSAGE_SIZE; i++)
    {
        arr[i] = !!(code & (1 << (MESSAGE_SIZE - i)));
        if (arr[i])
            ParityVal ^= i;
    }

    if (ParityVal)
    {
        printf(" ERROR AT : %d ", ParityVal);
        arr[ParityVal] = !arr[ParityVal];
    }
    else
        printf(" NO ERROR HERE ");

    int i = MESSAGE_SIZE;
    char res = 0;
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
