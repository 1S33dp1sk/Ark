/// UDEF \\\
user defined interaction (input/output)

#include "2c/_h512.h"

#define __PASS_MAX_C 24
#define __PASS_MID_C 16
#define __PASS_MIN_C 8


#define DEBUG 1
#define LOG_ERR 1


#define d_atpointer "@193rfzd193<python3>{ print('hello world') }"
#define d_atpoint "@charms/lbb/193rfzd193"
#define d_atbase "@charms/"
#define lbb_base "@charms/lbb"

void __udef_inp() {
	system("@cls||clear");
	printf("\t\t\tWelcome to 'd-cloud'\n\n");
};


char const *__getcaller(){

	return (char const *)__FILE__;
};

enum __p_types {
	__nul,
	__unk,
	__ptr,
	__pnt
};
typedef enum __p_types p_type;

#define __AT_DEFINED '@'
#if __AT_DEFINED!=64
	#define AT_DEFINED 64
#else
	#define AT_DEFINED __AT_DEFINED
#endif

struct __into {
	char const *argument;
	p_type arg_t;
};

typedef struct __into into_st;

void *__into__(into_st st) {

	return memset(&st, 0, sizeof(into_st));
}


#define i_argument(i) (i->argument)
#define i_ptype(i) (i->arg_t)


#define __P_LEN 8
#define __I_LEN 64
#define __A_LEN 512

ulong str_rwings(char const *__) {
	ulong temp=0;
	do {
		if(*__!='\0'){
			temp+=1;
		};
	}while(*__++);
	return temp;
};

struct __in_pia {
	char pointer[__P_LEN];
	char interpreter[__I_LEN];
	char args[__A_LEN];
};
typedef struct __in_pia pia_st;

void *__pia__(pia_st st) {

	return memset(&st, 0, sizeof(pia_st));
};

struct __at_pa {
	ulong p_len;
	char p_at[512];
};

#define __p_args(p) ((void *)(&(p.args)))
#define p_args(p) ((char const *)(p.args))
#define _p_args_len(p) ((ulong)(str_rwings(p_args(p))))

#define __p_pointer(p) ((void *)(&(p.pointer)))
#define p_pointer(p) ((char const *)((p.pointer)))
#define _p_pointer_len(p) ((ulong)(str_rwings(p_pointer(p))))

#define __p_interpreter(p) ((void *)(&(p.interpreter)))
#define p_interpreter(p) ((char const *)(p.interpreter))
#define _p_interpreter_len(p) ((ulong)(str_rwings(p_interpreter(p))))


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


#define __read_hash__ hashof(0, "read\0", 5)
#define __write_hash__ hashof(0, "write\0", 6)
#define __execute_hash__ hashof(0, "execute\0", 8)

#define log_var printf("wow called\n nice\n")

#define __log *log_var


int __get_command(char const *args[]) {
	char const *__c_arg=args[0];
	ulong __carglen=str_rwings(__c_arg);
	char const *__c_hash=hashof(0, __c_arg, __carglen);

	return log_var;
};


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
	int __cmd=__get_command(args);
	// void *cmd = (void *)&__cmd;
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

	return 0;
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
			printf("point buffer is null\n");
		#endif
		into->arg_t=__nul;
		return __nul;
	}
	if(*point_buffer!=AT_DEFINED) {
		#ifdef DEBUG
			printf("point buffer is not known\n");
		#endif
		into->arg_t=__unk;
		return __unk;
	};
	for(int i=0; i<strlen(d_atbase); i++) {
		if(point_buffer[i]!=d_atbase[i]) {
			#ifdef DEBUG
				printf("point buffer is a pointer\n");
			#endif
			into->arg_t=__ptr;
			return __ptr;
		};
	};
	#ifdef DEBUG
		printf("point buffer is a point\n");
	#endif
	into->arg_t=__pnt;
	return __pnt;
};


int main(int argc,char const*argv[]) {
	into_st into;
	__into__(into);
	into.argument=argv[1];
	p_type typepoint=__decode_p(&into);
	switch(typepoint){
	case __unk: 
		if(argc>=3){
			return decode_lbb_addr(&into, &argv[2]);
		};
		#ifdef LOG_ERR
			printf("unknown command\n");
			printf("usage :: udef addr command\n");
		#endif
		return 1;
	case __ptr: return decode_pointer(&into);
	case __pnt: return decode_point(&into);
	default: return 1;
	};

	
};









