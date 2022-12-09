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
