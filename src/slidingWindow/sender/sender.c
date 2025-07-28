#include <GBN.h>
#include <fileOps.h>
#include <stdio.h>

int ackCnt = 0, sentCnt = 0;
void getAck()
{
    int ack;
    printf("\nNo ACK: -1"
           "\n   ACK: no.");
    if (!scanf("%d", &ack))
    {
    }
    ackCnt = (ack == -1) ? ackCnt : ack;
}

int main(int argc, char **argv)
{
    printf("\n================= SENDER =================\n");
    long fileSize = getFiles(&argc, &argv);

    for (long i = 0; sentCnt < fileSize; i++)
    {
        while ((sentCnt - ackCnt) < WIN_SIZE)
        {
            printf("sending %d %c", sentCnt, in[i]);
            sentCnt += 1;
        }
        getAck();
        sentCnt = ackCnt;
    }

    printf("\n\n================= SENDER =================\n\n");
    return 0;
}