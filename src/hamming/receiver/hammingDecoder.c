#include <hamming.h>

char getDecodedCharFrom(unsigned short code)
{
    unsigned char arr[MESSAGE_SIZE + 1];
    unsigned char ParityVal = 0;
    for (int i = 1; i <= MESSAGE_SIZE; i++)
    { // Load value into arr, & update corresponding parity bits
        // opposite hammingEncoder:31 stmt :=>  result |= arr[i] << (MESSAGE_SIZE - i);
        arr[i] = !!(code & (1 << (MESSAGE_SIZE - i)));
        if (arr[i])
            ParityVal ^= i;
    }

    if (ParityVal)
    { // Error Correction
        printf(" ERROR AT : %d ", ParityVal);
        arr[ParityVal] = !arr[ParityVal];
    }
    else
        printf(" NO ERROR HERE ");

    char res = 0;
    unsigned char i = 1;
    for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; i++)
    {
        if (i == powOf2)
        { // skip parity bits(present at location 'powerOf2')
            powOf2 = powOf2 << 1;
            continue;
        }

        { // Load data Bit into 'result'
            res = res | (arr[i] ? (1 << (chLen)) : 0);
        }
        chLen--;
    }
    return res;
}
