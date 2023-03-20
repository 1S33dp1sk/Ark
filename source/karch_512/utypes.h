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

/**
 * putting this here because i have a tendency to
 * forget things like this when i am developing.
 * 
 * The simplist way to explain how the d-* works
 * is by realizing the structure of which it's built on.
 * 
 * The very first and the only two main actual types :: `ixr` &-> `lbb`.
 * 
 * `ixr` {a.k.a Indexer} is the initial d-type at all times.
 * `lbb` {a.k.a Linked Binary Book} are just mod(s) applied on any of the ixr types.
 * 
**/

enum __ixr_types {
	ixr_header,
	ixr_point,
	ixr_file,
	ixr_dprg,
	ixr_fld
};
typedef enum __ixr_types ixr_t;

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

struct __dpoint_t {
	ulong c_index;
	char const *c_name;
	uchar const *c_ref;
	char const *d_fmt;
};
typedef struct __dpoint_t dpoint_t;
	static const ulong size_dpoint_t=sizeof(dpoint_t);
	#define dpoint_p(x)		((dpoint_t *)x)
	#define dpoint_fmt(x)	((char const *)dpoint_p(x)->d_fmt)

struct __ixr_h {
	ulong __size;
	ulong d_count;
	ulong checksum;
	uchar head[__I_LEN];	
};
typedef struct __ixr_h ixr_h;

struct __path_t {
	ulong c_index;
	char const *c_name;
	uchar const *c_ref;
	char const *p_checksum;
	ulong p_offset;
};
typedef struct __path_t path_t;
	static const ulong size_path_t=sizeof(path_t);
	#define path_checksum(x) ((char const *)x->p_checksum)
	#define path_offset(x) ((ulong)x->p_offset)

struct __dprg_t {
	ulong c_index;
	char const *c_name;
	uchar const *c_ref;
	char const *prg_in;
	char const *prg_out;
	char const *prg_handler;
};
typedef struct __dprg_t dprg_t;
	static const ulong size_dprg_t=sizeof(dprg_t);
	#define dprg_in(x) ((char const *)x->prg_in)
	#define dprg_out(x) ((char const *)x->prg_out)
	#define dprg_handler(x) ((char const *)x->prg_handler)

struct __fld_t {
	ulong c_index;
	char const *c_name;
	uchar const *c_ref;
	char const *f_address;
	char const *f_alias;
	int f_flags;
};
typedef struct __fld_t fld_t;
	static const ulong size_fld_t=sizeof(fld_t);
	#define fld_address(x) ((char const *)x->f_address)
	#define fld_dname(x) ((char const *)x->f_alias)
	#define fld_flags(x) ((int)x->f_flags)


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

typedef ulong __ul[3];
struct __u2st {
	ulong _1;
	ulong _2;
	ulong _3;
};
typedef struct __u2st u2s;
static u2s ua;
typedef u2s *pt2s;
static pt2s up=(pt2s)&ua;	
#define __u2__(x) (x->_1=u[0]; x->_2=u[1];c->_3=u[2])
#define __u2(x) (u1__=u[0]; u2__=u[1];c->_3=u[2]) 
#define vt2s(x) (void *(x))
#define u1__ ua._1
#define u2__ ua._2
#define u3__ ua._3
static __ul u;



// atp :: {a.k.a @-Protocol} : types
enum __atypes_ {
	__at_p='0',
	__at_4=4,
	__at_6=6,
	__at_e='e',
};
typedef enum __atypes_ at_t;

// needed for inet resolutions
enum __sAF_types {
	__sAF_INET=2,
	__sAF_INET6=30
};
typedef enum __sAF_types sAF_type;

/**
 * each step is a specific `ARC` call
 * and yes, the step indicates the
 * size in bytes
**/
enum __step_size {
	__step_point=8,
	__step_addr=16,
	__step_sok=128,
	__step_start=256,
	__step_mor=512
};
typedef enum __step_size stp_size;


// M structure
struct __m_stat {
	ulong m_size;
	ulong m_mode;
	ulong m_blksz;
	ulong m_inn;
	char m_path[512];
};
typedef struct __m_stat m_stat;

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

enum __fmt_cats {
	_f_lbb, //all others e.g binaries
	_f_refs=8, //references
	_f_intr=64, //interpreters
	_f_payl=512, //payloads,
};
typedef enum __fmt_cats cfmt;

// file mount structure types
enum __fms_types {
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
typedef enum __fms_types fms_t;

// supported file sizes
enum __fms_sizes {
	__freader_sz=8,
	__fsocket_sz=64,
	__ffield_sz=512,
	__fdir_sz=4096,
	__fld1_sz=32768,
	__fld2_sz=262144,
	__fld3_sz=2097152,
	__fld4_sz=16777216
};
typedef enum __fms_sizes fms_s;

/*** string manipulation ***/
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

// K structure
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

// S structure
enum __sterm {
	Public='u',
	Private='v'
};
typedef enum __sterm sterm;

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


// fld :: Fields
struct __fld_content {
    ulong len;
    uchar etc[4096];
};
typedef struct __fld_content fldc_t;
#define content_len(x) (x.len)
#define content_etc(x) (x.etc)

typedef char fldn_t[24];
typedef ulong fldk_t[3];

struct __fld_nck {
    fldn_t fld_name;
    fldc_t fld_con;
    fldk_t fld_keys;
};
typedef struct __fld_nck fld;
#define field_name(x) ((char const *)(x.fld_name))
#define field_content(x) ((char const *)content_etc(x.fld_con))
#define field_length(x) ((ulong)content_len(x.fld_con))
#define field_keys(x) ((ulong *)(x.fld_keys))


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

enum __lbb_entries {
	__lbb_none__=-1,		// no entry
	__lbb_charms__='@',		// @charms
	__lbb_field__=1,		// @lbb
	__lbb_info__=0,			// (null)==ixr
	__lbb_variable__='*',	// *
	__lbb_atp__				// @*
};
typedef enum __lbb_entries lbb_entry;

struct __into {
	char const **args;
	char const *caller;
	int req_at;
};
typedef struct __into into_st;

enum __at_protocol {
	atp_base=__lbb_atp__,
	atp_get=atp_base+__lbb_variable__,
	atp_set,
	atp_return, // return : to caller
	atp_retain, // save
	atp_retreive, // collect :  get AND THEN { &-> } return to caller
	atp_dcloud,
	atp_next
};
typedef enum __at_protocol atp_t;



#define i_caller(i)		(char const *)(i->caller)
#define i_type(i)		(lbb_entry)(i->req_at)
#define i_proto(i)		(atp_t)(i->req_at)
#define i_base(i)		((int)(i->req_at))
#define i_args(i)		(char const **)(i->args)
#define i_narg(i, n)	(char const *)((i->args)[n])
#define i_argument(i)	i_narg(i, 0)

#define into_caller(i, c) i.caller=(char const *)c;
#define into_type(i, t) i.req_at=(int)t;
#define into_args(i, a) i.args=(char const **)a;
#define typepoint(i) i_type((&i))


struct __socket_address {
	at_t _atype;
	void *_sokaddr;
	char _sockaddr[128];
	char ascii_addr[__I_LEN];
};
typedef struct __socket_address aip_sockaddr;

enum __sha3_return {
	__sha3_u_ok=0,
	__sha3_u_n=1
};
typedef enum __sha3_return sha3_return_t;

enum __sha3_flags {
	__sha3_flag_none__=0,
	__sha3_flag_keccak__=1
};
typedef enum __sha3_flags sha3_config_t;

struct __ptr_addr {
	char const *chkref;
	void *ptr;//memory access
	char address[__P_LEN];
};
typedef struct __ptr_addr ptr_st;

struct __intr_addr { 
void *intr;
char address[__I_LEN];
};
typedef struct __intr_addr intr_st;

struct __payld_addr {
void *payld;
char address[__A_LEN];
};
typedef struct __payld_addr payld_st;

struct __cis_addr {
	char const *ref;
	void *ptr;
	char *addr;
};
typedef struct __cis_addr cis_st;
#define addr_ref(x) ((char const *)x->ref)
#define addr_ptr(x) ((void *)x->ptr)
#define addr_size(x) ((ulong)sizeof((x->addr)))
#define addr(x) ((char *)((&x->addr)+addr_size(x)))

static const char *__lbb_indexfile = "@charms/lbb/.lbb\0";
static const char *__lbb_convdir = "@charms/lbb\0";
static const char *__lbb_locking = "@charms/lock\0";


static uchar pbuffer[__A_LEN];
static uchar *pbuf=(uchar *)&pbuffer;



#define __UTYPES__H 1
#endif
