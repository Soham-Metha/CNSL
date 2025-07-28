#include <GBN.h>
#include <fileOps.h>
#include <stdio.h>

int ackCnt = 0, sentCnt = 0;
void getAck()
{
    int ack;
    printf("\nNo ACK: -1"
           "\n   ACK: no."
           "\nEnter : ");
    if (!scanf("%d", &ack))
    {
    }
    ackCnt = (ack == -1) ? ackCnt : ack + 1;
}

int main(int argc, char **argv)
{
    printf("\n================= SENDER =================\n");
    long fileSize = getFiles(&argc, &argv);

    while (sentCnt < fileSize)
    {
        while ((sentCnt < fileSize) && (sentCnt - ackCnt + 1) < WIN_SIZE)
        {
            printf("\nsending %3d/%ld '%c'", sentCnt, fileSize - 1, (in[sentCnt] == '\n') ? '\\' : in[sentCnt]);
            sentCnt += 1;
        }
        getAck();
        sentCnt = ackCnt;
    }

    printf("\n\n================= SENDER =================\n\n");
    return 0;
}