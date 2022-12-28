


#include "anet.h"



int main( int argc , char const *argv[] ) {

	void *ulbb , *point;

	ulbb = seed();

	printf( "ulbb : %x :: %ld = %p :: %s \n" , &ulbb , sizeof( &ulbb ) , ulbb , ulbb );



    return 0;
}
