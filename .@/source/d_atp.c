/// d-atp \\\

#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define DEBUG 1
#define LOG_ERR 1
#endif

#define __AT_DEFINED '@'
#if __AT_DEFINED!=64
	#define AT_DEFINED 64
#else
	#define AT_DEFINED __AT_DEFINED
#endif

#define __P_LEN 8
#define __I_LEN 64
#define __A_LEN 512
#define __API_LEN (__P_LEN+__I_LEN+__A_LEN)

#define __PASS_MAX_C 24
#define __PASS_MID_C 16
#define __PASS_MIN_C 8

#define __read_hash__ ((char const *)hashof(0, "read\0", 4))
#define __write_hash__ ((char const *)hashof(0, "write\0", 4))
#define __execute_hash__ ((char const *)hashof(0, "execute\0", 4))
#define __connect_hash__ ((char const *)hashof(0, "connect\0", 4))
#define __send_hash__ ((char const *)hashof(0, "send\0", 4))
#define __listen_hash__ ((char const *)hashof(0, "listen\0", 4))

#define d_atpointer "@193rfzd193<python3>{ print('hello world') }\0"
#define d_atpoint "@charms/lbb/193rfzd193\0"
#define d_atbase "@charms/\0"
#define lbb_base "@charms/lbb\0"

enum __p_types {
	__nul,
	__unk,
	__ptr,
	__pnt
};
typedef enum __p_types p_type;

struct __into {
	char const *argument;
	p_type arg_t;
};

typedef struct __into into_st;

void *__into__(into_st st) {

	return memset(&st, 0, sizeof(into_st));
};

#define i_argument(i) (i->argument)
#define i_ptype(i) (i->arg_t)

struct __in_pia {
	char pointer[__P_LEN];
	char interpreter[__I_LEN];
	char args[__A_LEN];
};
typedef struct __in_pia pia_st;

void *__pia__(pia_st st) {

	return memset(&st, 0, sizeof(pia_st));
};
#define __p_args(p) ((void *)(&(p.args)))
#define p_args(p) ((char const *)(p.args))
#define _p_args_len(p) ((ulong)(str_rwings(p_args(p))))
#define pst_args(p) ((char const *)(p->args))
#define pst_args_len(p) ((ulong)str_rwings(pst_args(p)))

#define __p_pointer(p) ((void *)(&(p.pointer)))
#define p_pointer(p) ((char const *)((p.pointer)))
#define _p_pointer_len(p) ((ulong)(str_rwings(p_pointer(p))))

#define __p_interpreter(p) ((void *)(&(p.interpreter)))
#define p_interpreter(p) ((char const *)(p.interpreter))
#define _p_interpreter_len(p) ((ulong)(str_rwings(p_interpreter(p))))


char const *__pia_http(pia_st *pst) {
	#ifdef OUTPUT
		printf("starting http parsers (pia) :: \n");
	#endif
	char __[__API_LEN], *__ptr=memset(&__,0,sizeof(__));
	char *__interpt=pst->interpreter;
	ulong __ilen=str_rwings(__interpt);
	memmove(__ptr, __interpt, __ilen);
	#ifdef OUTPUT
		printf("GET /%s", pst->pointer);
		printf("\nInterpreter:%s", pst->interpreter);
		printf("\nArgs:%s\n", pst->args);
	#endif
	return strdup(__);
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


int __check_allowed(char const *__){ 
	int __nallowed[]={'\\', '/', '.'};
	while(*__++){
		for(int i=0;i<arr_size(__nallowed); i++){
			int __cmp=*(__);
			if (__cmp==__nallowed[i]){
				return -1;
			};
		};
	};
	return 0;
};

int check_addr(const char *_addr) {
	
	return __check_allowed(_addr);
};


int check_command(into_st *into, char const **args) {
	char const *__pntr=i_argument(into);
	char const *__arghash=hashof(0, __pntr, 4);
	if(strstr(__read_hash__, __arghash)!=NULL) {
		printf("will read the hash\n");
		return 0;	
	}
	else if (strstr(__write_hash__, __arghash)!= NULL){
		printf("will write a message to hash\n");
		return 0;		
	}
	else if(strstr(__execute_hash__, __arghash)!=NULL) {
		printf("should execute the command \n");
		return 0;
	}
	else if (strstr(__send_hash__,__arghash)!=NULL) {
		printf("will send msg to hash\n");
		return 0;
	}
	else if (strstr(__connect_hash__,__arghash)!=NULL) {
		printf("will try to connect to address\n");
		return 0;
	}
	else if (strstr(__listen_hash__,__arghash)!=NULL) {
		printf("will try to listen on the address\n");
		return 0;
	}
	else {
		printf("none of them matched\n");
		return 1;
	}
}

int __exact_match(char const *_a, char const *_b) {
	ulong __alen=str_rwings(_a), __blen=str_rwings(_b);
	if (__alen!=__blen) {
		#ifdef LOG_ERR
			printf("A&B do not matchn\n");
		#endif
		return 0;
	};
	while(--__alen!=0) {
		if(_a[__alen]==_b[__alen]){
			continue;
		}else {
			return 0;
		};
	};
	return 1;
};

int decode_lbb_addr(into_st *into, char const *args[]) {
	char const *__arg=i_argument(into);
	ulong _lbb_baselen=str_rwings(lbb_base);
	ulong _addr_len=str_rwings(__arg);

	if(check_addr(__arg)==-1){
		#ifdef LOG_ERR
			printf("address is not correctly formatted\n");
		#endif
		return 1;
	};

	ulong _addr_max=_lbb_baselen+_addr_len;
	char __address[_addr_max];
	memset(&__address, 0, sizeof(__address));
	memmove(__address, lbb_base, _lbb_baselen);
	memmove((__address+_lbb_baselen), __arg, _addr_len);
	__address[_addr_max]='\0';

	#ifdef DEBUG
		printf("decoding lbb address :: \n");
	#endif
	if(!__stres(__address)){
		#ifdef LOG_ERR
			printf("address doesn't exist ( %s ) \n", __address);
		#endif
		return 2;
	};
	m_stat cm_st;
	m_stat *__cm_st=__mstat__(cm_st);
	#ifdef DEBUG
		printf("getting mstat :: \n");
	#endif
	get_mstat(__address, __cm_st);
	#ifdef DEBUG
		log_mstat(__cm_st);
	#endif


	return 0;
};

int decode_pointer(into_st *into) {
	#ifdef DEBUG
		printf("decoding pointer :: \n");
	#endif

	char const *arg=i_argument(into);
	ulong __argflen=str_rwings(arg);
	pia_st pst;
	__pia__(pst);

	ulong ptr_name_offset=sep_offset(arg, "<");
	// we increment the `arg` to get rid of the @ & then
	// seperate offset considers the `<` included in str_b4
	// so we decrement the count
	char *__ptrname=str_b4offset(++arg, ptr_name_offset-1);
	memmove(__p_pointer(pst), __ptrname, __P_LEN);
	ulong __pointer_len=_p_pointer_len(pst);
	if(__pointer_len>__P_LEN){
		#ifdef LOG_ERR
			printf("pointer names must be 8 bytes\n");
		#endif
		#ifdef DEBUG
			printf("pointer contents iteration ::\n");
			for(int i=0;i<__pointer_len; i++){
				printf("%d(%c)\n", __ptrname[i],__ptrname[i]);
			}
		#endif
		return 2;
	};

	// recenter the `arg` to be able to extract the correct offset
	char *_ptrcomplete=str_a4offset(--arg, ptr_name_offset);
	ulong intrpt_path_offset=sep_offset(_ptrcomplete, ">");
	char *__interpreter=str_b4offset(_ptrcomplete, intrpt_path_offset);
	memmove(__p_interpreter(pst), __interpreter, __I_LEN);
	ulong __interpreter_len=_p_interpreter_len(pst);
	if(__interpreter_len>__I_LEN){
		#ifdef LOG_ERR
			printf("interpreters always have a maximum of 64 bytes for a reference call\n");
		#endif
		#ifdef DEBUG
			printf("__interpreter :: %s : %lu\n", __interpreter,__interpreter_len);
			printf("offset is @ %lu\n", intrpt_path_offset);
		#endif
		return 3;
	};

	// seperate the bracket insides by seperating the `{`
	// and making use of the fact that `}` should be at end of data inp (eodi)
	char *_intrargs=str_a4offset(_ptrcomplete, __interpreter_len);
	ulong args_path_offset=sep_offset(_intrargs, "{");
	char *__args=str_a4offset(_intrargs, args_path_offset);
	ulong arg_length=str_rwings((char const *)__args);
	ulong __arg_offset=arg_length-1;
	if(__args[__arg_offset]!='}'){
		#ifdef LOG_ERR
			printf("err : malformat :: no closing arg sequence `}Z`\n");
		#endif
		return 1;
	};

	// get the actual args inside the brackets
	char *args=str_b4offset(__args, arg_length);
	memmove(__p_args(pst), args, __A_LEN);
	arg_length=_p_args_len(pst);
	if(arg_length>__A_LEN){
		#ifdef DEBUG
			printf("payloads are restricted to 512bytes max\n");
		#endif
		#ifdef DEBUG
			printf("ptr complete :: %s\n", _ptrcomplete);
			printf("intra arguments :: %s\n", _intrargs);
			printf("start args offset :: %lu\n", args_path_offset);
			printf("main args :: %s\n", __args);
		#endif
		return 4;
	};

	#ifdef DEBUG
		printf("pointer name := %s\n", p_pointer(pst));
		printf("interpreter  := %s\n", p_interpreter(pst));
		printf("arguments    := %s\n", p_args(pst));
	#endif

	__pia_http(&pst);

	return 0;
};

void *__arc_stpoints(ulong __stindex, char const *__stname) {
    dpoint *__point=__arcstp(0x8);
    memset(__point,0,sizeof(ulong));
    __point->__index=__stindex;
    
    ulong length=str_rwings(__stname);
    char *stname=(char *)malloc(length);
    memset(stname,0,length);
    memmove(stname,__stname,length);
    __point->__name=stname;

    char const *__stref=hashof(1, __stname, length);
    ulong ref_length=str_rwings(__stref);
    char *stref=(char *)malloc(ref_length);
    memset(stref,0,ref_length);
    memmove(stref,__stref,ref_length);
    __point->__ref=stref;

    // points_c+=1;
    return (dpoint *)__point;
};

int decode_point(into_st *into) {
	#ifdef DEBUG
		printf("decoding aetherpoint :: \n");
	#endif
	ulong pnt_offset=sep_offset(into->argument, d_atbase);
	char *point=str_a4offset(into->argument, pnt_offset);
	printf("point @%s\n", point);
	return 0;
};


p_type __decode_p(into_st *into) {
	char const *point_buffer=into->argument;
	if(point_buffer==NULL) {
		#ifdef DEBUG
			printf("\ndecode p : { NULL }\n");
		#endif
		into->arg_t=__nul;
		return __nul;
	}
	if(*point_buffer!=AT_DEFINED) {
		#ifdef DEBUG
			printf("\ndecode p : { unknown }\n");
		#endif
		into->arg_t=__unk;
		return __unk;
	};
	for(int i=0; i<str_rwings(d_atbase)-1; i++) {
		if(point_buffer[i]!=d_atbase[i]) {
			#ifdef DEBUG
				printf("\ndecode p : kPtr\n");
			#endif
			into->arg_t=__ptr;
			return __ptr;
		};
	};
	#ifdef DEBUG
		printf("\ndecode p : @point{}\n");
	#endif
	into->arg_t=__pnt;
	return __pnt;
};

int __point_run() {
	void *temp = __arcstp(512);
	return 0;
}
int main(int argc,char const*argv[]) {
#define __ARGC__ argc
#define __ARGV__ *argv
__LBB_START__
	into_st into;
	__into__(into);
	into.argument=argv[1];
	p_type typepoint=__decode_p(&into);
	switch(typepoint){
	case __nul:
		return __point_run();
	case __unk: 
		if(argc>=3){
			return decode_lbb_addr(&into, &argv[2]);
		}
		else if (argc>=2) {
			return check_command(&into, argv);
		};
		#ifdef LOG_ERR
			printf("unknown command\n");
		#endif
		#ifdef DEBUG
			printf("usage :: %s addr command\n", argv[0]);
		#endif
		return 1;
	case __ptr: return decode_pointer(&into);
	case __pnt: return decode_point(&into);
	default: return 1;
	};
INDEX_END("\n");
};









