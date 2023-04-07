<<<<<<< HEAD
#ifndef nai
<<<<<<< HEAD
	#define nai atherinterface // native ather interface

#define DEBUG


#include <stdio.h>
#include <stdint.h>

#define sp_network htons( 9999 )
// can convert to network & host byte order
// via byte definition

#define s_local "127.0.0.1"
#define s_local2 "localhost"
#define s_local_alias s_local2

#define s_localv6 "::1"
#define s_local2v6 "0:0:0:0:0:0:0:1"
=======
/// nai \\\
>>>>>>> anet_V9/athernet

// #define DEBUG

=======

// #define DEBUG


>>>>>>> in_vik/main
/**
 * nai is a union of structs to indicate which current
 * level is provided, since `__nai` is a union we will
 * use a concept called common initial sequence ( cis )
 * for the structs a_i*, 
 * 
cis :: prepend : `__`
 * 
 */

<<<<<<< HEAD
<<<<<<< HEAD
=======
#define __nai_name "nativeainterface"

>>>>>>> in_vik/main
struct a_inmp {
	long inn; // node number
	char imp[mpath_max]; // mount path
};

struct a_isok {
	long __inn; // cis
	char __imp[mpath_max]; //cis

	unsigned isv; // socket value
<<<<<<< HEAD
	// struct sockaddr_storage isa;
=======
	struct sockaddr_storage isa;
>>>>>>> in_vik/main
	int isp; // socket port
};

struct a_idns {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
<<<<<<< HEAD
	char __isa[saddr_max]; // cis
=======
	struct sockaddr_storage isa; // cis
>>>>>>> in_vik/main
	int __isp; // cis

	char ids[dstr_max]; // sub domain
	char idn[dstr_max]; // domain name
	char idt[dstr_max]; // top level domain
};

struct a_ibna {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
<<<<<<< HEAD
	char __isa[saddr_max]; // cis
=======
	struct sockaddr_storage isa; // cis
>>>>>>> in_vik/main
	int __isp; // cis

	char __ids[dstr_max]; // cis
	char __idn[dstr_max]; // cis
	char __idt[dstr_max]; // cis

	char ibi[bid_max]; // blockchain identifier
	char iba[baddr_max]; // blockchain address ( public key )
};

<<<<<<< HEAD

union __nai {
=======
typedef union __nai {
>>>>>>> in_vik/main
	struct a_inmp n_uni; // universal ( unix )
	struct a_isok n_loc; // local
	struct a_idns n_glo; // global
	struct a_ibna n_blo; // blockchain
<<<<<<< HEAD
};

#define ani union __nai



int atherinterface( int level , ani __ );
=======
} nai;


int uni_interface( struct a_inmp *n_uni );
int loc_interface( struct a_isok *n_loc );
int glo_interface( struct a_idns *n_glo );
int blo_interface( struct a_ibna *n_blo );

nai native_interface( int level );
char *native_address( int level );
>>>>>>> in_vik/main


#endif


<<<<<<< HEAD
#ifndef log_nai
	void log_uni( struct a_inmp n_uni ) {
		printf( "native ather interface\n" );
		printf( "	universal	\n" );
		printf( "inode num::		%ju\n" , ( uintmax_t ) n_uni.inn );
		printf( "mount path::		%s\n" , n_uni.imp );
	}
#endif
=======
>>>>>>> in_vik/main
=======
#ifndef nai
    #define __nai_name "native_ather_interface"
    #include "../probe.h"
    /**
    iterable( node & mount path )
    `a_inmp` :: struct i-nodenum,mountpath
    **/  
        struct a_inmp {
            long inn; 
                    // node number
            char imp[max_path]; 
                    // mount path
        };
    /**
    iterable( soket ) :: k_types : iterable
    **/
        struct a_isok {
            long __inn; 
                    // cis
            char __imp[max_path]; 
                    // cis

            unsigned isv; 
                    // socket value
            struct sockaddr_storage isa;
                    // binded socket address
            int isp;
                    // socket port
            };
    /**
    iterable( dynamic naming system )
    `a_idns` :: struct domain name system
    **/
        struct a_idns {
            long __inn; 
                    // cis
            char __imp[max_path]; 
                    // cis

            unsigned __isv; 
                    // cis
            struct sockaddr_storage isa; 
                    // cis
            int __isp; 
                    // cis

            char ids[max_str]; 
                    // sub domain
            char idn[max_str]; 
                    // domain name
            char idt[max_str]; 
                    // top level domain
        };
    /**
    iterable( blockchain native address )
     *
     * for any great blockchain to be acceptable
     * it must do a task to register said blocks
     * 
     **the task could be simple or complex.
     **as long as it's one particular task
     **or a sequence of tasks. changable or not
     * depening on the configuration params.
     *
    `a_ibna` :: struct blockchain native address
    **/
        struct a_ibna {
            long __inn; 
                    // cis
            char __imp[max_path]; 
                    // cis

            unsigned __isv; 
                    // cis
            struct sockaddr_storage isa; 
                    // cis
            int __isp; 
                    // cis

            char __ids[max_str];
                     // cis
            char __idn[max_str];
                     // cis
            char __idt[max_str];
                     // cis

            char ibi[max_str]; 
                    // blockchain identifier
            char iba[max_str];
                    // blockchain address ( public key )
        };
    /**
    `__nai` :: union that defines different interfaces
     * for the different levels & { 0...3 } web types
    **/
        union __nai {
            struct a_inmp __mach; 
                    // machine
            struct a_isok __loch; 
                    // local
            struct a_idns __gloh; 
                    // global
            struct a_ibna __unih; 
                    // universal
        };
        #define nai union __nai
    /**
    `l-addr` :: a *level* based char pointer
     * depending on the current attached level
     **/
        char const *native_address( int level );
            #ifdef __level
                static ( char * ) stdptr laddr;
            #endif
    /**
    returns ( indicator ) { fills struct `n_*interface` }
     *
    **/
        nai native_interface( int level );
            int mac_interface( struct a_inmp n_mach );
            int loc_interface( struct a_isok n_loch );
            int glo_interface( struct a_idns n_gloh );
            int uni_interface( struct a_ibna n_unih );
    static nai net_interface;
#endif
>>>>>>> anet_V9/athernet
