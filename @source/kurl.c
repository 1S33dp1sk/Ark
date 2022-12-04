/// what is my kurl ? \\\

#include "kurl/kurl.h"
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
	if ( argc < 3 ){
		printf( "usage :: lbb [key] [value]\n" );
		return 1;
	}
	init_lbb();


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
		






