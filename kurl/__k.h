/// klevels \\\
till now

#ifndef klevels
	#define klevels 7
	enum __k {
		__ki = 1,
		__kii = 2,
		__kiii = 4,
		__kiv = 8,
		__kv = 64,
		__kvi = 4096,
		__kvii = 16384,
	};
	#define kl_array unsigned int[] = { \
		__ki,	\
		__kii,	\
		__kiii,	\
		__kiv,	\
		__kv,	\
		__kvi,	\
		__kvii	\
	}
	unsigned __kswitch( unsigned __ ) {
		switch( __ ) { 
			case 0: 
				return __ki; 
			case 1: 
				return __kii; 
			case 2: 
				return __kiii; 
			case 3: 
				return __kiv;
			case 4: 
				return __kv;
			case 5: 
				return __kvi;
			case 6: 
				return __kvii; 
			default:
				return 16;
		}
	}
	#define charm_len(l) (__kswitch(l)*__kswitch(l))
	#define kmem_alloc(l) malloc(charm_len(l))
#endif

#ifndef __hat_name
	#define __hat_name "hash_ather_token"
#endif

#ifndef kurl_star
	#if kurl_i
		#include "k__/_i.h"
	#elif kurl_ii
		#include "k__/_ii.h"
	#elif kurl_iii
		#include "k__/_iii.h"
	#elif kurl_iv
		#include "k__/_iv.h"
	#endif
#endif

#ifndef ikp
	// can define kurl as { px , px1 , ... }
	// apply kurl = for p in kurl : ()
	#define p0 little_black_book()
	#define att book_reference()
	#define hat book_key()
	#define pat book_point()
	#define p1 atherpoint( pat )
#endif

