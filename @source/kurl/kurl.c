/// what is my kurl ? \\\

/**
usage ::

	a.	kurl [path] (level) 
		e.g:: kurl /home/kj/athernet 2

	b.	@[point_name] 
		e.g:: athernet@KARAM

	c.	[u_reference] || #reference 
		e.g:: 2x194102491959120
			note:: since most shells needs an escape char for `#` i.e :: `\#`
				kurls support direct level calls :: `0x` , `1x` , `2x` , ... 
**/
#include "kurl.h"

<<<<<<< HEAD
extern void __kurl__( const char **cmd_args );


#if defined( __hat__ ) 
<<<<<<< HEAD
void main( int argc , char const *argv[] ) {
	__kurl__( &argv[0] );
}
#else
#include "kurl/kurl.h"
extern kurl_t kurl; // each kurl has a different `stdptr` 
#define __kurl_seed &kurl // each kurl has a unique seed
void main( int argc , char const argv[] ) {
	printf("(*cool very cool )\n");
=======
int main( int argc , char const *argv[] ) {
	__kurl__( &argv[1] );
	return 0;
=======
void lbb_test() {
<<<<<<< HEAD
	printf( "book ref :: %x\n" , lbb );
>>>>>>> cbd7b5e (flight merge)
}

<<<<<<< HEAD
>>>>>>> 1482af4 (ATHERNET v06)
=======
int main( int argc ) {
=======

	printf( "book ref :: %p\n" , lbb );
}

int main( int argc , char **argv ) {
>>>>>>> fca5524 (ATHERNET v16)
	if ( argc == 1 ) {
		#define ik 8
	}
    #include "__k.h"
	ulong lbb_inn = p0;
	printf( "lbb inodenum :: %ld\n" , lbb_inn );
	char *lbb_ref = att;
	printf( "lbb current ref :: %s\n" , lbb_ref );
	char *lbb_key = hat;
	printf( "lbb current key :: %s\n" , lbb_key );
	char *lbb_des = pat;
	printf( "lbb current point :: %s\n" , lbb_des );
	int ap_lbb = p1;
<<<<<<< HEAD
	printf( "ather point reader :: %ld\n" , ap_lbb );
>>>>>>> cbd7b5e (flight merge)
=======
	printf( "ather point reader :: %d\n" , ap_lbb );
>>>>>>> fca5524 (ATHERNET v16)
}
























