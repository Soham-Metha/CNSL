#include <assert.h>
#include <utils.h>
#include <GBN.h>
#include <hamming.h>

int main(int argc, char **argv)
{
	assert(argc == PARAM_CNT);
	int8 fileSize = (int8)getFiles(&argc, &argv);
	fwrite(&fileSize, sizeof(int8), 1, outF);

	printf("\n================= SENDER =================\n"
	       "\nIN  : %s\nOUT : %s\nEXP : %s\n",
	       argv[PARAM_INPUT_FILE], argv[PARAM_OUTPUT_FILE],
	       argv[PARAM_EXP_NO]);

	switch (*argv[PARAM_EXP_NO]) {
	case '3':
		hammingSender(fileSize);
		break;

	case '4':
		goBackN(fileSize);
		break;

	default:
		break;
	}

	printf("\n\n================= SENDER =================\n\n");
	return 0;
}