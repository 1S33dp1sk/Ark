/// utypes \\\
default types are to be used\
as a default for all types. \
initiated at compile time or once at execution\
and loaded via a .o or .so


#ifndef __UTYPES__H
	#define __UTYPES__H 1


#ifndef __API_LEN
	#define __API_LEN 0x1000
	#define __A_LEN 0x200
	#define __P_LEN 0x8
	#define __I_LEN 0x40
#endif

#ifndef __ARCH_TYPES
	#define __ARCH_TYPES 7
	#ifndef uchar
		#define __ud_char unsigned char
	typedef __ud_char uchar;
	#endif
	#ifndef schar
		#define __sd_char signed char
	typedef __sd_char schar;
	#endif
	#ifndef ulong
		#define __ud8 unsigned long int
	typedef __ud8 ulong;
	#endif
	#ifndef slong
		#define __sd8 signed long int
	typedef __sd8 slong;
	#endif
	#ifndef ullong
		#define __u64 unsigned long long int
	typedef __u64 ullong;
	#endif
	#ifndef sllong
		#define __s64 signed long long int
	typedef __s64 sllong;
	#endif
	#ifndef uc
		#define __uc3 uchar*
	typedef uchar uc[3];
	#endif
	/**
	* 
	* can modify a call or similar, to `conifgure.ac` usign `autoreconf` to iterate 
	* e.g :: AC_DEFINE([__uX],[__u5],[defines a struct of 8**5]).
	* for any base 8-num a simple __u8 yeilds the `__u64` defined by linux kernel.
	* logically, to create a __uX structure where `X` is any number. where the resulting
	* struct can be computed as X<<3
	* Mathematically, this is the free base number, a dynamic definition instead of local constant which 
	* causes restricitions to the octal, hexa, deci, etx. numbering systems.
	* 
	**/
	#ifndef __u3
		typedef ulong __u[3];
		typedef ulong __ul[3];
		typedef ullong __ull[3];
			#define init_ul() memset(&u, 0, sizeof(__ul));
			#define return_u() return ((ulong)u);
			#define return_ul() return ((ulong *)u);
			#define return_ull() return ((ullong *)u);
	#endif
#endif

#ifndef __ADDR_TYPES

	#ifndef atp_pointer
		struct __ptr_addr {
			void *ptr;//memory access
			char addr[__P_LEN];
			char const *chkref;
		};
	typedef struct __ptr_addr atp_pointer;
		#define __ptr__(x) ((ptr_st *)(x->ptr))
		#define ptr_addr(x) cis_address(x)
		#define ptr_chkref(x) cis_chkref(x)
		#define ptr_addrlen(x) cis_address(x)

	#endif

	#ifndef atp_charm
		struct __charm_addr { 
			void *intr;
			char addr[__I_LEN];
			char const *chkref;
		};
	typedef struct __charm_addr atp_charm;
		#define __intr__(x) ((atp_charm *)(x->intr))
		#define intr_addr(x) cis_address(x)
		#define intr_chkref(x) cis_chkref(x)
		#define intr_addrlen(x) cis_address(x)

	#endif

	#ifndef atp_pyfld
		struct __payld_st {
			void *payld;
			char addr[__A_LEN];
			char const *chkref;
		};
	typedef struct __payld_st atp_pyfld;
		#define __payld__(x) ((atp_pyfld *)x->payld)
		#define pyld_addr(x) cis_address(x)
		#define pyld_chkref(x) cis_chkref(x)
		#define pyld_addrlen(x) cis_address(x)

	#endif

	#ifndef atp_data
		struct __cis_addr {
			void *ptr;
			char *addr;
			char const *chkref;
		};
	typedef struct __cis_addr atp_data;
		#define ATP(x, ...) atp_data d##__VA_ARGS__;
		#define c3atp(x)	x->ptr, x->addr, x->chkref
		#define __cis__(x) ((cis_st *)x->ptr)
		#define cis_ptr(x) ((void const *)x->ptr)
		#define cis_address(x) ((char const *)x->addr)
		#define cis_chkref(x) ((char const *)x->chkref)
		#define cis_addrsz(x) ((ulong)sizeof(x->addr))
		#define cis_addrlen(x) ((ulong)str_rwings(cis_address(x)))

	#endif

	#define __ADDR_TYPES { atp_pointer, atp_charm, atp_pyfld, atp_data }
	#define atp_init(x) atp_data x;
#endif

#ifndef __HBAR_TYPES
	#ifndef sha3_context
		#define __size_u64 sizeof(ullong)
        #define __sha3_k_sponge_w (((1600)/__P_LEN)/__size_u64) //bits to byte
	    struct __sha3_context {
	        ulong saved;             
	                // remainder of input string that we didn't consume yet
	        union {                     
	            ulong s[__sha3_k_sponge_w];
	            uchar sb[__sha3_k_sponge_w*8];
	        } u;                        
	                // keccak's state 
	        ulong byte_idx;         
	                // 0..7--the next byte after the set one (starts from 0; 0--none are buffered) 
	        ulong word_idx;         
	                // 0..24--the next word to integrate input (starts from 0)
	        ulong cap_words;
	                // the double size of the hash output in words (e.g. 16 for Keccak 512)
	    };
    typedef struct __sha3_context sha3_context;
    #endif		
	#ifndef sha3_return
		enum __sha3_return {
			__sha3_u_ok=0,
			__sha3_u_n=1
		};
	typedef enum __sha3_return sha3_r;
	#endif
	#ifndef sha3_flags
		enum __sha3_flags {
			__sha3_flag_none__=0,
			__sha3_flag_keccak__=1
		};
	typedef enum __sha3_flags sha3_f;
	#endif
#endif

#ifndef __C_TYPES

	#ifndef c_conv
		struct __conv_header {
		ulong chksize;
		char const *chkname;
		char const *chksum;
		char const *chkcont;
	};
	typedef struct __conv_header c_conv;
	#endif

	#ifndef c_path
		struct __path_st {
			ulong p_offset;
			ulong p_size;
			char const *p_reference;
			char const *p_caller;
			char const *p_called;
			char const *p_checksum;
		};
	typedef struct __path_st c_path;
		static const ulong size_cpath=sizeof(c_path);
		#define path_checksum(x) ((char const *)x->p_checksum)
		#define path_caller(x) ((char const *)x->p_caller)
		#define path_called(x) ((char const *)x->p_called)
		#define path_reference(x) ((char const *)x->p_reference)
		#define path_offset(x) ((ulong)x->p_offset)
		#define path_size(x) ((ulong)x->p_size)
		#define path_type(x) (())
	
	#endif

	#ifndef c_fld
			struct __fld_st {
				ulong f_index;
				char const *f_name;
				uchar const *f_ref;
				char const *f_address;
				char const *f_alias;
				int f_flags;
			};
	typedef struct __fld_st c_fld;
			static const ulong size_cfld=sizeof(c_fld);
			#define fld_address(x) ((char const *)x->f_address)
			#define fld_name(x) ((char const *)x->f_alias)
			#define fld_flags(x) ((int)x->f_flags)
		
	#endif

	#ifndef c_req
			// req :: c->request
			struct __c_data {
			    ulong len;
			    uchar etc[4096];
			};
		typedef struct __c_data c_data;
		typedef char c_name[24];
		typedef ulong c_keys[3];
			#define data_length(x) (x.len)
			#define data_content(x) (x.etc)
			struct __c_request {
			    c_name name;
			    c_data data;
			    c_keys keys;
			};
	typedef struct __c_request c_req;
		static const ulong size_creq=sizeof(c_req);
		#define req_name(x) ((char const *)(x.name))
		#define req_content(x) ((char const *)data_content(x.data))
		#define req_contlen(x) ((ulong)data_length(x.data))
		#define req_keys(x) ((ulong *)(x.keys))
	
	#endif

	#ifndef m_stat
		// M structure
		struct __cm_stat {
			ulong m_size;
			ulong m_mode;
			ulong m_blksz;
			ulong m_inn;
			char  m_path[512];
		};
	typedef struct __cm_stat m_stat;
		#define cm_size(x) ((ulong)(x.m_size))
		#define cm_mode(x) ((ulong)(x.m_mode))
		#define cm_iosz(x) ((ulong)(x.m_blksz))
		#define cm_inum(x) ((ulong)(x.m_inn))
		#define cm_path(x) ((char const *)(x.m_path))
	
	#endif

	#ifndef c_shard
		// Shard
		struct __c_shard {
			m_stat c_stat;
			ulong	c_fd;
		};
	typedef struct __c_shard c_shard;
		#define sh_stat(x) ((m_stat *)(x->c_stat))
		#define sh_fd(x) ((ulong)x->c_fd)

	#endif

	#define __C_TYPES { c_path, c_fld, c_req, c_mstat, c_shard }
#endif

#ifndef __D_TYPES
	#define format_args(x, ...) (ulong) lexical_args(x);
	#define file_hash(x,y) (char const *) fhashof(x,y);

	#ifndef d_num
			struct __num_d {
				ulong __val;
				void const *__;
				struct __num_d* __next;
			};
	typedef struct __num_d d_num;
			#define number(x,...) d_num x; \
				x.__val=__tonum(#__VA_ARGS__); \
				x.__=num2char(__VA_ARGS__); \
				x.__next=&x;\

	#endif

	#ifndef d_str
			struct __str_d {
				ulong __len;
				char const *__;
				struct __str_d* __next;
			};
	typedef struct __str_d d_str;
			#define __NADA__ "\0"
			#define str_len(x) (ulong)(x.__len)
			#define str_val(x) (char const *)(x.__)
			#define str_nxt(x) (d_str *)(x.__next)
			#define string(x,y) d_str x; \
			x.__=(char const *)y; \
			x.__len=str_rwings(y); \
			x.__next=&x;\

	#endif

	#ifndef d_prg
			struct __program_d {
				ulong c_index;
				char const *c_name;
				uchar const *c_ref;
				char const *prg_in;
				char const *prg_out;
				char const *prg_handler;
				struct __program_d* __next;
			};
	typedef struct __program_d d_prg;
			static const ulong size_dprg=sizeof(d_prg);
			#define dprg_in(x) ((char const *)x->prg_in)
			#define dprg_out(x) ((char const *)x->prg_out)
			#define dprg_handler(x) ((char const *)x->prg_handler)
			#define program(x) d_prg x;\

	#endif

	#ifndef d_array
			struct __array_d {
				ulong __count;
				void **__;
				struct __array_d* __next;
			};
	typedef struct __array_d d_array;
			#define array_count(x) (ulong)(x->__count)
			#define array_elems(x) (void *)(x->__)
			#define array(x, ...) int y; d_array x; \
				x.__=(void **)(#__VA_ARGS__); \
				x.__count=format_args(x.__, __VA_ARGS__);\
				x.__next=&x;\

	#endif

	#ifndef d_script
			struct __script_d {
				ulong __hash;
				void const *__;
				char const *__path;
				int __to;
				struct __script_d* __next;
			};
	typedef struct __script_d d_script;
			#define script_hash(x) (char const *)(x.__hash)
			#define script_path(x) (char const *)(x.__path)
			#define script_tofd(x) (ulong)(x.__to)
			#define script(x, a) d_script x; \
				x.__=read_book(#x);\
				x.__hash=hash8(a, x.__, fsze(x.__));\
				x.__path=(#x);\
				x.__to=a;\
				x.__next=&x;\

	#endif

	#ifndef d_pointer
			struct __pointer_d {
				ulong __count;
				void const **__content;
				char const *__llhash;
				struct __pointer_d* __next;
			};
	typedef struct __pointer_d d_pointer;
			#define ptr_count(x) ((ulong)(x->count))
			#define ptr_content(x) ((ulong)(x->content))
			#define pointer(x, v) d_pointer x; \
				x.__content=vcontent(v);\
				x.__count=content_count(v);\
				x.__llhash=varll_hash(v, x.__count);\
				x.__next=&x;\

	#endif

	#ifndef d_point
			struct __point_d {
				ulong c_index;
				char const *c_name;
				uchar const *c_ref;
				char const *c_fmt;
				struct __point_d* __next;
			};
	typedef struct __point_d d_point;
			static const ulong size_dpoint=sizeof(d_point);
			#define dpoint_p(x)		((d_point *)x)
			#define dpoint_fmt(x)	((char const *)dpoint_p(x)->c_fmt)
			#define point(x, a) d_point x;\
			
	#endif

	#ifndef d_into
			struct __into_d {
				int i_switch;
				char const **i_args;
				char const *i_caller;
				struct __into_d* __next;
			};
	typedef struct __into_d d_into;
		#define din_switch(x)	(x->i_switch)
		#define din_args(x)		((char const **)(x->i_args))
		#define din_caller(x)	((char const *)x->i_caller)
		#define din_arg_n(x,n)	((char const *)(din_args(x)[n]))
		#define din_argument(x) din_arg_n(x, 0)

		#define into_caller(i, c) i.caller=(char const *)c;
		#define into_type(i, t) i.req_at=(int)t;
		#define into_args(i, a) i.args=(char const **)a;

	#endif

	#ifndef d_pia
		struct __pia_d {
			char pointer[__P_LEN];
			char interpreter[__I_LEN];
			char args[__A_LEN];
			struct __pia_d* __next;
		};	
	typedef struct __pia_d d_pia;
		static const ulong dpia_size=sizeof(d_pia);
		#define via_ptr(x)			((void *)(x.pointer))
		#define via_interp(x)		((void *)(x.interpreter))
		#define via_args(x)			((void *)(x.args))
		#define dest_portal(x,...) 	_Generic((#x), \
			"pointer": memmove(x->pointer, __VA_ARGS__, str_rwings(__VA_ARGS__)),\
			default:NULL);
		#define pia(x,n) d_pia x;\
		memmove(x.pointer, n, str_rwings(n));\

	#endif

	#ifndef d_socket
			#ifndef atp_t
			// atp :: {a.k.a @-Protocol} : types
				enum __atypes_p {
					__at_p='0',
					__at_4=4,
					__at_6=6,
					__at_e='e',
					__at__='@'
				};
			typedef enum __atypes_p atp_t;
			
			#endif

			#ifndef sAF_t
			// needed for inet resolutions
				enum __sAF_types {
					__sAF_INET=2,
					__sAF_INET6=30
				};
			typedef enum __sAF_types sAF_t;
				#define s2a_type(x) int x; 
				#define a2s_type(x) atp_t x;\
					switch(x) {\
					case __at_4: return __sAF_INET;\
					case __at_6: return __sAF_INET6;\
					default: return __sAF_INET;\
				}\
			
			#endif
			// socket address
			struct __portal_d {
				atp_t s_protocol;
				void *s_address;
				char s_socket[128];
				char s_ascii[__I_LEN];
			};
		typedef struct __portal_d d_portal;
			#define portal(x) c_req x; mor(x)
			#define __socket_protocol(x) ((ulong)(x->s_protocol))
			#define socket_proto(x) ((atp_t)(x->s_protocol))
			#define socket_address(x) ((void *)(x->s_address))
			#define socket_raw(x) ((char const *)(x->s_socket))
			#define socket_name(x) ((char const *)(x->s_ascii))
		
	#endif


	#ifndef d_http
		#ifndef http_req_t
			enum __http_request_types {
				__http_rget,
				__http_rpost,
			};
		typedef enum __http_request_types http_req_t;
			#define http_request(x) char const *y; request_types x;\
			switch(x) {\
			case __http_rget:	y=__http_get;\
			case __http_rpost:	y=__http_post;\
			}\

		#endif

		#ifndef http_content
			enum __http_content_types {
				__hct_text,
				__hct_html,
				__hct_json,
				__hct_img,
			};
		typedef enum __http_content_types http_content;
			#define set_content_type(c,t) c.__type=http_content_type(t)
			#define http_content_type(x) &x; switch(x)\
				__hct_text:"text;";\
				__hct_html:"html;";\
				__hct_json:"json;";\
				__hct_img: "img;";\

		#endif

		#ifndef content_st
			struct __http_content_st {
				ulong c_size;
				void *content;
				char const *__type;
				http_content hc_type;
			};
		typedef struct __http_content_st content_st;
			#define http_clen(x) ((ulong)(x->c_size))
			#define http_cdata(x) ((void *)(x->content))
			#define http_ctype(x) ((http_content)(x->hc_type))
			#define http_stype(x) ((char const *)(http_content_type(x->hc_type)))
			#define http_htype(x) ((char const *)(x->__type))

		#endif

		#ifndef content_pm
			enum __http_protomethods {
				__http_request,
				__http_response,
				__http_switch,
			};
		typedef enum __http_protomethods content_pm;
			#define http_proto(x) char const *y; proto_methods x; \
			switch(x) {\
				case __http_response: 	y=http_response(200, "OK");\
				case __http_switch:		y=http_response(101, "Switching Protocols");\
				default: y=NULL;\
			}\

		#endif
		struct __http_d {
			http_req_t h_request;
			content_st h_content;
		};
	typedef struct __http_d d_http;

	#endif


	#define __D_TYPES { d_num, d_str, d_prg, d_arr, d_script, d_point, d_into, d_pia, d_http }
#endif

#ifndef __LBB_TYPES

	#ifndef lbb_t
		// lbb file mount structure types
		enum __lbb_types {
			/**
			{a.k.a} FIFO **/
			    lbb_reader=1,
			/**
			{a.k.a} C.PIPE **/
			    lbb_socket=2,
			/**
			{a.k.a} DIRECTORY **/
			    lbb_dir=3, 
			/**
			{a.k.a} B.FILE **/
			    lbb_field=4,
			/**
			{a.k.a} BOOK **/
			    lbb_1, //binary
			    lbb_2, //
			    lbb_3,
			    lbb_4,
			    __lbb_roof // roof can be adjusted with updates
		};
	typedef enum __lbb_types lbb_t;

	#endif

	#ifndef lbb_size
		#define lbb_size(x) (ulong)((1<<(x*3)))
	#endif

	#ifndef lbb_entry
		enum __lbb_entries {
			__lbb_none__=-1,		// no entry
			__lbb_charms__='@',		// @charms
			__lbb_yeild__=1,		// @lbb
			__lbb_info__=0,			// (null)==ixr
			__lbb_variable__='*',	// *
			__lbb_atp__				// @*
		};
	typedef enum __lbb_entries lbb_entry;
		#define entry_name(x) __atp_names(x)
		#define log_entry(x) log_str(entry_name(x))

	#endif

	static const char *__lbb_indexfile = "@charms/lbb/.lbb\0";
	static const char *__lbb_convdir = "@charms/lbb\0";
	static const char *__lbb_locking = "@charms/lock\0";

	#define __LBB_TYPES { lbb_t, lbb_size, lbb_entry }
#endif

#ifndef __IXR_TYPES
	/**
	 * putting this here because i have a tendency to
	 * forget things like this when i am developing.
	 * 
	 * The simplist way to explain how the d-* works
	 * is by realizing the structure of which it's built on.
	 * 
	 * The very first and the only two main actual types :: `ixr` &-> `lbb`.
	 * 
	 * The full first version of the d-language is ::: ATP IXR LBB 
	 * 
	 * `ixr` {a.k.a Indexer} is the initial d-type at all times.
	 * `lbb` {a.k.a Linked Binary Book} are just mod(s) applied on any of the ixr types.
	 * 
	**/
	enum __ixr_types {
		__ixr_header,
		ixr_point,
		ixr_file,
		ixr_dprg,
		ixr_fld
	};
	typedef enum __ixr_types ixr_t;

	#ifndef ixr_st
			struct __ixr_st {
				ulong c_index;
				char const *c_name;
				uchar const *c_ref;
			};
	typedef struct __ixr_st ixr_st;
			#define ixr_cis_p(x) ((ixr_st *)(&x))
			#define ixr_cis(x) ((ixr_st *)x)
			#define ist_index(x) ((ulong)(ixr_cis(x)->c_index))
			#define ist_name(x)	 ((char const *)(ixr_cis(x)->c_name))
			#define ist_ref(x) ((uchar const *)(ixr_cis(x)->c_ref))
	#endif

	#ifndef __fmt_t
	enum __fmt_t {
		__nofmt__='\0',
	    nfmt=0,
	    __idxr__,
	    hdr_t=__idxr__+3, // _S_D_C_
	    __keyval__,
	    kvi_t=__keyval__+3, // i : k : v
	    __envvar__,
	    bas_t=__envvar__+3, // i : e = v
	    __pathmut__,
	    pat_t=__pathmut__+3, // i : p := a
	    __fld__,
	    pld_t=__fld__+3, // i : s =: d
	    __intrprt__,
	    ipr_t=__intrprt__+1, // < i >
	    __csok__,
	    sok_t=__csok__+1, // @s
	    __call__,
	    atp_c=__call__+3, // @s<i>{ p }
	};
	typedef enum __fmt_t fmt_t;
	#endif

	#ifndef ixr_h
			struct __ixr_h {
				ulong __size;
				ulong d_count;
				ulong checksum;
				uchar head[__I_LEN];	
			};
	typedef struct __ixr_h ixr_h;
		#define ixr_header ixr_h

	#endif

	
	enum __lbb_add_t {
		__command, 
		__filepath, 
		__function,
		__field,
		__addr
	};
	typedef enum __lbb_add_t lbb_at;


	#define __IXR_TYPES { ixr_t, ixr_st, ixr_h }
#endif

#ifndef __ATP_TYPES

	#ifndef aip_sterm
		// S structure
		enum __sterm {
			Public='u',
			Private='v'
		};
	typedef enum __sterm aip_sterm;

	#endif
	
	#ifndef aip_stat
		struct __s_stat {
			char s_path[256];
			char s_ipv[16];
			ulong sa_len;
			char s_addr[64];
			ulong se_len;
			enum __sterm s_term;
		};
	typedef struct __s_stat s_stat;
		#define __s_port "9999"
	
	#endif

	#ifndef aip_sock
		struct __sok_st {
		    ulong aip_sockfd;
		    ulong aip_socklen;
		    d_portal *aip_sockst;
		};
	typedef struct __sok_st aip_sock;
		#define aip_sockfd(x)	((ulong)(x.aip_sockfd))
		#define aip_socklen(x)	((ulong)(x.aip_socklen))
		#define aip_socket(x)	((ulong)(x->aip_sockst))
	
	#endif


	#ifndef aip_arc
		#ifndef arc_s
			/**
			 * each step is a specific `ARC` call
			 * and yes, the step indicates the
			 * size in bytes
			**/
			enum __arc_sizes {
				__step_point=8,
				__step_addr=16,
				__step_sok=128,
				__step_start=256,
				__step_mor=512
			};
		typedef enum __arc_sizes arc_sizes;

		#endif

		#ifndef arc_st
			struct __arc_st {
				aip_sock __sok;
				ulong __pid;
				int __fork;
				ulong __next;
				d_point **__points;
			};
	typedef struct __arc_st aip_arc;
			// returns true for child process
			#define arc_process (!__arc.__fork) 
			#define arc_pid(x)	((ulong)(x->__pid))
			#define arc_fork(x) ((int)(x->__fork))
			#define arc_next(x) ((ulong)(x->__next))
			#define arc_points(x) ((dpoint_t **)(x->__points))

		#endif
	
	#endif

	#ifndef aip_act
		enum __aip_action {
			aip_base=~__lbb_atp__,
			aip_get,
			aip_set,
			aip_return, // return : to caller
			aip_retain, // save
			aip_retreive, // collect :  get AND THEN { &-> } return to caller
			aip_dcloud,
			aip_next
		};
	typedef enum __aip_action aip_act;
	
	#endif

	#ifndef aip_st
		struct __aip_st {
			int switcher;
			int action_type;
			ulong args_length;
			char const **args;
		};
	typedef struct __aip_st aip_st;
		#define aip_switch(x) (x->switcher)
		#define aip_action_t(x) (x->action_type)
		#define aip_args_count(x) ((ulong)(x->args_length))
		#define aip_args(x) ((char const **)args)
		#define aip_arg(x,n) ((char const *)((x->args)[n]))
		#define aip_base(x) aip_arg(x, 0)

	#endif
	
	#define __ATP_TYPES { aip_sterm, aip_stat, aip_sock, aip_arc, aip_act }
#endif


#endif
