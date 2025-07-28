#include <stdio.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

typedef struct icmp
{
    int8 type;
    int8 code;
    int16 checksum;
    int8 data[];
};

typedef struct icmp icmp;

icmp *icmpConstructor(int8 type, int8 code, int8 *data, int16 len);