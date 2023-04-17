
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __PASS_ATP_D 0x1000
	#define __PASS_MAX_D 0x200
	#define __PASS_MID_D 0x40
	#define __PASS_MIN_D 0x8
	#define __PASS_MIN_C 3
	#define __D_CHARMS 4
	#define Alpha ixr_h *IXR = 
	#define __dPRG ixr_h *main(int argc, char const*argv[])
	#define __cPRG int main(int argc, char const*argv[]) 
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)
	#define __base_address ((char const *)base_address(0))
	#define ARK_BASE __base_address
	#define M_ARG(...) (__VA_ARGS__)[0]
	#define F_ARG(...) (__VA_ARGS__)[1]
	#define __IXR "IXR\0"
	#define dPRG(...) __cPRG {__VA_ARGS__;}
	#define base_address(l) ((char const *)__address(l, __FILE__))
	#define __address(l,x) ((char const *)hashof(l, x, str_rwings(x)))

	#define README __readme
	#define mod(...) mod_##__VA_ARGS__
	#define readme(x) #x##"/README.md"
	#define __readme(x){\
		_ixr_prg.prg_handler = "/usr/bin/nano";\
		program(_ixr_prg, IXR&->x/README.md);\
		dprg_run(_ixr_prg);\
	}




	// base for charms
	#define charms_d "@charms/d.\0"
	#define d_charms "charms"
	#define CHARMS_BASE (ulong)str_rwings(charms_d)

	// LBB
	#define d_lbb "lbb\0"
	#define LBB_BASE (ulong)str_rwings(d_lbb)

	// ATP
	#define d_atp "run/\0"
	#define ATP_BASE (ulong)str_rwings(d_atp)

	// IXR
	#define d_ixr "out\0"
	#define IXR_BASE (ulong)str_rwings(d_ixr)

	// SRC
	#define d_src "src\0"
	#define SRC_BASE (ulong)str_rwings(d_src)


	#define d_sep ":\0"
	#define arch_filename "@charms/d.lbb/.lbb\0"
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
	#define __ATP__(...) const void **temp; {\
		__TEXT(@-Protocol);\
		int x=lbb_argument(#__VA_ARGS__);\
		temp=(const void**)&#__VA_ARGS__;\
		switch(x) {\
			case __lbb_none__: 		return __no_entry__(#__VA_ARGS__);\
			case __lbb_charms__: 	return __field__(#__VA_ARGS__);\
			case __lbb_variable__:	return __point__(#__VA_ARGS__);\
			case __lbb_info__:		return __info__(#__VA_ARGS__);\
			case __lbb_yeild__:		return __w3__(#__VA_ARGS__);\
			case __lbb_atp__:		x = get_atp_type(#__VA_ARGS__);\
			default: break;\
		};\
		switch(x) {\
			case aip_base:		return ixr_export(#__VA_ARGS__);\
			case aip_return:	return ixr_run(#__VA_ARGS__);\
			case aip_retreive:	return ixr_collect(#__VA_ARGS__);\
			case aip_retain:	return ixr_save(#__VA_ARGS__);\
			case aip_set:		return atp_set(#__VA_ARGS__);\
			case aip_get:		return atp_get(#__VA_ARGS__);\
			case aip_next:		x = get_ixr_type(#__VA_ARGS__);\
			default: break;\
		};\
		switch(x) {\
			case 1: printf("1 arg"); break;\
			case 2: printf("2 args"); break;\
			default: printf("2+ args"); break;\
		};\
		return ne__;\
	};

	#define __shard__() {\
		printf("lbb<%s> getting shard .::. \n",__base_address);\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
	};
	
	#define __dbuf__() {\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
	};

	#define __arch__() !check_archfile?arch_att(arch_filename, 3, __API_LEN):0;

	#define __LBB__ {\
		__shard__();__dbuf__();__arch__();\
	};

	#define __VARS__(...) {\
		__ARGC__; __ARGV__;\
		__TEXT(__ARGV__);\
		char const *__ARGS__=#__VA_ARGS__;\
		void const **__VARGS__=vcontent(__VA_ARGS__);\
		ulong __VA_SIZE__=__rwings(__VARGS__);\
		BASE(__ARGS__, __VA_SIZE__, __VA_ARGS__, __ARGC__, __ARGV__);\
	} __dPER


	#define __r_operation &
	#define __into_call "&->"
	#define __t_operation 3

	#define __call__(a,l) str_a4offset(a, sep_offset(#a, l))+str_rwings(l)-1

	#define __call_base(...) __call__(__VA_ARGS__, __into_call)
	#define modbase_call(x) __combine_str(run_mod, __call_base(x))

	#define Scratch(...) printf("%s\n", modbase_call(#__VA_ARGS__))


	#define Ark(x, ...) {\
		__ASCII(#x);\
		__ASCII(_Generic((__VA_ARGS__[0]), \
			int: "run &->",\
			char const *: "@-Protocol",\
			char const **: "C-Program",\
			d_into const *: "D-Program",\
			d_ark const *: dark(int),\
			IXR: "Indexer => ",\
		default:"default"));\
	};

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
    #define ixr_shared_size ((ulong)___header.shared_size)
    #define ixr_mods_count	((ulong)___header.mods_count)
    #define ixr_pub_address	((char const *)___header.pub_key)
	#define ixr_h_size(x) (x.shared_size)
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
	#define __init_method__(x, ...) x==0?&info:&zero;
	#define __INFO__(x,...) { info(); }

	#define gprg_handler(...) ((char const *)__handler_str(#__VA_ARGS__))


	
	#define ATP(a) __ASCII(cool);


	#define __TERMINAL_PAGE_CLEAR "\n\n\n\n\n\n\n"



#endif		
