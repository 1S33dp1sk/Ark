#ifndef __CHARMING__
	#include <unistd.h>
	#include <stdio.h>
	#include <sys/stat.h>
	#include <string.h>
	#include "idxer.h"
	static const uchar *charms[] = {
		"att","bal","ccc","def","env","fmt",
		"git","hlv","inc","jab","kei","lbb",
		"mke","nop","ops","pub","que","rdl",
		"trv","usr","vik","wln","xvl","ybn","z0x"
	};
	static const uns charms_count = arr_size(charms);
	static const uns _lbb_idx = 11;
	char *open_ccc(char const *cc, char const *path){
		char __ccc[256];
		memset(&__ccc,0,sizeof(__ccc));
		uns __pathlen=strlen(path),__len=__pathlen+4; //including the '\0' byte
		strcpy(__ccc,path);
		strcpy((__ccc+__pathlen),cc);
		if(__ccc[__len]!='\0'){
			__ccc[__len]='\0';
		}
		return strdup(__ccc);
	}
	int main(int argc, char const*argv[]){
		if(argc==1){
			printf("pass a path to files directory\n");
			return 0;
		}
		char *__3c;
		char const *_3curl=argv[1];
		int c=0; // count
		for(;c<charms_count;c++){
			__3c=open_ccc(charms[c],_3curl);
			printf("the string :: %s\n",__3c);
		}
	}
	#define __CHARMING__ 1
#endif