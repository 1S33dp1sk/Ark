#include "lbb.h"
// #define DEBUG

char const *hashof( unsigned l , void const *t , size_t s );

/*
***************************************************************************
	*******************************************************************
		***********************************************************
			***************************************************
				********************************************
					************************************
						****************************
							********************
								************
								  *******
									lbb
								  *******
								************
							********************
						****************************
					************************************
				********************************************
			***************************************************
		***********************************************************
	*******************************************************************
***************************************************************************
*/




const char *__anet_name() {
	char __[8];
	sprintf( __ , "%ld" , lbb_inodenum() );
	const char *__hnet_name = hashof( 0 , __ , 8 );
	printf( "inodenum : %ld :: %s\n" , lbb_inodenum() , __hnet_name );
	return __hnet_name;
}

const char *__hallmark( hallmark hm ) {
	unsigned __len = 3 + sizeof( unsigned char ) + sizeof( unsigned long ) \
						+ ( strlen( hm.__address )*sizeof( unsigned char ) ) \
						+ ( strlen( hm.__keyhash )*sizeof( unsigned char ) );

	char __hm[__len]; __hm[__len] = '\0';
	
	sprintf( __hm , "%c:%ld@%s=%s" , \
		hm.__level, \
		hm.__num_records, \
		hm.__address, \
		hm.__keyhash );

	printf( "hallmark :: %s\n" , __hm );

	return strdup( __hm );
}

const char *__word( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

const char *__read() {
	unsigned lbb_size = lbb_size();
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( book.st.lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

int __write( char const *strlbb ) {
	if ( book.st.lbb_fd <= 0 ) {
		printf( "no lbb file descriptor found\n" );
		return -1;
	}
	int __bytes_written = 0;
	const char *__prev = __read();
	unsigned _plen = strlen( __prev ), _slen = strlen( strlbb );

	unsigned __len = _plen + _slen + 1;
	char __full_lbb[__len]; __full_lbb[__len] = '\0';
	strncpy( __full_lbb , __prev , _plen );
	strncpy( __full_lbb , strlbb , _slen );

	__bytes_written = write( book.st.lbb_fd , __full_lbb , __len );

	return __bytes_written;
}

int compile_lbb( char const *rlbb , word **__words ) {

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	kei _k , _w;
	int __iter = 0;

	for ( ; ; __iter++ ) {

		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}
		memset( &_k , 0 , sizeof( _k ) );
		memset( &_w , 0 , sizeof( _w ) );

		_k.e__set = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.i__size = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.k = ( char * ) __s + pmatch[1].rm_so;

		// printf( "key -> \"%.*s\"\n", _k.i__size , _k.k + pmatch[1].rm_so );

		_w.e__set = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.i__size = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.k = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			printf( "offset @ :: %ld\n" , _k.e__set );
			printf( "key :: %.*s\n" , ( int ) _k.i__size, _k.k );
			printf( "val :: %.*s\n" , ( int ) _w.i__size , _w.k );
		#endif


		// ( *__words + __iter ) -> v = _k;
		// ( *__words + __iter ) -> a = _w;

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );
	#ifdef DEBUG
		printf("lbb>compiled\n");
	#endif

	return 0;
}

int little_black_book() {
	printf( "current level is :: %ld\n" , level );
	memset( &book , 0 , sizeof( struct lbb_si ) );

	word *words;
	unsigned _name_len = strlen( __lbb_ext );
	char const *__name = *&__lbb_ext;
	memmove( book.st.lbb_path , __name , _name_len );


	printf( "struct path :: %s\n" , book.st.lbb_path );

	switch ( lbb_check() ) {
		case 0x2:	
			#ifdef DEBUG
				printf( "-2) no lbb found, making one.\n" );
			#endif
			lbb_make();
			___next();
			break;
		case 0x1:
			#ifdef DEBUG
				printf( "-2) lbb found, loading.\n" );
			#endif
			lbb_open();
			___next();
			break;
		default:
			break;
	}

	#ifdef DEBUG
		printf( "current level is :: %ld\n" , level );
		printf( "-1) initializing lbb\n");
	#endif

	if ( lbb_status() != 0 ) {
		#ifdef DEBUG
			printf( "zero on a zero kurl\n" );
		#endif
			printf( "lbb status cannot be determined\n" );
		return -1;
	}

	if ( lbb_descriptors() <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return 0;
	}

	size_t t_size = lbb_size(); // total size
	#ifdef DEBUG
		printf( "lbb : size = %ld bytes\n" , t_size );	
		printf( "lbb : fd = %d\n" , book.st.lbb_fd );
	#endif

	const char *__data = __read();
	unsigned long __len = strlen( __data );
	printf( "read :: %ld bytes\n" , __len );
	___next();


	int compilation_res = compile_lbb( __data , &words );
	// #ifdef DEBUG
	// 	printf( "compiled : %d\n" , compilation_res );
	// 	printf( "\n words = \n k :: %.*s\n v :: %.*s\n" , 
	// 	(int)(words[0].v).i__size , (words[0].v).k , 
	// 	(int)(words[0].a).i__size , (words[0].a).k );
	// #endif

	return 0;
}

laddr lbb_entry (void const *_) {

	lbb_load();
	
	int __lbb_size = lbb_size();

	printf( "lbb size ::%d\n" , __lbb_size );

	return __lbb_size;
}


int lbb_prompt() {
	printf( "little black book v.1\n" );
	return 0;
}



