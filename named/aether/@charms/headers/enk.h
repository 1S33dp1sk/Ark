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
#endif/// encoder main \\\

#ifndef __ENK__H
#include "enk.h"
#endif
#ifndef __enk_name
	#define __enk_name "encoding_number_k"
    #define packi16 pack_i_16
    #define packi32 pack_i_32
    #define packi64 pack_i_64

    #define unpacki16 unpack_i_16
    #define unpacki32 unpack_i_32
    #define unpacki64 unpack_i_64
    
    #define unpacku16 unpack_u_16
    #define unpacku32 unpack_u_32
    #define unpacku64 unpack_u_64

    void enc_unum( ulong base , uchar *buf , ulong i ) {
        while ( base > 0 ) {
            *buf++ = i >> (8*base);
            base--; 
        }
        *buf++ = i;
    }

    void enc_brnum( ulong base , ulong roof , uchar *buf , ulong *i ) {
        for(ulong iter=0; roof-iter>0; iter++){
            while ( base > 0 ) {
                *buf++ = i[iter] >> (8*base);
                base--;
            }
            *buf++= i[iter];
        }
    }

    
    // 16 bit integer
    void pack_i_16(uchar*buf , unsigned int i ) {

        *buf++ = i >> 8; *buf++ = i;
    }
    // 32 bit integer
    void pack_i_32(uchar*buf , unsigned long int i ) {

        *buf++ = i>>24; *buf++ = i>>16;
        *buf++ = i>>8;  *buf++ = i;
    }
    // 64 bit integer
    void pack_i_64(uchar*buf , unsigned long long int i ) {
        *buf++ = i>>56; *buf++ = i>>48;
        *buf++ = i>>40; *buf++ = i>>32;
        *buf++ = i>>24; *buf++ = i>>16;
        *buf++ = i>>8;  *buf++ = i; 
    }

    /********************************************************************
    *********************************************************************/

    // 16 bit SIGNED
    int unpack_i_16(uchar*buf ) {
        unsigned int i2 = ( ( unsigned int )buf[0]<<8 )| buf[1];
        int i;
        if ( i2 <= 0x7fffu ) { i = i2; }
        else { i = -1 - ( unsigned int )( 0xffffu - i2 ); }
        return i;
    }
    // 16 bit UNSIGNED 
    unsigned int unpack_u_16(uchar*buf ) {
        return ( ( unsigned int )buf[0]<<8 )| buf[1]; 
    }
    // 32 bit SIGNED
    long int unpack_i_32(uchar*buf ) {
        unsigned long int i2 =  ( ( unsigned long int )buf[0]<<24 ) | 
                                ( ( unsigned long int )buf[1]<<16 ) |
                                ( ( unsigned long int )buf[2]<<8 )  |
                                buf[3];
        long int i;
        if ( i2 <= 0x7fffffffu ) { i = i2; }
        else { i = -1 - ( long int )( 0xffffffffu - i2 ); }
        return i;
    }
    // 32 bit UNSIGNED
    unsigned long int unpack_u_32(uchar*buf ) {
        return \
            ( ( unsigned long int )buf[0]<<24 ) | 
            ( ( unsigned long int )buf[1]<<16 ) |
            ( ( unsigned long int )buf[2]<<8 )  |
            buf[3];
    }
    // 64 bit SIGNED 
    long long int unpack_i_64(uchar*buf ) {
        unsigned long long int i2 = 
            ( ( unsigned long long int )buf[0]<<56 ) |
            ( ( unsigned long long int )buf[1]<<48 ) |
            ( ( unsigned long long int )buf[2]<<40 ) |
            ( ( unsigned long long int )buf[3]<<32 ) |
            ( ( unsigned long long int )buf[4]<<24 ) |
            ( ( unsigned long long int )buf[5]<<16 ) |
            ( ( unsigned long long int )buf[6]<<8 )  |
            buf[7];
        long long int i;
        if ( i2 <= 0x7fffffffffffffffu ) { i = i2; }
        else { i = -1 - ( long long int )( 0xffffffffffffffffu - i2 ); }
        return i;
    }
    // 64 bit UNSIGNED
    unsigned long long int unpack_u_64(uchar*buf ) {
        return \
            ( ( unsigned long long int )buf[0]<<56 ) |
            ( ( unsigned long long int )buf[1]<<48 ) |
            ( ( unsigned long long int )buf[2]<<40 ) |
            ( ( unsigned long long int )buf[3]<<32 ) |
            ( ( unsigned long long int )buf[4]<<24 ) |
            ( ( unsigned long long int )buf[5]<<16 ) |
            ( ( unsigned long long int )buf[6]<<8 )  |
            buf[7];
    }

    /*
    pack() -- store data dictated by the format string in the buffer
        **
        **   bits |signed   unsigned   float   string
        **   -----+----------------------------------
        **      8 |   c        C         
        **     16 |   h        H         f
        **     32 |   l        L         d
        **     64 |   q        Q         g
        **      - |                               s
        **
        **  (16-bit unsigned length is automatically prepended to strings)
    */ 
    unsigned int pack( unsigned char *buf , char const*format , ... ) {
        va_list ap;

        signed char c;              // 8-bit
        unsigned char C;

        int h;                      // 16-bit
        unsigned int H;

        long int l;                 // 32-bit
        unsigned long int L;

        long long int q;            // 64-bit
        unsigned long long int Q;

        char *s;                    // strings
        unsigned int len;

        unsigned int size = 0;

        va_start(ap, format);

        for(; *format != '\0'; format++) {
            switch(*format) {
            case '_':
                C=(unsigned char)'_';
                size+=1;*buf++=C;
                break;

            case 'c': // 8-bit
                size += 1;
                c = (signed char)va_arg(ap, int); // promoted
                *buf++ = c;
                break;

            case 'C': // 8-bit unsigned
                size += 1;
                C = (unsigned char)va_arg(ap, unsigned int); // promoted
                *buf++ = C;
                break;

            case 'h': // 16-bit
                size += 2;
                h = va_arg(ap, int);
                packi16(buf, h);
                buf += 2;
                break;

            case 'H': // 16-bit unsigned
                size += 2;
                H = va_arg(ap, unsigned int);
                packi16(buf, H);
                buf += 2;
                break;

            case 'l': // 32-bit
                size += 4;
                l = va_arg(ap, long int);
                packi32(buf, l);
                buf += 4;
                break;

            case 'L': // 32-bit unsigned
                size += 4;
                L = va_arg(ap, unsigned long int);
                packu32(buf, L);
                buf += 4;
                break;

            case 'q': // 64-bit
                size += 8;
                q = va_arg(ap, long long int);
                packi64(buf, q);
                buf += 8;
                break;

            case 'Q': // 64-bit unsigned
                size += 8;
                Q = va_arg(ap, unsigned long long int);
                packu64(buf, Q);
                buf += 8;
                break;

            case 's': // string
                s = va_arg(ap, char*);
                len = strlen(s);
                size += len + 4;
                packi32(buf, len);
                buf += 4;
                memcpy(buf, s, len);
                buf += len;
                break;
            }
        }

        va_end(ap);

        return size;
    }
    /*
    unpack() -- unpack data dictated by the format string into the buffer
        **
        **   bits |signed   unsigned   float   string
        **   -----+----------------------------------
        **      8 |   c        C         
        **     16 |   h        H         f
        **     32 |   l        L         d
        **     64 |   q        Q         g
        **      - |                               s
        **
        **  (string is extracted based on its stored length, but 's' can be
        **  prepended with a max length)
    */
    void unpack( unsigned char *buf , char const*format , ... ) {
        va_list ap;

        signed char *c;              // 8-bit
        unsigned char *C;

        int *h;                      // 16-bit
        unsigned int *H;

        long int *l;                 // 32-bit
        unsigned long int *L;

        long long int *q;            // 64-bit
        unsigned long long int *Q;

        float *f;                    // floats
        double *d;
        long double *g;
        unsigned long long int fhold;

        char *s;
        unsigned int len, maxstrlen=0, count;

        va_start(ap, format);

        for(; *format != '\0'; format++) {
            switch(*format) {
            case '_':
                C = va_arg(ap, unsigned char*);
                *C = *buf++;
                break;

            case 'c': // 8-bit
                c = va_arg(ap, signed char*);
                if (*buf <= 0x7f) { *c = *buf;} // re-sign
                else { *c = -1 - (unsigned char)(0xffu - *buf); }
                buf++;
                break;

            case 'C': // 8-bit unsigned
                C = va_arg(ap, unsigned char*);
                *C = *buf++;
                break;

            case 'h': // 16-bit
                h = va_arg(ap, int*);
                *h = unpacki16(buf);
                buf += 2;
                break;

            case 'H': // 16-bit unsigned
                H = va_arg(ap, unsigned int*);
                *H = unpack_u_16(buf);
                buf += 2;
                break;

            case 'l': // 32-bit
                l = va_arg(ap, long int*);
                *l = unpacki32(buf);
                buf += 4;
                break;

            case 'L': // 32-bit unsigned
                L = va_arg(ap, unsigned long int*);
                *L = unpack_u_32(buf);
                buf += 4;
                break;

            case 'q': // 64-bit
                q = va_arg(ap, long long int*);
                *q = unpacki64(buf);
                buf += 8;
                break;

            case 'Q': // 64-bit unsigned
                Q = va_arg(ap, unsigned long long int*);
                *Q = unpack_u_64(buf);
                buf += 8;
                break;

            case 's': // string
                s = va_arg(ap, char*);
                len = unpacku32(buf);
                buf += 4;
                if (maxstrlen > 0 && len >= maxstrlen) count = maxstrlen - 1;
                else count = len;
                memcpy(s, buf, count);
                s[count] = '\0';
                buf += len;
                break;

            default:
                if (isdigit(*format)) { // track max str len
                    maxstrlen = maxstrlen * 10 + (*format-'0');
                }
            }

            if (!isdigit(*format)) maxstrlen = 0;
        }

        va_end(ap);
    }
#endif