/// d-prg \\\


#ifndef __Karch_512__
#include "headers/_h512.h"
#include "headers/lbb.h"
#include "headers/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

char *tmp="/Users/mrkj/Custom/web-socket-app/public/index.html";

__dPRG
	__INDEXER__(

	payld_st pyld;
	void *ptr=malloc(8);

	// __lbb_command(tmp, NULL);

	__lbb_filepath(tmp, __pub);

	__lbb_function(tmp, paddr(pyld), &pyld);

	__lbb_field(tmp, ptr);

	__lbb_address(tmp);
)
	

