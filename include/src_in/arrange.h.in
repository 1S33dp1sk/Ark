/**
entity & sorting
	implementation :: 
		unsigned the_q[] = { 0xbc22 , 0x09a2 , 0x1011 , 0x102f , 0x192e , 0x0fa1 , 0x0de3 };
		set_sort_type( 0x1001 );
		sort_queue( &the_q , q_size );
		log_q();
**/
#ifndef enti
	#define __enti_name "e_sorting"
	#include "../probe.h"
	enum entity_max_t { 
		__e_call = 0x1000 , 
		__e_response = 0xffff 
	};
	#define entity enum entity_max_t
	
	enum __sort_t { 
		__bs_sort = 0x0 , 
		__sb_sort = 0x1 
	};
	
	static enum __sort_t sort_type;
	enum __sort_t __sort_type( unsigned _f_entity ){
		return _f_entity > __e_call ? __bs_sort : __sb_sort; 
	}
	
	#define __q_log_sort_type printf( "sort type :: %d\n" , sort_type )
	
	enum __sort_t set_sort_type( unsigned first_entity ) {
		sort_type = __sort_type( first_entity );
		return sort_type;
	}
	
	static const unsigned long __sort_entity_size = sizeof( unsigned );
	
	enum __cmp_res { 
		__cmp_l = -1 , 
		__cmp_e = 0 , 
		__cmp_g = 1 
	};
	
	#define __q_log_cmp( a , b ) printf( "comparing a: %d b: %d\n" , a , b )
	
	int __sort_cmp( void const*a , void const*b ) {
		unsigned const*_a = a, __a = *_a;
		unsigned const*_b = b , __b = *_b;
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
