#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum Params
{
    PARAM_FILE_NAME,
    PARAM_SENDER,
    PARAM_RECEIVER,
    PARAM_INPUT_FILE,
    PARAM_INTERMEDIATE_FILE,
    PARAM_OUTPUT_FILE,
} Params;

char senderCmd[256];
char receiverCmd[256];
char diffCmd[256];

int main(int argc, char *argv[])
{
    assert(argc == 6);
    char senderCmd[256];
    snprintf(senderCmd, sizeof(senderCmd), "%s %s %s >/dev/null", argv[PARAM_SENDER], argv[PARAM_INPUT_FILE],
             argv[PARAM_INTERMEDIATE_FILE]);
    snprintf(receiverCmd, sizeof(receiverCmd), "%s %s %s >/dev/null", argv[PARAM_RECEIVER],
             argv[PARAM_INTERMEDIATE_FILE], argv[PARAM_OUTPUT_FILE]);
    snprintf(diffCmd, sizeof(diffCmd), "diff %s %s >/dev/null", argv[PARAM_INPUT_FILE], argv[PARAM_OUTPUT_FILE]);
    assert(system(senderCmd) == 0);
    assert(system(receiverCmd) == 0);
    assert(system(diffCmd) == 0);

    return 0;
}