#include <GBN.h>
#include <stdio.h>

int ackCnt = 0, sentCnt = 0;

void getAck()
{
	int ack;
	printf("\nNo ACK: -1"
	       "\n   ACK: no."
	       "\nEnter : ");

	if (!scanf("%d", &ack)) {
		printf("\nCouldn't read ack, Please enter again.\n");
		return getAck();
	}

	if (ack == -1) {
		return;
	}

	if (ack > sentCnt || ack < ackCnt) {
		getAck();
	} else {
		ackCnt = ack;
	}
}

void goBackN(int8 fileSize)
{
	while (sentCnt < fileSize) {
		while ((sentCnt < fileSize) && (sentCnt - ackCnt) < WIN_SIZE) {
			printf("\nsending %3d/%d '%c'", sentCnt, fileSize - 1,
			       (in[sentCnt] == '\n') ? '\\' : in[sentCnt]);
			sentCnt += 1;
		}
		getAck();
		sentCnt = ackCnt;
	}
}