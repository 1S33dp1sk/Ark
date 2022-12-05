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
        struct point_st apst;
                // the ather point structure
        int level;
                // the level associated with the structure
        void *lai;
                // can && should be casted to a { nai } reference
    };
    #define __size_p_si sizeof( struct point_si )
    #define __size_p __size_p_si

    typedef struct point_si point;



    #define point_descriptors( __ ) \
        ( __.p_lbb.io_pfd > 0 ) || ( __.p_annon.io_pfd > 0 ) ? 1 : 0 

    #define point_exists() __file_exsits( __ap_name )
    #define make_point( __ ) atherpoint( __ap_name , &__ )



    int atherpoint( void *at_point , point* ap );
    int process_entry( char *_e , int _e_len );
    int app_engine( struct p_io *engint );
    int socket_execute( struct p_io *sexec );
    int applier( point* ap );



#endif


