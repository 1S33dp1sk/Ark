/// machine file \\\
K512-architecture 

#ifndef __KARCH__H
	#define __KARCH__H 1
/**
* nai =: native aether interface
* 
* The following are used as outputs
* DEBUG		#used to display most sub-processes happening on nai
* OUTPUT	#used to display any output on nai
* PROCESS	#used to display the names of the sub-processes being executed on nai
* LOG_ERR	#used to display the errors on nai
**/
	#define OUTPUT 1
	#define PROCESS 1
	#define DEBUG 1
	#define LOG_ERR 1
	#ifndef __UTYPES__H
		#include "utypes.h"
	#endif
	#ifndef __ANETSTD__H
		#include "standard.h"
	#endif
	#ifdef __HBAR__H
		#include "hbar.h"
	#endif
	#ifdef __ENK__H
		#include "enk.h"
	#endif
#endif


#ifndef __KARCH_D512__

/************************ h-constants ************************/

#ifndef __H512__C
	/********* types *********/
	static __ul u;

	static ulong __cindex=0;
	static ulong __ixr_fd=0x228;
	static ulong ___offset=0;
	static ixr_h ___header;
	static ulong env_hash_0;
	/********* unistd *********/

	extern char **environ;

	static const char *__http_protocol_version="HTTP/1.1";
	static const char *__http_base="P S R\r\n";
	static const char *__http_request_base="M P V\r\n";
	static const char *__http_response_base="B S R\r\n";
	static const char *__head_fmt="_Q_Q_Q_\n";
	static const char *__value_fmt="_Q:s:s_\n";
	static const char *__file_fmt="_Q:s:s#Q_\n";
	static const char *__dprg_fmt="_Q:s>s<s$s_\n";
	static const char *__fld_fmt="_Q:s@s=s+h_\n";
	static char *__http_get="GET";
	static char *__http_post="POST";
	static char *wss_key_h="Sec-WebSocket-Key: ";
	static char *wss_acc_h="Sec-WebSocket-Accept: ";		
	static char *__reph="HTTP/1.1 200 OK\r\nContent-Type: text;\r\nContent-Length: 10\r\n\r\nHello Raed\r\n";
	static char *__upgrade="HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nCache-Control: no-cache\r\nSec-WebSocket-Protocol: @-Protocol\r\n";
	static char *__cwss="258EAFA5-E914-47DA-95CA-C5AB0DC85B11\0";
	#define __H512__C 1
#endif


/************************ h-defintions ************************/

#ifndef __H512__D
	#define __Karch_512__ 4096
	#define LONG_MAX_COMPUTED_N_DIGITS 21 //logb(x) = loga(x) / loga(b)
	#define __MA__S 0x000000000000000000000008
	#define __GS__S __MA__S<<3
	#define __LO__F __GS__S<<3
	#define __UN__F __LO__S<<3
	#define ARC_GENERIC(x) (ulong)((1<<(x*3)))
	#define __dPER while(1!=1);

	#define shard_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW_ANY)
	#define shard_share (S_IRWXU|S_IWGRP|S_IXGRP|S_IWOTH|S_IXOTH)
	#define shard_nolock (O_RDWR)
	#define shard_lock_reader (O_RDONLY)
	#define shard_lock_writer (O_WRONLY)


    #define FMT_ASCII_SPEC(__) \
        _Generic((__), \
            int: "%d",\
            uns: "%u",\
            char: "%c",\
            long: "%ld",\
            ulong: "%lu",\
            utlong: "%llu",\
            char *: "%s",\
            char const *:"%s",\
            long long: "%lld",\
            default: "%x")

    #define FMT_HEXA_SPEC(__) \
        _Generic((__), \
            char: "c",\
            unsigned char: "C",\
            short: "h",\
            int: "h",\
            uns: "H",\
            long: "l",\
            ulong: "L",\
            long long: "q",\
            utlong: "Q",\
            char *: "s",\
            default: "_")
	#define _C_TYPES(x) \
	    _Generic((x), \
	        signed char: "char", \
	        unsigned char:"uchar", \
	        int:"int", \
	        unsigned int:"uns", \
	        long int:"ulong", \
	        unsigned long int:"ulong", \
	        long long int:"utlong", \
	        unsigned long long int:"utlong", \
	        char *:"string",\
	        void *:"pointer",\
	        default:"NULL")

    #define NOFB_TYPE(x) \
        _Generic((x), \
            signed char: (char)x, \
            unsigned char:(uchar)x, \
            int:(int)x, \
            unsigned int:(uns)x, \
            long int:(ulong)x, \
            unsigned long int:(ulong)x, \
            long long int:(utlong)x, \
            unsigned long long int:(utlong)x, \
            default:NULL)
    
    #define LBB_OUT_FMT(__) \
        _Generic((__), \
            void * : void *,\
            char * : char *,\
            const char *: const char *,\
            default: ulong*)

    #define IXR_FMT(__) _Generic((__), \
		char 		: "c",\
		char*		: "s",\
		char const*	: "s",\
		int*		: "h",\
		uns*		: "H",\
		long*		: "l",\
		ulong*		: "L",\
		utlong*		: "Q",\
		default 	: "_")

    #define IXR_ARG(__) _Generic((__), \
		char*					: (char*)x,\
		char const *			: (char const *)x,\
		unsigned char*			: (uchar*)x,\
		int*					: (int*)x,\
		unsigned int*			: (uns*)x,\
		long int*				: (ulong*)x,\
		unsigned long int*		: (ulong*)x,\
		long long int*			: (utlong*)x, \
		unsigned long long int*	: (utlong*)x, \
		default					: NULL)

	#define __lbb_call_generic(__) \
		_Generic((__),\
			ptr_st:"lbb command",\
			intr_st: "lbb interpreter",\
			payld_st: "lbb payload",\
			cis_st: "lbb field",\
		default:"lbb call")

	#define __lbb_resp_generic(__) \
		_Generic((__),\
			ptr_st*:"command response",\
			intr_st*: "interpreter reply",\
			payld_st*: "payload retrieve",\
			cis_st*: "field return",\
		default:"unknown args")

	#define __lbb_generic(__) \
		_Generic((__),\
			char[8]:(ptr_st *) &__,\
			char[64]:(intr_st *) &__,\
			char[512]:(payld_st *) &__,\
			char[4096]:(cis_st *) &__,\
			default:"unknown")

	#define __lbb_typd(__) \
		_Generic((__),\
			ptr_st * : char[8],\
			intr_st * : char[64],\
			payld_st * : char[512],\
			cis_st * : char[4096],\
			default:"unknown")

	#define fmt_out(x) log_str(_Generic((x), \
		num:(char const *)(x.__),\
		str:(char const *)(x.__),\
		arr:(char const *)(x.__),\
		default:__NADA__\
	));

	#define out(x) fmt_out(x);

	#define out_fmt(x) log_str(_Generic((x), \
		num:"number",\
		str:"string",\
		arr:"array",\
		default:"dPRG"\
	));

    #define OUT_ENK_H(fd,x) do { \
        char _[ATP_SPEC_SIZE];uchar __[ATP_BUFFER_SIZE];\
        memset(&_,0,sizeof _);memset(&__,0,sizeof __);\
        snprintf(_,sizeof _,"%s",FMT_HEXA_SPEC(x));\
        ulong pack_sz=pack(__,_,x);\
        if(pack_sz>0){write(fd,__,pack_sz);}\
    } __dPER

    #define OUT_ENK_A(fd,x) do { \
        char __[4096];\
        memset(&__,0,sizeof __);\
        snprintf(__,sizeof __,"%s\n", FMT_ASCII_SPEC(x));\
        dprintf(fd,__,(x));\
    } __dPER
	#define __vile ((void const *)(__FILE__))
	#define __caller_namelen (ulong)str_rwings(__FILE__)
	#define __ASCII(x) OUT_ENK_A(0,x)
	#define __TEXT(x) OUT_ENK_A(0,#x);
	/**
	** NNE : x :: true if x is not 0x0000
	**/
	#define NNE(v) v==0x0000?0x01:0x00
	// call result sucessful 
	#define CALL_SUCC(x) x==(ulong)0?1:0
	// call result instantiate
	#define CALL_INST(x) x==(ulong)1?1:0
	// call result not sucessful
	#define CALL_NSUC(x) x==(ulong)-1?1:0
	// call result jump
	#define CALL_NEXT(x) ((ulong)(x<(ulong)-1?x>1?1:x:0))
	#define __dPER while(1!=1);
	#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
	#define elem_hash(x) hash8(0,x,strlen(x))
	#define wsize(x,y) (sizeof(x)*y)
	#define ulong_wsize(x) wsize(ulong, x)
	#define str_wsize(x) wsize(char, x)
	#define ustr_wsize(x) wsize(uchar, x)
	#define vcontent(x) ((void const **)x)
	#define __typed_lbbfile_name(x) arch_tfile_lbb(x)
	#define typed_lbbfilename(x) #__typed_lbbfile_name(x)
	#define s_sign "+"
	#define s_lbbfile(x) s_sign##x

	#define LBB_READER(x)		x^0010000
	#define LBB_DIRECTORY(x)	x^0040000
	#define LBB_FIELD(x)		x^0100000
	#define LBB_SOCKET(x)		x^0140000
	#define ARCH_MADE(x)		x^0000700
	#define ARCH_SAVE(x)		x^0000007


	#define __H512__D 'k'
#endif


/************************ h-naming ************************/

#ifndef __H512__N
	// log
	void log_str(char const *string);
	void log_dpoint(d_point *dst_point);
	void log_sstat(s_stat *sfile);
	void log_mstat(m_stat *mfile);
	void log_esptr(ulong *ptr);
	void log_process_ids(ulong p_pid, ulong c_pid);
	void log_process_schema(ulong p_pid, ulong c_pid);
	void log_at_protoname(atp_t atp_name);
	void log_ixrh(ixr_h *ixrh);
	void log_socket(aip_sock *sock);
	// arch
	int __numchar(char c);
	int __smchar(char c);
	int __capchar(char c);
	int __atchar(char c);
	char const *__getcaller();
	// file
	int __stres(char const *__path);
	ulong __fsize(char const *__path);
	ulong __iosize(char const *__path);
	ulong __inodenum(char const *__path);
	ulong __dmode(char const *__path);
	ulong __file_r(char const *__path);
	ulong __file_w(char const *__path);
	ulong __file_x(char const *__path);
	int __dgetfd(char const *__path);
	// strings
	ulong __rwings(void const *__);
	ulong str_rwings(char const *__str);
	int spaces_and_tabs(char *__str);
	int tabs_and_spaces(char const *__str);
	ulong __tonum(char const *__path);
	ulong tonum(int i);
	char const *num2char(ulong num_in);
	char *__stn(char const *__str, ulong __len);
	void *__arg__(char const *file_args);
	int __exact_match(char const *__str_a, char const *__str_b);
	int __sep_atoff(char const *__str, char const *__sep);
	char *str_b4eoffset(char const *__str, ulong __offset);
	char *str_b4offset(char const *__str, ulong __offset);
	char *stn_b4offset(char const *__str, ulong __offset);
	char *str_a4woffset(char const *__str, ulong __offset);
	char *str_a4offset(char const *__str, ulong __offset);
	char const *expand_atoffset(char const *__str, char const *__expantion, ulong __offset);
	char const *expand(char const *__str, char const *__expantion, ulong __offset);
	char const *__combine_str(char const *__str_1, char const *__str_2);
	ulong str_cdelims(char const *__str, char const *__delim);
	ulong arr_cdelims(char const *__str);
	ulong sep_offset(char const *__str, char *__seperator);
	

	#define __H512__N
#endif
// CDN (:

/************************ h-logging ************************/

#ifndef __H512__L

	void log_str(char const *__) {
		write(0,__,str_rwings(__));
		write(0,"\n",1);
	};

	void log_dpoint(d_point *dst_point) {
		printf("dst point :: \n");
		printf("@%lu\n", dst_point->c_index);
		printf("name :%s\n",dst_point->c_name);
		printf("ref  :%s\n",dst_point->c_ref);
	};

	void log_sstat(s_stat *sfile){
		printf("dcloud : ATP :: dist ::: shared\n");
		printf("path	= %s\n", sfile->s_path);
		printf("iploc	= %s\n", sfile->s_ipv);
		printf("port	= %s\n", __s_port);
		printf("addr	= %s\n", sfile->s_addr);
		printf("term	= %s\n", sfile->s_term==0?"PUBLIC":"PRIVATE");
	};

	void log_mstat(m_stat *mfile){
		printf("dcloud : ATP :: dist ::: mounted\n");
		printf("path	= %s\n", mfile->m_path);
		printf("nodenum	= %lu\n", mfile->m_inn);
		printf("size	= %lu\n",mfile->m_size);
		printf("mode	= %lu\n",mfile->m_mode);
		printf("blkio	= %lu\n",mfile->m_blksz);
	};

	void log_esptr(ulong *esptr) {
		printf("dcloud : K :: esptr\n");
		ulong c=0;
		do {
			printf(":%lu=%lu\n",c,esptr[c]);c+=1;
		}
		while(*esptr++);
	};

	void log_process_ids(ulong p_pid, ulong c_pid) {
	   printf("process ids ::\n");
	   printf("p.pid    =%lu\n",p_pid);
	   printf("c.pid    =%lu\n",c_pid);
	};

	void log_process_schema(ulong p_pid, ulong c_pid) {
	    printf("p_pid :: %lu",p_pid);
	    printf("\nc_pid :: %lu",c_pid);
	    printf("\nsuccess=%d\tnsucess=%d\n",CALL_SUCC(c_pid),CALL_NSUC(c_pid));
	    printf("call next ? %lu\n",CALL_NEXT(c_pid));
	};

	void log_at_protoname(atp_t __atpname) {
		switch(__atpname) {
		case atp_get: 			printf("ATP : get       ::\b"); break;
		case atp_set: 			printf("ATP : set       ::\b"); break;
		case atp_return: 		printf("ATP : return    ::\b"); break;
		case atp_retain:		printf("ATP : retain    ::\b"); break;
		case atp_retreive: 	printf("ATP : retreieve ::\b"); break;
		case atp_dcloud:		printf("ATP <dcloud> :::\n"); break;
		default:					printf("{Unknown}\n"); break;
		};
	};
	
	void log_ixrh(ixr_h *ixrh) {
		// log indexer prototype
		printf("\nindexer head ::\n");
		printf("\tfldsze=%lu", ixrh->__size);
		printf("\tdcount=%lu", ixrh->d_count);
		printf("\tchksum=%lu", ixrh->checksum);
		printf("\n");
	};

	void log_socket(aipsock *sock) {
		aip_sockaddr info=__sock_addr(sock_aip_to_sa(sock));
		printf("socket @%s\n",info.ascii_addr);
	};


	//// log the format type specifications
	//void log_fmt_t(fmt_t __format) {
	//	switch(__format) {
	//	case __keyval__: __TEXT(Key:Value); break;
	//	case __envvar__: __TEXT(Enviroment=Spec); break;
	//	case __pathmut__: __TEXT(Path:=MountPoint); break;
	//	case __fld__: __TEXT(Field=:Callable); break;
	//	case __intrprt__: __TEXT(Interpreter<i>); break;
	//	case __csok__: __TEXT(@Socket); break;
	//	case __call__: __TEXT(@ATP<i>{p}); break;
	//	default: __TEXT(Unknown); break;
	//	};
	//};

	// log the key value as strings
	void log_keyvalue(char *key, char *value) {
		__ASCII(key);
		__ASCII(value);
	};
	// print the corrent way of using the `d-lbb` command
	void lbb_usage(){
		__TEXT(Use lbb as :: `d-lbb /path/to/file`);
	};


	#define __H512__L
#endif



/************************ d-files ************************/

#ifndef _D_FILE
	#define _D_FILE 1
	#define d512_read(d,o) (char const *)__readb(512,fd,fo*512)
	#define sz8(x)		((ulong)__8sz(x))
	#define fsze(x)		((ulong)__fsize(x))
	#define iosze(x)	((ulong)__iosize(x))
	#define dmde(x)		((ulong)__dmode(x))
	#define inn(x)		(ulong)__inodenum(x)
	#define status(x) __statusof(x)
	#define stres(x) __stres(x)
    #define len_ustrze(x) (((ulong)x)*(sizeof(uchar)))
	#define ixr_h_size(x) (x.__size)
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)


	void *__statusof(char const *__path) {
	    struct stat __;
	    memset(&__,0,sizeof(struct stat));
	    if(stat(__path,&__)==0){
	        return (void *)__path;
	    }
	    return NULL;
	};

	int __stres(char const *__path){
		int __res=access(__path, F_OK);
		#ifdef DEBUG
			printf("checking cpath :: %s\n", __path);
			printf("result of access = %d\n", __res);
		#endif
		return __res==0;
	};

	ulong fsize_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_size;
	};

	ulong iosize_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_blksize;
	};

	uns dmode_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_mode;
	};

	ulong inn_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_ino;
	};

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

	int __dgetfd(char const *__fpath) {
		return open(__fpath, __lock_reader);
	};

#endif




/************************ d-strings ************************/

#ifndef _D_STRING
	#define _D_STRING 1

	ulong __rwings(void const *__) {
		char const *__p=(char const *)__;
		ulong __c=0;
		do {
			if(*__p!='\0'){
				__c+=1;
			};
		}while(*__p++);
		return __c;
	};

	ulong str_rwings(char const *__str) {
		ulong temp=0;
		if(__str!=NULL){
			do {
				if(*__str=='\0'){
					break;
				};
				temp+=1;
			}while((*__str++)&&(temp<4096));
		};
		#ifdef DEBUG
			printf("str : %s =: %lu\n",(char const *)(__str-temp),temp);
		#endif
		return temp;
	};

	int spaces_and_tabs(char *__word){
	/**
	 * count spaces and tabs in `word`
	**/
		int count=0, x=0;
		while(__word[x]!='\0'){
			if(__word[x]==' '||__word[x]==' '){
				count+=1;
			};
			x+=1;
		};
		return count;
	};

	int tabs_and_spaces(char const *__word){
	/**
	 * count spaces and tabs until `word`
	**/
		int count=0;
		while(__word[count]==' '||__word[count]==' '){
			count+=1;
		};
		return count;	
	};

	ulong __tonum(char const *__var){
		ulong d=1,__c=0,res=0,__len=str_rwings(__var);
		int c;
		if(__var[__len]=='\0'){
			while(__numchar(__var[__c])){
				d*=10;
				__c+=1;
			};
			__c=0;
			if(d>=10){d/=10;}
			#ifdef DDEBUG
				printf("digits count :: %lu\n",d);
			#endif
			while(__numchar(__var[__c])){
				res+=(d*(__var[__c]-0x30));
				__c+=1;d/=10;
			}
			#ifdef DDEBUG
				printf("result is :: %lu\n", res);
			#endif
		};
		return res;
	};

	ulong tonum(int __i){
		ulong res=0;
		if(__i>0){
			res+=__i;
			return res;
		};
		return 0;
	};

	char const *num2char(ulong snum_in){
		char __[21];
		memset(&__,0,sizeof(__));
		sprintf(__,"%lu",snum_in);
		return (char const *)strdup(__);
	};

	char const *s_num2char(long snum_in) {
		char __[21];
		memset(&__, 0, sizeof(__));
		if(snum_in>0) {
			sprintf(__, "+%lu", snum_in);
		}
		else {
			sprintf(__, "-%lu", snum_in);
		};

		return (char const *)__;
	};

	char *__stn(char const *__word, ulong __len) {
		ulong rc=0, c=0;
		char temp[__len];memset(&temp, 0, sizeof(__word));
		do {
			if((__word[c]==' ')||(__word[c]=='	')||(__word[c]=='\n')){
				c+=1;
			}
			else {
				temp[rc]=__word[c];
				rc+=1;c+=1;
			};
		}while(c<=__len);
		temp[rc]='\0';
		return strdup(temp);
	};

	void *__arg__(char const *fc) {
		int tas=tabs_and_spaces(fc);
		printf("Arg : %c\n",*(fc+1));
		if(*(fc+1)=='"'){
			return "string";
		};
		return "n";
	};
	
	int __exact_match(char const *__a, char const *__b) {
		ulong __alen=str_rwings(__a), __blen=str_rwings(__b);
		if (__alen!=__blen) {
			#ifdef DEBUG
				printf("A&B lengths do not match\n");
			#endif
			return 0;
		};
		while(--__alen!=0) {
			if(__a[__alen]==__b[__alen]){
				continue;
			}else {
				return 0;
			};
		};
		return 1;
	};

	int __sep_atoff(char const *string, char const *seperator) {
	/**
	 * find the first `seperator` in `string`
	**/
		long x=0,y=0,len_count=0,offset_at=-1;
		while(string[x]!='\0'){
			if(string[x]==seperator[y]){
				while(seperator[y]==string[y+x]){
					y+=1;
				};
				if(seperator[y]=='\0'){
					offset_at=x;
				}
				else{
					y=0;
				};
			};
			x+=1;
		};
		if(offset_at==-1){
			return -1;
		};
		return offset_at;
	};

	char *str_b4eoffset(char const *string, ulong offset) {
		char temp[offset];
		memset(&temp,0,sizeof temp);
		memmove(temp, ++string, offset-2);
		return strdup(temp);
	};

	char *str_b4offset(char const *string, ulong offset) {
		char temp[offset];
		memset(&temp,0,sizeof temp);
		snprintf(temp,offset,"%s",string);
		return strdup(temp);
	};

	char *stn_b4offset(char const *string, ulong offset) {

		return __stn(string, offset);
	};

	char *str_a4woffset(char const *string, ulong offset){
		ulong flen=str_rwings(string);//to offset the offset 
		if(flen<offset){return NULL;}
		ulong slen=flen-offset;
		char temp[slen];
		memset(&temp,0,sizeof temp);
		snprintf(temp,slen,"%s",(string+offset));
		return strdup(temp);
	};

	char *str_a4offset(char const *string, ulong offset){
		ulong flen=str_rwings(string)+1;//to offset the offset 
		if(flen<offset){return NULL;}
		ulong slen=flen-offset;
		char temp[slen];
		memset(&temp,0,sizeof temp);
		snprintf(temp,slen,"%s",(string+offset));
		return strdup(temp);
	};

	char const *expand_atoffset(char const *__str, char const *expantion, ulong __offset) {
		#ifdef DEBUG
			printf("@index:%lu\n", __offset);
		#endif
		ulong __str_rwings=str_rwings(__str);
		ulong __explen=str_rwings(expantion);
		ulong __len=__str_rwings+__explen+1;
		char __[__len];memset(&__, 0, sizeof(__));
		memmove(__, __str, __offset);
		memmove((__+__offset), expantion, __explen);
		memmove((__+__offset+__explen), (__str+__offset+1), (__str_rwings-__offset));
		return (char const *)strdup(__);
	};

	char const *expand(char const *__str, char const *expantion, ulong __offset) {
		ulong __str_rwings=str_rwings(__str);
		ulong __explen=str_rwings(expantion);
		ulong __len=__str_rwings+__explen+1;
		char __[__len];memset(&__, 0, sizeof(__));
		memmove(__, __str, __offset);
		memmove((__+__offset), expantion, __explen);
		memmove((__+__offset+__explen), (__str+__offset), (__str_rwings-__offset));
		return (char const *)strdup(__);
	};

	char const *__combine_str(char const *str1, char const *str2) {
		ulong _lstr1=str_rwings(str1),_lstr2=str_rwings(str2);
		ulong __len=_lstr1+_lstr2+1;
		char __[__len], char *__p=&__;
		memset(__p, 0, sizeof(__));
		__[__len]='\0';
		memmove(__p, str1, _lstr1);
		memmove((__p+_lstr1), str2, _lstr2);
		return strdup(__);
	};

	ulong str_cdelims(char const *__str, char const *__dlm) {
		ulong count=0, temp=0, length=str_rwings(__str);
		char *substr=(char *)__str;
		d_str *subs;		
		while((temp=__sep_atoff(substr, __dlm))>=1) {
			if(!count){
				count=1;
				subs=(d_str*)malloc(sizeof(d_str));
				subs->__=str_a4offset(substr, temp);
				subs->__len=str_rwings(substr);
				subs->__next=NULL;
			}
			else if (count) {
				count+=1;
				substr=str_a4offset(substr, temp);
				++substr;subs++;
				printf("type     :%c: %s\n\n",*substr, (char *)__arg__(substr));
					// string(temp, substr)
				// subs->__next=&temp;
			}else {
			
			};
		};
		return count;
	};

	ulong arr_cdelims(char const *__str) {
		// add 1 more to create an array
		// #err if more elements than arg_count specifies
		ulong arg_count=str_cdelims(__, ',')+1;
		return arg_count;
	};

	ulong sep_offset(char const *string, char *seperator) {
		printf("string : %s\n", string);
		int tempres=__sep_atoff(string, seperator);
		if(tempres==-1){
			#ifdef LOG_ERR
				printf("unsigned call\n");
				_exit(1);
				// #error "should not return"
			#endif
			return 0;
		}
		else if (!tempres) {
			return 0;
		} else {
			return (ulong)tempres;
		};
	};
#endif



/************************ d-architicture ************************/

#ifndef _D_ARCH
	#define _D_ARCH 1
	#define d_charms "@charms/d.\0"
	#define d_lbb "@charms/d.lbb\0"
	#define d_atlbb "@charms/d.lbb/.lbb\0"
	#define arch_filename d_atlbb
	#define d_sep ":\0"

	int __nullchar(char __c) {
		if(__c==0x00) {
			return 1;
		};
		return 0;
	};

	int __numchar(char __c){   
		// check if char is a number
		if( (__c>=0x30)&&(__c<=0x39)){
			return 1;
		};
		return 0;
	};

	int __smchar(char __c) {
		// check if char is a small cap alphabet
		if((__c>=0x61)&&(c<=0x7a)){
			return 1;
		};
		return 0;
	};

	int __capchar(char __c) {
		// check if char is a large cap alphabet
		if((__c>=0x41)&&(c<=0x5a)){
			return 1;
		};
		return 0;
	};

	int __atchar(char __c) {
		// check if char is an '@' character
		if(__c==0x40){
			return 1;
		};
		return 0;
	};

	int __sepchar(char __c) {
		if(__c==0x3a) {
			return 1;
		};
		return 0;
	};

	int __delimchar(char __c) {
		if(__c==__os_delim) {
			return 1;
		};
		return 0;
	}

	char const *__getcaller(){
		// get the calling file
		return (char const *)__FILE__;
	};

	int __entry_valid(char const *__) {
		char c=*__;
		if(!__atchar(c)){
			#ifdef DEBUG
				printf("entries start with @\n");
			#endif
			return 0;
		};
		do {
			c=*__++;
			if ((__nullchar(c))||((!__numchar(c))&&(!__smchar(c))&&(!__capchar(c)))) {
				return 0;
			};
		}while(c);
		return 1;
	};

	ulong content_count(char const **__content) {
		ulong c=0;
		while(__content[c]) {
			c+=1;
		};
		return c;
	};


	/********* base8 *********/

	ulong lexical_args(void **__vars) { 
		char const *temp = (char const *)__vars;
		printf("vars : %s\n", temp);
		ulong arg_count=arr_cdelims(temp, ",");
		return arg_count;
	};

	ulong __size8(int _){
		if(_<0){
			return 0;
		}
		else {
			ulong __=1;
			do {
				__*=8;
				_--;
			}while(_>0);
			return __;
		}
	};

	ulong lbb_type2size(lbb_t lbb_type){
	
		return lbb_size(lbb_type);
	};


	/********* fld *********/

	int __check_fld(char const *__path, lbb_t __path_type){
		if(fsze(__path)==lbb_type2size(__path_type)){
			return 0;
		};
		return 1;
	};


	/********* mods *********/

	char const *__mod_call(char const *__mname) {
		char const *__caller=__getcaller();
		ulong __clen=str_rwings(__caller), __flen=str_rwings(__mname);
		ulong c_length=__clen+__flen, c_sep=sep_offset(__caller, d_charms);
		
		char charmcall[c_length];
		void *cc_ptr=memset(&charmcall, 0, sizeof(charmcall));

		if((!c_sep)||(__flen<3)) {
			#ifdef DEBUG
				printf("f:length=%lu, c:sep=%lu\n", __flen, c_sep);
			#endif
			return NULL;
		};

		memmove(cc_ptr, __caller, c_sep);
		memmove((cc_ptr+c_sep), __mname, __flen);

		#ifdef DEBUG
		#endif
		printf("charmcall :: %s\n", charmcall);

		return strdup(charmcall);
	};

	char const *__fcall(char const *__filename) {

		return __combine_str(__os_delim, __filename);
	};

	char const *__dcall(char const *__dirname) {

		return __combine_str(__dirname, __os_delim);
	};

	char const *__ecall(char const *__mod, char const *__name) {
		char const *__callbase=__dcall(__mod_call(__mod));
		return __combine_str(__callbase, __name);
	};

	int __check_mod(char const *modname) {
		char const *__ccc=__charm_call(modname);

		return stres(__ccc);
	};

	int __check_entry(char const *entry) {
		int __res=__entry_valid(entry);
		int __ds_offset=__sep_atoff(entry, d_seperator);
		if((!__res)||(__ds_offset==-1)) {
			#ifndef DEBUG
				printf("entry invalid : %s\n", entry);
			#endif
			return -1;
		};
		char const *__charm=str_b4offset(entry, __ds_offset);
		char const *__entry=str_a4woffset(entry, __ds_offset);
		
		return __check_charm(__entry);
	};

	// gets file size in ( x << n*3 ) 
	// gets file types in ( x >> n*3 )
	ulong arch_ufile(char const *__cpath) {
		ulong usize=0, __size=__fsize(__cpath);
		do {
			usize+=1;
			__size>>(3*usize);
		}while(__size>=1);
		return usize;
	};


	lbb_t arch_tfile_lbb(char const *__cpath) {
		
		return (lbb_t)arch_tfile(__cpath);
	};
	
	// gets file size number 
	// representation in characters
	char const *arch_cfile(char const *__cpath){

		return num2char(__fsize(__cpath));
	};


	char const *arch_hash(void const *__){

		return hashof(3,__,__rwings(__));
	};


	char const *arch_checksum(char const **__content) {
		ulong llcount=content_count(__content);

		return varll_hash(vcontent(__content), llcount);
	}

	char const *arch_namehash(char const *__name) {

		return hashof(1, __name, str_rwings(__name));
	};


	ulong env_hash(char **__var){
		uns __count=0;
		while(!(NNE(__var[__count]))){
			#ifdef DEBUG
				printf("%s\n",__var[__count]);
			#endif
			__count+=1;
		}
		env_hash_0=(ulong)hash8(0,&__count,sizeof(uns));
		return (ulong)__count;
	};


	char const *envarr_hash(uchar *__udef_pnop){
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


	char const *varll_hash(void const **__vars, ulong __vcount){
		// variable-linked-list hash
		ulong c=0, hashes[__vcount], h_vsize=ulong_wsize(__vcount);
		void *__hptr=memset(&hashes,0,h_vsize);
		if(!__vcount) {
			#ifdef DEBUG
				printf("vcount cannot be 0\n");
			#endif
			return zero_address(2);
		};
		else {
			while((__vars[c])&&(c<__vcount)){
				hashes[c]=hash8(1,__vars[c],str_rwings(__vars[c]));
				c+=1;
			};
			char const *__hash=hashof(2,__hptr,h_vsize);
			return __hash;
		};
	};

	// generate file name from path and size
	char const *arch_dfile(char const *__name, ulong arch_perm, ulong tfile_size) {
		char const *__cpath=__ecall("var", __name);
		if(stres(__cpath)){
			#ifdef DEBUG
				printf("file already exists\n");
			#endif
			return zero_address(3);
		};

		char const *tlbb_name=(char const *)typed_lbbfilename(fsize);
		char const *__raw_fname=__combine_str(__cpath, s_lbbfile(tlbb_name));
		
		char const *__arch_filename=arch_namehash(__raw_fname);
		if(!attsize(__arch_filename, arch_perm, tfile_size)){
			#ifdef DEBUG
				printf("failed to create dfile\n");
			#endif
			return zero_address(3);
		};

		return __arch_filename;
	};


	int arch_att(char const *__path, ulong __perm, ulong __fldsize) {
		int res=stres(__path);
		if(!res){
			res=open(__path, shard_flags, shard_share);
			if(res==-1) {
				// returns 0
				#ifdef LOG_ERR
					printf("cannot arch @%s\n:: create(err:%d)", __path, errno);
				#endif
				return 0;
			}
			else {
				// exists
				m_stat __pmstat;
				get_mstat(__path, &__pmstat);
				ulong __pszie=cm_size(&__pmstat);
				ulong __bsize=cm_iosz(&__pmstat);
				if(__pszie) {
					#ifdef LOG_ERR
						printf("err : non-zero archs\n");
					#endif
					_exit(1);
				}
				else {
					// returns write result in bytes
					ulong __init_size=__fldsize>__bsize?__bsize:__fldsize;
					uchar __content[__init_size];
					if(__init_size==__bsize) {
						memset(__content, 0x40, __bsize);
					}
					else {
						memset(&__content, 0x5e, __fldsize);
					};
					ulong __flag=0, b_written=0;
					long temp=0;
					while(b_written<__fldsize) {
						temp=pwrite(res, __content, __init_size, b_written);
						if(temp<0) {
							#ifdef DEBUG
								printf("err : cannot init enough memory for archfile : %s\n", __path);
							#endif
							return -1;
						};
						else if(!temp) {
							__flag+=1;
							if(__flag==3) {
								#ifdef DEBUG
									printf("err : arch struck on file @%s\n", __path);
								#endif
								return -1;
							}else {
								continue;
							};
						}else {
							b_written+=temp;
						};
					};
					return b_written;
				};	
			};
		}
		else {
			int __flags=0;
			if(__perm==1) {
				__flags|=shard_lock_reader;
			}
			else if(__perm==2) {
				__flags|=shard_lock_writer;
			}
			else if(__perm==3) {
				__flags|=shard_nolock;
			};

			res=open(__path, __flags);
			return res;
		};
	};

	// creates the arch file needed
	int arch_cfile(char const *cf_name, lbb_t lbb_ftype){
		
		return arch_att(cf_name, 3, lbb_size(lbb_ftype));
	};

	// checks the arch permissions for the requested path
	int arch_fpermissions(char const *__cpath, aip_sterm __sterm){
		mstat c_mstat; memset(&c_mstat, 0, sizeof(m_stat));
		get_mstat(__cpath, &c_mstat);
		if(__sterm==Public){
			return ARCH_MADE(cm_mode(__cpath));
		}else{
			return ARCH_SAVE(cm_mode(__cpath));
		};
	};

	// returns the 8b hash if not fld is not zero
	ulong arch_address(char const *__fpath, ulong __fld){
		if(__fld!=0) {
			if(stres(__fpath)) {
				return fhash8(2, __fpath);
			}
			else {
				return hash8(1, __fpath);
			};
		}else {
			return zero_address(2);
		};
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

	char const *arch_cenv(){
		char **__var=environ;
		ulong var_count=__env_hash(__var);
		return __keys_hash(var_hlist, var_count);
	};

	/**
	 * the reason im currently not using the following logic
	 *  mfile -> m_size = __fsze(...)
	 * is due to a feature that can be implemented into a
	 * single interface call regardless of the execution context(high level interface)
	 * i.e : language, compilier, etc...
	 * so im dividing them into functions for now.
	**/

	int get_mstat(char const *__path, m_stat *mfile) {
		memset(mfile,0,sizeof(m_stat));
		ulong path_len=str_rwings(__path);
		if(path_len>512){
			#ifdef LOG_ERR
				printf("path specified is 512+ \n");
			#endif
			return -1;
		}
		memmove(mfile->m_path,__path,path_len);
		struct stat temp;
		memset(&temp,0,sizeof(struct stat));
		if(stat(mfile->m_path,&temp)!=0){
			#ifdef LOG_ERR
				printf("cannot determine `stat` call :: %s\n", mfile->m_path);
			#endif
			return -1;
		};
		mfile->m_size=fsize_st(&temp);
		mfile->m_mode=dmode_st(&temp);
		mfile->m_blksz=iosize_st(&temp);
		mfile->m_inn=inn_st(&temp);
		return 0;
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
		__mstat__(&cm_st);
		int res=get_mstat(__fldname,&cm_st);
		if(res==-1){
			#ifdef LOG_ERR
				__TEXT(Field not found);
			#endif
			return NULL;
		};
		#ifdef DEBUG
			log_mstat(&cm_st);
		#endif

		
		char const *cflds_head=conv_fields(&cm_st);
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

#endif



/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __dPRG int main(int argc, char const*argv[]) 
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define __INDEXER__(...) {\
		if(!checkef_file){INDEXER(NULL);}\
		__ARGC__;\
		__ARGV__;\
		__VA_ARGS__;\
		return 0;\
	}
    #define dPRG(...) __dPRG __INDEXER__(__VA_ARGS__)
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
	#define __LBB__(...) {\
		__BASE__\
		__VA_ARGS__\
		INDEX_END("\n");\
	}
	#define __BASE__ {\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
		memset(lbb_mstat, 0, sizeof(struct __m_stat));\
		memset(l_shard,0,sizeof(struct __lbb_shard));\
		printf("getting shard .:%s:. \n",__lbb_indexfile);\
		if(!checkef_file){INDEXER(NULL);}\
		get_mstat(__lbb_indexfile,lbb_mstat);\
	}
	#define __TYPD__(d) {\
		__BASE__\
		printf("sizeof type-d : %lu\n",sizeof(d));\
	}
#endif		

	#define __KARCH_D512__ 4096
#endif
