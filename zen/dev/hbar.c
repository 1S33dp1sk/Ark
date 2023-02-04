#include "hbar.h"

#define __sha3_assert( x )
#define __sha3_trace( fmt , ... )
#define __sha3_trace_buf( format , buf , l )
#define sha3_init256( priv ) sha3_init( priv , 256 )
#define sha3_init384( priv ) sha3_init( priv , 384 )
#define sha3_init512( priv ) sha3_init( priv , 512 )

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
|| defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
    #define get16bits(d) (*((const uint16_t *)(d)))
#endif
#if !defined (get16bits)
    #define get16bits(d) ((((uint32_t) (((const uint8_t *)(d))[1]))<<8)\
                        +(uint32_t) (((const uint8_t *) (d))[0]))
#endif

#if defined( _MSC_VER )
    #define __sha3_const(x) x
#else
    #define __sha3_const(x) x##L
#endif

#ifndef __sha3_rot_l_64
    #define __sha3_rot_l_64(x, y) (((x) << (y)) | ((x) >> ((__size_u64*8) - (y))))
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

#ifndef hash_to_lstr
    void h_str_tl( char *buf , uint8_t *_i_hash , unsigned il ) {
        for ( int i=0; i < il ; i++ ) {
            char __[3];
            __btoh( _i_hash[i] , __ );
            strncat( buf , __ , 3 );
        }
    }
#endif
#define hash_to_strl h_str_tl 

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
#endif
#define hbar_str __s_hash


/**
super fast hash : used in function signatures
 *
**/  
    sfh_t super_fast_hash ( char const*data , int len ) {
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

        return hash;
    }

/**
XOR into state for keccak
 * generally called after `__sha3_k_sponge_w - ctx` -> cap_words words 
 * are `XOR()` into the state `s` 
**/
    static void keccakf( uint64_t s[25] ) {
        int i, j, round;
        uint64_t t, bc[5];
    #define __sha3_keccak_rounds 24

        for( round = 0; round < __sha3_keccak_rounds; round++ ) {

            /* Theta */
            for( i = 0; i < 5; i++ )
                bc[i] = s[i] ^ s[i + 5] ^ s[i + 10] ^ s[i + 15] ^ s[i + 20];

            for( i = 0; i < 5; i++ ) {
                t = bc[( i + 4 ) % 5] ^ __sha3_rot_l_64( bc[( i + 1 ) % 5], 1 );
                for( j = 0; j < 25; j += 5 )
                    s[j + i] ^= t;
            }

            /* Rho Pi */
            t = s[1];
            for( i = 0; i < 24; i++ ) {
                j = keccakf_piln[i];
                bc[0] = s[j];
                s[j] = __sha3_rot_l_64( t, keccakf_rotc[i] );
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

/**
[initiate | reset] the sha3 context
**/
    sha3_return_t sha3_init( void *priv , unsigned bit_size ) {
        sha3_context *ctx = (sha3_context *) priv;
        if( bit_size != 256 && bit_size != 384 && bit_size != 512 ) {
            return __sha3_u_n;
        }
        memset( ctx , 0 , __size_sha3_context );
        ctx->cap_words = 2 * bit_size / ( 8 * __size_u64 );
        return __sha3_u_ok;
    }

/**
[set | unset] keccak flag
 *
**/
    sha3_config_t sha3_set_flags( void *priv , sha3_config_t flags ) {
        sha3_context *ctx = (sha3_context *) priv;
        flags &= __sha3_flag_keccak__;
        ctx->cap_words |= ( flags == __sha3_flag_none__ ? __sha3_flag_keccak__ : 0 );
        return flags;
    }

/**
hash the buffer in ctx
 *
**/
    void sha3_update( void *priv , void const *buf_inp , size_t len ) {
        sha3_context *ctx = ( sha3_context * ) priv;
                // cast to context from voidptr
        unsigned tail , old_tail = (8 - ctx->byte_idx) & 7;
                // reminder for word 0...7 
        size_t words , i;

        const uint8_t *buf = buf_inp;

        __sha3_trace_buf("called to update with:", buf, len);

        __sha3_assert( ctx-> byte_idx < 8 );
        __sha3_assert( ctx-> word_idx < sizeof( ctx-> u.s ) / sizeof( ctx-> u.s[0] ) );

        if( len < old_tail ) {        
            // have no complete word or haven't started the word yet 
            __sha3_trace( "because %d<%d, store it and return", ( unsigned ) len,
                    ( unsigned ) old_tail );
            // endian-independent
            while ( len-- )
                ctx-> saved |= (uint64_t) ( * ( buf++ ) ) << ( ( ctx-> byte_idx++ ) * 8);
            __sha3_assert(ctx->byte_idx < 8);
            return;
        }

        if( old_tail ) {
            // process a single word
            __sha3_trace("completing one word with %d bytes", ( unsigned ) old_tail );
            // endian-independent
            len -= old_tail;
            while ( old_tail-- )
                ctx->saved |= ( uint64_t ) ( *( buf++ ) ) << ( ( ctx->byte_idx++ ) * 8 );

            /* now ready to add saved to the sponge */
            ctx->u.s[ctx->word_idx] ^= ctx->saved;
            __sha3_assert(ctx->byte_idx == 8);
            ctx->byte_idx = 0;
            ctx->saved = 0;
            if( ++ctx->word_idx == ( __sha3_k_sponge_w - __sha3_cw( ctx->cap_words ) ) ) {
                keccakf( ctx->u.s );
                ctx->word_idx = 0;
            }
        }

        /* now work in full words directly from input */

        __sha3_assert( ctx->byte_idx == 0 );

        words = len / __size_u64;
        tail = len - words * __size_u64;

        __sha3_trace("have %d full words to process", ( unsigned ) words );

        for(i = 0; i < words; i++, buf += __size_u64) {
            const uint64_t t = (uint64_t) (buf[0]) |
                    ((uint64_t) (buf[1]) << 8 * 1) |
                    ((uint64_t) (buf[2]) << 8 * 2) |
                    ((uint64_t) (buf[3]) << 8 * 3) |
                    ((uint64_t) (buf[4]) << 8 * 4) |
                    ((uint64_t) (buf[5]) << 8 * 5) |
                    ((uint64_t) (buf[6]) << 8 * 6) |
                    ((uint64_t) (buf[7]) << 8 * 7);
    #if defined(__x86_64__ ) || defined(__i386__)
            __sha3_assert( memcmp( &t , buf, 8 ) == 0 );
    #endif
            ctx->u.s[ctx->word_idx] ^= t;
            if( ++ctx->word_idx == ( __sha3_k_sponge_w - __sha3_cw( ctx->cap_words ) ) ) {
                keccakf( ctx->u.s );
                ctx->word_idx = 0;
            }
        }

        __sha3_trace("have %d bytes left to process, save them", ( unsigned ) tail );

        /* finally, save the partial word */
        __sha3_assert( ctx->byte_idx == 0 && tail < 8 );
        while ( tail-- ) {
            __sha3_trace("Store byte %02x '%c'", *buf, *buf);
            ctx->saved |= ( uint64_t ) ( *( buf++ ) ) << ( ( ctx->byte_idx++ ) * 8 );
        }
        __sha3_assert( ctx->byte_idx < 8 );
        __sha3_trace( "Have saved=0x%016" PRIx64 " at the end", ctx->saved );
    }

/**
simply the `update()` with the padding.
 * The padding block is 0x01 || 0x00* || 0x80. First 0x01 and last 0x80 
 * bytes are always present, but they can be the same byte.
**/
    void const *sha3_finalize( void *priv ) {
        sha3_context *ctx = ( sha3_context * ) priv;

        __sha3_trace("called with %d bytes in the buffer", ctx->byte_idx);

        /* Append 2-bit suffix 01, per SHA-3 spec. Instead of 1 for padding we
         * use 1<<2 below. The 0x02 below corresponds to the suffix 01.
         * Overall, we feed 0, then 1, and finally 1 to start padding. Without
         * M || 01, we would simply use 1 to start padding. */

        uint64_t t;

        if( ctx->cap_words & __sha3_k_use_flag ) {
            /* Keccak version */
            t = ( uint64_t )( ( ( uint64_t ) 1 ) << ( ctx->byte_idx * 8 ) );
        }
        else {
            /* SHA3 version */
            t = ( uint64_t )( ( ( uint64_t )( 0x02 | ( 1 << 2 ) ) ) << ( ( ctx->byte_idx ) * 8 ) );
        }

        ctx->u.s[ctx->word_idx] ^= ctx->saved ^ t;

        ctx->u.s[__sha3_k_sponge_w - __sha3_cw( ctx-> cap_words ) - 1] ^=
                __sha3_const( 0x8000000000000000UL );
        
        keccakf( ctx->u.s );

        /* Return first bytes of the ctx->s. This conversion is not needed for
         * little-endian platforms e.g. wrap with #if !defined(__BYTE_ORDER__)
         * || !defined(__ORDER_LITTLE_ENDIAN__) || __BYTE_ORDER__!=__ORDER_LITTLE_ENDIAN__ 
         *    ... the conversion below ...
         * #endif */
        {
            unsigned i;
            for(i = 0; i < __sha3_k_sponge_w; i++) {
                const unsigned t1 = (uint32_t) ctx->u.s[i];
                const unsigned t2 = (uint32_t) ( ( ctx->u.s[i] >> 16 ) >> 16 );
                ctx->u.sb[i * 8 + 0] = (uint8_t) ( t1 ); 
                ctx->u.sb[i * 8 + 1] = (uint8_t) ( t1 >> 8 );
                ctx->u.sb[i * 8 + 2] = (uint8_t) ( t1 >> 16 );
                ctx->u.sb[i * 8 + 3] = (uint8_t) ( t1 >> 24 );
                ctx->u.sb[i * 8 + 4] = (uint8_t) ( t2 ); 
                ctx->u.sb[i * 8 + 5] = (uint8_t) ( t2 >> 8 );
                ctx->u.sb[i * 8 + 6] = (uint8_t) ( t2 >> 16 );
                ctx->u.sb[i * 8 + 7] = (uint8_t) ( t2 >> 24 );
            }
        }

        __sha3_trace_buf( "hash: (first 32 bytes)", ctx->u.sb , 256 / 8 );

        return ( ctx->u.sb );
    }

/**
atomic hashing 
 *
**/
    sha3_return_t sha3_hash_buffer( unsigned bit_size, sha3_config_t flags, const void *in, unsigned in_bytes, void *out, unsigned out_bytes ) {
        
        sha3_return_t err;
        sha3_context c;

        err = sha3_init( &c , bit_size );
        
        if( err != __sha3_u_ok ) {
            return err;
        }
        
        if( sha3_set_flags(&c, flags) != flags ) {
            return __sha3_u_n;
        }
        
        sha3_update( &c , in , in_bytes );
        const void *h = sha3_finalize( &c );

        if( out_bytes > bit_size/8 ){
            out_bytes = bit_size/8;
        }
        memcpy( out , h , out_bytes );

        return __sha3_u_ok;
    }














//hbar family
    // hash,fhash uint8_t const *
    // hashof,fhashof char const *
    // hasht,fhasht type
char const *zeroatt(uns level){
    switch(level){
    case 0: return "0x0000";
    case 1: return "0x00000000";
    case 2: return "0x0000000000000000";
    case 3: return "0x00000000000000000000000000000000";
    default: return "0";
    }
}
/**
hashof str based on level
 * extreme care for the values must be taken when using this function
 * specially `thsize` {a.k.a to_hash_size} 
 *  ONLY send size values that are `sizeof(tohash)<=` otherwise the hash
 * will be random and there will be no way to guarantee consistency.
 * 
 * this is by design, as we can generate randomness from this. 
 ***AFNAB**
**/ 
char const *hashof( uns level , void const *tohash , size_t thsize ) {

        #ifdef DEBUG
            char const *_strhash = ( char const * ) tohash;
            printf( "string to hash :: %s\n" , _strhash );
        #endif
        unsigned hash_size = 0 , k_flag = 0 , hashstr_len = 4;

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
// raw 
uint8_t const *hash( uns level , void const *tohash , size_t thsize ) {

        #ifdef DEBUG
            char const *_strhash = ( char const * ) tohash;
            printf( "string to hash :: %s\n" , _strhash );
        #endif
        unsigned hash_size = 0 , k_flag = 0 , hashstr_len = 4;

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
        return ( uint8_t * ) sha3_finalize( &__sha3 );
    }
/**
hashof-4
 * 
**/
uns hash4(uns level,void const *tohash,size_t thsize) {
    uint8_t const *__ = hash(level,tohash,thsize);
    uns res=0;
    for(int i=0;i<4;i++){
        res|=(uns)__[i]<<(i*8);
    }
    return res;
}
/**
hashof-8
 * 
**/
ulong hash8(uns level,void const *tohash,size_t thsize) {
    uint8_t const *__ = hash(level,tohash,thsize);
    ulong res=0;
    for(int i=0;i<8;i++){
        res|=(ulong)__[i]<<(i*8);
    }
    return res;
}

ulong hhash8(uns level,void const *tohash,size_t thsize) {
    uint8_t const *__ = hash(level,tohash,thsize);
    ulong res=0;
    for(int i=0;i<8;i++){
        res|=(ulong)__[i]<<(i*8);
    }
    return res;
}

/**
hashof-16
 *
**/
void *hash16(uns level, void const *tohash, size_t thsize){
    uint8_t const *__ = hash(level,tohash,thsize);
    memset(&u,0,sizeof(u));
    #ifdef DEBUG
        printf("hash16-u:%lu:%08x%08x-",sizeof(u),u[0],u[1]);
    #endif
    for(uns k=0;k<2;k++){
        ulong res=0;
        for(uns i=0;i<8;i++){
            res|=(ullng)__[i]<<(i*8);
        }
        u[k]=res;
    }
    return &u;
}


/**
file hash
 *
**/
char const *fhashof( uns level , char const *filepath ) {
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

        size_t __size = __st.st_size;
        fl_hash = malloc( __size );

        size_t b_read = read( __fd , fl_hash , __size );
        #ifdef DEBUG
            printf( "file size :: %d\n" , __size );
            printf( "bytes read :: %d\n" , b_read );    
        #endif

        close(__fd);

        return hashof( level , fl_hash , b_read );
}
/**
file-hash raw
 *
**/
uint8_t const *fhash(uns level,char const*filepath) {
    struct stat __st;
    int __fd = open( filepath , O_RDONLY );
    char *fl_hash;

    #ifdef DEBUG
        printf( "attempting to open file :: %s :" , filepath );
        printf( "fd: %d\n" , __fd );
    #endif

    if ( fstat( __fd , &__st ) == -1 ) {
        #ifdef DEBUG
            printf( "cannot obtain file info\n" );
        #endif
        return NULL;
    }

    size_t __size = __st.st_size;
    fl_hash = malloc( __size );

    size_t b_read = read( __fd , fl_hash , __size );
    #ifdef DEBUG
        printf( "file size :: %d\n" , __size );
        printf( "bytes read :: %d\n" , b_read );    
    #endif

    return hash( level , fl_hash , b_read );
}   
/**
file-hash4
 * 
**/
uns fhash4(uns level,char const *filepath) {
    uint8_t const *__ = fhash(level,filepath);
    if(__==NULL){return 0;}
    uns res=0;
    for(int i=0;i<4;i++){
        res|=(uns)__[i]<<(i*8);
    }
    return res;
}
/**
file-hash8
 * 
**/
ulong fhash8(uns level,char const*filepath) {
    uint8_t const *__ = fhash(level,filepath);
    if(__==NULL){return 0;}
    ulong res=0;
    for(int i=0;i<8;i++){
        res|=(ulong)__[i]<<(i*8);
    }
    return res;
}
/**
file-hash16
 *
 * 
 * 
**/
ullng fhash16(uns level, char const*filepath){
    uint8_t const *__=fhash(level,filepath);
    if(__==NULL){return 0;}
    ullng res=0;
    for(int i=0;i<16;i++){
        res|=(ullng)__[i]<<(i*8);
    }
    return res;
}


