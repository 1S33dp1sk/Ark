#include <stdio.h>
#include <string.h>
#include "pipes.h"
#define MAX_PNAME 256


static char __point_name[MAX_PNAME]; 


// @point 
int main( int argc , char **argv , char **kvargs ) {
	if ( argc < 2 ) {
		printf("usage :: @point [atherpoint] [0|1|2|3]\n");
		return 1;
	}

	char lvl = argv[2][0];
	int __lvl = lvl - '0';



	printf( "level is :: %d\n" , __lvl );
	
}