#include <stdio.h>
#include <string.h>
#include "pipes.h"
#define MAX_PNAME 256


static char __point_name[MAX_PNAME]; 


// @point 
int main( int argc , char **argv , char **kvargs ) {
	if ( argc < 2 ) {
		printf("usage :: @point [atherpoint]\n");
		return 1;
	}
	else {
		strcpy( __point_name , argv[1] );
		if ( strlen( __point_name ) > 3 ) {
			printf( "creating @%s\n", __point_name );
			char *temp[1] = { "nice wow\n" };
			return pipes( 2 , temp );
		}
		printf( "cannot create atherpoint :: @%s\n" , __point_name );
		return 1;
	}
}