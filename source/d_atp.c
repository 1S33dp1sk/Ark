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

struct __kvp {
	char const *key;
	char const *val;
	struct __kvp *(*kv_memit)(char const *,char const *);
	struct __kvp *next;
	char offseter;
};
typedef struct __kvp kv_ptr;
static const ulong size_kv=sizeof(kv_ptr);
static const ulong size_kvp=sizeof(kv_ptr*);

kv_ptr *kv_memit(char const *key, char const *val) {
	ulong keylen=str_rwings(key), vallen=str_rwings(val);
	kv_ptr *__=(kv_ptr*)malloc(size_kv);
	void *__key=malloc(len_strze(keylen));
	void *__val=malloc(len_strze(vallen));
	memmove(__key, key, keylen);
	memmove(__val, val, vallen);
	__ -> key=(char const *)__key;
	__ -> val=(char const *)__val;
	__ -> offseter='\0';
	return __;
};


int kv_offset(kv_ptr *kv, char const *data, ulong offset_at) {
	memset((void *)kv, 0, size_kvp);
	kv->key=str_b4offset(data, offset_at);
	kv->val=str_a4offset(++data, offset_at);
	kv->offseter=data[offset_at];
	return 0;
};

kv_ptr *kv_at(char const *data, char *delim) {
	ulong __offset=sep_offset(data, delim);
	if(!__offset){
		return NULL;
	};
	kv_ptr *res=(kv_ptr*)malloc(size_kvp);
	kv_offset(res, data, __offset);
	return res;
};


void log_kvp(kv_ptr *res){
	printf("kv :'rn\n");
	printf("dlm -> %c\n", res->offseter);
	printf("key -> %s\n", res->key);
	printf("val -> %s\n", res->val);
}

void enumerate_kv(kv_ptr *__kvss, char const *__data, char *kv_sep, char *line_endings) {
	int __flag=0;
	kv_ptr *res_cont;
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
	// kv_ptr *ksvs;
	// enumerate_kv(ksvs, dummy, ":", "\r\n");






}












