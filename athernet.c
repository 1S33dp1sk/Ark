#include "anet.h"


/**
c ~> command
	[many executables]
		includes `cc` which creates more executables
h ~> number
	[digits]
		int, long, float, double { signed , unsigned }
b ~> binary
	[executable]
		can be run on a cpu
t ~> ternary
	[sxecutable]
		can be run on a gpu
y ~> yes
	[ok]
		1
s ~> socket
	[address]
		given name, internal
n ~> no
	[not ok]
		0
e ~> name
	[address]
		shareable name, known web lockation
d ~> data
	[string]
		ascii
**/


int main( int argc , char const *argv[] ) {
	if ( argc == 1 ) {
		return __check_att( *argv );
	}
	return lbb_entry(  &argv[1] , strlen( argv[1] ) );
}
