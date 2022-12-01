/// what is my kurl ? \\\

/**
 * The kurl
 * 			by :: mrkj ( aka Karam Jaber ) 
 * 
 * As a concept the kurl essentially provides a methodical way
 * of interacting with the athernet. To simplify the routine we
 * can quantitify the kurl into 4 main parts { K , U , R , L }
 * starting with the ( K ) we can state
 */
#define __ksize unsigned char
#include "hbar/hbar.h"
enum selector_call {
	__swi_k = 0x4ea585c0 ,   
	__swi_at = 0x973fc315 , 
	__swi_hsh = 0x477c7b61 , 
	__swi_num 
};
typedef enum selector_call kselect;
/**
 * the k-value should be identified by a single character
 * in the following order ( k , @ , # , 0 , 1 , 2 , 3 )
 * where k indicates *num > 3
 */
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
int usage_switch( char select_ ) {

	switch ( sfh( &select_ ) ) {
		case 0x4ea585c0: // k
			break;
		case 0x973fc315: // @
			break;
		case 0x477c7b61: // #
			break;
		case 0xf2475372: // 0  
			break;
		case 0xea1b9f56: // 1
			break;
		case 0x8288d321: // 2
			break;
		case 0x9d07d8da: // 3
			break;
		default:
			printf( "returning -1\n" );
			return -1;
	}
	return 0;
}




/**
usage ::

	a.	kurl [path] (level) 
		e.g:: kurl /home/kj/athernet 2

	b.	@[point_name] 
		e.g:: @KARAM/athernet

	c.	[u_reference] || #reference 
		e.g:: 2x194102491959120
			note:: since most shells needs an escape char for `#` i.e :: `\#`
				kurls support direct level calls :: `0x` , `1x` , `2x` , ... 
**/
int main( int argc , char **argv ) {

	k_switch( "@somevar" );

	return 0;
}




























































// #define __ik unsigned char // cfg
// #define __iu void * // exc
// #define __ir unsigned long // fd
// #define __il char * // hbar





// typedef struct k___ {
// 	void *url;
// 	size_t __size;
// 	unsigned __offset; 
// }__kurl;
// #define stdptr malloc( level ) 
// #define __k( __ ) \
// 	int qbc = 1 , __level = ( int ) __; \
// 	__level <= 0 ? 4 : \
// 	do { qbc *= 4; \
// 		--__level; \
// 	} while ( __level > 0 ) 
// 	#define level __level
// 	#define quatc qbc
// 	#define poset ( (int) (quatc/4) )
// #define k_( qc ) \
// 	__kurl __ = { \
// 		.__size=qbc			,\
// 		.__offset=poset		,\
// 		.url=stdptr			,\
// 	}
		






