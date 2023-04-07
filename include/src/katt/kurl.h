/// what is my kurl ? \\\
#define DEBUG

#ifndef kurl
/// what is my kurl ? \\\
by mrkj

/**
 */
#include "hbar/hbar.h"
/**
 * the k-value should be identified by a single character
 * in the following order ( k , @ , # , 0 , 1 , 2 , 3 )
 * where k indicates *num > 3
 */
#include "point/point.h"
#include "lbb/lbb.h"


/**
 * atherpoints have kurls or are in a kurling
 * any particular kurl can be described using ::
 */
static ap __ap; // net point
static lbb __lbb; // address book
/**
 * The kurl
 * As a concept the kurl essentially provides a methodical way
 * of interacting with the athernet. To simplify the routine we
 * can quantitify the kurl into 4 main parts { K , U , R , L }
 * starting with the ( K ) we can state
 */
#define __k_size unsigned char // the size
enum __k_types {
    __swi_k = 0x4ea585c0 , // 'k'
    __swi_at = 0x973fc315 , // '@'
    __swi_hsh = 0x477c7b61 , // '#'
    __swi_num                 // 'n'
}; 
typedef enum __k_types ktype;
/**
 * secondly, we can specifiy the ( U ) 
 */
#define __u_size void *
enum __u_types {
    _u_lbb = 0x0 , 
    _u_prg = 0x1 , 
    _u_net = 0x2 , 
    _u_pub = 0x3 
};
typedef enum __u_types utype;
/**
 * last but not least the ( R )
 */
#define __r_size unsigned long // the descriptor
enum __r_types {
    _fd__lbb = 0xF , // LBB 
    _fd__seq = 0x0 , // FIFO
    _fd__sok = 0x1 , // socket
};
typedef enum __r_types rtype;
/**
 * finally, the ( L )
 * very difficult to know
 * if the current buffer @hat is 
 * is the actual content or the hash
 */
struct _h_hat {
    unsigned long __len;
    void *__hat;
};
struct _st_addr {
    unsigned char __level; // k-value 
    char *__addr; // starting * address
};
struct __l {
    struct _h_hat hat;
    struct _st_addr addr; // address 
    long size; // left size
};
#define __l_size struct __l

typedef struct _h_hat kurl_t;



/**
 * only with #..... is the type
 * executable/loadable, otherwise it is
 */
    


// switch ( sc_sfh( (char * )"22" ) ) { \
//      case 0x4ea585c0: \
//          printf( "in k\n" ); \
//          break; \
//      case 0x973fc315: \
//          printf( "in @\n" ); \
//          break; \
//      case 0x477c7b61: \
//          printf( "in #\n" ); \
//          break; \
//      case 0xf2475372: \
//          printf( "in 0\n" ); \
//          break; \
//      case 0xea1b9f56: \
//          printf( "in 1\n" ); \
//          break; \
//      case 0x8288d321: \
//          printf( "in 2\n" ); \
//          break; \
//      case 0x9d07d8da: \
//          printf( "in 3\n" ); \
//          break; \
//      default : \
//          printf( "defaulting.. @%s \n" , ( char * )&__lvl );\
//          break; \
//  }







#define DEBUG
/**
definition ::
 * for any kurl to be anything useful
 * it needs to/must be in the ather. 
 * 
 * as an example to kurl *{a,any} net point 
 * there must be a running athernet instance.
 * 
**/
#include "probe.h"
#include <stdio.h>
#include <stdlib.h>
/**
(k)url ::
 * 
 * the kurl always starts from the `kurl version`
 * 
**/
#define __kurl_version ( ( unsigned char ) 0x1 )

/**
switching mechanism ::
 * select based on the super fast hash
 * of the first character in the passed char* as
 * args :: { k , @ , # , 0 , 1 , 2 , 3 , ... }
**/
extern int lvl_switch( void *select_ ) {
    switch ( sc_sfh( select_ ) ) {
        case 0x4ea585c0: // k
            return 'k';
        case 0x973fc315: // @
            return '@';
        case 0x477c7b61: // #
            return '#';
        case 0xf2475372: // 0  
            return 0;
        case 0xea1b9f56: // 1
            return 1;
        case 0x8288d321: // 2
            return 2;
        case 0x9d07d8da: // 3
            return 3;
        default:
            printf( "returning -1\n" );
            return -1;
    }
    return 0;
}




/**
usage ::

    a.  kurl [path] (level) 
        e.g:: kurl /home/kj/athernet 2

    b.  @[point_name] 
        e.g:: @KARAM/athernet

    c.  [u_reference] || #reference 
        e.g:: 2x194102491959120
            note:: since most shells needs an escape char for `#` i.e :: `\#`
                kurls support direct level calls :: `0x` , `1x` , `2x` , ... 
**/
int kurl( int argc , char **argv ) {

    // lvl_switch( "@somevar" );

    return 0;
}




























































// #define __ik unsigned char // cfg
// #define __iu void * // exc
// #define __ir unsigned long // fd
// #define __il char * // hbar





// typedef struct k___ {
//  void *url;
//  size_t __size;
//  unsigned __offset; 
// }__kurl;
// #define stdptr malloc( level ) 
// #define __k( __ ) \
//  int qbc = 1 , __level = ( int ) __; \
//  __level <= 0 ? 4 : \
//  do { qbc *= 4; \
//      --__level; \
//  } while ( __level > 0 ) 
//  #define level __level
//  #define quatc qbc
//  #define poset ( (int) (quatc/4) )
// #define k_( qc ) \
//  __kurl __ = { \
//      .__size=qbc         ,\
//      .__offset=poset     ,\
//      .url=stdptr         ,\
//  }
        







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


