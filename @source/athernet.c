/// what is my kurl ? \\\



/**
athernet points can be specified using ::
 *  1.  net point       // static point_si __ap;
 *  2.  address book    // static lbb_si __lbb; 
 *
**/

#ifndef __kurl_version
    #include "anet.h"
#endif

#define xxxx 1
#include <stdio.h>
#ifdef xxxx
void *lbb_entry( char const*_ );
int main( int argc , char const **argv ) {
    printf( "level :: %ld\n" , level );
    return 0;
}
#else
char *__word( char *k , char *v , char *d );
int lbb_add_line( char *line );
int little_black_book();
int lbb_add_hallmark();
int main() {
    little_black_book();
    // lbb_add_hallmark();
    // char *x = __word( "kurlv." , "9" , ":" );
    // int lbb_x = lbb_add_line( x );
    // printf( "string is :: %s\n" , x );
}
#endif
