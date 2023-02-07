/// mach file \\\
machine file ##by Karam Jaber.






#ifndef __ZENV__H
	#include <unistd.h>
	#include "utypes.h"
	#include "idxer.h"
	#include "hbar.h"
	extern char **environ;
	static const uchar*charms[]={
		"att","bal","ccc","def","env","fmt",
		"git","hlv","inc","jab","kei","lbb",
		"mke","nop","ops","pub","que","rdl","sok",
		"trv","usr","vik","wln","xvl","ybn","z0x"
	};
	static const uchar*mods[]={
		"address","balance","charm","defined","enviroment","format",
		"git","hash","include","jaber","kei","lbb",
		"make","networks","osys","public","queue","riddle","shared",
		"traverse","user","vik","webpage","xolve","ybin","zen0x"
	};
	static const uns mods_count=arr_size(mods);
	static const uns __lbb_idx__=11;
	static uns env_hash_0,env_hash_1;

	char *open_ccc(char const *cc, char const *path);
	char *tochar(ulong inp_u);
	ulong mem_amount(char *cpath);
	char *get_mem_reserved(char *cpath);
	ulong __file_r(char *cpath);
	ulong __file_w(char *cpath);
	ulong __file_x(char *cpath);
	ulong file_field(char *cpath);
	ulong ccc_field_offset(char *fpath,ulong f_field);
	int zmods(char const*c3path);



	ulong __env_hash(char **__var){
		uns __count=0;
		while(__var[__count]!=NULL){
			#ifdef DEBUG
				printf("%s\n",__var[__count]);
			#endif
			__count+=1;
		}
		env_hash_0=hash4(0,&__count,sizeof(uns));
		return (ulong)__count;
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


	int zenv(void){
		char **__var=environ;
		uns envar_count=__env_hash(__var);
		char const *hvar=__keys_hash(__var,envar_count);
		printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
		return 0;
	}
	#define __ZENV__H 1
#endif