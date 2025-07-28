#pragma once

#define DATA_BIT_CNT 8
#define PARITY_COUNT 4
#define MESSAGE_SIZE (DATA_BIT_CNT + PARITY_COUNT)
#define PRINT_BITS(ub, lb, data)                                                                                       \
    {                                                                                                                  \
        for (int __j = ub; __j >= lb; __j--)                                                                           \
        {                                                                                                              \
            printf("%d", (data >> __j) & 1);                                                                           \
        }                                                                                                              \
    }

typedef struct HammingSymbol
{
    unsigned char charValue;     // dealing with ASCII
    unsigned short encodedValue; // Bit after encoding (with Hamming parity applied)
} HammingSymbol;

extern unsigned char arr[MESSAGE_SIZE + 1];

void getMsbPosition(HammingSymbol *wrd);

void getPriorityBitCnt(HammingSymbol *wrd);

void getPrePriorityChangeValue(HammingSymbol *wrd);

HammingSymbol getCodeFor(char ch);

char getDecodedCharFrom(unsigned short code);