/**
 * 
 * the athernet
 * 
 */
#include "probe.h"
#include "hbar/hbar.h"
#include "point/point.h"
#include "lbb/lbb.h"
#include "nai/nai.h"
/**
 * < main > = 
 *	athernet 
 * 
 * < level > = 
 * 	athernet 0	|	unix	|	homenet
 * 	athernet 1	| 	local	|	intranet
 * 	athernet 2	| 	global	|	internet
 * 	athernet 3	| 	block	|	chainnet
 *
 * 
 */
// to be able to easily identify
// the origin we calculate the
// request net by defining a 
// level_to - level_from 

#define __net_kurl	0x00000000
#define inc_p_kurl	0x00000001
#define inc_n_kurl	0x10000001
#define __nmin_kurl	0x10000000
#define __pmax_kurl	0x0fffffff


static long genesis_kurl = __net_kurl;
int __kurl(){
	do { genesis_kurl|=0xf; genesis_kurl>>1; genesis_kurl|=0x1; } while( 0 );
}


/**
 * athernet always needs two components to
 * be able to function properly.
 * 1.   ather point
 * 2.   little black book
*/

#define DEBUG

void wdebug() {
	#ifdef DEBUG
		printf( "(DEBUG)	kurl :: k = %016lx\n" , genesis_kurl );
	#endif
}

int main( int argc , char **argv ) {

	
	unsigned __c = 0;

	ap __atherpoint; 
	lbb __pointlbb;

	wdebug();
	genesis_kurl = __kurl()&lbb_exists() \
		== __net_kurl ? __kurl()&lbb_load( __pointlbb ) : __kurl()&lbb_make( __pointlbb );		
	wdebug();
	
	genesis_kurl = genesis_kurl <= __pmax_kurl ? 0 : 1 ;
	wdebug();


	









}