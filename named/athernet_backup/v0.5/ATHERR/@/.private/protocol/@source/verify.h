

#ifndef AtherVerify

    #define AtherVerify "@verify"
    #define VECF_LOG "%s :: %c : %x : %d\n"
    #define LOG_VECF "%s%s »\n\t"
    #define MIN__ 33
    #define status_log( ss , vs , str ) _status_log( ss , vs , str )
    int _file_hash( FileData *filedata );
    extern uint32_t super_fast_hash ( char * data , int len );
    typedef enum { INIT , FOUND , EXECUTED , VERIFIED , NONE } VecfStatus;
    typedef enum { POS , POS_OPT , NEG , NEG_OPT } SignalSign;
    int _file_hash( FileData *filedata ) {
        int __len = strlen( filedata -> __contents );
        // printf("%d :: filesize :: %s " , filedata -> __size , filedata -> __name );
        if ( filedata -> __contents != NULL && __len >=  MIN__ ) {
            filedata -> __hash = super_fast_hash( filedata -> __contents , __len );
            return 0;
        }
        return 2;
    }
    char *_signal_status( char *_s , VecfStatus _vs ) {
        char *temp;
        switch( _vs ) {
            case INIT:
                temp = "Init";
                break;
            case FOUND:
                temp = "Found";
                break;
            case EXECUTED:
                temp = "Executed";
                break;
            case VERIFIED:
                temp = "Verified";
                break;
            case NONE:
                temp = NULL;
                break;
            default:
                temp = "@";
                break;
        }
        strcat( _s , temp );
        return _s;
    }
    char *_signal_sign( char *_s , SignalSign _ss ) {
        char *temp;
        switch ( _ss ) {
            case POS:
                temp = " + ";
                break;
            case POS_OPT:
                temp = "(+)";
                break; 
            case NEG:
                temp = " - "; 
                break; 
            case NEG_OPT:
                temp = "(-)";
                break; 
            default:
                temp = "•";
                break;     
        }
        strcat( _s , temp );
        return _s;
    }
    void _status_log( SignalSign ss , VecfStatus vs , char *str ) {

        printf( _signal_status( _signal_sign( str , ss ) , vs ) );
    }
    #undef get16bits
    #if ( defined( __GNUC__ ) && defined( __i386__ )) || defined( __WATCOMC__ ) \
      || defined( _MSC_VER ) || defined ( __BORLANDC__ ) || defined ( __TURBOC__ )
        #define get16bits( d ) ( * ( ( const uint16_t * ) ( d ) ) )
    #endif

    #if !defined ( get16bits )
        #define get16bits( d ) ( ( ( ( uint32_t ) ( ( ( const uint8_t * )( d ) )[1] ) ) << 8 )\
                           +( uint32_t ) ( ( ( const uint8_t * ) ( d ) )[0] ) )
    #endif
    uint32_t super_fast_hash (char *data , int len) {
        uint32_t hash = len, tmp;
        int rem;
        if (len <= 0 || data == NULL) { return 0; }
        rem = len & 3;
        len >>= 2;

        /* Main loop */
        for (;len > 0; len--) {
            hash  += get16bits (data);
            tmp    = (get16bits (data+2) << 11) ^ hash;
            hash   = (hash << 16) ^ tmp;
            data  += 2*sizeof (uint16_t);
            hash  += hash >> 11;
        }

        /* Handle end cases */
        switch (rem) {
            case 3: hash += get16bits (data);
                    hash ^= hash << 16;
                    hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                    hash += hash >> 11;
                    break;
            case 2: hash += get16bits (data);
                    hash ^= hash << 11;
                    hash += hash >> 17;
                    break;
            case 1: hash += (signed char)*data;
                    hash ^= hash << 10;
                    hash += hash >> 1;
        }

        /* Force "avalanching" of final 127 bits */
        hash ^= hash << 3;
        hash += hash >> 5;
        hash ^= hash << 4;
        hash += hash >> 17;
        hash ^= hash << 25;
        hash += hash >> 6;

        return hash;
    }
#endif
