/// nai ? \\\
by mrKJ

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
    /**
    iterable( node & mount path )
    `a_inmp` :: struct i-nodenum,mountpath
    **/  
        struct a_inmp {
            long inn; 
                    // node number
            char imp[mpath_max]; 
                    // mount path
        };
    /**
    iterable( soket ) :: k_types : iterable
    **/
        struct a_isok {
            long __inn; 
                    // cis
            char __imp[mpath_max]; 
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
            char __imp[mpath_max]; 
                    // cis

            unsigned __isv; 
                    // cis
            struct sockaddr_storage isa; 
                    // cis
            int __isp; 
                    // cis

            char ids[dstr_max]; 
                    // sub domain
            char idn[dstr_max]; 
                    // domain name
            char idt[dstr_max]; 
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
            char __imp[mpath_max]; 
                    // cis

            unsigned __isv; 
                    // cis
            struct sockaddr_storage isa; 
                    // cis
            int __isp; 
                    // cis

            char __ids[dstr_max];
                     // cis
            char __idn[dstr_max];
                     // cis
            char __idt[dstr_max];
                     // cis

            char ibi[bid_max]; 
                    // blockchain identifier
            char iba[baddr_max];
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
            #ifdef( __level )
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
#endif