<<<<<<< HEAD
<<<<<<< HEAD
#ifndef nai
	#define nai atherinterface // native ather interface
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)

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

#define s_global "0.0.0.0"
<<<<<<< HEAD
=======
	
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)
// supported natives < 0 , 1 , 2 , 3 >
#define nai_max 3
// mount path must be less than 512 bytes
#define mpath_max 512
// socket address max is ipv6 which is 16 bytes
#define saddr_max 16
// {sub,named,toplevel} domain must be less than 128 bytes each
#define dstr_max 128
// blockchain address is 256 bytes max
#define baddr_max 256
// blockchain identitfer must be 3 characters
#define bid_max 3

/**
 * since `__nai` is a union we will use a concept called 
 * 	common initial sequence ( cis ) for the structs a_i*
 * 
 * any struct element is prepended with `__` if the element
 * accessed is a *cis*
 */

struct a_inmp {
	long inn; // node number
	char imp[mpath_max]; // mount path
};

struct a_isok {
	long __inn; // cis
	char __imp[mpath_max]; //cis

<<<<<<< HEAD
<<<<<<< HEAD
	unsigned isv; // socket value
	// struct sockaddr_storage isa;
=======
	unsigned isv; // socket version
	char isa[saddr_max]; // socket address
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
	unsigned isv; // socket value
	// struct sockaddr_storage isa;
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)
	int isp; // socket port
};

struct a_idns {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	char __isa[saddr_max]; // cis
	int __isp; // cis

	char ids[dstr_max]; // sub domain
	char idn[dstr_max]; // domain name
	char idt[dstr_max]; // top level domain
};

struct a_ibna {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	char __isa[saddr_max]; // cis
	int __isp; // cis

	char __ids[dstr_max]; // cis
	char __idn[dstr_max]; // cis
	char __idt[dstr_max]; // cis

	char ibi[bid_max]; // blockchain identifier
	char iba[baddr_max]; // blockchain address ( public key )
};


union __nai {
	struct a_inmp n_uni; // universal ( unix )
	struct a_isok n_loc; // local
	struct a_idns n_glo; // global
	struct a_ibna n_blo; // blockchain
};

#define ani union __nai



int atherinterface( int level , ani __ );


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)
#endif


#ifndef log_nai
	void log_uni( struct a_inmp n_uni ) {
		printf( "native ather interface\n" );
		printf( "	universal	\n" );
		printf( "inode num::		%ju\n" , ( uintmax_t ) n_uni.inn );
		printf( "mount path::		%s\n" , n_uni.imp );
	}
<<<<<<< HEAD
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)
=======
/// nai ? \\\
by mrKJ
=======
#ifndef nai
>>>>>>> c1e4320 (athernet V0.9)

// #define DEBUG


/**
 * since `__nai` is a union we will use a concept called 
 * 	common initial sequence ( cis ) for the structs a_i*
 * 
 * any struct element is prepended with `__` if the element
 * accessed is a *cis*
 */

<<<<<<< HEAD
#ifndef nai
    #define __nai_name "native_ather_interface"

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
        typedef union __nai {
            struct a_inmp n_uni; 
                    // universal
            struct a_isok n_loc; 
                    // local
            struct a_idns n_glo; 
                    // network
            struct a_ibna n_blo; 
                    // blockchain
        } nai;

    /**
    `l-addr` :: a *level* based char pointer
     * depending on the current attached level
     **/
        char *native_address( int level );
            #ifdef __level
                static ( char * ) stdptr laddr;
            #endif

    /**
    returns ( indicator ) { fills struct `n_*interface` }
     *
    **/
        nai native_interface( int level );
            int uni_interface( struct a_inmp *n_uni );
            int loc_interface( struct a_isok *n_loc );
            int glo_interface( struct a_idns *n_glo );
            int blo_interface( struct a_ibna *n_blo );
>>>>>>> a415938 (kurls)
#endif
=======
#define __nai_name "nativeainterface"

struct a_inmp {
	long inn; // node number
	char imp[mpath_max]; // mount path
};

struct a_isok {
	long __inn; // cis
	char __imp[mpath_max]; //cis

	unsigned isv; // socket value
	struct sockaddr_storage isa;
	int isp; // socket port
};

struct a_idns {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	struct sockaddr_storage isa; // cis
	int __isp; // cis

	char ids[dstr_max]; // sub domain
	char idn[dstr_max]; // domain name
	char idt[dstr_max]; // top level domain
};

struct a_ibna {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	struct sockaddr_storage isa; // cis
	int __isp; // cis

	char __ids[dstr_max]; // cis
	char __idn[dstr_max]; // cis
	char __idt[dstr_max]; // cis

	char ibi[bid_max]; // blockchain identifier
	char iba[baddr_max]; // blockchain address ( public key )
};

typedef union __nai {
	struct a_inmp n_uni; // universal ( unix )
	struct a_isok n_loc; // local
	struct a_idns n_glo; // global
	struct a_ibna n_blo; // blockchain
} nai;


int uni_interface( struct a_inmp *n_uni );
int loc_interface( struct a_isok *n_loc );
int glo_interface( struct a_idns *n_glo );
int blo_interface( struct a_ibna *n_blo );

nai native_interface( int level );
char *native_address( int level );


#endif


>>>>>>> c1e4320 (athernet V0.9)
