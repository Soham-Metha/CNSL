#include <assert.h>
#include <ping.h>
#include <stdlib.h>

void copy(int8 *dst, int8 *src, int16 len)
{
    int16 n;
    int8 *sptr, *dptr;
    for (sptr = src, dptr = dst, n = len; n > 0; n--)
    {
        *dptr++ = *sptr++;
    }
}

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
    copy($1 & pkt->data, data, len);

    pkt->checksum = getChecksum(pkt);

    return pkt;
}

icmpWrapper *icmpWrapperConstructor(pktType type, int8 *data, int16 len)
{
    if (!data || !len)
        return (icmpWrapper *)0;

    icmpWrapper *pkt;
    int16 pktSize = len + sizeof(struct icmpWrapper);
    pkt = (icmpWrapper *)malloc($i pktSize);
    assert(pkt);

    pkt->type = TYPE_ECHO;
    pkt->len = len;
    pkt->data = data;

    return pkt;
}