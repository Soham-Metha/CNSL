#include <hamming.h>
#include <utils.h>

//  1   2   3   4   5   6   7   8   9   10  11  12
//  P1  P2  1   P3  2   3   4   P4  5   6   7   8

//  P1 = P1, 1, 2, 4, 5, 7      | 1, 3, 5, 7, 9, 11
//  P2 = P2, 1, 3, 4, 6, 7      | 2, 3, 6, 7, 10, 11
//  P3 = P3, 2, 3, 4, 8         | 4, 5, 6, 7, 12
//  P4 = P4, 5, 6, 7, 8         | 8, 9, 10, 11, 12

//  1:  P1,             |   1000    |   0001    |   1
//  2:      P2,         |   0100    |   0010    |   2
//  3:  P1, P2          |   1100    |   0011    |   3
//  4:          P3      |   0010    |   0100    |   4
//  5:  P1,     P3      |   1010    |   0101    |   5
//  6:      P2, P3      |   0110    |   0110    |   6
//  7:  P1, P2, P3      |   1110    |   0111    |   7
//  8:              P4  |   0001    |   1000    |   8
//  9:  P1,         P4  |   1001    |   1001    |   9
//  10:     P2,     P4  |   0101    |   1010    |   10
//  11: P1, P2,     P4  |   1101    |   1011    |   11
//  12:         P3, P4  |   0011    |   1100    |   12

char getDecodedCharFrom(unsigned short code)
{
	unsigned char arr[MESSAGE_SIZE + 1];
	unsigned char ParityVal = 0;
	for (int i = 1; i <= MESSAGE_SIZE;
	     i++) { // Load value into arr, & update corresponding parity bits
		// opposite hammingEncoder:31 stmt :=>  result |= arr[i] << (MESSAGE_SIZE - i);
		arr[i] = !!(code & (1 << (MESSAGE_SIZE - i)));
		if (arr[i])
			ParityVal ^= i;
	}

	if (ParityVal) { // Error Correction
		printf(" ERROR AT : %d ", ParityVal);
		arr[ParityVal] = !arr[ParityVal];
	} else
		printf(" NO ERROR HERE ");

	char res = 0;
	unsigned char i = 1;
	for (char chLen = DATA_BIT_CNT - 1, powOf2 = 1; chLen >= 0; i++) {
		if (i ==
		    powOf2) { // skip parity bits(present at location 'powerOf2')
			powOf2 = powOf2 << 1;
			continue;
		}

		{ // Load data Bit into 'result'
			// opposite hammingEncoder:18 :=> if (ch & (1 << (chLen))) arr[i] = 1;
			res = res | (arr[i] ? (1 << (chLen)) : 0);
		}
		chLen--;
	}
	return res;
}

void hammingReceiver()
{
	int16 *encodedText = (int16 *)(&in[1]);

	printf("\n┌───────────────────┬─────┬──────────────┐\n");
	for (int8 i = 0; i < in[0]; i++) {
		printf("│  ");
		char ch = getDecodedCharFrom(encodedText[i]);

		printf("  │  %c  │ ", char_val(ch));
		PRINT_BITS(MESSAGE_SIZE - 1, 0, encodedText[i])
		printf(" │\n");

		fprintf(outF, "%c", ch);
	}
	printf("└───────────────────┴─────┴──────────────┘");
}