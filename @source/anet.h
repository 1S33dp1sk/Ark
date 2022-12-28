/// athernet \\\



#ifndef __anet__h
	#define __anet_name "ATHERNET"
	static char anetpass[256];
	static const unsigned long passlen = sizeof( anetpass );
	static const unsigned long namelen = ( passlen / 2 );
	static const unsigned long naddrlen = ( passlen / 4 );
	#include "probe.h"
	#include "hbar/hbar.h"
	#include "lbb/lbb.h"

	#ifndef check_file
		#define check_file __file_exsits
		static struct stat __st;

		int __file_exsits( char *_name ) {
			return stat( _name , &__st ) == 0;	
		}
	#endif

	#ifndef seed
		#define uf_name ".lbb"
		#define seed __lbb

		void *__l__( unsigned __type ){
			struct stat st__;
			memset( &st__ , 0 , sizeof( struct stat ) );
			char __[namelen] , __hash[sizeof( int )];
			memset( &__ , 0 , sizeof( namelen ) * sizeof( char ) );
			__type &= sizeof( __type );
			switch ( __type ) {
				case 0 : 
					printf( "%s\n" , __ );
					return strdup( hashof( 0 , __ , sizeof( int ) ) );
				default:
					if ( stat( uf_name , &st__ ) != 0 ) {
						return NULL;
					}
					sprintf( __ , "%ld" , st__.st_ino );
				}
			return strdup( __ );
		}
		void *__lb_(){

		}
		void *__lbb(){
			return __l__( 0x0000 );
		}
	#endif

/**
entity & sorting
	implementation :: 
		unsigned the_q[] = { 0xbc22 , 0x09a2 , 0x1011 , 0x102f , 0x192e , 0x0fa1 , 0x0de3 };
		set_sort_type( 0x1001 );
		sort_queue( &the_q , q_size );
		log_q();
**/
	#ifndef entity
		enum entity_max_t { __e_call = 0x1000 , __e_response = 0xffff };
		#define entity enum entity_max_t
		enum __sort_t { __bs_sort = 0x0 , __sb_sort = 0x1 };
		static enum __sort_t sort_type;
		enum __sort_t __sort_type( unsigned _f_entity ){
			return _f_entity > __e_call ? __bs_sort : __sb_sort; 
		}
		enum __sort_t set_sort_type( unsigned first_entity ) {
			sort_type = __sort_type( first_entity );
			#ifdef DEBUG
				printf( "sort type :: %d\n" , sort_type );
			#endif
			return sort_type;
		}
		static const unsigned long __sort_entity_size = sizeof( unsigned );
		enum __cmp_res { __cmp_l = -1 , __cmp_e = 0 , __cmp_g = 1 };
		int __sort_cmp( void const*a , void const*b ) {
			unsigned const*_a = a, __a = *_a;
			unsigned const*_b = b , __b = *_b;
			#ifdef DEBUG
				printf( "comparing a: %d b: %d\n" , __a , __b );
			#endif
			if ( sort_type ) {
				return __a >= __b ? __cmp_l : __cmp_g;
			}
			return __a >= __b ? __cmp_g : __cmp_l;
		}
		void sort_queue( void *e_arr , size_t e_count ){

			qsort( e_arr , e_count , __sort_entity_size , &__sort_cmp );
		}
		#define q_size \
			( ( unsigned long ) ( sizeof( the_q ) / sizeof( the_q[0] ) ) )
		#define __q_log int i=0; \
			do { printf( "%08lx\n" , the_q[i] ); i++; } while( i < q_size )
		#define log_q() __q_log 
	#endif

	#ifndef stdptr
		#define stdptr ( void * ) __gen_ptr
		#define undptr ( void ) __free_ptr
	    size_t __size_ptr( unsigned _lvl ) {
	    	unsigned long quant_bc = 1 , __level = ( int ) _lvl;
	        while ( __level > 0 ){
	            quant_bc *=4;
	            __level--;
	        }
	    	return ( size_t ) quant_bc;
		}
		void *__gen_ptr( size_t __size ) {
			if ( ( __size % 4 ) == 0 ) {
				void *__ = malloc( __size );
				memset( __ , 0 , __size );
				return __;
			}
		}

		void __free_ptr( void *__ ) {
			free( __ );
		}
	#endif

	#ifndef netaddr
		#define netaddr ( char * ) _getaddr
		enum nettypes {
			agent = 0 ,
			local = 1 , 
			inter = 2 ,
			block = 3
		};
		char *_getaddr( enum nettypes __net ){
			char __[naddrlen];
			memset( &__ , 0 , naddrlen );
			memmove( __ , &anetpass[__net*naddrlen] , naddrlen );
			return strdup( __ );
		}
	#endif

	#ifdef levels 
		#ifndef lbb_add

		#endif
	#endif


#endif










