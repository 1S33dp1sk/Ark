/**
 * Thanks for the all the contributions and good work from 
 * the keccak team http://keccak.noekeon.org/
 * and brainhub team crypto@brainhub.org 
 * for their combined efforts on the implementation of the `sha-3` hash.
 *
**/
#ifndef __HBAR__H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "utypes.h"
    #define hlv h_level

    static uns h_level=0;
    
    #if defined( _MSC_VER )
        #define __sha3_const(x) x
    #else
        #define __sha3_const(x) x##L
    #endif

    static const uint64_t keccakf_rndc[24] = {
        __sha3_const( 0x0000000000000001UL ), __sha3_const( 0x0000000000008082UL ),
        __sha3_const( 0x800000000000808aUL ), __sha3_const( 0x8000000080008000UL ),
        __sha3_const( 0x000000000000808bUL ), __sha3_const( 0x0000000080000001UL ),
        __sha3_const( 0x8000000080008081UL ), __sha3_const( 0x8000000000008009UL ),
        __sha3_const( 0x000000000000008aUL ), __sha3_const( 0x0000000000000088UL ),
        __sha3_const( 0x0000000080008009UL ), __sha3_const( 0x000000008000000aUL ),
        __sha3_const( 0x000000008000808bUL ), __sha3_const( 0x800000000000008bUL ),
        __sha3_const( 0x8000000000008089UL ), __sha3_const( 0x8000000000008003UL ),
        __sha3_const( 0x8000000000008002UL ), __sha3_const( 0x8000000000000080UL ),
        __sha3_const( 0x000000000000800aUL ), __sha3_const( 0x800000008000000aUL ),
        __sha3_const( 0x8000000080008081UL ), __sha3_const( 0x8000000000008080UL ),
        __sha3_const( 0x0000000080000001UL ), __sha3_const( 0x8000000080008008UL )
    };

    static const unsigned keccakf_rotc[24] = {
        1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
        18, 39, 61, 20, 44
    };

    static const unsigned keccakf_piln[24] = {
        10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
        14, 22, 9, 6, 1
    };


    #define __size_u64 sizeof(uint64_t)
    #define __sha3_k_sponge_w (((1600)/8)/__size_u64) //bits to byte
    #define __sha3_k_use_flag 0x80000000 // flag for PURE keccak
    #define __sha3_cw(x) ((x)&(~__sha3_k_use_flag))
    #define __sha3_assert(rcond)
    #define __sha3_trace(fmt,...)
    #define __sha3_trace_buf(format,buf,l)
    #define sha3_init256(p) sha3_init(p,256)
    #define sha3_init384(p) sha3_init(p,384)
    #define sha3_init512(p) sha3_init(p,512)

    struct __sha3_context {
        uint64_t saved;             
                // remainder of input string that we didn't consume yet
        union {                     
            uint64_t s[__sha3_k_sponge_w];
            uint8_t sb[__sha3_k_sponge_w*8];
        } u;                        
                // keccak's state 
        unsigned byte_idx;         
                // 0..7--the next byte after the set one (starts from 0; 0--none are buffered) 
        unsigned word_idx;         
                // 0..24--the next word to integrate input (starts from 0)
        unsigned cap_words;
                // the double size of the hash output in words (e.g. 16 for Keccak 512)
    };
    #define sha3_context struct __sha3_context
    static sha3_context __sha3;
    #define __size_sha3_context sizeof( struct __sha3_context )
    enum __sha3_return {
        __sha3_u_ok = 0,
        __sha3_u_n = 1
    };
    enum __sha3_flags {
        __sha3_flag_none__ = 0,
        __sha3_flag_keccak__ = 1
    };
    #define sha3_config_t enum __sha3_flags
    #define sha3_return_t enum __sha3_return

    #ifndef __sha3_rot_l_64
        #define __sha3_rot_l_64(x, y) (((x) << (y)) | ((x) >> ((__size_u64*8) - (y))))
    #endif

    #undef get16bits
    #if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
    || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
        #define get16bits(d) (*((const uint16_t *)(d)))
    #endif
    #if !defined (get16bits)
        #define get16bits(d) ((((uint32_t) (((const uint8_t *)(d))[1]))<<8)\
                            +(uint32_t) (((const uint8_t *) (d))[0]))
    #endif

    // blzd hash

    #define __sfh_t const uns*
    #define sfh_t __sfh_t
    #define sfh(x) __sfh_t ((uns const*)(super_fast_hash(__,strlen(__))))

    void byte_to_hex(uint8_t _,char _s[3]);
    void hash_to_string(char *_hstr,uint8_t _);

    sha3_config_t sha3_set_flags(void *p,sha3_config_t);
    sha3_return_t sha3_init(void *p,unsigned bit_size);
    sha3_return_t sha3_hash_buffer(unsigned bit_size,sha3_config_t cfg,const void *in,unsigned in_bytes,void *out,unsigned out_bytes);
    void sha3_update(void *p,void const *buf_in,size_t len);
    void const *sha3_finalize(void *ctx_p);

    const char *zeroatt(uns level);

    char const *fhashof (uns level,char const*to_hash);
    uint8_t const *fhash (uns level,char const *to_hash);

    uns  fhash4 (uns level,char const *to_hash);
    ulong fhash8 (uns level,char const *to_hash);
    ulong fhash16 (uns level,char const *to_hash);

    char const *hashof (uns level,void const*to_hash,size_t the_hash_size);
    uint8_t const *hash (uns level,void const *to_hash,size_t the_hash_size);

    uns  hash4 (uns level,void const *to_hash,size_t the_hash_size);
    ulong hash8 (uns level,void const *to_hash,size_t the_hash_size);
    void * hash16 (uns level,void const *to_hash,size_t the_hash_size);

    #define __HBAR__H 1
#endif
