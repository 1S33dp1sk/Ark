/// atherpoint \\\

// #define DEBUG


/**
 * atherpoint is an `FIFO`
 * with a singular reader, that is the `lbb`
 * 
 * writers can connect to the atherpoint syncronously 
 * and query real time updates on the values , operations
 * that are used to create/modify these values.
 * 
 * that is done mainly by kurling the lbb between two or more
 * points. 
 * 
 */
#ifndef point
    #define __ap_name "atherpoint"
	#include "../probe.h"

    enum __io_types {
        __reader = 1,
        __writers
    };

    struct p_io {
        unsigned io_pfd;
                // a paticular file descriptor
        signed long io_pid;
                // the initating process id
        enum __io_types io_type;
                // the IO type, mainly will be writers
    };
    #define __size_p_io sizeof( struct p_io )

    struct point_st {
        struct stat p_stat;
                // the FIFO stat in the filesystem
        struct p_io p_lbb;
                // the point reader&executor
        struct p_io p_annon;
                  // annonymus point request
    };
    #define __size_p_st sizeof( struct point_st )

    struct point_si {
        struct point_st st;
                // the ather point structure
        int level;
                // the level associated with the structure
        void *lai;
                // can && should be casted to a { nai } reference
    };
    #define __size_p_si sizeof( struct point_si )
    #define __size_p __size_p_si
    #define point struct point_si

    extern unsigned long level;
    static char ap_name[8];
    static struct point_si ap; 

    #define point_descriptors() \
        ( ap.st.p_lbb.io_pfd > 0 ) || ( ap.st.p_annon.io_pfd > 0 ) ? 1 : 0 

    #define point_exists() __file_exsits( __ap_name )
    #define make_point atherpoint



    extern int atherpoint( char ap_ref[8] );
    int process_entry( char *_e , int _e_len );
    int app_engine( struct p_io *engint );
    int socket_execute( struct p_io *sexec );
    extern int applier();




    



#endif


