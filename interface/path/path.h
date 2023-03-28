

/**
 * in order to be able to get the full 
 * nav system and build paths correctly 
 * we will utilize the `PATH` structure.
*/
 
// typedef struct {
//     char *_main;
//     char *aether_path;
//     char *node_path;
//     char *node_name;
// } PATH;


void log_path_debug( PATH *path );
void log_path_debug_verbose( PATH *path );
static int aether_path( PATH *path );
char *mixin_path( char *ptr , PATH *path );


static int aether_path( PATH *path ) {
    char buffer[STRING_BUFFER];
    // check current link to aether
    if ( getcwd( buffer , sizeof( buffer ) ) != NULL ) {
        // .aether dir check
        if ( strstr( buffer , _AETHER_ ) != NULL ) {
            char * ptr = malloc( 100 );
            ptr = (char *)&buffer;
            if ( ptr ) {
                mixin_path( ptr , path );
            }
        }
        else {
            printf( AETHER_ERROR , "PATH" , buffer );
            return 1;
        }
    }
    return 0;
}
#include "debug.h"

char *mixin_path( char *ptr , PATH *path ) {
   int f_len = strlen( ptr );
   path->_main = malloc( f_len );
   path->node_path = malloc( f_len );
   int rloc = 2;
   char * em_ptr = malloc( f_len );
   int _idx = 0;
   for( int i=0; i<f_len; i++ ) {
        // printf("%c->", ptr[i]);
        (path->_main)[i] = ptr[i];
        int __dif = f_len - strlen( path->_main );
        if ( ! strstr( path->_main , AETHER_HOME ) ) {
            if ( rloc == 2 ) {
                path->aether_path = malloc( __dif );
                rloc = 0;
            }
            (path->aether_path)[i] = ptr[i];
        }
        else {
            // printf("\n%s",path->node_path);   
            (path->node_path)[_idx] = ptr[i];
            em_ptr[_idx] = ptr[i];
            _idx++;
        }
    }
    path->node_name = malloc( f_len );
    char * token = strtok(em_ptr, "/");
    while( token != NULL ) {
      char * temp = token;
      token = strtok( NULL , " " );
      if ( token == NULL ) {
        path->node_name = temp;
        break;
      }
    }
    log_path_debug_verbose( path );
    return ptr;
}


void log_path_debug( PATH *path ) {
    printf( AETHER_ENTRY , path->node_path );
}


void log_path_debug_verbose( PATH *path ) {
    printf(" PATH :: \n");
    printf(" _main -> %s\n" , path->_main );
    printf(" _aether_path -> %s\n" , path->aether_path );
    printf(" _node_path -> %s\n" , path->node_path );
    printf(" _node_name -> %s\n" , path->node_name );
}
