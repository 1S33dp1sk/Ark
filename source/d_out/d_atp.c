/// d-lbb \\\

#ifndef __Karch_512__
#include "headers/_h512.h"
#include "headers/lbb.h"
#include "headers/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#define PROCESS 1
#endif




	int __info__(into_st *info);
	int __lbb__(into_st *into_lbb);
	int __point__(into_st *into_point);
	int __pointer__(into_st *into_pointer);
	int __atp__(into_st *into_protocol);
	int get(into_st *into_var);
	int set(into_st *into_var);
	int atp(into_st *into_call);
	int save(into_st *into_data);
	int collect(into_st *into_request);
	int dcloud(into_st *into_0xa);



int main(int argc,char const*argv[]) {
__LBB_START__
	into_st into, *into_p=&into;
	__into__(into, into_p, argv);
	printf("into.req_at = %d\n", into.req_at);
	switch(into.req_at){

	case __lbb_none__:
		return __no_entry__(into_p);

	case __lbb_charms__: 
		return __pointer__(into_p);

	case __lbb_field__:
		return __field__(into_p);

	case __lbb_info__:
		return __info__(into_p);

	case __lbb_variable__: 
		return __point__(into_p);

	case atp_base:
		return __lbb__(into_p);

	case atp_get:
		return get(into_p);

	case atp_set:
		return set(into_p);

	case atp_return:
		return atp(into_p);

	case atp_retain:
		return save(into_p);

	case atp_retreive:
		return collect(into_p);

	case atp_dcloud:
		return dcloud(into_p);

	default: 
		break;
	};
INDEX_END("\n");
};
