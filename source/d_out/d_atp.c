/// d-lbb \\\

#ifndef __Karch_512__
	#include "headers/_h512.h"
	#include "headers/lbb.h"
	#include "headers/ixr.h"
	#define OUTPUT 1
	#define LOG_ERR 1
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

