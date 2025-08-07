#include <assert.h>
#include <utils.h>
#include <hamming.h>

int main(int argc, char **argv)
{
	assert(argc == PARAM_CNT);
	assert(getFiles(&argc, &argv));

	printf("\n================ RECEIVER ================\n"
	       "\nIN  : %s\nOUT : %s\nEXP : %s\n",
	       argv[PARAM_INPUT_FILE], argv[PARAM_OUTPUT_FILE],
	       argv[PARAM_EXP_NO]);

	switch (*argv[PARAM_EXP_NO]) {
	case '3':
		hammingReceiver();
		break;

	default:
		break;
	}

	printf("\n\n================ RECEIVER ================\n\n");
	return 0;
}
