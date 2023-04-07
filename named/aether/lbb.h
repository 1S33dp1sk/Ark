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


#ifndef lbb_hash
	#define lbb_hash hash( __key , __hashbuf )
	// convert each byte to a hexadecimal number
	void byte_to_hex( uint8_t b , char s[3] );
	// convert the `hash` to a hexdecimal number
	// saved as a string, i.e: characters
	void to_hashstr( char *hashstr , uint8_t *hash );
	// perform sha3 ( sha256 keccak ) on `__key`
	// and populate result in `__entryhash`
	char *hash( char *__key , char *__entryhash );
	/*-----------------------------------------------
	 -----------------------------------------------*/
	void byte_to_hex( uint8_t b , char s[3] ) {
	    uint32_t i=1;
	    s[0] = s[1] = '0';
	    s[2] = '\0';
	    while( b ) {
	        uint32_t t = b & 0x0f;
	        
	        if( t < 10 ) {
	            s[i] = '0' + t;
	        } 
	        else {
	            s[i] = 'a' + t - 10;
	        }
	        
	        i--;
	        b >>= 4;
	    }
	}
	void to_hashstr( char *hashstr , uint8_t *hash ) {
		for ( int _ = 0 ; _ < 32 ; _ ++ ) {
			char __[3];
			byte_to_hex( hash[_] , __ );
			strncat( hashstr , __ , 3 );
		}
		#ifdef DEBUG
		printf( "\n\t hash :: %s\n" , hashstr );
		#endif
	}
	char *hash( char *__key , char *__entryhash ) {
		int key_len = strlen( __key );
		sha3_init256( &__sha3 );
		sha3_set_flags( &__sha3 , 1 );
		sha3_update( &__sha3 , __key , key_len );
		uint8_t *__hash = ( uint8_t *) sha3_finalize( &__sha3 );
		#ifdef DEBUG
		printf( "lbb [+] \n\t key :: %s" , __key );
		#endif
		to_hashstr( __entryhash , __hash );
		return __entryhash;
	}
#endif

// lbb here is used as the main buffer
// for any entry. that is, to perform ops 
struct lbb {
	char *name;
	int __descriptor;
	char __path[PATH_MAX];
	char __out[256];
	struct stat __sb;
	int __idx;
	char __atype[6];
};
// disects to a kv pair
// basically string(k[delim]v) -> _key__value_ -> (key,value)
void _key__value_( char *__lbb_entry , char *__key , char *__value );
// makes the kv pair
// basically (key,value) -> __key_value__ -> string(k[delim]v)
void __key_value__( char *__lbb_entry , char *__key , char *__delim , char *__value );
// concat path with filename
// according to the OS
// non-POSIX basically.
void safe_path( char *__lbb_path , char *__lbb_name );
// create the regular lbb file
// with a valid, unique peername
int crt_lbb( char *__lbb_path );
// nitiate the lbb values
// using sys calls
int nit_lbb( struct lbb *__lbb , char *__name , int __type );
// As POSIX does not really 
// specifiy any portable or
// "standard" way of executing
// 		`lseek`|`fseek`
// this replaces that in lbb ctx.
int save_lbb( struct lbb *__lbb );
// key : value
// little_black_book { KV } implementation
int lbb_kv( struct lbb *__lbb , char *__key , char *__value );
// hash( key ) = hash( value )
// little_black_book { KVHH } implementation
int lbb_kv_h( struct lbb *__lbb , char *__key , char *__value );
// hash( key ) := value
// little_black_book { KVH } implementation
int lbb_kv_hh( struct lbb *__lbb , char *__key , char *__value );





void _key__value_( char *__lbb_entry , char *__key , char *__value ) {
}


void __key_value__( char *__lbb_entry , char *__key , char *__delim , char *__value ) {
	int idx = 0 , key_len = strlen( __key ) , value_len = strlen( __value ) , delim_len = strlen( __delim );
	char *delim_temp;
	strncat( __lbb_entry , __key , key_len );
	idx += strlen( __lbb_entry );
	if ( delim_len <= 2 && delim_len > 0 ) {
		if ( delim_len == 1 ) {
			delim_temp = malloc( 3 );
			delim_temp[0] = '\t';
			delim_temp[1] = __delim[0];
			delim_temp[2] = '\t';
		}
		else if ( delim_len == 2 ) {
			delim_temp = malloc( 4 );
			delim_temp[0] = '\t';
			delim_temp[1] = __delim[0];
			delim_temp[2] = __delim[1];
			delim_temp[3] = '\t';
		}
		delim_len = strlen( delim_temp );
		strncat( __lbb_entry , delim_temp , delim_len );
		idx += delim_len;
	}
	else {
		strncat( __lbb_entry , __delim , delim_len );
		idx += delim_len;
	}
	strncat( (&__lbb_entry[idx]) , __value , value_len );
	idx += value_len;
	__lbb_entry[idx] = '\n';
}


int crt_lbb( char *__lbb_path ) {
	printf("(creating a new lbb @ { %s }) :: ", __lbb_path );
	if ( mknod( __lbb_path , S_IFREG|S_IRWXU|S_IRWXG|S_IRWXO , 0 ) != 0 ) {
		printf( "[\u2715]" );
		printf( " -> cannot create node.\n" );
		return -1;
	}else{ 
		printf( "[\u2713]" );
		printf( "\n" );
		return 0;
	}
}

#define KV_DELIM ":"
int lbb_kv( struct lbb *__lbb , char *__key , char *__value ) {
	char *lbb_out = *(&(__lbb -> __out));  
	__key_value__( lbb_out , __key , KV_DELIM , __value );
	return 0;	
}

#define KVH_DELIM ":="
int lbb_kv_h( struct lbb *__lbb , char *__key , char *__value ) {
	char entry_hash[256] = {0} , *lbb_out = *(&(__lbb -> __out));  
	hash( __key , entry_hash );
	__key_value__( lbb_out , entry_hash , KVH_DELIM , __value );
	return 0;
}

#define KVHH_DELIM "="
int lbb_kv_hh( struct lbb *__lbb , char *__key , char *__value ) {
	char entry_hash[256] = {0} , outro_hash[256] = {0} , *lbb_out = *(&(__lbb -> __out));
	hash( __key , entry_hash );
	hash( __value , outro_hash );
	__key_value__( lbb_out , entry_hash , KVHH_DELIM , outro_hash );
	return 0;
}


void safe_path( char *__lbb_path , char *__lbb_name ) {

	strncat( __lbb_path , ".lbb\0" , 5 );
}


int nit_lbb( struct lbb *__lbb , char *__name , int __type ) {

	if ( iszero( __type ) ) {
		if( isnull( __name ) ) {
			#ifdef DEBUG
			printf( "type && name cannot be 0\n" );
			#endif
			return -1;
		}
	}
	
	__lbb -> name = __name;
	
	if ( getpath( __lbb -> __path ) ) {
		#ifdef DEBUG
		printf( "could init lbb\n" );
		#endif
		return -1;
	}
	
	safe_path( __lbb -> __path , __lbb -> name );

	if ( ispathempty( __lbb -> __path , &( __lbb -> __sb ) ) ) {
		#ifdef DEBUG
		printf( "stat : cannot be obtained :: path :: %s\n" , __lbb -> __path );
		printf( "crt>%s.lbb\n" , __name );
		#endif
		if ( crt_lbb( __lbb -> __path ) != 0 ) {
		#ifdef DEBUG
		printf( "could not create lbbn\n" );
		#endif
		return -1;
		}
	}

	lbb_t_name( __type , __lbb -> __atype );

	if ( !eopen( __lbb -> __path , __lbb -> __descriptor ) ) {
		#ifdef DEBUG
		printf( "descriptor cannot be obtained\n" );
		#endif
		return -1;
	}
	return 1;
}


int save_lbb( struct lbb *__lbb  ) { 
	int lbb_last = write( __lbb -> __descriptor , __lbb -> __out , strlen( __lbb -> __out ) + 1 );
	close( __lbb -> __descriptor );
	if ( lbb_last <= 0 ) {
		#ifdef DEBUG
		printf("lbb [\u2715]\n");
		#endif
		return -1;
	}
	#ifdef DEBUG
	printf("lbb [\u2713]\n");
	printf("\t bytes :: %d\n", lbb_last);
	#endif
	return 0;
}



// main usage
//

// include "misc.h"
// static sha3_context __sha3;
// #include "lbb.h"
// // the filesize for the lbb
// // and the atype are global
// // should be defined as a
// // static or external vars
//
// int main( int argc , char **argv ) {
// 	if ( argc < 2 ) {
// 		printf("usage :: lbb (key/hash) [value]\n");
// 		return 2;
// 	}
// 	struct lbb _lbb = {0};
// 	nit_lbb( &_lbb , argv[1] , 0 );
// 	lbb_kv( &_lbb , "main" , "self" );
// 	lbb_kv_h( &_lbb , "main" , "self" );
// 	lbb_kv_hh( &_lbb , "main" , "self" );
// 	save_lbb( &_lbb );
// 	return 0;
// }
//	