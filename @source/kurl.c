<<<<<<< HEAD
/// what is my kurl ? \\\


#include "kurl/kurl.h"

extern kurl_t kurl; // each kurl has a different `stdptr` 
#define kurl_seed &kurl // each kurl has a unique seed
=======
>>>>>>> 39e3f43 (pre-merge)

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


<<<<<<< HEAD
int main( int argc , char **argv ) {


	kurl0();



	return 0;
}
=======

#if defined( __hat__ ) 
void main( int argc , char const *argv[] ) {
	__kurl__( &argv[0] );
}
#else
#include "kurl/kurl.h"
extern kurl_t kurl; // each kurl has a different `stdptr` 
#define __kurl_seed &kurl // each kurl has a unique seed
void main( int argc , char const argv[] ) {
	printf("(*cool very cool )\n");
}
#endif
>>>>>>> 39e3f43 (pre-merge)
