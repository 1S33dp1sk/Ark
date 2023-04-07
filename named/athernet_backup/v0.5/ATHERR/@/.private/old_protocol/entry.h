#ifndef ENTRY
	#define ENTRY( __ather__ ) __ENTRY( __ather__ )
	#define ENTRY__START "{"
	#define ENTRY__END "}"


const int ascii_entry[] = { 69, 78, 84, 82, 89, 123, 32 };

char *entry( char *_entry , Entry *__entry__ );
void exec( Entry *__entry__ );
int _make_entry_ctx( char *_entry , Entry *__entry__ );
int __check__entry( char *entry_name );
char *__ENTRY__( char *_entry , Entry *__entry__ );


/**
 * @needed for executing the entry -- incoming
 */
int __check__entry( char *entry_name ) {
	for ( int _i=0; _i<6; _i++ ) {
		if ( entry_name[_i] != ascii_entry[_i] ) {
			return 10;
		}
	}
	return 20;
}
int _make_entry_ctx( char *_entry , Entry *__entry__ ) {
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
char *__ENTRY__( char *_entry , Entry *__entry__ ) {
	char *_e__name = malloc( MAX_STR * sizeof( char ) );
	_e__name = strtok_r( _entry , ENTRY__END , &_entry );
	int __;
	if ( ( __ = __check__entry( _e__name ) ) == 10 ) {
		_entry = strtok( NULL , ENTRY__END );
		_make_entry_ctx( _entry , __entry__ );
	}
	return _entry;
}
char *entry( char *_entry , Entry *__entry__ ) {
	return __ENTRY__( _entry , __entry__ );
	// exec( __entry__ );
}
void exec( Entry *__entry__ ) {
	if ( strlen( __entry__ -> __ctx ) > 2 ) {
		__entry__ -> __depth += 1;
		__entry__ -> __res = system( __entry__ -> __ctx );
	}
}

int __ENTRY( Ather *_ ) {

}

#endif




