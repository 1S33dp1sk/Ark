#define MAX_NAME 100
#define MAX_PATH 4096

typedef struct {    
    char _name[MAX_NAME-1];
    char af_path[MAX_PATH-1];
    char **prefered_coms;
    union {
        char *__ip; // support both ipv4 && ipv6
        char *__str; // whatever the name is
        struct sockaddr_storage *__soc;
    } a_type;
#define a_ip a_type.__ip
#define a_str a_type.__str
#define a_socket a_type.__soc;
    char *cur_coms;
    unsigned char con_status; // e(xists) n(o_def)
    unsigned char *__defcall;
} a_info;


#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

// #include <stdlib.h>
// getuid :: always successful
// check errors on getpwuid
void __homedir( char *__ ) {
    struct passwd *pw = getpwuid( getuid() );
    int __len = strlen( pw -> pw_dir );
    memcpy( __ , pw -> pw_dir , __len );
    __ += __len;
    memcpy( __ , "/@/\0" , 3 );
    __ += 3;
    printf( "home dir :: %s\n" , __ - ( __len + 3 ) );
}

unsigned char __dfexists( char *__df ) {
    struct stat st;
    if ( stat( __df , &st ) == 0 ) {
        return 'e';    
    }
    return 'n';
}

int getainfo( char *basepath , char *filename , a_info *__ ) {
    int bp__len = strlen( basepath ) , fn__len = strlen( filename );
    char *__name = ( char * ) &(__ -> af_path);
    memcpy( __name , basepath , bp__len );
    memcpy( (char *)&(__name[bp__len]) , filename , fn__len );
    __ -> con_status = __dfexists( __name );


    return 0;
}

// #include <sys/types.h>
#include <dirent.h>
int _check_entry( struct dirent *dir_entry ) {
    char *__name = dir_entry -> d_name;
    if ( __name[0] == '.' ) {
        if ( strcmp( __name , ".ather" ) == 0 ) {
            return 0;
        }
	    return 2;
    }
    else {
        printf( "\tentry : size :: %s : %d\n" , __name , dir_entry -> d_reclen );
        return 1;        
    }
}
int __entries( char *base_path , a_info *path_entry ) {
    DIR *d;
    struct dirent *dir;
    if ( d = opendir( base_path ) ) {
        while ( ( dir = readdir( d ) ) != NULL ) {
        	if ( _check_entry( dir ) == 0 ) {
                getainfo( base_path , dir -> d_name , path_entry );
                break;
            }
        }
        closedir( d );
    }
}

