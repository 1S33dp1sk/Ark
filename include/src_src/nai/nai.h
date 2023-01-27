/// nai \\\

// #define DEBUG

/**
 * nai is a union of structs to indicate which current
 * level is provided, since `__nai` is a union we will
 * use a concept called common initial sequence ( cis )
 * for the structs a_i*, 
 * 
cis :: prepend : `__`
 * 
 */

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