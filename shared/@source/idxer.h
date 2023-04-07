/// idxer \\\
ternary indexer (:
#include "utypes.h"
static ulong ___base___[3]={
    0xFFFFFFFF77777777,
    0x7777777711111111,
    0x1111111100000000
};
static const ulong *idx=(ulong*)&___base___;
#define base_k ((ulong *)(idx))

struct __kei {
    ulong k;
    ulong e;
    ulong i;
};
#define IDX 0xa0
#define TD_INDEX 0x1<<3
#if TD_INDEX
    #include <stdio.h>
    #define log_td() \
    do {printf("((%lu))\n", TD_INDEX );}while(1!=0)
#endif
    