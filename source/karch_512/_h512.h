/// machine file \\\
K512-architecture 

#ifndef __Karch_512__
	#define K_512 5
#ifndef __k_arch512__h
#include "standard.h"
#ifndef __UTYPES__H
	#include "utypes.h"
#endif
#ifndef __LBB__H
	#include "lbb.h"
#endif
#ifndef __ATP__H
	#include "atp.h"
#endif
#ifndef __HBAR__H
	#include "hbar.h"
#endif
#ifndef __ENK__H
	#include "enk.h"
#endif
#ifndef __IXR__H
	#include "ixr.h"
#endif
#define __k_arch512__h 1
#endif

#define LOG_ERR 1
/************************ defintions ************************/

#define __Karch_512__ 
#define __MA__F 0x000000000000000000000008
#define LONG_MAX_COMPUTED_N_DIGITS 21 //logb(x) = loga(x) / loga(b)
#define MachPtr 16
#define __GS__F __MA__F<<3
#define GSocketField 64
#define __LO__F __GS__F<<3
#define LockF 512
#define __UN__F __LO__F<<3
#define UFile 4096
#define ARC_GENERIC(x) (ulong)((1<<(x*3)))
#define arch_filename "@charms/Lockfile"


/************************ naming ************************/

ulong __fsize(char const *__fpath);
ulong __iosize(char const *__fpath);
ulong __inodenum(char const *__fpath);
uns __dmode(char const *__fpath);
ulong __file_r(char const *__fpath);
ulong __file_w(char const *__fpath);
ulong __file_x(char const *__fpath);
uns __8sz(uns __8to);
fld_sz fld_type2sz(fld_t __ftype);
int __get_fd(char const *__fpath, int __flag);
int __get_process_flags(char const *__cpath);
int __check_fld(char const *__cpath, fld_t ftype);
char const *__getcaller();
char const *__charm_call(char const *__ffrom);
int __init_3ci();
int arch_3ci();
void log_arcs();
char const *__gdelim(fmt_t g_fmt);
char const *__gfmt(fmt_t gt);
char const *__generic_fmt(fmt_t g_fmt, char const *__key, char const *__value);
ulong __env_hash(char **__envvar);
char const *__h_passcode(char *udef_pass);
char const *__kgev(uchar *__udef_pnop);
void k1_addr(ulong _h8res, ulong _count, char *_kval);
char const *__keys_hash(char **__envvar, uns __varc);

fld_t __size_switch(char const *__cpath);
char const *ccopy_to_path(char const *cc, char const *__cpath);
char const *arch_gfile(char const *__cpath);
fld_sz arch_tfile(char const *__cpath);
ulong arch_cfile(fld_t fld_type);
ulong attsize(ulong __sz);
ulong fldatt(uns level, ulong szatt);
ulong arch_fpermissions(char const *__cpath);
char const *tochar(ulong num_in);
ulong arch_foffset(char const *__fpath, ulong f_field);
static ulong arch_fname(char const *__fpath, ulong fsize);
int arch_mods(char const *__cpath);
int arch_cenv();

char const *__irv(char const *__key, char const *__val);
ulong __index_increment();
ulong __set_next(char const *__head);
ulong __idx_start();

char const *__xreference(char const *__);
int __index_r(char const *idxnr);
int __index_irn(char const *key, char const *val);
int __index_ixn(char const *key);
int __index_caller();
int __index_point(dpoint *dst);
void log_ixrh(ixr_h *ixrh);
int __rd_ixrh();
int __wt_ixrh();
int refresh_h();
void *__header__();
int indexer_start();
int __indexer__(char const *__id);
int refer_index(void *__ptr, void *__ref, char *__prname);
void log_fmt_t(fmt_t __format);
void log_keyvalue(char *key, char *value);
void lbb_usage();
int get_allstats(char *__mountpoint, char *__socketaddr, char *__fieldshare);
char *flds(char const *__fldname);
dpoint *__stpoint(char const *__stname, char const *__stval);
void *__search_r(char const *__rname, lbb_t entry_type);
void *__lbb_ref(char const *__rname);
void *__lbb_addref(char const *__rname, char const *__rval);


// static const char *__os_delim="/\0";

/************************ functions ************************/
/********* files *********/

ulong __fsize(char const *__fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(__fpath,&__)!=0){return 0;}
	return __.st_size;
};

ulong __iosize(char const *__fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(__fpath,&__)!=0){return 0;}
	return __.st_blksize;
};

ulong __inodenum(char const *__fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(__fpath,&__)!=0){return 0;}
	return __.st_ino;
};

uns __dmode(char const *__fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(__fpath,&__)!=0){return 0;}
	return __.st_mode;
};

ulong __file_r(char const *__cpath){
	if (access(__cpath,R_OK)==0){
		return 1;
	}
	return 0;
};

ulong __file_w(char const *__cpath){
	if (access(__cpath,W_OK)==0){
		return 2; 
	}
	return 0;
};

ulong __file_x(char const *__cpath){
	if (access(__cpath,X_OK)==0){
		return fsze(__cpath);
	}
	return 0;
};

/********* base8 *********/

uns __8sz(uns _){
	uns __=1;while(_>0){__*=8;_--;}
	return __;
};

/********* fld *********/

fld_sz fld_type2sz(fld_t type){
	switch(type){
	case f_reader: return __freader_sz;
	case f_socket: return __fsocket_sz;
	case f_field: return __ffield_sz;
	case f_dir: return __fdir_sz;
	case fld_1: return __fld1_sz;
	case fld_2: return __fld2_sz;
	case fld_3: return __fld3_sz;
	case fld_4: return __fld4_sz;
	default: break;
	};
	return 0;
};

int __get_fd(char const *__cpath, int __flag){

	return open(__cpath, __flag);
};

int __get_process_flags(char const *__cpath){

	return dmde(__cpath);
};

int __check_fld(char const *__cpath, fld_t __ftype){
	if(fsze(__cpath)<fld_type2sz(__ftype)){
		return 0;
	}
	return 1;
};

char const *__getcaller(){

	return (char const *)__FILE__;
};

char const *__charm_call(char const *__filefrom) {
	char const *__caller=__getcaller();
	ulong __clen=str_rwings(__caller);
	ulong __flen=str_rwings(__filefrom);
	char charmcall[__clen];
	memset(&charmcall, 0, sizeof(charmcall));

	ulong f_sep=sep_offset(__filefrom, d_atbase);
	ulong c_sep=sep_offset(__caller, d_atbase);
	if(!c_sep||!f_sep) {
		#ifdef LOG_ERR
			printf("f:sep=%lu, c:sep=%lu\n", f_sep, c_sep);
			printf("seperate offset is null\n");
		#endif
		return NULL;
	};
	memmove(charmcall, __caller, c_sep);
	memmove((charmcall+c_sep), (__filefrom+f_sep), (__flen-f_sep));
	#ifdef DEBUG
		printf("charmcall :: %s\n", charmcall);
	#endif

	return strdup(charmcall);
};


/********* unistd *********/

extern char **environ;


/********* base26 *********/


static const uchar charms[26][4]={
	"att\0","bal\0","ccc\0","def\0","env\0","fmt\0",
	"git\0","hlv\0","inc\0","jab\0","kei\0","lbb\0",
	"mke\0","nop\0","ops\0","pub\0","que\0","rdl\0","sok\0",
	"trv\0","usr\0","vik\0","wln\0","xvl\0","ybn\0","z0x\0"
};

char const *mount_at="@charms/lbb/\0";

static const ulong __enu_size=512;
static const char mod_att[]="address\0";
static const char mod_bal[]="balance\0";
static const char mod_ccc[]="charm\0";
static const char mod_def[]="defined\0";
static const char mod_env[]="enviroment\0";
static const char mod_fmt[]="format\0";
static const char mod_git[]="git\0";
static const char mod_hlv[]="hash\0";
static const char mod_inc[]="include\0";
static const char mod_jab[]="jaber\0";
static const char mod_kei[]="kei\0";
static const char mod_lbb[]="lock\0";
static const char mod_mke[]="make\0";
static const char mod_net[]="networks\0";
static const char mod_oss[]="osys\0";
static const char mod_pub[]="public\0";
static const char mod_que[]="queue\0";
static const char mod_rdl[]="riddle\0";
static const char mod_shd[]="shared\0";
static const char mod_trv[]="traverse\0";
static const char mod_usr[]="user\0";
static const char mod_vik[]="vik\0";
static const char mod_wln[]="webpage\0";
static const char mod_xvl[]="xolve\0";
static const char mod_ybn[]="ybin\0";
static const char mod_zen[]="zen0x\0";
static const char *mods[26] ={
	mod_att,mod_bal,mod_ccc,mod_def,mod_env,mod_fmt,
	mod_git,mod_hlv,mod_inc,mod_jab,mod_kei,
	mod_lbb,mod_mke,mod_net,mod_oss,mod_pub,
	mod_que,mod_rdl,mod_shd,mod_trv,mod_usr,
	mod_vik,mod_wln,mod_xvl,mod_ybn,mod_zen
};


static const uns mods_count=arr_size(mods);
#define elem_hash(x) hash8(0,x,strlen(x))

struct __ccc_item {
	struct __ccc_item* nxt;
	ulong __3chash;
	const uchar *__charm;
	const char *__mod;
};
typedef struct __ccc_item ccc;

static ccc kCCC[26];

int __init_3ci(){
	int i_index=0;
	for(; i_index<25;i_index+=1){
		kCCC[i_index].__charm=charms[i_index];
		kCCC[i_index].__mod=mods[i_index];
		kCCC[i_index].__3chash=elem_hash(mods[i_index]);
		kCCC[i_index].nxt=&kCCC[i_index+1];
		printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
	}
	printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
	kCCC[i_index].__charm=charms[i_index];
	kCCC[i_index].__mod=mods[i_index];
	kCCC[i_index].__3chash=elem_hash(mods[i_index]);
	kCCC[i_index].nxt=NULL;
	return i_index;
};

int arch_3ci(){
	return __init_3ci();
};

void log_arcs(){
	ccc *kccc=kCCC;
	while(kccc!=NULL){
		printf("name :: %s\n",kccc->__mod);
		printf("charm :: %s\n",kccc->__charm);
		printf("hash :: %lu\n",kccc->__3chash);
		kccc=kccc->nxt;
	};
};



/********* formatting *********/

char const *__gdelim(fmt_t __gtype) {
	char __delim[3], *_d=((char *)&__delim);
	memset(&__delim,0,3);
	switch(__gtype){
		// Key : Value
		case __keyval__:
			memmove(_d, __ATP_KEY, sizeof(__ATP_KEY));
			break;
		// ENV = Variable
		case __envvar__:
			memmove(_d, __ATP_ENV, sizeof(__ATP_ENV));
			break;
		// Socket := Address
		case __pathmut__:
			memmove(_d, __ATP_KEY, sizeof(__ATP_KEY));
			memmove(_d+sizeof(__ATP_KEY), __ATP_ENV, sizeof(__ATP_ENV));
			break;
		// Variable =: description
		case __fld__:
			memmove(_d, __ATP_ENV, sizeof(__ATP_ENV));
			memmove((_d+sizeof(__ATP_ENV)), __ATP_KEY, sizeof(__ATP_KEY));
			break;
		default: 
			return NULL;
	};
	__delim[2]='\0';
	#ifdef DEBUG
		printf("delimiter is '%s'\n",_d);
	#endif
	return strdup(__delim);
};

char const *__gfmt(fmt_t gt) {
	switch(gt) {
	case __idxr__: return "_Q_Q_Q_\n";
	case hdr_t: return "_U_";
	case __keyval__: return "Q:s:s\n";
	case kvi_t: return "Q:s:s";
	default: return ((void *)(__nofmt__));
	};
};

char const *__generic_fmt(fmt_t g_type,char const *__key, char const *__value){
	ulong klen=str_rwings(__key);
	ulong vlen=str_rwings(__value);
	ulong clen=klen+vlen+3;


	char lbb_field[clen];memset(&lbb_field,0,sizeof(lbb_field));lbb_field[clen]='\0';

	memmove(lbb_field,__key,klen);
	char const *_delim=__gdelim(g_type);
	if(_delim==NULL) {
		#ifdef LOG_ERR
			printf("generic format :: delimiter is null\n");
		#endif
		return NULL;
	}
	ulong __dlen=str_rwings(_delim);
	memmove((lbb_field+klen),_delim, __dlen);
	memmove((lbb_field+klen+__dlen),__value,vlen);

	lbb_field[str_rwings(lbb_field)]='\n';    


	return (char const *)strdup(lbb_field);
};


/********* env handler *********/
static const uns __lbb_idx__=11;
static uns env_hash_0,env_hash_1;

ulong __env_hash(char **__var){
	uns __count=0;
	while(!(NNE(__var[__count]))){
		#ifdef DEBUG
			printf("%s\n",__var[__count]);
		#endif
		__count+=1;
	}
	env_hash_0=hash4(0,&__count,sizeof(uns));
	return (ulong)__count;
};

char const *__h_passcode(char *udef_pass){

	return hashof(2,udef_pass,strlen(udef_pass));
};

char const*__kgev(uchar *__udef_pnop){
	char **env_var=environ;
	char *udef_pnop=(char*)__udef_pnop;
	ulong vcount=0,__c=0, envar_count=__env_hash(env_var), evar_count=envar_count+1;
	ulong __hashes[evar_count];
	void *__hptr=memset(&__hashes,0,(sizeof(ulong)*evar_count));
	do {
		vcount=strlen(env_var[__c]);
		__hashes[__c]=hash8(1,env_var[__c],vcount);
		vcount=0;__c+=1;
	} while(__c<envar_count);
	if(__hashes[envar_count-1]==0){
		return NULL;
	}
	__hashes[envar_count]=hash8(1,udef_pnop,strlen(udef_pnop));
	return hashof(3,__hashes,sizeof(__hashes));
};

void k1_addr(ulong _h8res,ulong _count,char *_kval) {
	ulong __len=11+16+strlen(_kval);
	char __kaddr[__len];
	memset(&__kaddr,0,__len);
	sprintf(__kaddr,"k-%08lx:%lu:=%s\n",_h8res,__cindex,_kval);
	__cindex+=1;
	ulong psize=lbb_print(__kaddr);
};

char const *__keys_hash(char **__var, uns __varc){
	uns _c=0;
	ulong hashes[__varc];
	void *__hptr=memset(&hashes,0,(sizeof(ulong)*__varc));
	while(_c<__varc){
		ulong vclen=strlen(__var[_c]);
		hashes[_c]=hash8(1,__var[_c],vclen);
		#ifdef LBB_0
			k1_addr(hashes[_c],_c,__var[_c]);
		#endif
		_c+=1;
	}
	char const *env_hash_2=hashof(2,__hptr,sizeof(hashes));
	return env_hash_2;
};


/********* utilities *********/

// gets file size in increments ( 8 << n+2 )
fld_t __size_switch(char const *__cpath) {
	ulong _fsize=__fsize(__cpath);
	switch(_fsize){
		case __freader_sz:return f_reader;
		case __fsocket_sz: return f_socket;
		case __ffield_sz: return f_field;
		case __fdir_sz: return f_dir;
		case __fld1_sz: return fld_1;
		case __fld2_sz: return fld_2;
		case __fld3_sz: return fld_3;
		case __fld4_sz: return fld_4;
		default: return 0;
	};
};
// free after
char const *ccopy_to_path(char const *cc, char const *path){
	char __ccc[256];
	memset(&__ccc,0,sizeof(__ccc));
	uns __pathlen=strlen(path),__len=__pathlen+4; //including the '\0' byte
	strcpy(__ccc,path);
	strcpy((__ccc+__pathlen),cc);
	if(__ccc[__len]!='\0'){
		__ccc[__len]='\0';
	};
	return (char const *)strdup(__ccc);
};
// free after 
char const *tochar(ulong inp_u){
	char __[LONG_MAX_COMPUTED_N_DIGITS];
	memset(&__,0,sizeof(__));
	sprintf(__,"%lu",inp_u);
	return (char const *)strdup(__);
};
// gets file size in characters
char const *arch_gfile(char const *__cpath){

	return tochar(__fsize(__cpath));
};
// returns the numbered increment of the file size
fld_sz arch_tfile(char const *__cpath){
	ulong _fsize=__fsize(__cpath), res=0;
	while((_fsize>>3)>8){
		res+=1;
	};
	switch(res){
		case 1:return __freader_sz;
		case 2: return __fsocket_sz;
		case 3: return __ffield_sz;
		case 4: return __fdir_sz;
		case 5: return __fld1_sz;
		case 6: return __fld2_sz;
		case 7: return __fld3_sz;
		case 8: return __fld4_sz;
		default: return 0; 
	};
};
// creates the arch file needed
ulong arch_cfile(fld_t _){
	switch(_){
		case f_reader:return attsize(__8sz(1));
		case f_socket:return attsize(__8sz(2));
		case f_field:return attsize(__8sz(3));
		case f_dir:return attsize(__8sz(4));
		case fld_1:return fldatt(1,__8sz(5));
		case fld_2:return fldatt(2,__8sz(6));
		case fld_3:return fldatt(3,__8sz(7));
		case fld_4:return fldatt(4,__8sz(8));
		default:return 0;
	};
};
// creates a file of a particular increment size
ulong attsize(ulong __size){
	int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
	if(fd==-1){
		printf("cannot create .lbb\n");
		return 0;
	};
	uchar buf[__size];
	memset(&buf,'#',(__size*sizeof(char)));
	uchar *buffer=buf;
	ulong __set=0;
	long int temp=0;
	while(__set<__size){
		temp=pwrite(fd,buf,__size,__set);
		if(temp==-1){
			printf("error pwriting\n");return 0;
		};
		__set+=temp;temp=0;
	};
	return fd;
};
// fills up the file created 
ulong fldatt(uns level,ulong sizeatt){
	int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
	if(fd==-1){
		printf("cannot create .lbb\n");
		return 0;
	};
	ulong lbb_iosize=iosze(arch_filename);
	uns cptr=0,blk=0,chk_blocks=sizeatt&lbb_iosize,nblocks=sizeatt/lbb_iosize;
	if(chk_blocks||!nblocks){
		printf("wrong size.\noctal system handler \n");
		return 0;
	};
	ulong total=0;long int temp=0;
	uchar buf[512];
	memset(&buf,'@',(512*sizeof(uchar)));
	for(;blk<nblocks;){
		temp=pwrite(fd,buf,512,total);
		if(temp==-1){printf("error writing\n"); return 0;}
		total+=temp;temp=0;blk++;
	};
	return fd;
};
// checks the arch permissions for the requested path
ulong arch_fpermissions(char const *__cpath){
	ulong __=__file_x(__cpath);
	return __<2?__+__file_w(__cpath)+__file_r(__cpath):__;
};
// returns the 8b hash if not fld is not zero
ulong arch_foffset(char const *__fpath, ulong __fld){
	return __fld!=0?fhash8(2,__fpath):__fld;
}
// get the entire field+name of `__fname` for `__csize` bytes
static ulong arch_fname(char const *__fname,ulong __csize){
	ulong __res=0;
	ulong _ures=0;
	uchar *__=malloc(__csize);
	if(!(NNE(__))){return 0;}
	memset(__,0,sizeof(__csize));
	size_t step=__csize/3;
	memmove(__,__fname,step);
	char *__idx=(char*)__+step;
	// printf("__ : %p\n__idx : %p\n",__,__idx);
	// printf("%s\n",__idx-3);
	memmove(__idx,":",1);
	uchar *__xer=(uchar *)&__idx+1;
	ulong __packed=0;
	if((__packed=pack(__xer,"L",__csize))!=4){
		printf("error packing L in xer\n"); 
		return 0;
	}
	unpack(__xer,"L",&_ures);
	if(__[__csize]=='\0'){
		printf("%s",__);
		printf("%08lx%08lx",u[0],u[1]);
		printf("k+%lu\n",_ures);
		// *u=hash16(3,__,8);
	};
	return __res;
};
// get this architicture modificiations {{ CERTIFICATE }}
int arch_mods(char const *__3curl){
	ulong fieldname=0, ccc__offset=0;
	char const *__mod,*__crm,*__3c;
	ulong __len=0, __offset=0;
	int c=0; // count
	for(;c<mods_count;c++){
		__mod=(char*)mods[c];
		__crm=(char*)charms[c];
		__3c=ccopy_to_path(__crm,__3curl);
		__len=arch_tfile(__3c);
		__offset+=arch_fpermissions(__3c);
		ccc__offset+=arch_foffset(__3c,__offset);
		fieldname=arch_fname(__crm,ccc__offset);
	}
	return 0;
}
// get required randomness from the c `environ` variable
int arch_cenv(){
	char **__var=environ;
	uns envar_count=__env_hash(__var);
	char const *hvar=__keys_hash(__var,envar_count);
	printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
	return 0;
};

/********* indexing *********/
static ixr_h ___header;
static void *hixr=(void *)&___header;
//expanding args
#define __eixrh(x) x->__size, x->d_count, x->checksum
#define __ihsz(x) x->__size
// unistd flags for `open`&`creat`
#define __ixr_start_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW_ANY)
#define __ixr_access_flags (O_RDWR|O_NOFOLLOW_ANY)
#define __ixr_pmode (S_IRWXU|S_IXGRP|S_IXOTH)


char const *__kaddress(char const *__hash) {
    ulong __len=str_rwings(__hash)+3;
    char temp[__len];memset(&temp, 0, sizeof(temp));
    temp[0]='k';
    switch((__len-3)) {
    case 8:  temp[1]='C'; break; // command 
    case 16: temp[1]='I'; break; // interpreter
    case 32: temp[1]='P'; break; // payload
    default: temp[1]='-'; break; // K-address
    };
    memmove((temp+2), __hash, __len);
    temp[__len]='\0';
    return (char const *)strdup(temp);
};

char const *kaddress(char const *__name, lbb_t __type) {
	ulong __len=str_rwings(__name);
    switch(__type){
    case __unknown: break;
    case __path_sys: return __kaddress(fhashof(0, __name));
    case __proto_call: return __kaddress(hashof(1, __name, __len));
    case __intrp_decl: return __kaddress(hashof(2, __name, __len));
    case __payld_entr: return __kaddress(hashof(3, __name, __len));
    default: break;
    };
    return NULL;
};


void *__erv(char const *__key,char const *__val) {
	ulong __sz=str_rwings(__key)+str_rwings(__val)+5;
	ulong __len=len_ustrze(__sz);
	void *__=malloc(__len);
	memset(__, 0, __len);
	uns psz=pack(__, __gfmt(__keyval__), __cindex, __key, __val);
	return __;
};

ulong __set_next_p(void *__) {
	ulong retres=__set_next((char const *)(__));
	free(__);
	return retres;
};

// irv
char const *__irv(char const *__key, char const *__value) {
	char const *__rv=__generic_fmt(__keyval__, __key, __value);
	ulong irv_len=str_rwings(__rv)+LONG_MAX_COMPUTED_N_DIGITS;
	char irv[irv_len];memset(&irv, 0, sizeof(irv));
	sprintf(irv, "%lu:%s", __cindex, __rv);
	return (char const *)strdup(irv);
};
// increment the cindex
ulong __index_increment() {
	__cindex+=1;
	return __cindex;
};
// set the next header at a new entry
ulong __set_next(char const *__head){
	ulong __len=str_rwings(__head);
	if((__head==NULL)||__len==1){
		return 0;
	};
	long _res=pwrite(__ixr_fd,__head,__len,___offset);

	if(_res!=-1){
		___offset+=__len;
	};
	#ifdef DEBUG
		printf("\nnext -->\n");
		printf("head   :: %s\n", __head);
		printf("length :: %lu\n", __len);
		printf("result :: %ld\n", _res);
		printf("offset ::: %lu\n", ___offset);
	#endif
	return __index_increment();
};
// start the indexer
ulong __idx_start(){
	if(__cindex!=0){
		return 0;
	};
	return __index_increment();
};
// create a xreference for the current indexer
char const *__xreference(char const *__) {

	return hashof(1,(void *)__,str_rwings(__));
};
// generic fmt -> xreference -> setnext
int __index_r(char const *idxnr) {
	char const *_rfmt=__generic_fmt(__keyval__,  __xreference(idxnr), idxnr);
	return __set_next(_rfmt);
};
// irv -> __setnext -> (key, val)
int __index_irn(char const *key, char const *val) {

	return __set_next(__irv(key, val));;
};
// irv -> __setnext -> (key, __xreference)
int __index_ixn(char const *key) {

	return __index_irn(key, __xreference(key));
};
// irv -> __setnext -> (__xreference, caller)
int __index_caller() {
	char const *caller=__getcaller();
	return __index_irn(__kaddress(__xreference(caller)), caller);
};
// irv -> __setnext -> (reference, name)
int __index_point(dpoint *dst) {

	return __index_irn(dst->__ref, dst->__name);
};
// log indexer prototype
void log_ixrh(ixr_h *ixrh) {
	printf("\nindexer head ::\n");
	printf("\tfldsze=%lu", ixrh->__size);
	printf("\tdcount=%lu", ixrh->d_count);
	printf("\tchksum=%lu", ixrh->checksum);
	printf("\n");
};
// read the indexer header \\
OFFSET ALWAYS 0
int __rd_ixrh() {
	ixr_h *ixrh=(ixr_h*)hixr;
	#ifdef LOG_PROCESS
		printf("reading :::\n");
	#endif
	uchar __head[29];ulong __hsz=sizeof(__head);memset(&__head, 0, __hsz);
	ulong __hfsize=fsze(__lbb_indexfile);
	if(__hfsize<__hsz) {
		__hsz=__hfsize;
	};
	int __tempres=pread(__ixr_fd, (void *)__head, __hsz, 0);
	if(__tempres==-1) {
		#ifdef LOG_ERR
			printf("cannot read header\n");
		#endif
		return -1;
	};
	unpack(__head, __gfmt(hdr_t), __ihsz(ixrh));
	ixrh->__size=u[0];
	ixrh->d_count=u[1];
	ixrh->checksum=u[2];
	___offset=(ulong)__tempres;
	#ifdef DEBUG
		printf("attempting %d @indexfile: %lu\n", __tempres, __hfsize);
		log_ixrh(ixrh);
	#endif
	return 0;
};
// write the indexer header \\
OFFSET ALWAYS 0
int __wt_ixrh() {
	ixr_h *ixrh=(ixr_h*)hixr;
	uchar __head[29];ulong __hsz=sizeof(__head);memset(&__head, 0, __hsz);
	#ifdef LOG_PROCESS
		printf("writing :::");
	#endif
	unsigned __temp=pack(__head, __gfmt(__idxr__), __eixrh(ixrh));
	__head[__temp]='\n';
	int _temp=pwrite(__ixr_fd, (void *)__head, __temp, 0);
	if(_temp==-1) {
		#if LOG_ERR
			printf("cannot write header to indexfile\n");
		#endif
		return -1;
	}
	___offset=(ulong)_temp;
	#ifdef DEBUG
		printf("packed %d bytes for idx header\n", __temp);
		printf("wrote %d bytes for idx header\n", _temp);
		log_ixrh(ixrh);
	#endif
	return 0;
};
// obtain header properties { ENVIROMENT }
int refresh_h() {
	ixr_h *ixrh=(ixr_h*)hixr;
	if(!__stres(__lbb_indexfile)) {
		#ifdef LOG_ERR
			printf("indexfile does not exist\n");
		#endif
		return -1;
	};
	ixrh->__size=fsze(__lbb_indexfile);
	ixrh->d_count=__cindex;
	ixrh->checksum=fhash16(1, __lbb_indexfile);
	return 0;
};
// initiate and set memory to zero for header struct
void *__header__() {
	return memset(&___header, 0, sizeof(struct __ixr_h));
};
// start the indexer 
int indexer_start() {
	// if the indexer has not been instantiated but has
	// a different value than the original constant

	if(__ixr_fd!=0x228){
		#ifdef LOG_ERR
			printf("trying to instantiate indexer that is not on %d", 0x228);
		#endif
		return -1;
	};
	if(__stres(__lbb_indexfile)) {
		#ifdef LOG_ERR
			printf("indexer already exists\n");
		#endif
		return -1;
	}
	int ixr_fd=-1;
	ixr_fd=open(__lbb_indexfile, __ixr_start_flags, __ixr_pmode);
	if(ixr_fd==-1){
		#ifdef LOG_ERR
			printf("indexer fd failed on create\n");
		#endif
		return -1;
	};
	__ixr_fd=(ulong)ixr_fd;
	#ifdef DEBUG
		printf("Indexer started :::\n");
		printf(" cfd :: %lu\n",__ixr_fd);
	#endif
	if(refresh_h()) {
		#ifdef LOG_ERR
			printf("cannot refresh header\n");
		#endif
		return -1;
	};
	if(__wt_ixrh()) {
		#ifdef LOG_ERR
			printf("cannot write indexer header\n");
		#endif
		return -1;
	};
	#ifdef DEBUG
		printf("@offset %lu\n",___offset);
	#endif
	return 0;
};
// index any incoming idrs
int __indexer__(char const *idr) {
	if(idr==NULL){
		#ifdef LOG_ERR
			printf("requested to index NULL\n");
		#endif
		return -1;
	};
	if(__ixr_fd==0x228) {
		int ixr_fd=-1;
		ixr_fd=open(__lbb_indexfile, __ixr_access_flags, __ixr_pmode);
		if(ixr_fd==-1){
			#ifdef LOG_ERR
				printf("Cannot open indexer file\n");
			#endif
			return -1;
		};
		__ixr_fd=(ulong)ixr_fd;
		#ifdef DEBUG
			printf("Parsing index file :: %s\n", __lbb_indexfile);
			printf("file descriptor :open::%d\n",ixr_fd);
		#endif
	};
	__header__();
	if(__rd_ixrh()) {
		#ifdef LOG_ERR
			printf("cannot read indexer header\n");
		#endif
		return -1;
	};
	#ifdef DEBUG
		printf("@offset %lu\n",___offset);
	#endif
	return 0;
};

int refer_index(void *__ptr, void *__ref, char *__prname) {
	char *rname=(char *)__ref;
	if(__exact_match(rname, __prname)) {
		printf("exact match\n");
	};

	printf("ptr  : %p\n", __ptr);
	printf("lbbr : %p\n", __ref);
	printf("ref  : %s\n", rname);
	printf("name : %s\n", __prname);
	return 0;
}
// log the format type specifications
void log_fmt_t(fmt_t __format) {
	switch(__format) {
	case __keyval__: __TEXT(Key:Value); break;
	case __envvar__: __TEXT(Enviroment=Spec); break;
	case __pathmut__: __TEXT(Path:=MountPoint); break;
	case __fld__: __TEXT(Field=:Callable); break;
	case __intrprt__: __TEXT(Interpreter<i>); break;
	case __csok__: __TEXT(@Socket); break;
	case __call__: __TEXT(@ATP<i>{p}); break;
	default: __TEXT(Unknown); break;
	};
};
// log the key value as strings
void log_keyvalue(char *key, char *value) {
	__ASCII(key);
	__ASCII(value);
};
// print the corrent way of using the `d-lbb` command
void lbb_usage(){
	__TEXT(Use lbb as :: `d-lbb /path/to/file`);
};
// get the full stats with an `ATP` call \\
ATP = @-Protocol
int get_allstats(char *__mountpoint, char *__socketaddress, char *__fieldshare){
	m_stat mstat;
	int res=get_mstat(__mountpoint,&mstat);
	printf("get mstat res=%d\n",res);
	log_mstat(&mstat);

	s_stat sstat;
	res=get_sstat(__socketaddress,&sstat);
	printf("get sstat res=%d\n",res);
	log_sstat(&sstat);

	k_stat kstat;
	res=get_kstat(__fieldshare,&kstat);
	printf("get kstat res=%d\n",res);
	log_kstat(&kstat);

	return res;
};
// convolute through the file to get
// the fields
char *flds(char const *__fldname) {
	if(__fldname==NULL){
		#ifdef LOG_ERR
			__TEXT(API : flds :: fld is null);
		#endif
		return NULL;
	};
	ulong __fld_n_size=strlen(__fldname);
	#ifdef DEBUG
		printf("flds : fldname :: %s ::: %lu\n", __fldname, __fld_n_size);
	#endif

	m_stat cm_st;
	m_stat *__cm_st=__mstat__(cm_st);
	int res=get_mstat(__fldname,__cm_st);
	if(res==-1){
		#ifdef LOG_ERR
			__TEXT(Field not found);
		#endif
		return NULL;
	};
	#ifdef DEBUG
		log_mstat(&cm_st);
	#endif


	char const *cflds_head=conv_fields(__cm_st);
	if(cflds_head==NULL){
		#ifdef LOG_ERR
			printf("cflds header is null\n");
		#endif
		return NULL;
	};
	// needs to index here

	#ifdef OUTPUT
		printf("'%s'\n",cflds_head);
	#endif

	return strdup(cflds_head);
};

dpoint *__stpoint(char const *st_name, char const *st_val) {
    if(st_name==NULL){
        return NULL;
    };
    ulong __len=str_rwings(st_name);
    dpoint *d_stpoint=(dpoint *)malloc(sizeof(dpoint));

    if(st_name[0]!='k') {
    	d_stpoint->__name=st_name;
		d_stpoint->__ref=kaddress(st_val, get_lbb_type(st_name));
		d_stpoint->__index=__cindex;	
    }
    else {
      switch(st_name[1]){
	    case 'C': break;
	    case 'I': break;
	    case 'P': break;
	    case 'K': break;
	    default: break;
	    };
	    return NULL;
    };
    return d_stpoint;
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

unsigned get_hlevel(char *href) {
    ulong c=str_rwings(href);
    unsigned res=((c)>>3);
    if (res>3){
        return 3;
    };
    return res;
};




#endif



