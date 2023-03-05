/// d-atp \\\

#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define DEBUG 1
#define LOG_ERR 1
#endif


int main(int argc,char const*argv[]) {
#define __ARGC__ argc
#define __ARGV__ *argv
__LBB_START__
	into_st into;
	__into__(into);
	into.argument=argv[1];
	p_type typepoint=__decode_p(&into);
	switch(typepoint){
	case __nul:
		return __point_run();
	case __unk: 
		if(argc>=3){
			return decode_lbb_addr(&into, &argv[2]);
		}
		else if (argc>=2) {
			return check_command(&into, argv);
		};
		#ifdef LOG_ERR
			printf("unknown command\n");
		#endif
		#ifdef DEBUG
			printf("usage :: %s addr command\n", argv[0]);
		#endif
		return 1;
	case __ptr: return decode_pointer(&into);
	case __pnt: return decode_point(&into);
	default: return 1;
	};
INDEX_END("\n");
};









