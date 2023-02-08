
/// mach file \\\
machine file ##by Karam Jaber.

#include <unistd.h>
extern char **environ;
#include "utypes.h"
#include "idxer.h"
#include "enk.h"
#include "hbar.h"
#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
/**
NNE(X)
 * @returns :   true if x is not 0x0000
*/
#define NNE(v) v==0x0000?0x01:0x00
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

ulong __env_hash(char **evar);
char const *__keys_hash(char **evar, uns varc);
char *open_ccc(char const *cc, char const *path);
char *tochar(ulong inp_u);
ulong mem_amount(char *cpath);
char *get_mem_reserved(char *cpath);
ulong __file_r(char *cpath);
ulong __file_w(char *cpath);
ulong __file_x(char *cpath);
ulong file_field(char *cpath);
ulong ccc_field_offset(char *fpath,ulong f_field);
int mid_mods(char const*c3path);



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

int mid_env(void){
	char **__var=environ;
	uns envar_count=__env_hash(__var);
	char const *hvar=__keys_hash(__var,envar_count);
	printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
	return 0;
}

// free after
char *copy_top(char const *cc, char const *path){
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

ulong mid_fsize(char *cpath){
	return fsze(cpath);		
}
// free after 
char *mid_get(char *cpath){
	return tochar(fsze(cpath));
}

ulong mid_permissions(char *cpath){
	ulong __=__file_x(cpath);
	return __<2?__+__file_w(cpath)+__file_r(cpath):__;
}

ulong mid_offset(char *fpath,ulong f_field){
	return f_field!=0?(ulong)fhash8(2,fpath):(ulong)f_field;
}

static ulong mid_name(char *name,ulong csize){
	ulong __res=0;
	ulong _ures=0,__size=9; //(sizeof(ulong))+(5*sizeof(char))\\;
	uchar *__=malloc(__size);
	if(__==NULL){return 0;}
	memset(__,0,sizeof(__size));
	size_t step=__size/3;
	memmove(__,name,step);
	char *__idx=(char*)__+step;
	// printf("__ : %p\n__idx : %p\n",__,__idx);
	// printf("%s\n",__idx-3);
	memmove(__idx,":",1);
	uchar *__xer=(uchar *)&__idx+1;
	ulong __packed=0;
	if((__packed=pack(__xer,"L",csize))!=4){
	    printf("error packing L in xer\n"); 
	    return 0;
	}
	unpack(__xer,"L",&_ures);
	if(__[__size]=='\0'){
	    printf("%s",__);
	    printf("%08x%08x",u[0],u[1]);
	    printf("k+%llu\n",_ures);
	    // *u=hash16(3,__,8);
	}
	return __res;
}

int mid_mods(char const*_3curl){
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







