#include <stdio.h>
#include "path.h"



int main( int argc, char const *argv[] ) {
	Ather ather = {0};
	ather.__name__ = (char *)argv[0];
	ather__path( &ather );
	return 0;
}