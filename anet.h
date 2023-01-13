/// athernet \\\


#ifndef __anet__h
	#define __anet_name "ATHERNET"
	#include "probe.h"
	#include "hbar/hbar.h"
	#include "lbb/lbb.h"
	#include "nai/nai.h"
	#include "point/point.h"
	#include "lenk/lenk.h"
	#include "kurl/kurl.h"
	
	#define __os_pre '.'
	#define __os_prepend '/'
	static const char _os_prepend[] = { '.' , '/' };

	#define __att__len 4
	#define att_id 64

	#define __att_mac "@mac"
	#define __att_loc "@loc"
	#define __att_glo "@glo"
	#define __att_blk "@blk"

	char const *__get_arg_id( void const *__arg ) {
		char const*_arg_id = __arg;
		unsigned i = 0 , c = 0 , a_size = arr_size(_os_prepend);
		for( ; i<a_size; i++ ){
			if ( _arg_id[i] == _os_prepend[i] ) {
				c+=1;
			}
		}
		return c == 0 ? _arg_id : _arg_id+c;
	}

	int __check_att( void const*__arg ) {
		char const *arg_id = __get_arg_id( __arg );
		printf( "%s\n" , arg_id );	
		uint32_t __cmp = super_fast_hash( arg_id , __att__len );
		if ( arg_id[0] == att_id ) { //@
			if ( __cmp == sfh(__att_mac) ) {
				return kurl_i(kmem_alloc(1));
			}
			else if ( __cmp == sfh(__att_loc)) {
				return kurl_ii(kmem_alloc(2));
			}
			else if ( __cmp == sfh(__att_glo)) {
				return kurl_iii(kmem_alloc(3));
			}
			else if ( __cmp == sfh(__att_blk)) {
				return kurl_iv(kmem_alloc(4));
			}
			else{
				return kurl(kmem_alloc(0));
			}
		}
	}

#endif










