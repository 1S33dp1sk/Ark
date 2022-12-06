/// athernet \\\

/**
athernet points can be specified using ::
 *  1.  net point       // static point_si __ap;
 *  2.  address book    // static lbb_si __lbb; 
 *
**/


#include "hbar/hbar.h"

int main( int argc , char **argv ) {


    printf( "hashof :: %s : %x\n" , argv[1], sfh( argv[1] ) );

}