// the zero kurl

#define kurl0 _kurl_0
#define __kurl_level 0
#define __kurl_hat 0





#include "../anet.h"
#if !defined( __lbb_name )
#include "../lbb/lbb.h"
#endif

#if !defined( __ap_name )
#include "../point/point.h"
#endif
// access ( good || deny )
// 
#define DEBUG





int _kurl_0() {


	int __check_lbb = lbb_check();

	/**
	 *whilst checking the lbb
	 * following must occur
	 * 
	 * 2) NO LBB -> create lbb && ap engine (reciever)
	 * 1) LBB -> read lbb && ap writer
	 */

	switch ( __check_lbb ) {
		case 0x0:
			printf( "lbb&ap already initialized\n" );
			return 0;
		case 0x1:
			lbb_open();
			break;
		case 0x2:
			lbb_make();
			break;
	}


	printf( "result of check lbb :: %d\n" , __check_lbb );
	
}








