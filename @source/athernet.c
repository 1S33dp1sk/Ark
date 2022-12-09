/// athernet \\\

/**
athernet points can be specified using ::
 *  1.  net point       // static point_si __ap;
 *  2.  address book    // static lbb_si __lbb; 
 *
**/


#ifndef __kurl_version
    #include "anet.h"
#endif

#include <stdio.h>

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
int main( int argc , char **argv ) {

<<<<<<< HEAD
	
	unsigned __c = 0;

	ap __atherpoint; 
	lbb __pointlbb;

	wdebug();
	genesis_kurl = __kurl()&lbb_exists() \
		== __net_kurl ? __kurl()&lbb_load( __pointlbb ) : __kurl()&lbb_make( __pointlbb );		
	wdebug();
=======
	a.	athernet (level|alias)
		e.g:: athernet
			: athernet 2
			: athernet chainnet
			: athernet unix
**/
int main( int argc , char **argv ) {
<<<<<<< HEAD
>>>>>>> c94b96b (started documentation with proper formatting as follows)
=======

	little_black_book( "" , __lbb );
	lbb_append( &__lbb , "0ai" , "2" );
>>>>>>> a5fe3ac (combining progress)
	
=======

>>>>>>> 3e18750 (sub-merge of nets)
	
=======
	unsigned long __gen = 0;
	kurl0( &__gen );
>>>>>>> b5baa17 (broke everything)
=======

>>>>>>> bfde0aa (started anet.h)
=======
    printf( "hashof :: %s : %x\n" , argv[1], sfh( argv[1] ) );
>>>>>>> c0f8193 (started the_*kurl)

}
=======
#ifdef __lbb__h
int main( int argc , char const **argv ) {
    printf( "\n" , level );
    lbb_entry( argv[1] );
}
#else
int main() {
    printf( "no lbb header found\n" );
}
#endif
>>>>>>> 5c2d5f4 (alignments)
