/// d-atp \\\


#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif


char const *dummy_data(){
	keyvals kvs_st, *kvs=__kvs__(&kvs_st, ": ", "\r\n");
	kvs_pair(kvs,"_keynumber1\0","value_number8\0");
	// kvs_pair(kvs,"_keynumber2\0","value_number64\0");
	// kvs_pair(kvs,"_keynumber3\0","value_number512\0");
	// kvs_pair(kvs,"_keynumber4\0","value_number4096\0");
	// kvs_pair(kvs,"_keynumber5\0","value_number32k\0");
	// kvs_pair(kvs,"_keynumber6\0","value_number262k\0");
	// kvs_pair(kvs,"_keynumber7\0","value_number2m\0");
	// kvs_pair(kvs,"_keynumber8\0","value_number17m\0");
	// kvs_pair(kvs,"_keynumber9\0","value_number134m\0");
	char const *all_lines=kvs_traverse(kvs);
	return all_lines;
};

void enumerate_kv(kvptr *__kvss, char const *__data, char *kv_sep, char *line_endings) {
	int __flag=0;
	kvptr *res_cont;
	char const *temp=__data;
	while(!__flag) {
		res_cont=kv_at(temp, line_endings);
		if(res_cont==NULL) {
			__flag=1;
		};
		log_kvp(res_cont);
		temp=res_cont->val;
		res_cont=kv_at(res_cont->key, kv_sep);
		if(res_cont==NULL){
			temp=res_cont->key;
		}
		log_kvp(res_cont);
	};
	free(res_cont);
};



int main() {

	char const *dummy=dummy_data();
	printf("data :: \n%s\n", dummy);
	// kvptr *ksvs;
	// enumerate_kv(ksvs, dummy, ":", "\r\n");






}












