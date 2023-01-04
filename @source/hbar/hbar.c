#include "hbar.h"

<<<<<<< HEAD
<<<<<<< HEAD
#include <stdio.h>

/**
 * NOTICE :: missing file hashing
 */


#define MAX_STR 256

#define SHA3_ASSERT( x )
#define SHA3_TRACE( format, ... )
#define SHA3_TRACE_BUF( format , buf , l )

#undef get16bits
#if ( defined( __GNUC__ ) && defined( __i386__ )) || defined( __WATCOMC__ ) \
    || defined( _MSC_VER ) || defined ( __BORLANDC__ ) || defined ( __TURBOC__ )
=======
=======
#define MAX_STR 256
>>>>>>> c1e4320 (athernet V0.9)

#define SHA3_ASSERT( x )
#define SHA3_TRACE( format, ... )
#define SHA3_TRACE_BUF( format , buf , l )

#undef get16bits
#if ( defined( __GNUC__ ) && defined( __i386__ )) || defined( __WATCOMC__ ) \
|| defined( _MSC_VER ) || defined ( __BORLANDC__ ) || defined ( __TURBOC__ )
>>>>>>> a415938 (kurls)
    #define get16bits( d ) ( * ( ( const uint16_t * ) ( d ) ) )
#endif
#if !defined ( get16bits )
    #define get16bits( d ) ( ( ( ( uint32_t ) ( ( ( const uint8_t * )( d ) )[1] ) ) << 8 )\
                       +( uint32_t ) ( ( ( const uint8_t * ) ( d ) )[0] ) )
#endif

<<<<<<< HEAD
<<<<<<< HEAD
#if defined(_MSC_VER)
    #define SHA3_CONST(x) x
#else
    #define SHA3_CONST(x) x##L
#endif

#ifndef SHA3_ROTL64
    #define SHA3_ROTL64(x, y) (((x) << (y)) | ((x) >> ((sizeof(uint64_t)*8) - (y))))
#endif

static sha3_context __sha3;

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
=======
#if defined( _MSC_VER )
    #define __sha3_const(x) x
=======
#if defined(_MSC_VER)
    #define SHA3_CONST(x) x
>>>>>>> c1e4320 (athernet V0.9)
#else
    #define SHA3_CONST(x) x##L
#endif

#ifndef SHA3_ROTL64
    #define SHA3_ROTL64(x, y) (((x) << (y)) | ((x) >> ((sizeof(uint64_t)*8) - (y))))
#endif

static sha3_context __sha3;

static const uint64_t keccakf_rndc[24] = {
<<<<<<< HEAD
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
>>>>>>> a415938 (kurls)
=======
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
>>>>>>> c1e4320 (athernet V0.9)
};

static const unsigned keccakf_rotc[24] = {
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
    18, 39, 61, 20, 44
};

static const unsigned keccakf_piln[24] = {
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
    14, 22, 9, 6, 1
};

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1e4320 (athernet V0.9)
enum SHA3_FLAGS {
    SHA3_FLAGS_NONE=0,
    SHA3_FLAGS_KECCAK=1
};

enum SHA3_FLAGS sha3_set_flags(void *priv, enum SHA3_FLAGS);
void sha3_update(void *priv, void const *bufIn, size_t len);
void const *sha3_finalize(void *priv);

<<<<<<< HEAD

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


#ifndef hash_to_string
void __htostr( char *hashstr , uint8_t *hash ) {
    #ifdef DEBUG
    printf( " hashstr :: %s\n " , hashstr );
    #endif
    for ( int _ = 0 ; _ < 32 ; _ ++ ) {
        char __[3];
        __btoh( hash[_] , __ );
        strncat( hashstr , __ , 3 );
    }
    #ifdef DEBUG
    printf( " hash :: %s\n" , hashstr );
    #endif
}
=======
=======
>>>>>>> c1e4320 (athernet V0.9)

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

void h_str_tl( char *buf , uint8_t *_i_hash , unsigned il ) {

    for ( int i=0; i < il ; i++ ) {
        char __[3];
        __btoh( _i_hash[i] , __ );
        strncat( buf , __ , 3 );
    }
}

#ifndef hash_to_string
void __htostr( char *hashstr , uint8_t *hash ) {
    #ifdef DEBUG
    printf( " hashstr :: %s\n " , hashstr );
    #endif
    for ( int _ = 0 ; _ < 32 ; _ ++ ) {
        char __[3];
        __btoh( hash[_] , __ );
        strncat( hashstr , __ , 3 );
    }
<<<<<<< HEAD
>>>>>>> a415938 (kurls)
=======
    #ifdef DEBUG
    printf( " hash :: %s\n" , hashstr );
    #endif
}
>>>>>>> c1e4320 (athernet V0.9)
#endif
#define hash_to_string __htostr

/**
 * @dev used to hash the input from
 * @param key       : `argv[1]`
 * 
 * and copy the result to a pre-allocated buffer
 * @param hashkey   : ( char[256] )
 */
#ifndef hbar_str
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1e4320 (athernet V0.9)
char *__s_hash( char *key , char *hashkey ) {
    #ifdef DEBUG
    printf( "-----BEGIN HASH DEBUG-----\n");
    printf( "key :: %s\n" , key );
    #endif
    int key_len = strlen( key );
    #ifdef DEBUG
    printf( "keylen :: %d\n" , key_len );
    #endif
    sha3_init256( &__sha3 );
    sha3_set_flags( &__sha3 , 1 );
    sha3_update( &__sha3 , key , key_len );
    uint8_t *__hash = ( uint8_t *) sha3_finalize( &__sha3 );
    __htostr( hashkey , __hash );
    #ifdef DEBUG
    printf( "hashkey : result : %s\n" , hashkey );
    printf( "-----END HASH DEBUG-----\n" );
    #endif
    return hashkey;
}
<<<<<<< HEAD
=======
    char *__s_hash( char *key , char *hashkey ) {
        #ifdef DEBUG
        printf( "-----BEGIN HASH DEBUG-----\n");
        printf( "key :: %s\n" , key );
        #endif
        int key_len = strlen( key );
        #ifdef DEBUG
        printf( "keylen :: %d\n" , key_len );
        #endif
        sha3_init256( &__sha3 );
        sha3_set_flags( &__sha3 , 1 );
        sha3_update( &__sha3 , key , key_len );
        uint8_t *__hash = ( uint8_t *) sha3_finalize( &__sha3 );
        __htostr( hashkey , __hash );
        #ifdef DEBUG
        printf( "hashkey : result : %s\n" , hashkey );
        printf( "-----END HASH DEBUG-----\n" );
        #endif
        return hashkey;
    }
>>>>>>> a415938 (kurls)
=======
>>>>>>> c1e4320 (athernet V0.9)
#endif
#define hbar_str __s_hash


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1e4320 (athernet V0.9)
uint32_t super_fast_hash ( char *data  , int len ) {
    uint32_t hash = len, tmp;
    int rem;
    if (len <= 0 || data == NULL) { return 0; }
    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }
<<<<<<< HEAD

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

/* Single-call hashing */
sha3_return_t sha3_hash_buffer( 
    unsigned bitSize,   /* 256, 384, 512 */
    enum SHA3_FLAGS flags, /* SHA3_FLAGS_NONE or SHA3_FLAGS_KECCAK */
    const void *in, unsigned inBytes, 
    void *out, unsigned outBytes );     /* up to bitSize/8; truncation OK */

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

    SHA3_TRACE_BUF("Hash: (first 32 bytes)", ctx->u.sb, 256 / 8);

    return (ctx->u.sb);
}

sha3_return_t sha3_hash_buffer( unsigned bit_size, enum SHA3_FLAGS flags, const void *in, unsigned in_bytes, void *out, unsigned out_bytes ) {
    
    sha3_return_t err;
    sha3_context c;

    err = sha3_init(&c, bit_size);
    if( err != SHA3_RETURN_OK )
        return err;
    if( sha3_set_flags(&c, flags) != flags ) {
        return SHA3_RETURN_BAD_PARAMS;
    }
    sha3_update(&c, in, in_bytes);
    const void *h = sha3_finalize(&c);

    if(out_bytes > bit_size/8)
        out_bytes = bit_size/8;
    memcpy( out , h , out_bytes );
    return SHA3_RETURN_OK;
}


char *hash_bar( char *hbar_in , unsigned level )  {

    char hbar_out[MAX_STR];
    memset( &hbar_out , 0 , sizeof( hbar_out ) );

    int _ilen = strlen( hbar_in );
    uint8_t *__hash;

    switch ( level ) {
        case 0: 
        	sprintf( hbar_out , "@%x" , super_fast_hash( hbar_in , _ilen ) ); 
        	break;
        case 1:
            sha3_init384( &__sha3 );
            sha3_set_flags( &__sha3 , 1 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
        case 2:
            sha3_init512( &__sha3 );
            sha3_set_flags( &__sha3 , 0 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
        case 3:
        default:
            sha3_init256( &__sha3 );
            sha3_set_flags( &__sha3 , 1 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
    }
    printf( "%s\n" , hbar_out );
    
    return strdup( hbar_out );
}
=======
/**
super fast hash : used in functions signature
 *
**/  
    sfh_t super_fast_hash ( char *data , int len ) {
        uint32_t hash = len, tmp;
        int rem;
        if (len <= 0 || data == NULL) { return 0; }
        rem = len & 3;
        len >>= 2;

        /* main */
        for (;len > 0; len--) {
            hash  += get16bits (data);
            tmp    = (get16bits (data+2) << 11) ^ hash;
            hash   = (hash << 16) ^ tmp;
            data  += 2*sizeof (uint16_t);
            hash  += hash >> 11;
        }

        /* handler */
        switch (rem) {
            case 3: hash += get16bits (data);
                    hash ^= hash << 16;
                    hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                    hash += hash >> 11;
                    break;
            case 2: hash += get16bits (data);
                    hash ^= hash << 11;
                    hash += hash >> 17;
                    break;
            case 1: hash += (signed char)*data;
                    hash ^= hash << 10;
                    hash += hash >> 1;
        }

        /* force out 127 bits*/
        hash ^= hash << 3;
        hash += hash >> 5;
        hash ^= hash << 4;
        hash += hash >> 17;
        hash ^= hash << 25;
        hash += hash >> 6;
=======
>>>>>>> c1e4320 (athernet V0.9)

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

/* Single-call hashing */
sha3_return_t sha3_hash_buffer( 
    unsigned bitSize,   /* 256, 384, 512 */
    enum SHA3_FLAGS flags, /* SHA3_FLAGS_NONE or SHA3_FLAGS_KECCAK */
    const void *in, unsigned inBytes, 
    void *out, unsigned outBytes );     /* up to bitSize/8; truncation OK */

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

    SHA3_TRACE_BUF("Hash: (first 32 bytes)", ctx->u.sb, 256 / 8);

    return (ctx->u.sb);
}

sha3_return_t sha3_hash_buffer( unsigned bit_size, enum SHA3_FLAGS flags, const void *in, unsigned in_bytes, void *out, unsigned out_bytes ) {
    
    sha3_return_t err;
    sha3_context c;

    err = sha3_init(&c, bit_size);
    if( err != SHA3_RETURN_OK )
        return err;
    if( sha3_set_flags(&c, flags) != flags ) {
        return SHA3_RETURN_BAD_PARAMS;
    }
    sha3_update(&c, in, in_bytes);
    const void *h = sha3_finalize(&c);

    if(out_bytes > bit_size/8)
        out_bytes = bit_size/8;
    memcpy( out , h , out_bytes );
    return SHA3_RETURN_OK;
}


char *hashof( unsigned level , void *tohash , size_t thsize ) {

    int hash_size = 0 , k_flag = 0 , hashstr_len = 4;

    switch ( level ) {
        case 0:
            hash_size = 256;
            break;
        case 1:
            hash_size = 384;
            hashstr_len = 8;
            break;
        case 2:
            hash_size = 512;
            hashstr_len = 16;
            break;
        case 3:
            k_flag = 1;
            hash_size = 256;
            hashstr_len = 32;
            break;
        default:
            return NULL;        
    }

    char __hsized[hash_size];
    memset( &__hsized , 0 , hash_size );
    uint8_t *__hptr;

    sha3_init( &__sha3 , hash_size );
    sha3_set_flags( &__sha3 , k_flag );
    sha3_update( &__sha3 , tohash , thsize );
    h_str_tl( __hsized , ( uint8_t * ) sha3_finalize( &__sha3 ) , hashstr_len );

    return strdup( __hsized );
}

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *fhash( unsigned level , char *filepath ) {
    struct stat __st;
    int __fd = open( filepath , O_RDONLY );
    char *fl_hash;

    #ifdef DEBUG
        printf( "attempting to open file :: %s :" , filepath );
        printf( "fd: %d\n" , __fd );
    #endif

    if ( fstat( __fd , &__st ) == -1 ) {
        printf( "cannot obtain file info\n" );
        return NULL;
    }

    unsigned long int __size = __st.st_size;
    fl_hash = malloc( __size );

    unsigned long int b_read = read( __fd , fl_hash , __size );
    #ifdef DEBUG
        printf( "file size :: %d\n" , __size );
        printf( "bytes read :: %d\n" , b_read );    
    #endif

<<<<<<< HEAD
        return hashof( level , fl_hash , b_read );
    }   
>>>>>>> a415938 (kurls)
=======
    return hashof( level , fl_hash , b_read );
}   
>>>>>>> c1e4320 (athernet V0.9)




