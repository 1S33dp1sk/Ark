#include "../probe.h"

int check_level( char *aname , int aname_len );
int __check_atomic( char *aname , int aname_len );
int __check_local( char *aname , int aname_len );
int __check_global( char *aname , int aname_len );
int __check_universal( char *aname , int aname_len );


int main( int argc , char **argv ) {

	if ( argc > 2 || argc == 1 ) {
		printf( "usage :: @levels [athername]\n" );
		return -1;
	}

	char *__aname = argv[1];
	int aname_len = strlen( __aname ) - 1;

	return check_level( __aname , aname_len );
}

int check_level( char *aname , int aname_len ) {

	if ( aname_len < 1 ) {
		printf( "athernames are always 2 or more characters\n" );
		return -2;
	}

	switch ( aname[0] ) {
		case '@':
			return __check_atomic ( aname , aname_len );
		case '/':
			return __check_local( aname , aname_len );
		case '0':
			if ( aname[1] == 'x' )
				return __check_universal( aname , aname_len );
		default:
			return __check_global( aname , aname_len );
	}
	return 0;
}

int __check_atomic( char *aname , int aname_len ) {

	return __sys_entry( aname ) == 0 ? 1 : 0;
}

int __check_local( char *aname , int aname_len ) {

	return __path_entry( aname ) == 0 ? 1 : 0;
}

int __check_global( char *aname , int aname_len ) {
	int socket_listener = __dns_entry( aname );
	if ( socket_listener > 0 ) {
		return socket_listener;
	}
	return 0;
}

int __check_universal( char *aname , int aname_len ) {

	return 0;
}

