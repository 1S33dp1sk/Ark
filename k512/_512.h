#ifndef __KARCH_D512__

/************************ h-constants ************************/

#ifndef __H512__C
	#include "utypes.h"
	/********* types *********/
	static __ul u;
	static aip_sock __sok;
	static aip_arc __arc;
	/********* constants *********/
	static ulong __cindex=0;
	static ulong __ixr_fd=0x228;
	static ulong ___offset=0;
	static ixr_h ___header;
	static ulong env_hash_0;
	/********* unistd *********/
	extern char **environ;
	/********* http *********/
	static char *__http_get="GET";
	static char *__http_post="POST";
	static char *wss_key_h="Sec-WebSocket-Key: ";
	static char *wss_acc_h="Sec-WebSocket-Accept: ";		
	static char *__reph="HTTP/1.1 200 OK\r\nContent-Type: text;\r\nContent-Length: 10\r\n\r\nHello Raed\r\n";
	static char *__upgrade="HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nCache-Control: no-cache\r\nSec-WebSocket-Protocol: @-Protocol\r\n";
	static char *__cwss="258EAFA5-E914-47DA-95CA-C5AB0DC85B11\0";
	static const char *__http_protocol_version="HTTP/1.1";
	static const char *__http_base="P S R\r\n";
	static const char *__http_request_base="M P V\r\n";
	static const char *__http_response_base="B S R\r\n";
	/********* formats *********/
	static const char *__head_fmt="_Q_Q_Q_\n";
	static const char *__value_fmt="_Q:s:s_\n";
	static const char *__file_fmt="_Q:s:s#Q_\n";
	static const char *__dprg_fmt="_Q:s>s<s$s_\n";
	static const char *__fld_fmt="_Q:s@s=s+h_\n";

	#define __H512__C 1
#endif

/************************ h-defintions ************************/

#ifndef __H512__D
	#include "standard.h"
	#include "darc/__lang"
	#define LONG_MAX_COMPUTED_N_DIGITS 21 //logb(x) = loga(x) / loga(b)
	#define __MA__S 0x000000000000000000000008
	#define __GS__S __MA__S<<3
	#define __LO__F __GS__S<<3
	#define __UN__F __LO__S<<3
	#define __dPER while(1!=1);
	#define shard_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW)
	#define shard_share (S_IRWXU|S_IWGRP|S_IXGRP|S_IWOTH|S_IXOTH)
	#define shard_nolock (O_RDWR)
	#define shard_lock_reader (O_RDONLY)
	#define shard_lock_writer (O_WRONLY)
	#define __vile ((void const *)(__FILE__))
	#define __caller_namelen (ulong)str_rwings(__FILE__)
	#define ARR_DELIM ",\0"
	
	#define __switcher(x) (int)(x->switcher)
	#define ARC_GENERIC(x) (ulong)((1<<(x*3)))

	#ifndef k512
		#define k512(x) _Generic((x),\
		uchar: uchar*,\
		schar: schar*,\
		slong: slong*,\
		ulong: ulong*,\
		ullong: ullong*,\
		sllong: sllong*,\
		default: NULL)
	#endif

	//FMT_ASCII_SPEC
	#define __C_FMT_SPEC(x) _Generic((x), \
		char: "%c",\
		unsigned char: "%d",\
		int: "%d",\
		unsigned int:"%u",\
		long: "%ld",\
		unsigned long: "%lu",\
		char *: "%s",\
		unsigned char *: "%s",\
		long long: "%lld",\
		unsigned long long: "%llu",\
		default: "%x")

	//FMT_HEXA_SPEC
    #define __ENK_FMT_SPEC(__) \
        _Generic((__), \
            char: "c",\
            unsigned char: "C",\
            short: "h",\
            int: "h",\
            uns: "H",\
            long: "l",\
            ulong: "L",\
            long long: "q",\
            ullong: "Q",\
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
	        long long int:"ullong", \
	        unsigned long long int:"ullong", \
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
            long long int:(ullong)x, \
            unsigned long long int:(ullong)x, \
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
		ullong*		: "Q",\
		default 	: "_")

    #define IXR_ARG(__) _Generic((__), \
		char*					: (char*)x,\
		char const *			: (char const *)x,\
		unsigned char*			: (uchar*)x,\
		int*					: (int*)x,\
		unsigned int*			: (uns*)x,\
		long int*				: (ulong*)x,\
		unsigned long int*		: (ulong*)x,\
		long long int*			: (ullong*)x, \
		unsigned long long int*	: (ullong*)x, \
		default					: NULL)

	#define __lbb_call_generic(__) \
		_Generic((__),\
			atp_pointer:"lbb command",\
			atp_charm: "lbb interpreter",\
			atp_pyfld: "lbb payload field",\
			atp_data: "lbb data",\
		default:"lbb call")

	#define __lbb_resp_generic(__) \
		_Generic((__),\
			atp_pointer*:"command response",\
			atp_charm*: "interpreter reply",\
			atp_pyfld*: "payload retrieve",\
			atp_data*: "field return",\
		default:"unknown args")

	#define __lbb_generic(__) \
		_Generic((__),\
			char[8]:(atp_pointer *) &__,\
			char[64]:(atp_charm *) &__,\
			char[512]:(atp_pyfld *) &__,\
			char[4096]:(atp_data *) &__,\
			default:"unknown")

	#define __lbb_typd(__) \
		_Generic((__),\
			atp_pointer * : char[8],\
			atp_charm * : char[64],\
			atp_pyfld * : char[512],\
			atp_data * : char[4096],\
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
        snprintf(_,sizeof _,"%s",__ENK_FMT_SPEC(x));\
        ulong pack_sz=pack(__,_,x);\
        if(pack_sz>0){write(fd,__,pack_sz);}\
    } __dPER

    #define OUT_ENK_A(fd,x) do { \
        char __[4096];\
        memset(&__,0,sizeof __);\
        snprintf(__,sizeof __,"%s\n", __C_FMT_SPEC(x));\
        dprintf(fd,__,(x));\
    } __dPER
	#define __ASCII(x) OUT_ENK_A(0,x)
	#define __TEXT(x) OUT_ENK_A(0,#x);
	#define __STRING(x) #x
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
	#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
	#define elem_hash(x) hash8(0,x,strlen(x))
	#define wsize(x,y) (sizeof(x)*y)
	#define ulong_wsize(x) wsize(ulong, x)
	#define str_wsize(x) wsize(char, x)
	#define ustr_wsize(x) wsize(uchar, x)
	#define vcontent(x) ((void const **)x)
	#define __typed_lbbfile_name(x) arch_tfile_lbb(x)
	#define typed_lbbfilename(x) __STRING(arch_tfile_lbb(x))
	#define s_lbbfile(x1,x2) x1##x2
	#define _C_ZERO(x) x-'0'

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
	#ifndef _D_FILE_H
		#define _D_FILE_H 1
		// file
    	void *__statusof(char const *__path);
		int __stres(char const *__path);
		ulong __fsize(char const *__path);
		ulong __iosize(char const *__path);
		ulong __inodenum(char const *__path);
		ulong __dmode(char const *__path);
		ulong __file_r(char const *__path);
		ulong __file_w(char const *__path);
		ulong __file_x(char const *__path);
		int __dgetfd(char const *__path);
		#ifndef _D_FILE
			#include "darc/__file"
		#endif
	#endif
	#ifndef _D_STRING_H
		#define _D_STRING_H 1
		// strings
		int __nullchar(char c);
		int __numchar(char c);
		int __smchar(char c);
		int __capchar(char c);
		int __atchar(char c);
		int __sepchar(char c);
		int __delimchar(char c);
		ulong __rwings(void const *__);
		ulong str_rwings(char const *__str);
		int spaces_and_tabs(char *__str);
		int tabs_and_spaces(char const *__str);
		ulong __tonum(char const *__path);
		ulong tonum(int i);
		char const *num2char(ulong num_in);
		char const *s_num2char(long snum_in);
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
		char const *__expand_str(char const *__str, char const *__expantion);
		char const *__combine_str(char const *__str_1, char const *__str_2);
		ulong str_cdelims(char const *__str, char const *__delim);
		ulong arr_cdelims(char const *__str);
		ulong sep_offset(char const *__str, char *__seperator);
		#ifndef _D_STRING
			#include "darc/__string"
		#endif
	#endif
	#ifndef _D_LOG_H
		#define _D_LOG_H 1
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
		void log_atp_names();
		void log_content(content_st *content);
		void log_into(d_into *into);
		void log_keyvalue(char *key, char *value);
		void lbb_usage();
		void log_ixr_point(void *__);
		#ifndef _D_LOG
			#include "darc/__log"
		#endif
	#endif
	#ifndef _D_ARCH_H
		#define _D_ARCH_H 1
		// arch
		char const *__get_atnmae(char const *__naming);
		char const *__getcaller();
		int __entry_valid(char const *__);
		ulong vcontent_count(void const **__vc);
		ulong content_count(char const **__content);
		ulong lexical_args(void **__vars);
		ulong __size8(int _);
		ulong lbb_type2size(lbb_t lbb_type);
		int __check_fld(char const *__path, lbb_t __path_type);
		char const *__mod_call(char const *__mname);
		char const *__fcall(char const *__filename);
		char const *__dcall(char const *__dirname);
		char const *__ecall(char const *__mod, char const *__name);
		int __check_ectx(char const *__mod, char const *__name);
		int __check_entry(char const *entry);
		char const *arch_namehash(char const *__name);
		ulong env_hash(char **__var);
		char const *varll_hash(void const **__vars, ulong __vcount);
		ulong arch_ufile(char const *__cpath);
		lbb_t arch_tfile_lbb(char const *__cpath);
		char const *arch_szfile(char const *__cpath);
		char const *arch_hash(void const *__);
		char const *arch_checksum(char const **__content);
		int get_mstat(char const *__path, m_stat *mfile);
		int arch_att(char const *__path, ulong __perm, ulong __fldsize);
		char const *arch_dfile(char const *__name, ulong arch_perm, ulong tfile_size);
		int arch_cfile(char const *cf_name, lbb_t lbb_ftype);
		int arch_fperm(char const *__cpath, aip_sterm __sterm);
		ulong arch_address(char const *__fpath, ulong __fld);
		char const *arch_cenv();
		void *__mstat__(m_stat *st);
		char *flds(char const *__fldname);
		#ifndef _D_ARCH
			#include "darc/__main"
		#endif
	#endif
	#define __H512__N 1
#endif



#define __KARCH_D512__ "K-arch512d"
#endif