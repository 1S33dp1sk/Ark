#include "lbb.h"

#define DEBUG





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

char *__record( 
	int __rlevel , // record level
	char *__raddr , // record address
	char *__rencorh , // record encryption|hash
	unsigned __rcount ) { // record lines count 
	return NULL;
}

int __write_record() {

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

int __lbb_record( entry_t *ent ) {	
}

char *__hallmark( hallmark *__ ) {
	char __hal[max_str];
	int __ = 0;
	memset( &__hal , 0 , max_str*sizeof( char ) );
	__hal[__] = __ -> __l;
	__+=1;
	__hal[__] = ':';
	__+=1;
	unsigned int *__hal[__] = __->__n;
	__+=sizeof( unsigned int );
	__hal[__] = __kurl_version; 
	__+=1;
	unsigned int *__hal[__] = strlen( __ -> __n );
	__+=sizeof( unsigned int );
	__hal[__] = '@';
	__+=1;
	unsigned _a_addr = strlen( __ -> __a ); 
	memcpy( *__hal[__] , __ -> __a , _a_addr*sizeof( char ) );
	__+=_a_addr;
	__hal[__] = __kurl_version;
	__+=1;
	unsigned long *__hal[__] = __ -> __k;
	__+=sizeof( unsigned long );
	__hal[__] = 0xa;
	__+=1;
	printf( "%c:%d\t@%s\t=%lx\n" , \
	__ -> __l ,\
	__ -> __n ,\
	__ -> __a ,\
	__ -> __k );
	return strdup( __hal );
}

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

	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb>compiled\n");
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
			printf( "k :: %s\n" , _k.sptr );
			printf( "w :: %s\n" , _w.sptr );
		#endif

		// ( *__lines + __iter ) -> key = _k;
		// ( *__lines + __iter ) -> wry = _w;

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}

int little_black_book() {
	printf( "current level is :: %ld\n" , level );

	struct seam *lines;
	memset( &book , 0 , sizeof( struct lbb_si ) );

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
			printf( "not zero on a zero kurl\n" );
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

	const char *__data = __read( &book.st );
	unsigned long __len = strlen( __data );
	printf( "read :: %ld bytes\n" , __len );
	___next();


	int compilation_res = compile_lbb( __data , &lines );
	// #ifdef DEBUG
	// 	printf( "compiled : %d\n" , compilation_res );
	// 	printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
	// 	(int)(lines[0].key).tal , (lines[0].key).sptr , 
	// 	(int)(lines[0].wry).tal , (lines[0].wry).sptr );
	// #endif

	lbb_close();
	return 0;
}

laddr lbb_entry t_entry {

	int tmp = little_black_book();
	printf( "res lbb :: %d\n" , tmp );

	char const *argv0 = ( char * ) _;

	hallmark hm = {
		.__l = 'k',
		.__n = 2491,
		.__a = "athernet\0",
		.__k = 0x4ea585c0
	};

	__hallmark( &hm );

	return __val;
}


