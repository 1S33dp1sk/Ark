#ifndef hbar
    #define __hbar_name "hash_bar"
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
    #define hbar hashof


/**
 * 
 * Thanks for the all the contributions and good work from 
 * the keccak team http://keccak.noekeon.org/
 * and brainhub team crypto@brainhub.org 
 * for their combined efforts on the implementation of the `sha-3` hash.
 *
 */
#define __size_u64 sizeof( uint64_t )
#define __sha3_k_sponge_w ( ( ( 1600 ) / 8 ) / __size_u64 )
        //bits to byte
#define __sha3_k_use_flag 0x80000000
        // flag for PURE keccak
#define __sha3_cw( x ) ( ( x ) & ( ~__sha3_k_use_flag ) )


struct __sha3_context {
    uint64_t saved;             
            // remainder of input string that we didn't consume yet
    union {                     
        uint64_t s[__sha3_k_sponge_w];
        uint8_t sb[__sha3_k_sponge_w * 8];
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
#define __size_sha3_context sizeof( struct __sha3_context )
static sha3_context __sha3;

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
#define sfh_t uint32_t

sha3_config_t sha3_set_flags( 
    void *p, 
    sha3_config_t 
);

sha3_return_t sha3_init( 
    void *p, 
    unsigned bit_size 
);

sha3_return_t sha3_hash_buffer( 
    unsigned bit_size,   
            // 256, 384, 512 
    sha3_config_t cfg, 
            // __sha3_flag_none__ or __sha3_flag_keccak__
    const void *in, unsigned in_bytes,
            // up to bit_size / 8
    void *out, unsigned out_bytes 
            // truncation OK 
);

sfh_t super_fast_hash( 
    char const*data , 
    int len
);

void sha3_update( 
    void *p , 
    void const *buf_in , 
    size_t len 
);

void const *sha3_finalize( 
    void *p
);

void byte_to_hex( 
    uint8_t _, 
    char _s[3]
);

void hash_to_string( 
    char *_hstr , 
    uint8_t _ 
);

extern char const *hashof( 
    unsigned level , 
    void const *tohash , 
    size_t thsize 
);

extern char const *fhash( 
    unsigned level, 
    char const *filepath 
);

#define sfh( __ ) \
    (int)super_fast_hash( __ , strlen( __ ) )

#define sc_sfh( _ ) \
    super_fast_hash( ( (char *) _ ) , 1 )

#define sha3_init256( priv ) \
    sha3_init( priv , 256 )

#define sha3_init384( priv ) \
    sha3_init( priv , 384 )

#define sha3_init512( priv ) \
    sha3_init( priv , 512 )

#define hof_size( level ) \
    level == 0 ? 1 : \
    level == 1 ? sizeof( int ) : \
    sizeof( int ) * ( ( level ) * ( level ) ) 

#define sof_size( level ) \
    ( hof_size( level ) * 2  )

uint8_t const *hashof_raw(unsigned level,void const *tohash,size_t thsize);

unsigned hash4(unsigned level,void const*tohash,size_t thsize);

ulong hash8(unsigned level,void const*tohash,size_t thsize);

ulong fhash8(
    unsigned lvl,
    char const*fpath
);

#endif
