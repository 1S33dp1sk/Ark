/// unsigned types \\\


#ifndef __UTYPES__H
	#define __A_LEN 512
	#define __P_LEN 8
	#define __I_LEN 64
	#define __API_LEN (__A_LEN+__P_LEN+__I_LEN)
	#ifndef uns
		#define uns unsigned int
	#endif
	#ifndef uchar
		#define uchar unsigned char
	#endif
	#define __d8 unsigned long
	#define __t8 unsigned long long

	typedef __d8 ulong;
	typedef __t8 tlong;

	enum __lbb_types {
		__unknown,
		__path_sys,
		__proto_call,
		__intrp_decl,
		__payld_entr
	};
	typedef enum __lbb_types lbb_t;

	enum __types_f {
		FLD_STORAGE=0,
		F_FIFO_LD=1,
		FL_LOCK_D=2,
	};
	typedef enum __types_f type_f;

	enum __atypes_ {
		atp='0',
	    at4=4,
	    at6=6,
		ate='e',
	};
	typedef enum __atypes_ at_t;

	enum __stypes {
	    __sAF_INET=2,
	    __sAF_INET6=30
	};
	typedef enum __stypes sAF_type;

	enum __step_size {
		__step_point=8,
		__step_addr=16,
		__step_sok=128,
		__step_start=256,
		__step_mor=512
	};
	typedef enum __step_size stp_size;

	struct __st_points {
		ulong __index;
		char const *__ref;
		char const *__name;
	};
	typedef struct __st_points dpoint;

	struct __arc_t {
		ulong __pid;
		int __fork;
		ulong __next;
		dpoint **__points;
	};
	typedef struct __arc_t arc_t;

	struct __sok_t {
	    ulong aip_sockfd;
	    ulong aip_socklen;
	    char aip_socket[128];
	};
	typedef struct __sok_t aipsock;
		
	/**
	 * M-structure {a.k.a mounted} **
	                                */
	struct __m_stat {
	    ulong m_size;
	    ulong m_mode;
	    ulong m_blksz;
	    ulong m_inn;
	    char m_path[512];
	};
	typedef struct __m_stat m_stat;

	struct __ixr_h {
		ulong __size;
		ulong d_count;
		ulong checksum;
	};
	typedef struct __ixr_h ixr_h;


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
        atp_t=__call__+3, // @s<i>{ p }
    };
    typedef enum __fmt_t fmt_t;

	enum __fmt_cats {
		__cval=4, //commands
		__refs=8, //references
		__intr=64, //interpreters
		__payl=512, //payloads,
		__lbb //all others e.g binaries
	};
	typedef enum __fmt_cats cfmt;

	struct __dpoint_indexes {
	    ulong count;
	    ulong filesize;
	    dpoint **idxrs;
	};
	typedef struct __dpoint_indicies dices;

	// supported file types
	enum __ftypes {
		/**
		{a.k.a} FIFO **/
		    f_reader=1,
		/**
		{a.k.a} C.PIPE **/
		    f_socket=2,
		/**
		{a.k.a} B.FILE **/
		    f_field=3,
		/**
		{a.k.a} DIRECTORY **/
		    f_dir=4, 
		/**
		{a.k.a} BOOK **/
		    fld_1, //binary
		    fld_2, //
		    fld_3,
		    fld_4
		};
	typedef enum __ftypes fld_t;

	// supported file sizes
	enum __ftypes__size {
		    __freader_sz=8,
		    __fsocket_sz=64,
		    __ffield_sz=512,
		    __fdir_sz=4096,
		    __fld1_sz=32768,
		    __fld2_sz=262144,
		    __fld3_sz=2097152,
		    __fld4_sz=16777216
		};
	typedef enum __ftypes__size fld_sz;


	/**
	 * string manipulation **
							*/
	struct __str {
		int len;
		char *data;
	};
	typedef struct __str strld;

	struct sepstr {
		char *str;
		int str_length;
		char *sep;
		int sep_offs;	
	};
	typedef struct sepstr spstr;

	/**
	 * K-structture **
					 */
	struct __ptrdx {
		ulong pidx;
		ulong tri;
	};
	union __exs_ptr {
		ulong *esptr;
		struct __ptrdx ptrdx;
	};
	struct __k_stat {
		char u_name[8];
		union __exs_ptr exsp;
		char i_addr[512];
	};
	typedef struct __k_stat k_stat;

	/**
	 * S-structure {a.k.a socket} **
								   */
	enum __sterm {
		__pub=0,
		__pvt
	};

	struct __s_stat {
		char s_path[256];
		char s_ipv[16];
		ulong sa_len;
		char s_addr[64];
		ulong se_len;
	#define __s_port "9999"
		enum __sterm s_term;
	};
	typedef struct __s_stat s_stat;

	struct __contents {
	    ulong len;
	    uchar et[512];
	};
	typedef struct __contents __ucont;
	typedef char __uname[24];
	struct __ucname__ {
	    __uname uname;
	    __ucont contents;
	};
	typedef struct __ucname__ field;
	typedef field* fld;
	typedef fld* fields;

	struct __shard {
		m_stat sd_mstat;
		field sd_fld;
	};
	typedef struct __shard shard;

	struct __lbb_shard {
		struct __m_stat lbb_mst;
		ulong lbb_fd;
	};
	typedef struct __lbb_shard lshard;

	struct __in_pia {
		char pointer[__P_LEN];
		char interpreter[__I_LEN];
		char args[__A_LEN];
	};
	typedef struct __in_pia pia_st;

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

	struct __socket_address {
		enum __atypes_ _atype;
		void *_sokaddr;
		char _sockaddr[128];
		char ascii_addr[__I_LEN];
	};
	typedef struct __socket_address aip_addr;

    enum __sha3_return {
        __sha3_u_ok = 0,
        __sha3_u_n = 1
    };
    typedef enum __sha3_return sha3_return_t;

    enum __sha3_flags {
        __sha3_flag_none__ = 0,
        __sha3_flag_keccak__ = 1
    };
    typedef enum __sha3_flags sha3_config_t;
    struct __ptr_addr {
	    void *m_ace;//memory access
	    char address[__P_LEN];
	};

	struct __intr_addr { 
		void *s_mnt;
		char address[__I_LEN];
	};

	struct __payld_addr {
		void *a_sok;
		char address[__A_LEN];
	};

	struct __paddr {
		void *ptr;
		char *addr;
	};

	typedef struct __paddr addr_p;

	#define i_argument(i) (i->argument)
	#define i_ptype(i) (i->arg_t)

static const char *__lbb_indexfile = "@charms/lbb/.lbb\0";
static const char *__lbb_convdir = "@charms/lbb\0";
static const char *__lbb_locking = "@charms/lock\0";

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
		static ulong __cindex;

		struct _u2st {
			ulong _1;
			ulong _2;
			ulong _3;
		};
		static struct _u2st ua;

		#define __u2__(x) (x->_1=u[0]; x->_2=u[1];c->_3=u[2])
		#define __u2(x) (u1__=u[0]; u2__=u[1];c->_3=u[2]) 

typedef struct _u2st _u2s;
typedef struct _u2st * pt2s;
		static pt2s up=(pt2s)&ua;
#define vt2s(x) (void *(x))
		static ulong u[3];
#define u1__ ua._1
#define u2__ ua._2
#define u3__ ua._3
	#define __UTYPES__H 1
#endif
