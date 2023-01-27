#ifndef entry
#define ENTRY__START "{"
#define ENTRY__END "}"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int ascii_entry[] = { 69, 78, 84, 82, 89, 123, 32 };

void entry( char *_entry , ENTRY *__entry__ );
void exec( ENTRY *__entry__ );

int _check_entry_name( char *entry_name );
int _make_entry_ctx( char *_entry , ENTRY *__entry__ );

char *__ENTRY__( char *_entry , ENTRY *__entry__ );


/**
 * @needed for executing the entry -- incoming
 */
int _check_entry_name( char *entry_name ) {
	for ( int _i=0; _i<5; _i++ ) {
		if ( entry_name[_i] == '\0' || entry_name[_i] != ascii_entry[_i] ) {
			printf( "\n\n---> NO__ENTRY <---\n\n" );
			return -1;
		}
	}
	return 1;
}
int _make_entry_ctx( char *_entry , ENTRY *__entry__ ) {
	int _iterlen = strlen( _entry );
	int _idx = 0;
	for( ; _idx < _iterlen ; _idx++ ) {
		if ( _entry[_idx] == '#' ) {
			break;
		}
	}
	char *__ref = &(_entry[_idx+1]);
	strncpy( __entry__ -> __ctx , __ref , _iterlen - _idx );
	return 0;
}
char *__ENTRY__( char *_entry , ENTRY *__entry__ ) {
	// super fash hash here
	// finish exec and then super fast hash 
	// to check for any inclusion attacks
	_entry = strtok( _entry , ENTRY__START );
	int __FLAG = 2;
	while ( _entry != NULL && __FLAG > 0 ){
		switch( __FLAG ) {
			case 2:
				__FLAG = _check_entry_name( _entry );
				break;
			case 1:
				__FLAG = _make_entry_ctx( _entry , __entry__ );
				break;
			default:
				return _entry;

		}
		_entry = strtok( NULL , ENTRY__END );
	}
	if ( __FLAG >= 0 ){
		printf( AETHER_EVALUATE , __entry__->__ctx );
	}
	return _entry;
}
void entry( char *_entry , ENTRY *__entry__ ) {
	__ENTRY__( _entry , __entry__ );
	exec( __entry__ );
}
void exec( ENTRY *__entry__ ) {
	if ( strlen( __entry__ -> __ctx ) > 2 ) {
		__entry__ -> __depth += 1;
		__entry__ -> exec__res = system( __entry__ -> __ctx );
	}
}

#endif




