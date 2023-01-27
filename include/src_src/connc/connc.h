#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>


int aether_dir();
int get_files( PATH *a_path ,  CONNC *connc );
int _check_entry( struct dirent *dir_entry , CONNC *connc );
void _loop_dir( char *dir_path , CONNC *connc );
void _connc_and_hash( CONNC *connc );
void _index_and_total( CONNC *connc );
void log_connc_debug( CONNC *connc );
uint32_t super_fast_hash ( char * data , int len );

char *__getcwd() {
    char cwd[PATH_MAX];

    return strdup(getcwd(cwd,sizeof(cwd)))
}

int aether_dir() {
   char cwd[STRING_BUFFER];
   if ( getcwd( cwd , sizeof(cwd) ) != NULL ) {
   		if ( strstr( cwd , _AETHER_ ) != NULL ) {
   			if( access( _AETHER_ , F_OK ) == 0 ) {

   				file_t file = {0};
   				file._file->_name = _AETHER_;
   				file.key = CONNC__NAME;

   				if ( get_file_data( &file ) ) {
   					key_exist( &file );
   					char *value = get_value( file._file->_contents );
                    return 0;
                }
                perror("cannot access .aether file, check permissions");
                return 1;
   			}
            perror("No .aether file present");
            return 1;
   		}
        perror("Not in aether");
        return 2;
    }
    perror("cannot get current working dir");
    return 2;
}

void _loop_dir( char *dir_path , CONNC *connc ) {
    DIR *d;
    struct dirent *dir;
    if ( d = opendir( dir_path ) ) {
        while ( ( dir = readdir( d ) ) != NULL ) {
            _check_entry( dir , connc );
        }
        closedir( d );
    }
    _index_and_total( connc );
    _connc_and_hash( connc );
    // log if needed
    log_connc_debug( connc );
}

void _index_and_total( CONNC *connc ) {
    // remove extra increment
    // for index to start from 0
    connc->num_dirs -= 1;
    connc->num_files -= 1;
    // combine for hashing
    connc->_total = connc->num_dirs + connc->num_files;
}

void log_connc_debug( CONNC *connc ) {

    for( int _dir_iter=0; _dir_iter<=connc->num_dirs; _dir_iter++ ) {
        printf( AETHER_PATH , connc->_dirs[_dir_iter] );
    }

    printf("\n");

    for( int _file_iter=0; _file_iter<=connc->num_files; _file_iter++ ) {
        printf( AETHER_F_EXEC , connc->_files[_file_iter] , connc->_hashes[_file_iter] );
    }

}

int _check_entry( struct dirent *dir_entry , CONNC *connc ) {
    if( dir_entry -> d_type == DT_DIR && strcmp( dir_entry->d_name , "." ) &&  strcmp( dir_entry->d_name , ".." ) ) {
        *(connc->_dirs+connc->num_dirs) = dir_entry->d_name;
        connc->num_dirs = connc->num_dirs + 1;
    }
    else if ( dir_entry -> d_type == DT_REG ) {
        *(connc->_files+connc->num_files) = dir_entry->d_name;
        connc->num_files = connc->num_files + 1;
    }
    return 0;
}

uint32_t super_fast_hash (char * data, int len) {
    uint32_t hash = len, tmp;
    int rem;
    if (len <= 0 || data == NULL) return 0;
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

int get_files( PATH *a_path , CONNC *connc ) {
    connc->_dirs = malloc( 100 * sizeof( char ) );
    connc->_files = malloc( 100 * sizeof( char ) );
    _loop_dir( a_path->_main , connc );
    return 0;
}

void _connc_and_hash( CONNC *connc ) {
    int __total = connc->_total;
    int _iter = 0;
    uint32_t __safehash;
    connc->_hashes = malloc( (__total)*sizeof(int) );
    a_file __f = {0};
    for( ; _iter <= connc->num_files; _iter++ ) {
        __f._name = connc->_files[_iter];
        _file_contents( &__f );
        __safehash = super_fast_hash( __f._contents , strlen( __f._contents ) );
        connc->_hashes[_iter] = __safehash;
    }
}
