#ifndef hbar
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


typedef struct __sha3_context {
    uint64_t saved;             
            // remainder of input string that we didn't consume yet
    union {                     
        uint64_t s[__sha3_k_sponge_w];
        uint8_t sb[__sha3_k_sponge_w * 8];
    } u;                        
            // Keccak's state 
    unsigned byte_idx;         
            // 0..7--the next byte after the set one (starts from 0; 0--none are buffered) 
    unsigned word_idx;         
            // 0..24--the next word to integrate input (starts from 0)
    unsigned cap_words;
            // the double size of the hash output in words (e.g. 16 for Keccak 512)
} sha3_context;

#define __size_sha3_ctx sizeof( struct __sha3_context )

static sha3_context __sha3;

enum __sha3_return {
    __sha3_u_ok = 0,
    __sha3_u_n = 1
};

enum __sha3_flags {
    __sha3_flag_none__ = 0,
    __sha3_flag_keccak__ = 1
};

typedef enum __sha3_flags sha3_config_t;
typedef enum __sha3_return sha3_return_t;
typedef uint32_t sfh_t;

sha3_config_t sha3_set_flags( 
    void *p, 
    sha3_config_t 
);
sha3_return_t sha3_init( 
    void *priv, 
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
    char *data , 
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
extern char *hashof( 
    unsigned level , 
    void *tohash , 
    size_t thsize 
);
extern char *fhash( 
    unsigned level, 
    char *filepath 
);


#define sfh( __ ) \
    super_fast_hash( __ , strlen( __ ) )

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

#endif
