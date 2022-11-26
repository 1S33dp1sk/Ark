/// what is my kurl ? \\\

/**
 * for any kurl to be anything useful
 * it needs to/must be in the ather. 
 * 
 * as an example to kurl *{a,any} net point 
 * there must be a running athernet instance.
 * 
 */
#include "hbar/hbar.h"
#include <stdio.h>
//	usage :: 
//		kurl [os/dependent/path] (level) 
//		: example :
//			kurl /home/kj/athernet 2
//
//					or
//
//		@[point_name] 
//		: example :
//			@KARAM/athernet
//		
//					or
//
//		[u_reference]
//		#reference 
//		: example :
//			2x194102491959120
//		**note :: since most shells needs an escape char for `#` i.e :: `\#`
//					kurls support direct level calls
//									or
//					kurls are supported directly with the level 
//					i.e :: `0x` , `1x` , `2x` , ... 
//
//



int initial_kurl();		


int main( int argc , char **argv ) {

	if ( argc == 0 ) {

		return initial_kurl();
	}

	switch ( sfh( &argv[0][0] ) ) {
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

	printf( "returning 0\n" );
	return 0;
}




int initial_kurl() {
	return 0;
}



