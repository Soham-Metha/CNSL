#include <utils.h>
#include <hamming.h>

//  1   2   3   4   5   6   7   8   9   10  11  12
//  P1  P2  1   P3  2   3   4   P4  5   6   7   8

//  P1 = P1, 1, 2, 4, 5, 7      | 1, 3, 5, 7, 9, 11
//  P2 = P2, 1, 3, 4, 6, 7      | 2, 3, 6, 7, 10, 11
//  P3 = P3, 2, 3, 4, 8         | 4, 5, 6, 7, 12
//  P4 = P4, 5, 6, 7, 8         | 8, 9, 10, 11, 12

//  1:  P1, P2          |   1100    |   0011    |   3
//  2:  P1,     P3      |   1010    |   0101    |   5
//  3:      P2, P3      |   0110    |   0110    |   6
//  4:  P1, P2, P3      |   1110    |   0111    |   7
//  5:  P1,         P4  |   1001    |   1001    |   9
//  6:      P2,     P4  |   0101    |   1010    |   10
//  7:  P1, P2,     P4  |   1101    |   1011    |   11
//  8:          P3, P4  |   0011    |   1100    |   12

unsigned short getCodeFor(char ch)
{
	unsigned char arr[MESSAGE_SIZE + 1];
	for (unsigned char i = 0; i <= MESSAGE_SIZE; i++)
		arr[i] = 0;

	unsigned char i = 1;
	for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; i++) {
		if (i ==
		    powOf2) { // skip parity bits(present at location 'powerOf2')
			powOf2 = powOf2 << 1;
			continue;
		}

		if (ch &
		    (1
		     << (chLen))) { // Load value into arr, & update corresponding parity bits
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

void hammingSender(int8 fileSize)
{
	printf("\n┌─────┬──────────────┐\n");
	for (int8 i = 0; i < fileSize; i++) {
		int16 code = getCodeFor(in[i]);

		printf("│  %c  │ ", char_val(in[i]));
		PRINT_BITS(MESSAGE_SIZE - 1, 0, code)
		printf(" │\n");

		code |= 2;
		fwrite(&(code), sizeof(int16), 1, outF);
	}
	printf("└─────┴──────────────┘");
}