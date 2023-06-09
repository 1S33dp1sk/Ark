
/************************ d-koding ************************/


    void enc_u(uchar *__buffer, uchar __) {
        *__buffer++=__;
    };

    void enc_s(uchar *__buffer, schar __) {
        *__buffer++=__;
    };

    void enc_u8(uchar *__buffer, ulong __) {
        *__buffer++=__>>24; *__buffer++=__>>16;
        *__buffer++=__>>8;  *__buffer++=__;
    };

    void enc_u64(uchar *__buffer, ullong __) {
        *__buffer++=__>>56; *__buffer++=__>>48;
        *__buffer++=__>>40; *__buffer++=__>>32;
        *__buffer++=__>>24; *__buffer++=__>>16;
        *__buffer++=__>>8;  *__buffer++=__; 
    };

    void enc_u512(uchar *__buffer, ullong __[3]) {
        for(ulong i=0; i<3; i+=1) {
            enc_u64(__buffer, __[i]);
        };
    };

    void enc_unum(ulong base, uchar *buf, ulong i) {
        while (base>0) {
            *buf++=i>>(8*base);
            base--; 
        };
        *buf++=i;
    };

    void enc_punum( ulong base , ulong roof , uchar *buf , ulong *i ) {
        for(ulong iter=0; roof-iter>0; iter++){
            while (base>0) {
                *buf++ = i[iter] >> (8*base);
                base--;
            };
            *buf++= i[iter];
        };
    };

    void enc_i(uchar *__buffer, char __) {
        *__buffer++=__;
    };

    /********************************************************************
    *********************************************************************/

    char dnc_i(uchar *__buffer) {

        return (char)*__buffer++;
    };

    schar dnc_s(uchar *__buffer) {

        return (schar)*__buffer++;
    };

    uchar dnc_u(uchar *__buffer) {

        return *__buffer++;
    };

    slong dnc_i8(uchar *__buffer) {
        slong res=0;
        ulong temp = \
            ((ulong)__buffer[0]<<24) | 
            ((ulong)__buffer[1]<<16) |
            ((ulong)__buffer[2]<<8)  | __buffer[3];
        if(temp<=_LONG_MID) {
            res=temp;
        }
        else {
            res=-1-((slong)(_LONG_MAX-temp));
        };
        return res;
    };

    ulong dnc_u8(uchar *__buffer) {
        return \
            ((ulong)__buffer[0]<<24) | 
            ((ulong)__buffer[1]<<16) |
            ((ulong)__buffer[2]<<8)  | __buffer[3];
    };

    sllong dnc_i64(uchar *__buffer) {
        sllong res=0;
        ullong temp = \
            ((ullong)__buffer[0]<<56) |
            ((ullong)__buffer[1]<<48) |
            ((ullong)__buffer[2]<<40) |
            ((ullong)__buffer[3]<<32) |
            ((ullong)__buffer[4]<<24) |
            ((ullong)__buffer[5]<<16) |
            ((ullong)__buffer[6]<<8)  | __buffer[7];
        if(temp<=_LLONG_MID) {
            res=temp;
        }
        else {
            res=-1-((sllong)(_LLONG_MAX-temp));
        };
        return res;
    };

    ullong dnc_u64(uchar *__buffer) {
        return \
            ((ullong)__buffer[0]<<56) |
            ((ullong)__buffer[1]<<48) |
            ((ullong)__buffer[2]<<40) |
            ((ullong)__buffer[3]<<32) |
            ((ullong)__buffer[4]<<24) |
            ((ullong)__buffer[5]<<16) |
            ((ullong)__buffer[6]<<8)  | __buffer[7];
    };


    sllong* dnc_i512(uchar *__buffer) {
        sllong temp=0;
        sllong res[3];
        for(ulong i=0;i<3;i+=1) {
            res[i]=dnc_i64(__buffer);
        };
        return_sll();
        // return &res;
    };

    // ullong* dnc_u512(uchar *__buffer) {
    //     ullong *res = __d3(ullong);
    //     for(ulong i=0;i<3;i+=1) {
    //         res[i]=dnc_u64(__buffer);
    //     };
    //     return res;
    // };
    ulong pack(uchar *__buffer, char const *__format , ...){
        return 0;
    }
    void unpack(uchar *__buffer, char const *__format , ... ) {
    }



    // /*
    // pack() -- store data dictated by the format string in the buffer
    //     **
    //     **   bits - bytes |  signed   unsigned   float   string
    //     **   -----+--------------------------------------------
    //     **      8 -   1    |   c         C         
    //     **     16 -   2    |   h         H         f
    //     **     32 -   4    |   l         L         d
    //     **     64 -   8    |   q         Q         g
    //     **      - - 2 -    |                               s
    //     **
    //     **  (16-bit unsigned length is automatically prepended to strings)
    // */ 
    // ulong pack(unsigned char *buf, char const *format, ...) {
    //     va_list ap;

    //     signed char c;              // 8-bit
    //     unsigned char C;

    //     int h;                      // 16-bit
    //     unsigned int H;

    //     long int l;                 // 32-bit
    //     unsigned long int L;

    //     long long int q;            // 64-bit
    //     unsigned long long int Q;

    //     char *s;                    // strings
    //     unsigned int len;

    //     unsigned int size = 0;

    //     va_start(ap, format);

    //     for(; *format != '\0'; format++) {
    //         switch(*format) {

    //         case '\n':
    //             C=(unsigned char)'\n';
    //             size+=1;*buf++=C;
    //             break;

    //         case '_':
    //             C=(unsigned char)'_';
    //             size+=1;*buf++=C;
    //             break;
           
    //         case ':':
    //             C=(unsigned char)':';
    //             size+=1;*buf++=C;
    //             break;

    //         case 'c': // 8-bit
    //             size += 1;
    //             c = (signed char)va_arg(ap, int); // promoted
    //             *buf++ = c;
    //             break;

    //         case 'C': // 8-bit unsigned
    //             size += 1;
    //             C = (unsigned char)va_arg(ap, unsigned int); // promoted
    //             *buf++ = C;
    //             break;

    //         case 'h': // 16-bit
    //             size += 2;
    //             h = va_arg(ap, int);
    //             packi16(buf, h);
    //             buf += 2;
    //             break;

    //         case 'H': // 16-bit unsigned
    //             size += 2;
    //             H = va_arg(ap, unsigned int);
    //             packu16(buf, H);
    //             buf += 2;
    //             break;

    //         case 'l': // 32-bit
    //             size += 4;
    //             l = va_arg(ap, long int);
    //             packi32(buf, l);
    //             buf += 4;
    //             break;

    //         case 'L': // 32-bit unsigned
    //             size += 4;
    //             L = va_arg(ap, unsigned long int);
    //             packu32(buf, L);
    //             buf += 4;
    //             break;

    //         case 'q': // 64-bit
    //             size += 8;
    //             q = va_arg(ap, long long int);
    //             packi64(buf, q);
    //             buf += 8;
    //             break;

    //         case 'Q': // 64-bit unsigned
    //             Q = va_arg(ap, ulong);
    //             if(Q==0) {
    //                 packu16(buf, 0);
    //                 buf+=2;
    //                 size+=2;
    //             }
    //             else {
    //                 packu64(buf, Q);
    //                 buf+=8;
    //                 size+=8;
    //             };
    //             break;

    //         case 's': // string
    //             s = va_arg(ap, char*);
    //             len = strlen(s);
    //             size += len + 4;
    //             packi32(buf, len);
    //             buf += 4;
    //             memcpy(buf, s, len);
    //             buf += len;
    //             break;
    //         }
    //     }

    //     va_end(ap);

    //     return size;
    // }
    // /*
    // unpack() -- unpack data dictated by the format string into the buffer
    //     **
    //     **   bits |signed   unsigned   float   string
    //     **   -----+----------------------------------
    //     **      8 |   c        C         
    //     **     16 |   h        H         f
    //     **     32 |   l        L         d
    //     **     64 |   q        Q         g
    //     **      - |                               s
    //     **
    //     **  (string is extracted based on its stored length, but 's' can be
    //     **  prepended with a max length)
    // */
    // void unpack( unsigned char *buf , char const*format , ... ) {
    //     va_list ap;

    //     signed char *c;              // 8-bit
    //     unsigned char *C;

    //     int *h;                      // 16-bit
    //     unsigned int *H;

    //     long int *l;                 // 32-bit
    //     unsigned long int *L;

    //     long long int *q;            // 64-bit
    //     ulong *Q;



    //     float *f;                    // floats
    //     double *d;
    //     long double *g;
    //     unsigned long long int fhold;

    //     char *s;
    //     unsigned int len, maxstrlen=0, count;

    //     va_start(ap, format);

    //     for(; *format != '\0'; format++) {
    //         switch(*format) {

    //         case ':': 
    //             #ifdef TRACE
    //                 printf("Socket:buffer @%u\n", *buf);
    //             #endif
    //             buf++; break;

    //         case '_':
    //             #ifdef TRACE
    //                 printf("Parse_buffer @%u\n", *buf);
    //             #endif
    //             ++buf; break;

    //         case '\n':
    //             #ifdef TRACE
    //                 printf("n'buffer @%u\n", *buf);
    //             #endif
    //             buf++; break;

    //         case 'c': // 8-bit
    //             c = va_arg(ap, signed char*);
    //             if (*buf <= 0x7f) { *c = *buf;} // re-sign
    //             else { *c = -1 - (unsigned char)(0xffu - *buf); }
    //             buf++;
    //             break;

    //         case 'C': // 8-bit unsigned
    //             C = va_arg(ap, unsigned char*);
    //             *C = *buf++;
    //             break;

    //         case 'h': // 16-bit
    //             h = va_arg(ap, int*);
    //             *h = unpacki16(buf);
    //             buf += 2;
    //             break;

    //         case 'H': // 16-bit unsigned
    //             H = va_arg(ap, unsigned int*);
    //             *H = unpacku16(buf);
    //             buf += 2;
    //             break;

    //         case 'l': // 32-bit
    //             l = va_arg(ap, long int*);
    //             *l = unpacki32(buf);
    //             buf += 4;
    //             break;

    //         case 'L': // 32-bit unsigned
    //             L = va_arg(ap, unsigned long int*);
    //             *L = unpacku32(buf);
    //             buf += 4;
    //             break;

    //         case 'q': // 64-bit
    //             q = va_arg(ap, long long int*);
    //             *q = unpacki64(buf);
    //             buf += 8;
    //             break;

    //         case 'Q': // 64-bit unsigned
    //             Q=va_arg(ap, ulong*);
    //             *Q=unpack_u_64(buf);
    //             buf+=8;
    //             break;

    //         case 'U': // u128 bit unsigned compression
    //             if(unpacku16(buf)==0){
    //                 printf("u0 = 0\n");
    //                 u[0]=0;
    //                 buf+=2;
    //             }
    //             else {
    //                 u[0]=unpack_u_64(buf);
    //                 buf+=8;
    //             };
    //             ++buf;
    //             if(unpacku16(buf)==0){
    //                 printf("u1 = 0\n");
    //                 u[1]=0;
    //                 buf+=2;
    //             }
    //             else {
    //                 u[1]=unpack_u_64(buf);  
    //                 buf+=8;
    //             };
    //             ++buf;
    //             if(unpacku16(buf)==0){
    //                 printf("u2 = 0\n");
    //                 u[2]=0;
    //                 buf+=2;
    //             }
    //             else {
    //                 u[2]=unpack_u_64(buf);  
    //                 buf+=8;
    //             };
    //             ++buf;
    //             #ifdef DEBUG
    //                 printf("U0 : %lu\t", u[0]);
    //                 printf("U1 : %lu\t", u[1]);
    //                 printf("U2 : %lu\n", u[2]);
    //             #endif
    //             break;

    //         case 's': // string
    //             s = va_arg(ap, char*);
    //             len = unpacku32(buf);
    //             buf += 4;
    //             printf("length is = %u\n", len);
    //             count=len;
    //             memcpy(s, buf, count);
    //             s[count] = '\0';
    //             printf("s : %s\n", s);
    //             buf+=len;
    //             break;
    //         default:
    //             if(__numchar(*format)) { 
    //                 // track max str len
    //                 maxstrlen=(maxstrlen*10)+_C_ZERO(*format);
    //             };
    //         };
    //         if(!__numchar(*format)){
    //           maxstrlen=0;  
    //         };
    //     };

    //     va_end(ap);
    // }

