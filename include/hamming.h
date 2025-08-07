#pragma once
#include <stdio.h>
#include <utils.h>

#define DATA_BIT_CNT 8
#define PARITY_COUNT 4
#define MESSAGE_SIZE (DATA_BIT_CNT + PARITY_COUNT)
#define char_val(v) (v == '\n') ? '\\' : v
#define PRINT_BITS(ub, lb, data)                         \
	{                                                \
		for (int __j = ub; __j >= lb; __j--) {   \
			printf("%d", (data >> __j) & 1); \
		}                                        \
	}

unsigned short getCodeFor(char ch);

char getDecodedCharFrom(unsigned short code);

void hammingSender(int8 fileSize);

void hammingReceiver();