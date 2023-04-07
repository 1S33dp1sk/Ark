/// d-atp \\\
@-Protocol

#ifndef karch
#include "headers/karch.h"
#endif

__dPRG
	__LBB__(
		into_st into;
		into_st *__p=__into__(&into);
		into_caller(into, argv[0]);
		into_args(into, &argv[1]);
		into_type(into, get_atp_type(argv[1]));
		__protocol__(into.req_at);
	);

