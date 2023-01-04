<<<<<<< HEAD
#include "aether.h"

/**
 * aether is a two choice and a next; system k = 3.
 * The current default value, defines the k which is essentially the base of the sys.
***
 * choice 1 :
 *      K
 * choice 2 :
 *      les
 * current : 
 *      .lbb
 * 
 * There's no need for security configurations as the system is isolated based on the 
 * context created by the serve then the request then the response.
 * with it's own user, sockets, listeners, repliers, etc... . 
 * 
 * There's two main componenets for the ather, one is to be viewed as a whole and that is the `0xather`
 * and the other is the fundemental componenet of the system and that is the atherpoint. An atherpoint
 * is a singular core, dynamically linked with other atherpoints. Given that they are NOT identical, they can
 * tether to one another. Each tether represents two different atherpoints and each link represents two different
 * tethers creating a TRI-STATE system.
 * 
 *                                      X_1 <-> A <-> X_2
 * 
 * 
 * 
 * The lbb keeps track of the default and changes. a differencing library essentially,
 * because neither 0xather nor the atherpoints care about state changes, the implementation is 100% dynamic.
 * 0xather is the name of the full interconnectivity of atherpoints
 * now the `0x`(ather) is essentially how we can differenciate between the different cores, so the basic
 * is at ( @her )  == home
 * is at ( ip.ather ) == local
 * is at ( ip6:ather ) == global
 * is at ( 0xather ) == universal
 * 
 * universal must be blockchain-based.
 * 
 * any type of atherfile a.k.a socket/server/les can relay lbb requests to the local socket.
 * the local socket decides on /K | .lbb\
 * 
 * the request is simple :
 *
 * key @ atherpoint {
 *      !#entry
 * }
 * 
 * the response is simplier :
 * 
 * response @ hash {
 *      LOG
 * }
 * 
 * 
 * entries can contain any executable, script, function, command, etc... .
 * an entry can be 
 * 
 *       #{ 
 *          !#
 *          #! 
 *       }
 * 
 * the aether is a system-wide user than can only execute in it's own directory. 
 * 
 * Nonetheless, the core technology here is adaptive, so execution is based on the wrapper which
 * is the ather in the amount of bit processing between the different atherpoints. @atherpoint is fully defined if the ::
 *      path/to/@||path\to\@ is defined
 *      192.168.*.*|10.0.1.0 is defined 
 *      6f:::*||6f0:000:201:3fa:102:a21 is defined
 *      eth201||btcd12a is defined
 *  
 * 
 * access differes based on defined iota's in the .lbb 
 * basically when accessing the .lbb, the main call is ( K , res )
 * res -> responsible for providing that context. only way for that to happen, is if K is viable.
 * 
 * However, as for ather, when talking about the interfacing provided
 * it is quite simple in a sense.
 * 0 -> ather
 * 1 -> operating sys(linux,macOS,Win{32,64},POSIX-complaint) or any other
 * 2 -> Apache or any other
 * 3 -> ethereum or any other
 * 
 * 
 * Any atherpoint on 0xather is always aware and in total control of everything that is happening
 * to the system as a whole ( in&out of the atherpoint ), however each point is i-defined; user-defined.
 * Thus, @home is different:
 *  for each 
 *  1.  person(unique phone,ethereum address,... for example)/ 
 *  2.  each group of people(unique LAN)/ 
 *  3.  each collection of groups(unique subnet)
 *  4.  each (global ip) 
 *  5.  each protocol type  
 * @ protocol includes the different machine processes that are
 * being run, including a fantastic signature creating mechanism.
 * that combines any or all the above to form uniqueness which is coupled by a `c struct`
 * enable the protocol to call sockets, open/close files, interrupt processes, process scripts, run shells, etc...
 * 
 */


int main(int argc, char *argv[]) {
    int __ = argc > 1 ? super_fast_hash( argv[1] , strlen( argv[1] ) ) : 0;

    switch( __ ) {
        case 0:
            break;
        case 0x9eefc5c9:
            mor( argc , argv );
            break;
        case 0x350647ed:
            les( argc , argv );
            break;
        default:
            break;
    }

    // les( argc , argv );
    // mor( argc , argv );
    return 0;
}




=======
#include "misc.h"
static sha3_context __sha3;
#include "lbb.h"


// the filesize for the lbb
// and the atype are global
// should be defined as a
// static or external var

int main( int argc , char **argv ) {

	if ( argc < 2 ) {
		printf("usage :: lbb (key/hash) [value]\n");
		return 2;
	}

	struct lbb _lbb = {0};
	nit_lbb( &_lbb , argv[1] , 0 );
	lbb_kv( &_lbb , "main" , "self" );
	lbb_kv_h( &_lbb , "main" , "self" );
	lbb_kv_hh( &_lbb , "main" , "self" );
	save_lbb( &_lbb );

	return 0;
}			
>>>>>>> eb99d6a (0xather)
