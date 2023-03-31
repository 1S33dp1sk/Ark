/************************ h-constants ************************/
#include "utypes.h"

#ifndef __H512__C
	/********* types *********/
	static __ul u;
	static aip_sock __sok;
	static aip_arc __arc;

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

	#ifndef __d3
		#define __d3 0;
		
	#endif
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
	#define __vile ((void const *)(__FILE__))
	#define __caller_namelen (ulong)str_rwings(__FILE__)
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
	#define __dPER while(1!=1);
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

	#define LBB_READER(x)		x^0010000
	#define LBB_DIRECTORY(x)	x^0040000
	#define LBB_FIELD(x)		x^0100000
	#define LBB_SOCKET(x)		x^0140000
	#define ARCH_MADE(x)		x^0000700
	#define ARCH_SAVE(x)		x^0000007
	
	#define _C_ZERO(x) x-'0'

	#define ARR_DELIM ",\0"


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
	// hbar
    void __btoh(uchar __c, uc __s);
    void h_str_tl(char *__, uchar *__hash, ulong __len);
    void __htostr(char *__str, uchar *hash);
    char *__s_hash(char *__key, char *__hashkey);
    ulong blaz_hash(char const *__data);
    static void keccakf(ulong s[25]);
    sha3_r sha3_init(void *p,ulong bit_size);
    sha3_f sha3_set_flags(void *p,sha3_f flags);
    void sha3_update(void *p,void const *buf_in,ulong len);
    void const *sha3_finalize(void *ctx_p);
    sha3_r sha3_hash_buffer(ulong bit_size,sha3_f cfg,const void *in,ulong in_bytes,void *out,ulong out_bytes);
    const char *zero_address(ulong level);
    void *__generate_lock(char const *__hash, ulong __hlen);
    char const *hashof (ulong level, void const*to_hash, ulong the_hash_size);
    uchar const *hash (ulong level, void const *to_hash, ulong the_hash_size);
    ulong hash8 (ulong level, void const *to_hash, ulong the_hash_size);
    ullong  hash24 (ulong level, void const *to_hash, ulong the_hash_size);
    char const *fhashof(ulong level, char const *to_hash);
    char const *fdhashof(ulong level, ulong fd, ulong filesize);
    uchar const *fhash(ulong level, char const *to_hash);
    ulong fhash4 (ulong level, char const *to_hash);
    ulong fhash8 (ulong level, char const *to_hash);
    ulong fhash16 (ulong level, char const *to_hash);

    //lbb
	char const *conv_fields(m_stat *m_st);


	//atp
	d_socket __sock_addr(struct sockaddr *sa);
	struct sockaddr *sock_aip_to_sa(aip_sock *sock);

    

	#define __H512__N
#endif