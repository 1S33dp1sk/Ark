
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __PASS_ATP_D 0x1000
	#define __PASS_MAX_D 0x200
	#define __PASS_MID_D 0x40
	#define __PASS_MIN_D 0x8
	#define __PASS_MIN_C 3
	#define __D_CHARMS 4
	#define __dPRG struct __c_shard *main(__ARGC__,__ARGV__) 
	#define __cPRG int main(int argc, char const*argv[]) 
	#define dPRG(...) __cPRG {__VA_ARGS__;}
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define F_ARG __VA_ARGS__[1]
	#define M_ARG __VA_ARGS__[0]
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)
	#define __address(l,x) ((char const *)hashof(l, x, str_rwings(x)))
	#define base_address(l) ((char const *)__address(l, __FILE__))
	#define __base_address ((char const *)base_address(0))
	

	#define ARK_BASE __base_address


	// base for charms
	#define charms_d "@charms/d.\0"
	#define CHARMS_BASE (ulong)str_rwings(charms_d)

	// LBB
	#define d_lbb "lbb/\0"
	#define LBB_BASE (ulong)str_rwings(d_lbb)

	// ATP
	#define d_atp "run/\0"
	#define ATP_BASE (ulong)str_rwings(d_atp)

	// IXR
	#define d_ixr "out/\0"
	#define IXR_BASE (ulong)str_rwings(d_ixr)

	// SRC
	#define d_src "src/\0"
	#define SRC_BASE (ulong)str_rwings(d_src)


	#define d_sep ":\0"
	#define arch_filename "@charms/__3c__\0"
	#define arch_callport "9999"
	#define checkef_file(x,y) ((ulong)__stres(x)&&(ulong)__stres(y))
	#define checkef_dir(x) ((ulong)__stres(x))
	#define check_caller(x) ((ulong)__exact_match(__address(x), base_address(3)))
	#define checkef_lo ((ulong)__sokres(arch_callport))
	#define checkef (ulong)__stres(arch_filename)
	#define check_archfile (get_mstat(arch_filename, lbb_mstat)!=1)
	#define __ECHO__ __TEXT(Ark)
	#define handler *(*_fname)(void *x) {\
		m_stat ms = (m_stat *)(aptr);\
		log_mstat(ms);\
	};
	#define __ATP__(...) {\
		__TEXT(@-Protocol);\
		if(*__VA_ARGS__[1]!='@'){ get_atp_type(__VA_ARGS__[1] ); }\
		else { lbb_argument(__VA_ARGS__[1]); };\
	};
	#define __IXR__(c_name, shard_props) {\
		__TEXT(IXR);\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
		printf("getting shard .:%s:. \n",__base_address);\
		if(!check_archfile) { arch_att(arch_filename, 3, __API_LEN); };\
	};
	#define __LBB__(type, key, value) {\
		__TEXT(lbb);\
		__set_next("\n");\
	};
	#define BASE(d_atp, d_lbb, d_ixr, argc, entry, ...) {\
		__TEXT(Ark ⚡);\
		__ASCII(d_atp); __ASCII(d_lbb);\__ASCII(d_ixr);\
		do {\
		_Generic((*entry), \
			const char *: printf("var[%d]: %s\n", argc, entry[argc]));\
		}while(--argc!=0);\
	};
	#define __VARS__(...) {\
		__ARGC__; __ARGV__;\
		__TEXT(__ARGV__);\
		char const *__ARGS__=#__VA_ARGS__;\
		void const **__VARGS__=vcontent(__VA_ARGS__);\
		ulong __VA_SIZE__=__rwings(__VARGS__);\
		BASE(__ARGS__, __VA_SIZE__, __VA_ARGS__, __ARGC__, __ARGV__);\
	} __dPER


	#define Ark(x, ...) {\
		__ASCII(x);\
		__ASCII(_Generic((__VA_ARGS__), \
			int: "run &=>",\
			char const *: "@-Protocol",\
			char const **: "C-Program",\
			d_into const *: "D-Program",\
			d_ark const *: dark(int)));\
	} break;



	#define s_into(x) (char const *)(x)[0]
    #define info() __ASCII(__os_name);__ASCII(__FILE__)
	#define zero(x)  ((char const *)(&(zero_address)));
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
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
	#define __init_method__(x, ...) x==0?&info:&zero;
	#define __INFO__(x,...) { info(); }

	

	#define ATP(a) __ATP__(a); break;
	#define IXR(c,s) __IXR__(c,s) break;
	#define LBB(t,k,v) __LBB__(t,k,v); break;




#endif		
