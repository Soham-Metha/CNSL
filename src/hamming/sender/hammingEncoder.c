#include <hamming.h>

unsigned short getCodeFor(char ch)
{
    unsigned char arr[MESSAGE_SIZE + 1];
    for (unsigned char i = 0; i <= MESSAGE_SIZE; i++)
        arr[i] = 0;

    unsigned char i = 1;
    for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; i++)
    {
        if (i == powOf2)
        { // skip parity bits(present at location 'powerOf2')
            powOf2 = powOf2 << 1;
            continue;
        }

        if (ch & (1 << (chLen)))
        { // Load value into arr, & update corresponding parity bits
            arr[i] = 1;
            for (char j = 0; j < PARITY_COUNT; j++)
                // arr[1 << j] ^= !!(i & (1 << j));
                if (i & (1 << j))
                    arr[(1 << j)] = !arr[(1 << j)];
        }
        chLen--;
    }

    unsigned short result = 0;
    for (int i = 1; i <= MESSAGE_SIZE; i++)
        // Load all Bits into 'result'
        result |= arr[i] << (MESSAGE_SIZE - i);

    return result;
}
