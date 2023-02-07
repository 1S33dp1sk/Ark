#ifndef __ZENV__
	#include <unistd.h>
	#include <stdio.h>
	#include "zenv.h"
	extern const uchar *charms[];
	extern const uchar *mods[];
	extern const uns mods_count;
	extern const uns __lbb_idx__;
	// free after
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
	// free after 
	char *tochar(ulong inp_u){
		char __[9];
		memset(&__,0,sizeof(__));
		sprintf(__,"%u\0",inp_u);
		return strdup(__);
	}

	ulong mem_amount(char *cpath){
		return fsze(cpath);		
	}

	char *get_mem_reserved(char *cpath){
		return tochar(fsze(cpath));
	}

	ulong __file_r(char*cpath){
		if (access(cpath,R_OK)==0){
			return 1;
		}
		return 0;
	}
	ulong __file_w(char*cpath){
		if (access(cpath,W_OK)==0){
			return 2; 
		}
		return 0;
	}
	ulong __file_x(char*cpath){
		if (access(cpath,X_OK)==0){
			return fsze(cpath);
		}
		return 0;
	}

	ulong file_field(char *cpath){
		ulong __=__file_x(cpath);
		return __<2?__+__file_w(cpath)+__file_r(cpath):__;
	}

	ulong ccc_field_offset(char *fpath,ulong f_field){
		return f_field!=0?(ulong)fhash8(2,fpath):(ulong)f_field;
	}

	int zmods(char const*_3curl){
		ulong fieldname=0, ccc__offset=0;
		char *__mod,*__crm,*__3c;
		ulong __len=0, __offset=0;
		int c=0; // count
		for(;c<mods_count;c++){
			__mod=(char*)mods[c];
			__crm=(char*)charms[c];
			__3c=open_ccc(__crm,_3curl);
			__len=mem_amount(__3c);
			__offset+=file_field(__3c);
			ccc__offset+=ccc_field_offset(__3c,__offset);
			fieldname=field_name(__crm,ccc__offset);
		}
	}
	#define __ZENV__ 1
#endif