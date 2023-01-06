#ifndef hbar
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    #define hbar hash_bar
=======
=======
    #define __hbar_name "hash_bar"
<<<<<<< HEAD
>>>>>>> b3b1c06 (started the_*kurl)
=======
    #include "../probe.h"
>>>>>>> d369e4b (alignments)
    #define hbar hashof
>>>>>>> 4f65147 (initial athernet structure including kurling , probing & builder for simple first stage rollout)

#include <stdint.h>
#include <string.h>
=======
#include <stdint.h>
#include <string.h>
// #define HASH_DEBUG

>>>>>>> 4947f52 (v0.01-NS)
=======
    #define hbar hash_bar

#include <stdint.h>
#include <string.h>
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
    #define __hbar_name "hash_bar"
    #include "../probe.h"
=======
>>>>>>> c1e4320 (athernet V0.9)
    #define hbar hashof
>>>>>>> a415938 (kurls)

/**
 * 
 * Thanks for the all the contributions and good work from 
 * the keccak team http://keccak.noekeon.org/
 * and brainhub team crypto@brainhub.org 
 * for their combined efforts on the implementation of the `sha-3` hash.
 *
 */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1e4320 (athernet V0.9)
#define SHA3_KECCAK_SPONGE_WORDS \
    ( ( ( 1600 ) / 8/*bits to byte*/) / sizeof( uint64_t ) )

// flag is used to configure "pure" Keccak, as opposed to NIST SHA3.
#define SHA3_USE_KECCAK_FLAG 0x80000000
#define SHA3_CW( x ) ( ( x ) & ( ~SHA3_USE_KECCAK_FLAG ) )
<<<<<<< HEAD


typedef struct sha3_context_ {
    uint64_t saved;             /* the portion of the input message that we didn't consume yet */
    union {                     
        uint64_t s[SHA3_KECCAK_SPONGE_WORDS];
        uint8_t sb[SHA3_KECCAK_SPONGE_WORDS * 8];
    } u;                        /* Keccak's state */
    unsigned byteIndex;         /* 0..7--the next byte after the set one (starts from 0; 0--none are buffered) */
    unsigned wordIndex;         /* 0..24--the next word to integrate input (starts from 0) */
    unsigned capacityWords;     /* the double size of the hash output in words (e.g. 16 for Keccak 512) */
} sha3_context;

=======
#define MAX_STR 256
#define sfh( _ ) super_fast_hash( _ , strlen( _ ) )
#define sha3_init256( priv ) sha3_init( priv , 256 )
#define sha3_init384( priv ) sha3_init( priv , 384 )
#define sha3_init512( priv) sha3_init( priv , 512 )
#define SHA3_KECCAK_SPONGE_WORDS ( ( ( 1600 ) / 8/*bits to byte*/) / sizeof( uint64_t ) )
#define hbar hash_bar( _in , lvl , _out )


uint32_t super_fast_hash( char *data , int len );
void byte_to_hex( uint8_t _ , char _s[3] );
void hash_to_string( char *_hstr , uint8_t _ );



#ifndef byte_to_hex
void __btoh( uint8_t b , char s[3] ) {
    uint32_t i=1;
    s[0] = s[1] = '0';
    s[2] = '\0';
    while( b ) {
        uint32_t t = b & 0x0f;
        
        if( t < 10 ) {
            s[i] = '0' + t;
        } 
        else {
            s[i] = 'a' + t - 10;
        }
        
        i--;
        b >>= 4;
    }
}
#endif
#define byte_to_hex __btoh

=======
#define SHA3_KECCAK_SPONGE_WORDS \
    ( ( ( 1600 ) / 8/*bits to byte*/) / sizeof( uint64_t ) )
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

// flag is used to configure "pure" Keccak, as opposed to NIST SHA3.
#define SHA3_USE_KECCAK_FLAG 0x80000000
#define SHA3_CW( x ) ( ( x ) & ( ~SHA3_USE_KECCAK_FLAG ) )
=======
#define __size_u64 sizeof( uint64_t )
#define __sha3_k_sponge_w ( ( ( 1600 ) / 8 ) / __size_u64 )
        //bits to byte
#define __sha3_k_use_flag 0x80000000
        // flag for PURE keccak
#define __sha3_cw( x ) ( ( x ) & ( ~__sha3_k_use_flag ) )
>>>>>>> 4317814 (started anet.h)


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

<<<<<<< HEAD
<<<<<<< HEAD
enum SHA3_FLAGS {
    SHA3_FLAGS_NONE=0,
    SHA3_FLAGS_KECCAK=1
};
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

enum SHA3_RETURN {
    SHA3_RETURN_OK=0,
    SHA3_RETURN_BAD_PARAMS=1
};

typedef enum SHA3_RETURN sha3_return_t;

/* For Init or Reset call these: */
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
sha3_return_t sha3_init( void *priv , unsigned bit_size );
uint32_t super_fast_hash( char *data , int len );
void byte_to_hex( uint8_t _ , char _s[3] );
void hash_to_string( char *_hstr , uint8_t _ );
<<<<<<< HEAD
<<<<<<< HEAD
char *hash_bar( char *_in , unsigned level );
<<<<<<< HEAD
=======
char *hashof( unsigned level , void *tohash , size_t thsize );
char *fhash( unsigned level , char *filepath );

=======
extern char *hashof( unsigned level , void *tohash , size_t thsize );
extern char *fhash( unsigned level , char *filepath );
>>>>>>> 1b97cf4 (broke everything)

>>>>>>> 4f65147 (initial athernet structure including kurling , probing & builder for simple first stage rollout)

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



=======
sha3_return_t sha3_init(void *priv, unsigned bitSize);

enum SHA3_FLAGS sha3_set_flags(void *priv, enum SHA3_FLAGS);

void sha3_update(void *priv, void const *bufIn, size_t len);

void const *sha3_finalize(void *priv);

/* Single-call hashing */
sha3_return_t sha3_hash_buffer( 
    unsigned bitSize,   /* 256, 384, 512 */
    enum SHA3_FLAGS flags, /* SHA3_FLAGS_NONE or SHA3_FLAGS_KECCAK */
    const void *in, unsigned inBytes, 
    void *out, unsigned outBytes );     /* up to bitSize/8; truncation OK */


#define SHA3_ASSERT( x )
#define SHA3_TRACE( format, ... )
#define SHA3_TRACE_BUF( format , buf , l )

/* 
 * This flag is used to configure "pure" Keccak, as opposed to NIST SHA3.
 */
#define SHA3_USE_KECCAK_FLAG 0x80000000
#define SHA3_CW(x) ((x) & (~SHA3_USE_KECCAK_FLAG))


#if defined(_MSC_VER)
#define SHA3_CONST(x) x
#else
#define SHA3_CONST(x) x##L
#endif

#ifndef SHA3_ROTL64
#define SHA3_ROTL64(x, y) (((x) << (y)) | ((x) >> ((sizeof(uint64_t)*8) - (y))))
#endif


static const uint64_t keccakf_rndc[24] = {
    SHA3_CONST(0x0000000000000001UL), SHA3_CONST(0x0000000000008082UL),
    SHA3_CONST(0x800000000000808aUL), SHA3_CONST(0x8000000080008000UL),
    SHA3_CONST(0x000000000000808bUL), SHA3_CONST(0x0000000080000001UL),
    SHA3_CONST(0x8000000080008081UL), SHA3_CONST(0x8000000000008009UL),
    SHA3_CONST(0x000000000000008aUL), SHA3_CONST(0x0000000000000088UL),
    SHA3_CONST(0x0000000080008009UL), SHA3_CONST(0x000000008000000aUL),
    SHA3_CONST(0x000000008000808bUL), SHA3_CONST(0x800000000000008bUL),
    SHA3_CONST(0x8000000000008089UL), SHA3_CONST(0x8000000000008003UL),
    SHA3_CONST(0x8000000000008002UL), SHA3_CONST(0x8000000000000080UL),
    SHA3_CONST(0x000000000000800aUL), SHA3_CONST(0x800000008000000aUL),
    SHA3_CONST(0x8000000080008081UL), SHA3_CONST(0x8000000000008080UL),
    SHA3_CONST(0x0000000080000001UL), SHA3_CONST(0x8000000080008008UL)
};

static const unsigned keccakf_rotc[24] = {
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
    18, 39, 61, 20, 44
};

static const unsigned keccakf_piln[24] = {
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
    14, 22, 9, 6, 1
};

/* generally called after SHA3_KECCAK_SPONGE_WORDS-ctx->capacityWords words 
 * are XORed into the state s 
 */
static void keccakf( uint64_t s[25] ) {
    int i, j, round;
    uint64_t t, bc[5];
#define KECCAK_ROUNDS 24

    for( round = 0; round < KECCAK_ROUNDS; round++ ) {

        /* Theta */
        for( i = 0; i < 5; i++ )
            bc[i] = s[i] ^ s[i + 5] ^ s[i + 10] ^ s[i + 15] ^ s[i + 20];

        for( i = 0; i < 5; i++ ) {
            t = bc[( i + 4 ) % 5] ^ SHA3_ROTL64( bc[( i + 1 ) % 5], 1 );
            for( j = 0; j < 25; j += 5 )
                s[j + i] ^= t;
        }

        /* Rho Pi */
        t = s[1];
        for( i = 0; i < 24; i++ ) {
            j = keccakf_piln[i];
            bc[0] = s[j];
            s[j] = SHA3_ROTL64( t, keccakf_rotc[i] );
            t = bc[0];
        }

        /* Chi */
        for( j = 0; j < 25; j += 5 ) {
            for( i = 0; i < 5; i++ )
                bc[i] = s[j + i];
            for( i = 0; i < 5; i++ )
                s[j + i] ^= ( ~bc[( i + 1 ) % 5] ) & bc[( i + 2 ) % 5];
        }

        /* Iota */
        s[0] ^= keccakf_rndc[round];
    }
}

/* *************************** Public Inteface ************************ */

/* For Init or Reset call these: */
sha3_return_t sha3_init(void *priv, unsigned bitSize) {
    sha3_context *ctx = (sha3_context *) priv;
    if( bitSize != 256 && bitSize != 384 && bitSize != 512 )
        return SHA3_RETURN_BAD_PARAMS;
    memset(ctx, 0, sizeof(*ctx));
    ctx->capacityWords = 2 * bitSize / (8 * sizeof(uint64_t));
    return SHA3_RETURN_OK;
}



enum SHA3_FLAGS sha3_set_flags(void *priv, enum SHA3_FLAGS flags) {
    sha3_context *ctx = (sha3_context *) priv;
    flags &= SHA3_FLAGS_KECCAK;
    ctx->capacityWords |= (flags == SHA3_FLAGS_KECCAK ? SHA3_USE_KECCAK_FLAG : 0);
    return flags;
}


void sha3_update( void *priv, void const *bufIn, size_t len ) {
    sha3_context *ctx = (sha3_context *) priv;

    /* 0...7 -- how much is needed to have a word */
    unsigned old_tail = (8 - ctx->byteIndex) & 7;

    size_t words;
    unsigned tail;
    size_t i;

    const uint8_t *buf = bufIn;

    SHA3_TRACE_BUF("called to update with:", buf, len);

    SHA3_ASSERT(ctx->byteIndex < 8);
    SHA3_ASSERT(ctx->wordIndex < sizeof(ctx->u.s) / sizeof(ctx->u.s[0]));

    if(len < old_tail) {        /* have no complete word or haven't started 
                                 * the word yet */
        SHA3_TRACE("because %d<%d, store it and return", (unsigned)len,
                (unsigned)old_tail);
        /* endian-independent code follows: */
        while (len--)
            ctx->saved |= (uint64_t) (*(buf++)) << ((ctx->byteIndex++) * 8);
        SHA3_ASSERT(ctx->byteIndex < 8);
        return;
    }

    if(old_tail) {              /* will have one word to process */
        SHA3_TRACE("completing one word with %d bytes", (unsigned)old_tail);
        /* endian-independent code follows: */
        len -= old_tail;
        while (old_tail--)
            ctx->saved |= (uint64_t) (*(buf++)) << ((ctx->byteIndex++) * 8);

        /* now ready to add saved to the sponge */
        ctx->u.s[ctx->wordIndex] ^= ctx->saved;
        SHA3_ASSERT(ctx->byteIndex == 8);
        ctx->byteIndex = 0;
        ctx->saved = 0;
        if(++ctx->wordIndex ==
                (SHA3_KECCAK_SPONGE_WORDS - SHA3_CW(ctx->capacityWords))) {
            keccakf(ctx->u.s);
            ctx->wordIndex = 0;
        }
    }

    /* now work in full words directly from input */

    SHA3_ASSERT(ctx->byteIndex == 0);

    words = len / sizeof(uint64_t);
    tail = len - words * sizeof(uint64_t);

    SHA3_TRACE("have %d full words to process", (unsigned)words);

    for(i = 0; i < words; i++, buf += sizeof(uint64_t)) {
        const uint64_t t = (uint64_t) (buf[0]) |
                ((uint64_t) (buf[1]) << 8 * 1) |
                ((uint64_t) (buf[2]) << 8 * 2) |
                ((uint64_t) (buf[3]) << 8 * 3) |
                ((uint64_t) (buf[4]) << 8 * 4) |
                ((uint64_t) (buf[5]) << 8 * 5) |
                ((uint64_t) (buf[6]) << 8 * 6) |
                ((uint64_t) (buf[7]) << 8 * 7);
#if defined(__x86_64__ ) || defined(__i386__)
        SHA3_ASSERT(memcmp(&t, buf, 8) == 0);
#endif
        ctx->u.s[ctx->wordIndex] ^= t;
        if(++ctx->wordIndex ==
                (SHA3_KECCAK_SPONGE_WORDS - SHA3_CW(ctx->capacityWords))) {
            keccakf(ctx->u.s);
            ctx->wordIndex = 0;
        }
    }

    SHA3_TRACE("have %d bytes left to process, save them", (unsigned)tail);

    /* finally, save the partial word */
    SHA3_ASSERT(ctx->byteIndex == 0 && tail < 8);
    while (tail--) {
        SHA3_TRACE("Store byte %02x '%c'", *buf, *buf);
        ctx->saved |= (uint64_t) (*(buf++)) << ((ctx->byteIndex++) * 8);
    }
    SHA3_ASSERT(ctx->byteIndex < 8);
    SHA3_TRACE("Have saved=0x%016" PRIx64 " at the end", ctx->saved);
}

/* This is simply the 'update' with the padding block.
 * The padding block is 0x01 || 0x00* || 0x80. First 0x01 and last 0x80 
 * bytes are always present, but they can be the same byte.
 */
void const *sha3_finalize(void *priv) {
    sha3_context *ctx = (sha3_context *) priv;

    SHA3_TRACE("called with %d bytes in the buffer", ctx->byteIndex);

    /* Append 2-bit suffix 01, per SHA-3 spec. Instead of 1 for padding we
     * use 1<<2 below. The 0x02 below corresponds to the suffix 01.
     * Overall, we feed 0, then 1, and finally 1 to start padding. Without
     * M || 01, we would simply use 1 to start padding. */

    uint64_t t;

    if( ctx->capacityWords & SHA3_USE_KECCAK_FLAG ) {
        /* Keccak version */
        t = (uint64_t)(((uint64_t) 1) << (ctx->byteIndex * 8));
    }
    else {
        /* SHA3 version */
        t = (uint64_t)(((uint64_t)(0x02 | (1 << 2))) << ((ctx->byteIndex) * 8));
    }

    ctx->u.s[ctx->wordIndex] ^= ctx->saved ^ t;

    ctx->u.s[SHA3_KECCAK_SPONGE_WORDS - SHA3_CW(ctx->capacityWords) - 1] ^=
            SHA3_CONST(0x8000000000000000UL);
    keccakf(ctx->u.s);

    /* Return first bytes of the ctx->s. This conversion is not needed for
     * little-endian platforms e.g. wrap with #if !defined(__BYTE_ORDER__)
     * || !defined(__ORDER_LITTLE_ENDIAN__) || __BYTE_ORDER__!=__ORDER_LITTLE_ENDIAN__ 
     *    ... the conversion below ...
     * #endif */
    {
        unsigned i;
        for(i = 0; i < SHA3_KECCAK_SPONGE_WORDS; i++) {
            const unsigned t1 = (uint32_t) ctx->u.s[i];
            const unsigned t2 = (uint32_t) ((ctx->u.s[i] >> 16) >> 16);
            ctx->u.sb[i * 8 + 0] = (uint8_t) (t1);
            ctx->u.sb[i * 8 + 1] = (uint8_t) (t1 >> 8);
            ctx->u.sb[i * 8 + 2] = (uint8_t) (t1 >> 16);
            ctx->u.sb[i * 8 + 3] = (uint8_t) (t1 >> 24);
            ctx->u.sb[i * 8 + 4] = (uint8_t) (t2);
            ctx->u.sb[i * 8 + 5] = (uint8_t) (t2 >> 8);
            ctx->u.sb[i * 8 + 6] = (uint8_t) (t2 >> 16);
            ctx->u.sb[i * 8 + 7] = (uint8_t) (t2 >> 24);
        }
    }
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

#define sfh( _ ) \
    super_fast_hash( _ , strlen( _ ) )
=======
#define __size_u64 sizeof( uint64_t )
#define __sha3_k_sponge_w ( ( ( 1600 ) / 8 ) / __size_u64 )
        //bits to byte
#define __sha3_k_use_flag 0x80000000
        // flag for PURE keccak
#define __sha3_cw( x ) ( ( x ) & ( ~__sha3_k_use_flag ) )
=======
>>>>>>> c1e4320 (athernet V0.9)


typedef struct sha3_context_ {
    uint64_t saved;             /* the portion of the input message that we didn't consume yet */
    union {                     
        uint64_t s[SHA3_KECCAK_SPONGE_WORDS];
        uint8_t sb[SHA3_KECCAK_SPONGE_WORDS * 8];
    } u;                        /* Keccak's state */
    unsigned byteIndex;         /* 0..7--the next byte after the set one (starts from 0; 0--none are buffered) */
    unsigned wordIndex;         /* 0..24--the next word to integrate input (starts from 0) */
    unsigned capacityWords;     /* the double size of the hash output in words (e.g. 16 for Keccak 512) */
} sha3_context;

=======
#define __size_sha3_ctx sizeof( struct __sha3_context )

static sha3_context __sha3;
>>>>>>> 4317814 (started anet.h)

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
    super_fast_hash( __ , strlen( __ ) )

#define sc_sfh( _ ) \
    super_fast_hash( ( (char *) _ ) , 1 )
>>>>>>> a415938 (kurls)

#define sha3_init256( priv ) \
    sha3_init( priv , 256 )

#define sha3_init384( priv ) \
    sha3_init( priv , 384 )

#define sha3_init512( priv ) \
    sha3_init( priv , 512 )

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD



<<<<<<< HEAD
/**
 * @dev used to hash the input from
 * @param key       : `argv[1]`
 * 
 * and copy the result to a pre-allocated buffer
 * @param hashkey   : ( char[256] )
 */
#ifndef hbar_str
char *__s_hash( char *key , char *hashkey ) {
    #ifdef HASH_DEBUG
    printf( "-----BEGIN HASH DEBUG-----\n");
    printf( "key :: %s\n" , key );
    #endif
    int key_len = strlen( key );
    #ifdef HASH_DEBUG
    printf( "keylen :: %d\n" , key_len );
    #endif
    sha3_init256( &__sha3 );
    sha3_set_flags( &__sha3 , 1 );
    sha3_update( &__sha3 , key , key_len );
    uint8_t *__hash = ( uint8_t *) sha3_finalize( &__sha3 );
    __htostr( hashkey , __hash );
    #ifdef HASH_DEBUG
    printf( "hashkey : result : %s\n" , hashkey );
    printf( "-----END HASH DEBUG-----\n" );
    #endif
    return hashkey;
}
#endif
#define hbar_str __s_hash
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

=======
=======

>>>>>>> c1e4320 (athernet V0.9)
=======
>>>>>>> 4317814 (started anet.h)
#define hof_size( level ) \
    level == 0 ? 1 : \
    level == 1 ? sizeof( int ) : \
    sizeof( int ) * ( ( level ) * ( level ) ) 

#define sof_size( level ) \
    ( hof_size( level ) * 2  )
>>>>>>> a415938 (kurls)

#endif
