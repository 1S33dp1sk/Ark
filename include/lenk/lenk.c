#include <stdio.h>
#include "lenk.h"

// various bits for floating point types--
// varies for different architectures
#define float32_t float
#define float64_t double

int pack_unpack_test() {
    unsigned char buf[1024];
    int8_t magic;

    int16_t monkeycount;
    
    int32_t altitude;
    
    float32_t absurdityfactor;
    
    char *s = "Great unmitigated Zot! You've found the Runestaff!";
    
    char s2[96];
    
    int16_t packetsize, ps2;

    packetsize = pack(buf, "chhlsf", (int8_t)'a', (int16_t)0, (int16_t)37, 
            (int32_t)-5, s, (float32_t)-3490.6677);

    packi16(buf+1, packetsize); // store packet size in packet for kicks

    printf("packet is %ld bytes\n", packetsize);

    unpack(buf, "chhl96sf", &magic, &ps2, &monkeycount, &altitude, s2,
        &absurdityfactor);

    printf("'%d' %ld %d %d\"%s\" %f\n", magic, ps2, monkeycount,
            altitude, s2, absurdityfactor);

    return 0;
}

