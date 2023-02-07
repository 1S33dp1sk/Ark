/// idxer \\\
ternary indexer (:

#ifndef __IDXER__H
    #ifndef __HBAR__H
    #include "hbar.h"
    #endif
    #ifndef __ENK__H
    #include "enk.h"
    #endif
    #include <sys/stat.h>

    #define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
/**
NNE(X)
     * @returns :   true if x is not 0x0000
*/
    #define NNE(v) v==0x0000?0x01:0x00

    enum __ftypes {
        que=1, //queue_idx
        sok=2, //socket_addr
        fid=3, //field
        dir=4, //directory
        lbb_1, //binary
        lbb_2, //
        lbb_3,
        lbb_4
    };
    #define ftype enum __ftypes

    uns __8sz(uns __);
    #define sz8(x) ((ulong)__8sz(x))

    ulong __fsize(char *fpath);
    #define fsze(x) ((ulong)__fsize(x))

    ulong __iosize(char *fpath);
    #define iosze(x) ((ulong)__iosize(x))

    uns __dmode(char *fpath);
    #define dmde(x) ((uns)__dmode(x))

    ulong attsize(ulong __sz);
    ulong lbbatt(uns level, ulong szatt);
    ulong fsz8(ftype __);

    static const uns ter_base[3]={0xFFFF7777,0x77771111,0x11110000};
    #define ter_t typeof(ter_base)
    // ternary system 
    // but i would rather call it
    // system ternary or `sys`&`ter`->`syster`
    static ter_t syster;

    #define __IDXER__H 1
#endif