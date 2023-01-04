// the zero kurl
#ifndef zkurl

#if !defined( lbb) || !defined( ap )
	#include "kurl.h"
#endif

#ifndef hat
	#include "hat.h"
#endif

#ifdef lbb
struct zk_st {
	struct lbb_si zk_lbb;
	apoint zk_ap;
	hat zk_hat;
};
static struct zk_st kz;
#endif

#define st_zk( _ ) ( zk_st * )( _ )
#define __zkurl__ ( hat e )
#define zkurl kurl0

extern hat kurl0 __zkurl__{
	unsigned long res = ksig__;
	res = ksig( e );

	printf( "%08lx\n" , res );


	return e;
}

#endif
