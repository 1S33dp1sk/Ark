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
	static ulong __cindex=0;
	static ulong __ixr_fd=0x228;
	static ulong ___offset=0;
	static ixr_h ___header;
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
    #define FMT_ASCII_SPEC(__) \
        _Generic((__), \
            int: "%d",\
            uns: "%u",\
            char: "%c",\
            long: "%ld",\
            ulong: "%lu",\
            tlong: "%llu",\
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
            tlong: "Q",\
            char *: "s",\
            default: "_")
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
	#define __H512__D 'k'
#endif


/************************ h-naming ************************/

#ifndef __H512__N
	int __incheck(char __c);
	char const *__getcaller();
	// calculate length till `__NADA__`
	ulong __rwings(void const *__);
	// convert a number-string representation
	// to a number
	ulong __tonum(char const *__var);
	// calculate length of a string
	// cannot exceed 4096 chars
	// 8192 bytes
	ulong str_rwings(char const *__str);
	// convert an int to a ulong
	ulong tonum(int i);
	
	int __stres(char const *__fpath);

	void *__mstat__(m_stat *st);
	int get_kstat(char const *__path, k_stat *kfile);
	int get_sstat(char const *__path, s_stat *sfile);
	int get_mstat(char const *__path, m_stat *mfile);

    const char *zeroatt(uns level);

    char const *fhashof (uns level,char const*to_hash);
    uint8_t const *fhash (uns level,char const *to_hash);
	char const *conv_fields(m_stat *mst);
	lbb_entry __decode_arg(char const *argument);

    uns  fhash4 (uns level,char const *to_hash);
    ulong fhash8 (uns level,char const *to_hash);
    ulong fhash16 (uns level,char const *to_hash);

    char const *hashof (uns level,void const*to_hash,size_t the_hash_size);
    uint8_t const *hash (uns level,void const *to_hash,size_t the_hash_size);

    uns  hash4 (uns level,void const *to_hash,size_t the_hash_size);
    ulong hash8 (uns level,void const *to_hash,size_t the_hash_size);
    void * hash16 (uns level,void const *to_hash,size_t the_hash_size);

	char const *num2char(ulong n);
	char *stn_b4offset(char const *string, ulong offset);

    unsigned int pack(uchar *buf,char const *fmt,...);
    void unpack(uchar *buf,char const *fmt,...);

	ulong lbb_print(char *kaddr);

	void log_mstat(m_stat *mfile);
	void log_sstat(s_stat *sfile);
	void log_kstat(k_stat *kfile);
	void log_strld(strld __strld);
	void log_sepstr(spstr __spstr);
	void log_ptrdx(struct __ptrdx *ptrdx);
	void log_esptr(ulong *esptr);
	void log_process_ids(ulong ppid, ulong cpid);
	void log_process_schema(ulong ppid, ulong cpid);
	void log_ixrh(ixr_h *ixrst);

	uns __8sz(uns __8to);
	fms_s fms_type2sz(fms_t __ftype);
	int __get_fd(char const *__fpath, int __flag);
	int __get_process_flags(char const *__cpath);
	int __check_fld(char const *__cpath, fms_t ftype);
	char const *__charm_call(char const *__ffrom);
	int __init_3ci();
	int arch_3ci();
	void log_arcs();
	ulong __env_hash(char **__envvar);
	char const *__h_passcode(char *udef_pass);
	char const *__kgev(uchar *__udef_pnop);
	void k1_addr(ulong _h8res, ulong _count, char *_kval);
	char const *__keys_hash(char **__envvar, uns __varc);
	fms_t __size_switch(char const *__cpath);
	char const *ccopy_to_path(char const *cc, char const *__cpath);
	char const *arch_gfile(char const *__cpath);
	fms_s arch_tfile(char const *__cpath);
	ulong arch_cfile(fms_t fms_type);
	ulong attsize(ulong __sz);
	ulong fldatt(uns level, ulong szatt);
	ulong arch_fpermissions(char const *__cpath);
	char const *tochar(ulong num_in);
	ulong arch_foffset(char const *__fpath, ulong f_field);
	static ulong arch_fname(char const *__fpath, ulong fsize);
	int arch_mods(char const *__cpath);
	int arch_cenv();
	void log_fmt_t(fmt_t __format);
	void log_keyvalue(char *key, char *value);
	void lbb_usage();
	int get_allstats(char *__mountpoint, char *__socketaddr, char *__fieldshare);
	char *flds(char const *__fldname);
	void *__search_r(char const *__rname, lbb_entry in);
	void *__lbb_ref(char const *__rname);
	void log_str(char const *__);
	void log_socket(aipsock *sock);
	aip_sockaddr __sock_addr(struct sockaddr *sa);
	struct sockaddr *sock_aip_to_sa(aipsock *sock);
	#define __H512__N
#endif
// CDN (:

/************************ h-logging ************************/

#ifndef __H512__L

	void log_dpoint(d_point *dst_point) {
		printf("dst point :: \n");
		printf("@%lu\n", dst_point->c_index);
		printf("name :%s\n",dst_point->c_name);
		printf("ref  :%s\n",dst_point->c_ref);
	};

	void log_kstat(k_stat *kfile) {
		printf("dcloud : K\n");
		printf("uname	= %s\n", kfile->u_name);
		printf("iaddr	= %s\n", kfile->i_addr);
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

	void log_strld(strld __){
		printf("string\n");
		printf("length=%d\n",__.len);
		printf("data:=%s\n",__.data);
	};

	void log_sepstr(spstr ss){
		printf("string=%s\nlength=%d\nseperator=%s\noffset=%d\n",ss.str,ss.str_length,ss.sep,ss.sep_offs);
	};

	void log_ptrdx(struct __ptrdx *ptrdx) {
		printf("dcloud : K :: ptrdx\n");
		printf("pidx :%lu\n",ptrdx->pidx);
		printf("tri  :%lu\n",ptrdx->tri);
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


	#define __H512__L
#endif



/************************ d-architicture ************************/

#ifndef _D_ARCH
	#define d_charms "@charms/d.\0"
	#define d_lbb "@charms/d.lbb\0"
	#define d_atlbb "@charms/d.lbb/.lbb\0"
	#define arch_filename d_atlbb

	int __incheck(char __c){   
	// check character in character set
		if( (__c>=0x30)&&(__c<=0x39)){
			#ifdef DDEBUG
				printf("char %c has a value of %d\n",__c,__c);  
			#endif
			return 1;
		};
		return 0;
	};


	char const *__getcaller(){
		// get the calling file
		return (char const *)__FILE__;
	};
	#define _D_ARCH 1
#endif


/************************ d-files ************************/

#ifndef _D_FILE
	#define d512_read(d,o) (char const *)__readb(512,fd,fo*512)
	#define sz8(x) ((ulong)__8sz(x))
	#define fsze(x) ((ulong)__fsize(x))
	#define iosze(x) ((ulong)__iosize(x))
	#define dmde(x) ((uns)__dmode(x))
	#define inn(x) (ulong)__inodenum(x)
	#define status(x) __statusof(x)
	#define stres(x) __stres(x)
    #define len_ustrze(x) (((ulong)x)*(sizeof(uchar)))
	#define ixr_h_size(x) (x.__size)
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)


	int __stres(char const *__cpath){
		int __res=access(__cpath, F_OK);
		#ifdef DEBUG
			printf("checking cpath :: %s\n", __cpath);
			printf("result of access = %d\n", __res);
		#endif
		return __res==0;
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

	#define _D_FILE 1
#endif


/************************ d-strings ************************/

#ifndef _D_STRING

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
			while(__incheck(__var[__c])){
				d*=10;
				__c+=1;
			};
			__c=0;
			if(d>=10){d/=10;}
			#ifdef DDEBUG
				printf("digits count :: %lu\n",d);
			#endif
			while(__incheck(__var[__c])){
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

	char const *num2char(ulong __inpu){
		char __[21];
		memset(&__,0,sizeof(__));
		sprintf(__,"%lu",__inpu);
		return (char const *)strdup(__);
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
		long x=0,y=0,len_count=0,offset_at=0;
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
		ulong __len=_lstr1+_lstr2+3;
		char __[__len];memset(&__, 0, sizeof(__));
		__[__len]='\0';
		memmove(__, str1, _lstr1);
		memmove((__+_lstr1), str2, _lstr2);
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

	ulong arr_cdelims(char const *__, char const *__d) {
		// add 1 more to create an array
		// #err if more elements than arg_count specifies
		ulong arg_count=str_cdelims(__, __d)+1;
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
	#define _D_STRING 1
#endif


/************************ d-formatting ************************/

#ifndef _D_FMT

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

	ulong lexical_args(void **__vars) { 
		char const *temp = (char const *)__vars;
		printf("vars : %s\n", temp);
		ulong arg_count=arr_cdelims(temp, ",");
		return arg_count;
	};


	/********* base8 *********/


	void log_str(char const *__) {
		write(0,__,str_rwings(__));
		write(0,"\n",1);
	};

	uns __8sz(uns _){
		uns __=1;while(_>0){__*=8;_--;}
		return __;
	};

	/********* fld *********/

	fms_s fms_type2sz(fms_t type){
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

	int __check_fld(char const *__cpath, fms_t __ftype){
		if(fsze(__cpath)<fms_type2sz(__ftype)){
			return 0;
		}
		return 1;
	};


	char const *__charm_call(char const *__filefrom) {
		char const *__caller=__getcaller();
		ulong __clen=str_rwings(__caller);
		ulong __flen=str_rwings(__filefrom);
		char charmcall[__clen];
		memset(&charmcall, 0, sizeof(charmcall));

		ulong f_sep=sep_offset(__filefrom, d_charms);
		ulong c_sep=sep_offset(__caller, d_charms);
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

	#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))

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
	fms_t __size_switch(char const *__cpath) {
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
	fms_s arch_tfile(char const *__cpath){
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
	ulong arch_cfile(fms_t _){
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
	/**
	 * the reason im currently not using the following logic
	 *  mfile -> m_size = __fsze(...)
	 * is due, to hopefully being able to implement a single
	 * call interface regardless of the language high-level interface
	 * so im dividing them into functions to remember this.
	**/

	int get_mstat(char const *__path, m_stat *mfile) {
		memset(mfile,0,sizeof(struct __m_stat));
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

	void *__search_r(char const *rname, lbb_entry in_type) {


		return NULL;
	};

	void *__lbb_ref(char const *__rname) {
		lbb_entry __ltype=__decode_arg(__rname);
		void *temp=__search_r(__rname, __ltype);
		return temp;
	};

	unsigned get_hlevel(char *href) {
	    ulong c=str_rwings(href);
	    unsigned res=((c)>>3);
	    if (res>3){
	        return 3;
	    };
	    return res;
	};
	#define _D_FMT 1
#endif


/************************ d-language ************************/

#ifndef _D_LANG
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
	#define _D_LANG 1
#endif		

	#define __KARCH_D512__ 4096
#endif
