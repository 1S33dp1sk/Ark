#include "probe.h"
#include "point/point.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"
=======

>>>>>>> 757e790 (shared library for point)
=======
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)


int main( int argc , char **argv ) {

<<<<<<< HEAD
<<<<<<< HEAD
	union __nai __;

	int res = nai( argv[1][0] - '0' , __ );
=======
	unsigned lvl = 0;

	atherpoint( emp , lvl );



>>>>>>> 757e790 (shared library for point)
=======
	union __nai __;

<<<<<<< HEAD
	int res = nai( 0 , __ );
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
	int res = nai( argv[1][0] - '0' , __ );
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)

}