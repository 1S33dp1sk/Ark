/// points \\\

#define __AP_NAME 1

#ifndef __APOINTS__H
	#include "utypes.h"
	#include <unistd.h>
	#include <stdio.h>
	#include <string.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	#define __APOINTS__H 1
#endif

/**
atherpoint `FIFO`s
 * by defintion FirstInFirstOut MUST have only a singular reader
 * 
 * 
 * writers can connect to the atherpoint syncronously 
 * and query real time updates on values, utilize operations
 * to create&|modify these values.
 * 
 * 
 *little black book
**/

#if __AP_NAME
	#if __APOINTS__H	
		#undef __AP_NAME
		#define __NAI_NAME "native_ather_interface"
	#elif  __ATHER_POINT__
		#error "point is named without a header"
	#endif

	#if __NAI_NAME
		#undef __NAI_NAME
		#if _LBB
			struct __nai_lbb {
				ulong lbb_innum;
				ulong lbb_plen;
				char *lbb_path;
			} lbb = {
				.lbb_innum=
			}
			#include "lbb.h"
		#elif _LOC
			
		#elif _GLO

		#elif _UNI
		
	#endif
#endif
#ifndef __APOINTS__H
	/**
	 * nai is a union of structs to indicate which current
	 * level is provided, since `__nai` is a union we will
	 * use a concept called common initial sequence ( cis )
	 * for the structs a_i*, 
	 * 
	cis :: prepend : `__`
	 * 
	 */
	#define sp_network htons( 9999 )
	#define PORT_ACCEPT "9999"  // the global conf port
	#define __q_len 10   // queue size for connections

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
    static nai net_interface;

  
    /**
    returns ( indicator ) { fills struct `n_*interface` }
     *
    **/
    nai native_interface( int level );
    int mac_interface( struct a_inmp n_mach );
    int loc_interface( struct a_isok n_loch );
    int glo_interface( struct a_idns n_gloh );
    int uni_interface( struct a_ibna n_unih );

	enum __io_types {
		__io_r = 1,
		__io_ws
	};

	struct p_io {
		ulong io_pfd;
				// a paticular file descriptor
		long io_pid;
				// the initating process id
		enum __io_types io_type;
				// the IO type, mainly will be writers
	};
	#define __size_p_io sizeof( struct p_io )
	#define point_io struct p_io

	struct p_st {
		struct stat p_stat;
				// the FIFO stat in the filesystem
		point_io p_known;
				// the point reader&executor
		point_io p_annon;
				  // annonymus point request
	};
	#define __size_p_st sizeof( struct point_st )
	#define point_st struct p_st

	struct p_si {
		point_st pst;
				// the ather point structure
		int plvl;
				// the level associated with the structure
		void *p_i;
				// can && should be casted to a { nai } reference
	};
	#define __size_p_si sizeof( struct p_si )
	#define __size_p __size_p_si
	#define point_si struct p_si

	static char ap_name[8];
	static point_si ap; 

	#define point_descriptors() \
		( ap.st.p_lbb.io_pfd > 0 ) || ( ap.st.p_annon.io_pfd > 0 ) ? 1 : 0 

	#define point_exists() __file_exsits( __ap_name )
	#define make_point atherpoint

	#define is_reader ap.st.p_annon.io_pid == 0
	#define is_writer ap.st.p_known.io_pid == 0
	
	#define p_writer() int _w_res = 0;\
		do { ap.st.p_annon.io_pfd = _ap_w_entry(); _w_res = ( ap.st.p_annon.io_pfd != 0 )  } while( 0 )

	#define p_reader() int _r_res = 0;\
		do { ap.st.p_known.io_pfd = _ap_r_entry(); _r_res = ( ap.st.p_known.io_pfd != 0 ) } while( 0 )

	extern int atherpoint( char ap_ref[8] );
	int process_entry( char *p_entry , int pe_type );
	int app_engine( point_io *engint );
	int socket_execute( point_io *sexec );
	extern int applier();
#endif
#ifndef atherpoint
    int atherpoint( char ap_ref[8] ) {
        memmove( ap_name , ap_ref , 8 );
        #ifdef DEBUG
            printf( "@point :: ref = %s\n" , ap_name );
        #endif
        memset( &ap , 0 , __size_p_si );
        #ifdef DEBUG
            printf( "@point :: checking for atherpoint\n" );
        #endif
        if ( !__ap_fifo( ap_name , &ap.st.p_stat ) ) {
            #ifdef DEBUG
                printf( "@point :: no atherpoint found, attempting to create one\n" );
            #endif
            if ( !__ap_make() ) {
                #ifdef DEBUG
                    printf( "@point :: unable to create atherpoint\n" );
                #endif
                return -2;
            }
        }
        return 0;
    }
#endif

/*  
    @-PROTOCOL  
     #Morles
                */ 


