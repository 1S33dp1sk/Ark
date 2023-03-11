/// d-prg \\\


#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define LOG_ERR 1
#define OUTPUT 1
#endif

char *tmp="/Users/mrkj/Custom/web-socket-app/public/index.html";

#define addr_size(x) ((ulong)sizeof((x->address)))
#define paddr(x) &(x.address)


int main(int argc, char const *argv[]) {
	payld_st pyld;
	void *ptr=malloc(8);

// __lbb_command(tmp, NULL);

__lbb_filepath(tmp, __pub);

__lbb_function(tmp, paddr(pyld), &pyld);

__lbb_field(tmp, ptr);

__lbb_address(tmp);
};

