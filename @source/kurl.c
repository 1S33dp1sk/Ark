/// what is my kurl ? \\\

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
#include "hbar/hbar.h"
#include "probe.h"
#include <stdio.h>





/**
(k)url ::
 * 
 * 
**/
#define __net_kurl	( ( long ) 0x0 )
#define inc_p_kurl	( ( long ) 0x0000000000000001 )
#define inc_n_kurl	( ( long ) 0x1000000000000001 )
#define __nmin_kurl	( ( long ) 0x1000000000000000 )
#define __pmax_kurl	( ( long ) 0x0fffffffffffffff )
static long genesis_kurl = __net_kurl;
int __kurl(){
	do { genesis_kurl|=0xf; genesis_kurl>>1; genesis_kurl|=0x1; } while( 0 );
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

	return 0;
}



/**
switching mechanism ::
 * select based on the super fast hash
 * of the first character in the passed
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



void wdebug() {
	#ifdef DEBUG
		printf( "(DEBUG)	kurl :: k = %016lx\n" , genesis_kurl );
	#endif
}

