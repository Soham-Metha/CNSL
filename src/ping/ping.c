#include <assert.h>
#include <ping.h>
#include <stdlib.h>

icmp *icmpConstructor(int8 type, int8 code, int8 *data, int16 len)
{
    if (!data || !len)
        return (icmp *)0;

    icmp *pkt;
    int16 pktSize = len + sizeof(struct icmp);
    pkt = (icmp *)malloc($i pktSize);
    assert(pkt);

    pkt->code = code;
    pkt->type = type;
    pkt->checksum = getChecksum(pkt);
}