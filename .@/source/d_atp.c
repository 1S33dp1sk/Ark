/// d-atp \\\


#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif


char const *dummy_data(){
	keyvals *kvs=__kvs__(": ", "\r\n");
	kvs_add_pair("_keynumber1\0","value_number16\0");
	kvs_add_pair("_keynumber2\0","value_number12\0");
	kvs_add_pair("_keynumber3\0","value_number11\0");
	kvs_add_pair("_keynumber5\0","value_number31\0");
	kvs_add_pair("_keynumber7\0","value_number11\0");
	kvs_add_pair("_keynumber1\0","value_number14\0");
	kvs_add_pair("_keynumber6\0","value_number19\0");
	char const *all_lines=kvs_traverse(kvs);
	return all_lines;
};

struct __k_v {
	char const *key;
	char const *val;
};
typedef struct __k_v key_value;

key_value *kv_meminit(char const *key, char const *val) {
	ulong keylen=str_rwings(key), vallen=str_rwings(val);
	key_value *__=(key_value*)malloc(key_value);
	void *__key=malloc(len_strze(keylen));
	void *__val=malloc(len_strze(vallen));
	memmove(__key, key, keylen);
	memmove(__val, val, vallen);
	__ -> key=(char const *)__key;
	__ -> val=(char const *)__val;
	return __;
};

void enumerate_kv(key_value *__kvss, char const *__data, char const *kv_sep, char const *line_endings) {

}


int main() {
	char const *dummy=dummy_data();
	key_value *ksvs;

	enumerate_kv(ksvs, dummy, kv_sep, lds);


}


