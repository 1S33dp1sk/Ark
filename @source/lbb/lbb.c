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

#ifndef __lbb_raw__
	#define __lbb_raw__ "KW"
	char *_raw_kei( kei __kei ) {
		if( ( __kei.k != NULL ) && ( __kei.i__size != 0 ) ) {
			char __raw[__kei.i__size];
			memset( &__raw , 0 , sizeof( __kei.i__size )*sizeof( char ) );
			memcpy( __raw , __kei.k , __kei.i__size );
			return strdup( __raw );
		}
		return NULL;
	}
	char *_raw_word( word __word ) {
		unsigned __len_v = __word.v.i__size, __len_a = __word.a.i__size;
		unsigned __len_total = __len_v + __len_a + 3; 
		char __raw[__len_total];
		__raw[__len_total] = '\0';
		memcpy( __raw , _raw_kei( __word.v ) , __word.v.i__size );
		memcpy( __raw , __word.l , 2 );
		memcpy( __raw , _raw_kei( __word.a ) , __word.a.i__size );
		return strdup( __raw );
	}
#endif

entry_t __word( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

entry_t __read( struct lbb_st *st ) {
	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

entry_t __hallmark( hallmark *__ ) {
	char __hal[max_str];


	return strdup( __hal );
}

int lbb_append( struct lbb_si*__ , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( &__ -> st );
	const char *curr = __word( key , val , ":" );
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


	int compilation_res = compile_lbb( __data , &words );
	// #ifdef DEBUG
	// 	printf( "compiled : %d\n" , compilation_res );
	// 	printf( "\n words = \n k :: %.*s\n v :: %.*s\n" , 
	// 	(int)(words[0].v).i__size , (words[0].v).k , 
	// 	(int)(words[0].a).i__size , (words[0].a).k );
	// #endif

	lbb_close();
	return 0;
}

laddr lbb_entry t_entry {

	int tmp = little_black_book();
	printf( "res lbb :: %d\n" , tmp );

	char const *argv0 = ( char * ) _;

	return __val;
}

int lbb_add_line( entry_t _l ) {
	int x = -1;
	if ( book.st.lbb_fd > 0 ) {
		int x = write( book.st.lbb_fd , _l , strlen( _l )*sizeof( char ) );
		printf( "fd : %d : wrote x :: %d bytes\n" , book.st.lbb_fd , x );
	}
	return x;
}

int lbb_add_hallmark(){
	unsigned char *at_name = "@karam";
	hallmark hm = {
		.__k = '@',
		.__a = ':',
		._y_ = '0',
		._a = at_name,
		.n = 0,
	};
	printf( "\n%c%ld%c%s%d\n" , \
		hm.__k,
		hm.__a,
		hm._y_,
		hm._a,
		hm.n
	);
	// memset( &hm , 0 , sizeof( hallmark ) );
}


