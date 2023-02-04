#ifndef __ZENV__
	#include <unistd.h>
	#include <stdio.h>
	#include "utypes.h"
	#include "hbar.h"
	#include "idxer.h"
	extern char **environ;
	static uns env_hash_0,env_hash_1;
	
	ulong __env_hash(char **__var){
		uns __count=0;
		while(__var[__count]!=NULL){
			#ifdef DEBUG
				printf("%s\n",__var[__count]);
			#endif
			__count+=1;
		}
		env_hash_0=hash4(0,&__count,sizeof(uns));
		return __count;
	}

	char const *__keys_hash(char **__var, uns __varc){
		uns _c=0;
		ulong hashes[__varc];
		void *__hptr=memset(&hashes,0,(sizeof(ulong)*__varc));
		while(_c<__varc){
			hashes[_c]=hash8(1,__var[_c],strlen(__var[_c]));
			#ifdef DEBUG
				printf("k-%08x:%u:=%s\n",hashes[_c],_c,__var[_c]);
			#endif
			_c+=1;
		}
		char const *env_hash_2=hashof(2,__hptr,sizeof(hashes));
		return env_hash_2;
	}

	int main(void){
		char **__var=environ;
		uns envar_count=__env_hash(__var);
		char const *hvar=__keys_hash(__var,envar_count);
		printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
		return 0;
	}
#define __ZENV__ 0x1
#endif
