#include "entry.h"





int main(int argc , char **argv) {

	eptr entry_ptr;

	struct _e_header eh;
	memset( &eh , 0 , sizeof( eh ) );

	eh._level = 2;
	eh.requ = argv;

	entry_ptr = encode_header( eh );


}