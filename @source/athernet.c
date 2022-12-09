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


#ifdef xxxx
void *lbb_entry( char const*_ );
int main( int argc , char const **argv ) {
    printf( "%ld\n" , level );
    lbb_entry( argv[1] );
}
#else
char *__line( char *k , char *v , char *d );

int main() {
    char *x = __line( "kurlv." , "9" , ":" );
    printf( "string is :: %s\n" , x );
    printf( "no lbb header found\n" );
}
#endif
