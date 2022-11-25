#include "probe.h"


int main( int argc , char **argv ) {

	void *x;

	int __x = builder( x );

	printf( "value of builder :: %x\n" , __x );
}