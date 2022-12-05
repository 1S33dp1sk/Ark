#include "lbb.h"


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
									lbb
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

word_t __read( struct lbb_st *__st );
word_t __line( char *key , char *val , char *delim );


int lbb_append( struct lbb_si*__ , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( &__ -> st );
	const char *curr = __line( key , val , ":" );
	char total[strlen( prev ) + strlen( curr )];
	strcpy( total , prev );
	strcpy( total , curr );
	int b_written = write( __ -> st.lbb_fd , total , strlen( total ) );
	
	#ifdef DEBUG
		printf( "wrote %d bytes\n" , b_written );
	#endif

	return b_written;
}

int lbb_query( struct lbb_si*__ , char *key ) {

}

int compile_lbb( char const *rlbb , struct seam **__lines ) {

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif

	struct sota _k , _w;
	int __iter = 0;

	for ( ; ; __iter++ ) {

		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}
		memset( &_k , 0 , sizeof( _k ) );
		memset( &_w , 0 , sizeof( _w ) );

		_k.offset = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.tal = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.sptr = ( char * ) __s + pmatch[1].rm_so;

		_w.offset = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.tal = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.sptr = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			log_sota( &_k );
			log_sota( &_w );
		#endif

		( *__lines + __iter ) -> key = _k;
		( *__lines + __iter ) -> wry = _w;

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}

word_t __line( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

word_t __read( struct lbb_st *st ) {

	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

int little_black_book( char *lbb_name ) {

	struct seam *lines;
	memset( &book , 0 , sizeof( struct lbb_si ) );

	unsigned _name_len = strlen( lbb_name );
	char *__name = _name_len <= 3 \
		? __lbb_name : lbb_name;
	memmove( book.st.lbb_path , __name , _name_len );

	printf( "struct path :: %s\n" , book.st.lbb_path );
	if ( lbb_check( book ) == -1 ) {
		#ifdef DEBUG
			printf( "no lbb found, creating one\n" );
		#endif
		lbb_make();
	}
	#ifdef DEBUG
	printf( "initializing lbb\n");
	#endif
	lbb_open( book );

	if ( lbb_status( book ) != 0 ) {
		printf( "lbb status cannot be determined\n" );
		return -1;
	}

	#ifdef DEBUG
	printf( "lbb : size = %ld bytes\n" , lbb_size( book ) );	
	#endif

	if ( lbb_descriptors( book ) <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return -2;
	}
	#ifdef DEBUG
	printf( "lbb : fd = %d\n" , book.st.lbb_fd );
	#endif

	word_t _word_all = __read(  &(book.st) );
	long _word_alen = strlen( _word_all );

	printf( "read :: %ld\n" , _word_alen );

	int compilation_res = compile_lbb( _word_all , &lines );
	if ( _word_alen < 4 ) {
		return compilation_res;
	}
	#ifdef DEBUG
		printf( "compiled : %d\n" , compilation_res );
		printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
		(int)(lines[0].key).tal , (lines[0].key).sptr , 
		(int)(lines[0].wry).tal , (lines[0].wry).sptr );
	#endif

	return 0;
}

