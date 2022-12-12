<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
/**
 * thinking that the ather is anything other than
 * ather is useless.
 */
>>>>>>> a95c3a4 (comments and usages for athernet, kurls & probe)
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


/**
 * < main > = 
 *	athernet 
 * 
 * < level > = 
 * 	athernet 0	|	unix	|	homenet
 * 	athernet 1	| 	local	|	intranet
 * 	athernet 2	| 	global	|	internet
 * 	athernet 3	| 	block	|	chainnet
 *
 * 
 */



int main( int argc , char **argv ) {

<<<<<<< HEAD
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
=======
/***
 * Mr. Karam.J :
 * 		However, as for ather, when talking about the interfacing provided
 * it is quite simple in a sense.
 * 0 -> ather
 * 1 -> operating sys(linux,macOS,Win{32,64},POSIX-complaint) or any other
 * 2 -> Apache or any other
 * 3 -> ethereum or any other
 * Any peer on 0xather is always aware and in total control of everything that is happening
 * to the system as a whole, however the ather is i-defined; user-defined.
 * Thus, @home is different:
 *  for each 
 * 	1.	person(unique phone,ethereum address,... for example)/ 
 * 	2.	each group of people(unique LAN)/ 
 * 	3.	each collection of groups(unique sub_net)
 * 	4.  each (global ip) 
 * 	5.  each protocol type  
 * @ protocol includes the different machine processes that are
 * being run, including a fantastic signature creating mechanism.
 * that combines any or all the above to form uniqueness which is coupled by a `c struct`
 * enable the protocol to call sockets, open/close files, interrupt processes, process scripts, run shells, etc...
 * 
 ***/ 


=======
>>>>>>> b78d224 (@)
#include "common.h"
#define INTRO__A "\n\tWelcome to ather ( a.k.a @-Protocol )\n"
#define SYMB__NN '@'
#define ENTER__NN "enter( » )nodename :: @"
#define SCAN__NN "%s"
static char __udef_nodename[MAX_STR];
#include "iota.h"
#include "lbb/little_black_book.h"
=======
=======
>>>>>>> e950094 (pre-merge)
#include "kurl/probe.h"
#include "point/point.h"
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"
<<<<<<< HEAD
>>>>>>> cf46ec7 (athernet v0)
=======
#include "probe.h"
>>>>>>> 4f65147 (initial athernet structure including kurling , probing & builder for simple first stage rollout)
=======
>>>>>>> e950094 (pre-merge)


int main( int argc , char **argv ) {

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e950094 (pre-merge)
	union __nai __;

	int res = nai( argv[1][0] - '0' , __ );

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> eb99d6a (0xather)
=======
}
>>>>>>> cf46ec7 (athernet v0)
=======
	void *x;
=======
>>>>>>> a95c3a4 (comments and usages for athernet, kurls & probe)


<<<<<<< HEAD
	printf( "value of builder :: %x\n" , __x );
}
>>>>>>> 4f65147 (initial athernet structure including kurling , probing & builder for simple first stage rollout)
=======
}
>>>>>>> a95c3a4 (comments and usages for athernet, kurls & probe)
=======
}
>>>>>>> e950094 (pre-merge)
