/// what is my kurl ? \\\
#define DEBUG

#ifndef kurl

/**
overview&def ::
 * for any kurl to be anything useful
 * it needs to/must be in the ather. 
 * 
 * as an example to kurl *{a,} net point 
 * there must be a running athernet instance.
 * 
**/
    #define __kurl_name "k_u_r_l"

/**
the kurl version
 * 
 * the starting point of any kurl is always the version
 * 
**/
    #define __kurl_version 0x3

/**
dependencies from probe
**/
    #include "../probe.h"
    #include "__k.h"

/**
k&urls ::
 * As a concept the k in kurl essentially provides a methodical way
 * of interacting with athernet. To simplify the routine we
 * can quantitify the kurl into 4 main parts { K , U , R , L }
**/
        // #define stdptr void*
        // typedef stdptr kurl_t;

/**
starting with the ( K ) we can state ::
 * should be identified by a single character
 * in the following order ( k , @ , # , 0 , 1 , 2 , 3 )
 * where k indicates *num > 3
**/
    enum __k_types {
    	__swi_k = 0x4ea585c0 , // 'k'
    	__swi_at = 0x973fc315 , // '@'
    	__swi_hsh = 0x477c7b61 , // '#'
    	__swi_num 				  // 'n'
    }; 
    #define ktype enum __k_types;
    #define __size_k sizeof( unsigned char ) // the size

/**
secondly, we can specifiy the ( U ) 
 *
**/
    enum __u_types {
    	_u_lbb = 0x0 , 
    	_u_prg = 0x1 , 
    	_u_net = 0x2 , 
    	_u_pub = 0x3 
    };
    #define utype enum __u_types ;
    #define __size_u sizeof( void * )

/**
last but not least the ( R )
 *
**/
    enum __r_types {
    	_lbb_file = 0xF , 
                // LBB **file**
    	 _lbb_fifo = 0x0 , 
                // FIFO **write**
    	_lbb_sok = 0x1 , 
                // socket
        _lbb_bci = 0x2 , 
                // client
    };
    #define rtype enum __r_types;
    #define __size_r sizeof( unsigned long ) // the descriptor

/**
finally, the ( L )
 * very difficult to know
 * if the current buffer @hat is 
 * is the actual content or the hash
**/
    struct h_at {
    	unsigned long __len;
    	void *__hat;
    };
    #define __size_h_at sizeof( struct h_at )
    struct addr_st {
    	unsigned char __level; // k-value 
    	char *__addr; // starting * address
    };
    #define __size_addr_st sizeof( struct addr_st )
    struct __l {
    	struct h_at lhat; // left hash token
    	struct addr_st laddr; // left address 
    	long lsize; // left size
    };
    #define __size_l sizeof( struct __l )

/**
_urls && levels
 *
**/ 
    enum __kurl_levels {
        __mach = 0 ,
        __local = 1 ,
        __inet = 2 ,
        __chain = 3
    };
    #define levels enum __kurl_levels;

    struct __url {
        void *url;
        size_t __size;
        unsigned __offset; 
    };
    #define kurl_st struct __url;

/**
switching mechanism ::
 * select based on the super fast hash
 * of the first character in the passed char* as
 * args :: { k , @ , # , 0 , 1 , 2 , 3 , ... }
**/

/**
kurling ::
 *
**/
    extern void __kurl__( char const **__args ) {
        char __level = **__args;
        printf( "level :: %c\n" , __level );
        switch ( sc_sfh( *__args ) ) { \
            case 0x4ea585c0: \
                level  = ( unsigned long )  'k';\
                break; \
            case 0x477c7b61: \
                level = ( unsigned long )  '#';\
                break; \
            case 0x8288d321: \
                level = ( unsigned long ) 2;\
                break; \
            case 0x973fc315: \
                level = ( unsigned long )  '@';\
                break; \
            case 0x9d07d8da: \
                level = ( unsigned long ) 3;\
                break; \
            case 0xea1b9f56: \
                level = ( unsigned long ) 1; \
                break; \
            case 0xf2475372: \
                level = ( unsigned long ) 0; \
            default : \
                level = ( unsigned long ) '!';
                break; \
        }
    }

    extern int kurl_i( void * );
    extern int kurl_ii( void * );
    extern int kurl_iii( void * );
    extern int kurl_iv( void * );
    extern int kurl( void * );

#endif


