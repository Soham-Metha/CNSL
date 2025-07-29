#pragma once
#include <stdio.h>

#define DATA_BIT_CNT 8
#define PARITY_COUNT 4
#define MESSAGE_SIZE (DATA_BIT_CNT + PARITY_COUNT)
#define char_val(v) (v == '\n') ? '\\' : v
#define PRINT_BITS(ub, lb, data)                                                                                       \
    {                                                                                                                  \
        for (int __j = ub; __j >= lb; __j--)                                                                           \
        {                                                                                                              \
            printf("%d", (data >> __j) & 1);                                                                           \
        }                                                                                                              \
    }

unsigned char arr[MESSAGE_SIZE + 1];
// extern unsigned char arr[MESSAGE_SIZE + 1];

// void getMsbPosition(HammingSymbol *wrd);

// void getPriorityBitCnt(HammingSymbol *wrd);

void getPrePriorityChangeValue(char ch);

unsigned short getCodeFor(char ch);

char getDecodedCharFrom(unsigned short code);