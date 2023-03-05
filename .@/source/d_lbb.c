/// d-lbb \\\


#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

#define __LBB__ K_512

void log_lbb_type(lbb_t lbbt) {
	switch(lbbt) {
	case __proto_call: printf("lbb type {Protocol}\n"); break;
	case __intrp_decl: printf("lbb type {Interpreter}\n"); break;
	case __payld_entr: printf("lbb type {Payload}\n"); break;
	default: printf("lbb type {Unknown}\n"); break;
	};
};

void *__search_r(char const *rname, lbb_t entry_type) {


	return NULL;
};


void *__lbb_ref(char const *__rname) {
	lbb_t __ltype=get_lbb_type(__rname);
	void *temp=__search_r(__rname, __ltype);
	return temp;
};


void *__lbb_addref(char const *__rname, char const *__rval) {
	dpoint *__dst=__stpoint(__rname, __rval);
	if(__dst!=NULL){
		__index_point(__dst);
		log_dpoint(__dst);
		return __dst;
	};
	free(__dst);	
	return NULL;
};

#ifdef __LBB__
int main(int argc,char const*argv[]) {
char *__ref_out;
#define __ARGC__ argc
#define __ARGV__ argv
	__LBB_START__
	if(__ARGC__){
		switch(__ARGC__) {
		case 1:
			printf("usage -> d-lbb [ATP_REF] [REFERENCE+PERM]\n");
			return 1;
		case 2:
			__ref_out=__lbb_ref(__ARGV__[1]);
			if(__ref_out==NULL) {
				#ifdef LOG_ERR
					printf("lbb cannot recognize reference : %s\n", __ARGV__[1]);
				#endif
				return 1;
			};
			break;
		case 3:
			__ref_out=__lbb_addref(__ARGV__[1], __ARGV__[2]);
			if(__ref_out==NULL) {
				#ifdef LOG_ERR
				printf("lbb cannot add reference : %s\n", __ARGV__[1]);
				#endif
				return 1;
			};
			break;
		};
		#ifdef OUTPUT
			printf("lbb -> \n");
			printf("%s\n",__ref_out);
		#endif
		return 0;
	};
	return 0;
};
#endif






















