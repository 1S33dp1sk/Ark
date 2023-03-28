/// what is my kurl ? \\\

#define DEBUG
/**
overview&def ::
 * for any kurl to be anything useful
 * it needs to/must be in the ather. 
 * 
 * as an example to kurl *{a,any} net point 
 * there must be a running athernet instance.
 * 
**/
#include "../probe.h"
#include <stdio.h>
#include <stdlib.h>

/**
the kurl
 * 
 * the kurl always starts from the `kurl version`
 * 
**/
#define __kurl_version ( ( unsigned char ) 0x1 )
/**
atherpoints' kurls 
 * any atherpoint either has kurls or are in a kurling
 * any specific kurl can be described using ::
 */
static point_si __ap; // net point
static lbb_si __lbb; // address book
/**
k&urls ::
 * As a concept the k in kurl essentially provides a methodical way
 * of interacting with the athernet. To simplify the routine we
 * can quantitify the kurl into 4 main parts { K , U , R , L }
 * starting with the ( K ) we can state
 */
#define __k_size unsigned char // the size
/**
the values 
 * should be identified by a single character
 * in the following order ( k , @ , # , 0 , 1 , 2 , 3 )
 * where k indicates *num > 3
 */
enum __k_types {
	__swi_k = 0x4ea585c0 , // 'k'
	__swi_at = 0x973fc315 , // '@'
	__swi_hsh = 0x477c7b61 , // '#'
	__swi_num 				  // 'n'
}; 
typedef enum __k_types ktype;
/**
secondly, we can specifiy the ( U ) 
 *
**/
#define __u_size void *
enum __u_types {
	_u_lbb = 0x0 , 
	_u_prg = 0x1 , 
	_u_net = 0x2 , 
	_u_pub = 0x3 
};
typedef enum __u_types utype;
/**
last but not least the ( R )
 *
**/
#define __r_size unsigned long // the descriptor
enum __r_types {
	_fd__lbb = 0xF , // LBB 
	_fd__seq = 0x0 , // FIFO
	_fd__sok = 0x1 , // socket
};
typedef enum __r_types rtype;
/**
finally, the ( L )
 * very difficult to know
 * if the current buffer @hat is 
 * is the actual content or the hash
**/
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
/**
 * only with #..... is the type
 * executable/loadable, otherwise it is
 */
typedef struct _h_hat kurl_t;
/**
switching mechanism ::
 * select based on the super fast hash
 * of the first character in the passed char* as
 * args :: { k , @ , # , 0 , 1 , 2 , 3 , ... }
**/
#define k_switch( kchr ) \
    char *_kselect = ( char * )&kchr; \
    switch ( sc_sfh( _kselect ) ) { \
        case 0x4ea585c0: \
            printf( "in k\n" ); \
            break; \
        case 0x973fc315: \
            printf( "in @\n" ); \
            break; \
        case 0x477c7b61: \
            printf( "in #\n" ); \
            break; \
        case 0xf2475372: \
            printf( "in 0\n" ); \
            break; \
        case 0xea1b9f56: \
            printf( "in 1\n" ); \
            break; \
        case 0x8288d321: \
            printf( "in 2\n" ); \
            break; \
        case 0x9d07d8da: \
            printf( "in 3\n" ); \
            break; \
        default : \
            printf( "defaulting.. @%s \n" , ( char * )&kchr );\
            break; \
    }
