#ifndef hbar
    #define hbar hashof

#include <stdint.h>
#include <string.h>

/**
 * 
 * Thanks for the all the contributions and good work from 
 * the keccak team http://keccak.noekeon.org/
 * and brainhub team crypto@brainhub.org 
 * for their combined efforts on the implementation of the `sha-3` hash.
 *
 */
#define SHA3_KECCAK_SPONGE_WORDS \
    ( ( ( 1600 ) / 8/*bits to byte*/) / sizeof( uint64_t ) )

// flag is used to configure "pure" Keccak, as opposed to NIST SHA3.
#define SHA3_USE_KECCAK_FLAG 0x80000000
#define SHA3_CW( x ) ( ( x ) & ( ~SHA3_USE_KECCAK_FLAG ) )


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


enum SHA3_RETURN {
    SHA3_RETURN_OK=0,
    SHA3_RETURN_BAD_PARAMS=1
};

typedef enum SHA3_RETURN sha3_return_t;

/* For Init or Reset call these: */
sha3_return_t sha3_init( void *priv , unsigned bit_size );
uint32_t super_fast_hash( char *data , int len );
void byte_to_hex( uint8_t _ , char _s[3] );
void hash_to_string( char *_hstr , uint8_t _ );
char *hashof( unsigned level , void *tohash , size_t thsize );
char *fhash( unsigned level , char *filepath );



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
