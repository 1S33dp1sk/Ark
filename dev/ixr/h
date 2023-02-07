/// idxer \\\
ternary indexer (:

/**
 * ternary base is what determines
 * the main permissions in the system.
 * 
 * Permissions are divided into 2 main parts:
 * 1.   File type
 * a simple 2 bit/1 byte solution to determine the 
 * known type of the file. i.e: FIFO,Socket,Storage...
 &-> 
 * 2.   Access
 * With `Access` that's where the ternary actually 
 * shines. As it is divided into 3 main parts
 * a.   Root `file created-on`
 * b.   User `file use-by`
 * c.   Public `file accessible-to` 
 * 
 * the three different numbers determine the actual
 * R-W-X assignable values.
 * 
 * Keep in mind that all of the following code is based
 * on the current machines and their operations. Thus,
 * we are simulating a ternary system on a binary machine.
 * 
**/ 
#ifndef __IDXER__H
    #ifndef __UTYPES__H
    #include "utypes.h"
    #endif
    #ifndef __HBAR__H
    #include "hbar.h"
    #endif
    #ifndef __ENK__H
    #include "enk.h"
    #endif
    #include <sys/stat.h>

    #define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))

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

    size_t att(ulong sz);
    size_t lbb(uns level, ulong sz);
    size_t fsz8(ftype __);

    static const uns ter_base[3]={0xFFFF7777,0x77771111,0x11110000};
    #define ter_t typeof(ter_base)
    // ternary system 
    // but i would rather call it
    // system ternary or `sys`&`ter`->`syster`
    static ter_t syster;

    #define fatt att
    #define satt att
    #define fitt att
    #define datt att

    #define __IDXER__H 1
#endif