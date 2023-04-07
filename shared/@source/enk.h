/// enk \\\
encode N with base K

#ifndef __ENK__H
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdint.h>
    #include "utypes.h"

    unsigned int pack(uchar *buf,char const *fmt,...);
    void unpack(uchar *buf,char const *fmt,...);

    // various encodings
    void enc_unum(size_t base,uchar *buf,ulong i);
    #define packu16(ubuf,num) (enc_unum(1,ubuf,num))
    #define packu32(ubuf,num) (enc_unum(3,ubuf,num))
    #define packu64(ubuf,num) (enc_unum(7,ubuf,num))
    void enc_brnum(size_t base,size_t roof,uchar *buf,ulong *i);

    //packing
    void pack_i_16(uchar *buf,uns i);
    void pack_i_32(uchar *buf,unsigned long int i);
    void pack_i_64(uchar *buf,unsigned long long int i);
   

    //unpacking
    uns unpack_u_16(uchar *buf);
    int unpack_i_16(uchar *buf);
    #define unpacki16 unpack_i_16
    unsigned long int unpack_u_32(uchar *buf);
    long int unpack_i_32(uchar *buf);
    unsigned long long int unpack_u_64(uchar *buf);
    long long int unpack_i_64(uchar *buf);

    #define __ENK__H 1
#endif