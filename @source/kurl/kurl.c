/// what is my kurl ? \\\


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



#if defined( __hat__ ) 
int main( int argc , char const *argv[] ) {
	__kurl__( &argv[0] );
	return 0;
}
#else
#include "kurl.h"
// extern kurl_t kurl; // each kurl has a different `stdptr` 
// #define __kurl_seed &kurl // each kurl has a unique seed
int main( int argc , char const argv[] ) {
	printf("(*cool very cool )\n");
	return 0;
}
#endif
