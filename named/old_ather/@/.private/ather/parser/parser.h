


void parse_aether_file( AETHER_FILE *A__F );

int _get_attribs( AETHER_FILE *A__F );


void parse_aether_file( AETHER_FILE *A__F ) {
	a_file _file = {0};
	A__F->A_FILE = &_file;
	A__F->A_FILE->_name = _AETHER_;
	if ( _file_contents( A__F-> A_FILE ) == 0 ) {
		_get_attribs( A__F );
	}
}


int _get_attribs( AETHER_FILE *A__F ) {
	char attrib_str[AETHER_FILE_BUFFER];
	strcpy( attrib_str , A__F->A_FILE->_contents );
	char *ptr = strtok( attrib_str , __delim );

	A__F->A_PATH = malloc( 50 * sizeof( char ) );
	A__F->A_CONNC = malloc( 100 * sizeof( char ) );
	A__F->A_CALL = malloc( 50 * sizeof( char ) );
	A__F->A_ENTRY = malloc( 50 * sizeof( char ) );

	while ( ptr != NULL ) {
		// printf("\n ->\t%s\t<-\n" , ptr);
		if ( strcmp( ptr , PATH__NAME ) == 0 ) {
			if ( ptr != NULL && ptr[0] == '=' ) {
				ptr++;
				A__F->A_PATH = ptr;
			}
		}
		else if ( strcmp( ptr , CONNC__NAME ) == 0 ) {
			ptr = strtok( NULL , "\n" );
			if ( ptr != NULL && ptr[0] == '=' ) {
				ptr++;
				A__F->A_CONNC = ptr;
			}
		}
		else if ( strcmp( ptr , CALL__NAME ) == 0 ) {
			ptr = strtok( NULL , "\n" );
			if ( ptr != NULL && ptr[0] == '=' ) {
				ptr++;
				A__F->A_CALL = ptr;
			}
		}
		else if ( ptr[0] == 'E' ) {
			Entry entry__ = {0};
			entry( ptr , &entry__ );
			
			// ptr = strtok( NULL , "\n" );
			// if ( ptr != NULL ) {
			// 	while( ptr[0] != '{' ){
			// 		ptr++;
			// 	}				
			// 	A__F->A_ENTRY = ptr;
			// }
		}
		else {
			perror( "Unknown attrb" );
			return 2;
		}
		ptr = strtok( NULL , "\n" );
		ptr = strtok( NULL , __delim );
	}
	return 0;
}

