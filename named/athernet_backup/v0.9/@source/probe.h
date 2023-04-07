#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void sha3_init256( void *priv );
void sha3_init384( void *priv );
void sha3_init512( void *priv );


int __sys_entry( char *__ );
int __path_entry( char *__ );
int __socket_entry( char *__ , int __v );
int __dns_entry( char *__ );
int __ather_entry( char *__ , char *_ );

#define __ather_outdir "@outa"
#define __ather_indir "@entries"
#define __ather_def "@"

#define emp ""


char *__path_unix( char *__path , char *__filename ) {
    int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
    if ( __path[path_len] != '/' ) {
        strncat( __path , "/\0" , 2 );
    }
    return ( path_len + fname_len ) < 4096 ? strcat( strdup( __path  ) , __filename ) : emp;
}

char *__file_extention( char *ename , char *extention ) {
    int _ = strlen( ename ) , __ = strlen( extention );
    return _ > 0 && __ > 0 ? strncat( strdup( ename ) , extention , __ ) : emp;
}


#ifndef getcwd
    int __ather_entry( char *__filename , char *__filedata ) {
        #undef MAX_PATH
        #define MAX_PATH 4096
        char __wd[MAX_PATH];
        int __fd = 0 , __flags = ( O_CREAT | O_RDWR ) , __mode = ( S_IRWXU | S_IRWXG | S_IRWXO );
        memset( &__wd , 0 , sizeof( __wd ) );
        if ( getcwd( *(&__wd) , sizeof( __wd ) ) != NULL ) {
            // __path_unix( __wd , __ather_indir );
            strcat( __wd , __filename );
            __fd = open( __wd , __flags , __mode );
            if ( write( __fd , __filedata , strlen( __filedata ) ) > 0 ) {
                return __fd;
            }
        }
        return 0;
    }
#endif


#ifndef stat
    static struct stat fifo_stat;
    int __sys_entry( char *__filename ) {
        #ifdef DEBUG
        printf( "@(sys entry)\n" );
        printf( "\tentry :: %s\n" , __filename );
        #endif
        if ( stat( __filename , &fifo_stat ) == 0 ) {
            return  __path_entry( __filename );
        }
        return 0;
    }
#endif


#ifndef access
    int __fd = 0 , __flags = ( R_OK | W_OK | X_OK );
    int __path_entry( char *__pathname ) {
        #ifdef DEBUG
        printf( "@(path entry)\n" );
        printf( "\tentry :: %s\n" , __pathname );
        #endif
    	if ( access( __pathname , __flags ) == 0 ) {
            __flags = O_RDONLY;
            __fd = open( __pathname , __flags );
            return __fd > 0 ? __fd : 0; 
        }
        return 0;
    }
#endif


#ifndef getaddrinfo
    #include <netdb.h>
    #ifndef PORT_ACCEPT
    	#define PORT_ACCEPT "9999"
    #endif
    int __socket_entry( char *__ipaddr , int ipv  ) {
    	int __listener , __rv , __g2g__ = 1;

    	struct addrinfo as_hints , *as_info , *temp;
    	memset( &as_hints , 0 , sizeof( as_hints ) );

    	if ( ( __rv = getaddrinfo( __ipaddr , PORT_ACCEPT , &as_hints , &as_info ) ) != 0 ) {
    		return 0;
    	}

    	for ( temp = as_info ; temp != NULL ; temp = temp -> ai_next ) {
    		__listener = socket( temp -> ai_family , temp -> ai_socktype , temp -> ai_protocol );
    		if ( __listener < 0 )
    			continue;
    		setsockopt( __listener , SOL_SOCKET , SO_REUSEADDR , &__g2g__ , sizeof( int ) );
    		if ( bind( __listener , temp -> ai_addr , temp -> ai_addrlen ) < 0 )
    			continue;
    		break;
    	}

    	freeaddrinfo( as_info );
    	return temp == NULL ? 0 : __listener;
    }
    int __dns_entry( char *__dnsname ) {

    }
#endif


/**
 * 
 * Thanks for the good work of people @brainhub.org for their implementation
 * on the `sha` hash mechanism.
 *
 */
#ifndef asha3
    /*
     * Works when compiled for either 32-bit or 64-bit targets, optimized for 
     * 64 bit.
     *
     * Canonical implementation of Init/Update/Finalize for SHA-3 byte input. 
     *
     * SHA3-256, SHA3-384, SHA-512 are implemented. SHA-224 can easily be added.
     *
     * Based on code from http://keccak.noekeon.org/ .
     *
     * I place the code that I wrote into public domain, free to use. 
     *
     *  Aug 2015. Andrey Jivsov. crypto@brainhub.org 
     *
     *  'Words' here refers to uint64_t 
     */
    #define asha3 sha3_init256( void *tohash );
    #include <stdint.h>
    
    #define SHA3_KECCAK_SPONGE_WORDS \
    ( ( ( 1600 ) / 8/*bits to byte*/) / sizeof( uint64_t ) )
    typedef struct sha3_context_ {
    uint64_t saved;             /* the portion of the input message that we
                                 * didn't consume yet */
    union {                     /* Keccak's state */
        uint64_t s[SHA3_KECCAK_SPONGE_WORDS];
        uint8_t sb[SHA3_KECCAK_SPONGE_WORDS * 8];
    } u;
    unsigned byteIndex;         /* 0..7--the next byte after the set one
                                 * (starts from 0; 0--none are buffered) */
    unsigned wordIndex;         /* 0..24--the next word to integrate input
                                 * (starts from 0) */
    unsigned capacityWords;     /* the double size of the hash output in
                                 * words (e.g. 16 for Keccak 512) */
    } sha3_context;

    enum SHA3_FLAGS {
        SHA3_FLAGS_NONE=0,
        SHA3_FLAGS_KECCAK=1
    };

    enum SHA3_RETURN {
        SHA3_RETURN_OK=0,
        SHA3_RETURN_BAD_PARAMS=1
    };
    typedef enum SHA3_RETURN sha3_return_t;

    /* For Init or Reset call these: */
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
    #define SHA3_ROTL64(x, y) \
        (((x) << (y)) | ((x) >> ((sizeof(uint64_t)*8) - (y))))
    #endif


    #ifndef byte_to_hex
        #define byte_to_hex byte_to_hex
    void byte_to_hex( uint8_t b , char s[3] ) {
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
    #ifndef to_hashstr
        #define to_hashstr to_hashstr
    void to_hashstr( char *hashstr , uint8_t *hash ) {
        for ( int _ = 0 ; _ < 32 ; _ ++ ) {
            char __[3];
            byte_to_hex( hash[_] , __ );
            strncat( hashstr , __ , 3 );
        }
        #ifdef DEBUG
        printf( "\n\t hash :: %s\n" , hashstr );
        #endif
    }
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

    void sha3_init256( void *priv ) {
        sha3_init( priv , 256 );
    }
    void sha3_init384( void *priv ) {
        sha3_init( priv , 384 );
    }
    void sha3_init512( void *priv ) {
        sha3_init( priv , 512 );
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
#endif

