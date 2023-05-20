
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __D_CHARMS 4
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)
	#define __base_address mac_address
	#define temp_name "temp\0"
	#define d_src "src/\0"
	#define __IXR "IXR\0"
	#define d_sep ":\0"
	#define arch_filename "@charms/d.lbb/.lbb\0"
	#define arch_callport "9999"
	#define charms_d "@charms/d.\0"
	#define __cPRG int main(int argc, char const*argv[]) 
	#define _Call -> 
	#define _Call_1 =1>
	#define _Call_2 =2>
	#define _Call_3 =3>
	#define __r_operation &
	#define __into_call "&->"
	#define __t_operation 3
	#define _ARK =ARK
	#define Alpha_atp atp_h *ATP = 
	#define Alpha_ixr ixr_h *IXR = 
	#define Alpha_lbb lbb_h *LBB = 
	#define __dPRG ixr_h *main(int argc, char const*argv[])
	#define charm_mod __mod_call(charms_d)
	#define run_mod __combine_str(charm_mod, "run/")
	#define lbb_mod __combine_str(charm_mod, "lbb/")
	#define out_mod __combine_str(charm_mod, "out/")
	#define src_mod __combine_str(charm_mod, "src/")
	#define CHARMS_BASE (ulong)str_rwings(charms_d)
	#define SRC_BASE 	(ulong)str_rwings(d_src)
	#define checkef_lo 		((ulong)__sokres(arch_callport))
	#define checkef 		(ulong)__stres(arch_filename)
	#define __ECHO__ __TEXT(0, Ark)
	#define __PAGE_CLEAR "\n\n\n\n\n\n\n"
	#define check_archfile(x) (get_mstat(x, lbb_mstat)!=1)
	#define __ARK__() {\
	};\

	#define dFUN(x,y,...) static y (x)() __VA_ARGS__;
	#define lang(intrpt, ...) int intrpt;
	#define arch_fld(x) __combine_str(lbb_mod, x)
/**
 * The coefficient KOV
 * a KOV number determines the base sizes of a system
 * instead of arbitrary choosing lengths and values to save
 * to memory which might include complex and semmingly random
 * padding functions and memory allocation techniques. Perhaps,
 * it will be much simplier if we determine a segmentation formula
 * in which we can let systems adapt based on variables and not-preset
 * hardware instructions. 
 * 
 * 
 * a simple KOV=1
 * 
 * where the resulting memory spaces can range 
 * 	K<<n where n=3*i and i iters from 1-4
 * 
 * organizing the memory spaces requires a strict 
 * format in which any interpreter or loader can 
 * decode, thus we can define for a `kov=1`
 * 
 * [i = 1] Key : Value (8-bytes)
 * [i = 2] Key : Reference (64-bytes)
 * [i = 3] Key : Certificate (512-bytes)
 * [i = 4] Key : Linked-Binary-Book (4096-bytes)
 * 
 * However, implementing a decoder functions which accepts different
 * sizes with the same formats, in-practice, leads to security issues, 
 * thus forward variable formats are much more suitable and they
 * provide a more roboust, effective communication adaptive protocol.
 * 
 **/
	#define fld_out(x, fmt, ...) __TRAV(x, \n, __VA_ARGS__)
	#define lbb_out(fmt, ...) __TRAV(3, \n, __VA_ARGS__)
	#define lbb_putAddr(a,b) __TRAV(3, \n, lbb##a=:#b)
	#define lbb_putPath(a,b) __TRAV(3, \n,#a:=b)
	#define lbb_putJson(a,b) __TRAV(3, \n,#a:b)
	#define lbb_putVar(a,b) __TRAV(3, \n,#a=#b)
	#define lbb_putTag(a,b) __TRAV(3, \n<a>b,</a>)
	#define handler *(*_fname)(void *x) {\
		m_stat ms = (m_stat *)(aptr);\
		log_mstat(ms);\
	};
	#define M_ARG(...) (__VA_ARGS__)[0]
	#define F_ARG(...) (__VA_ARGS__)[1]
	#define dPRG(...)  __cPRG {__VA_ARGS__;}
	#define mod(a,...) program(#a, __VA_ARGS__)
	#define readme(x) #x##"/README.md"
	// #define __readme(x){\
	// 	_ixr_prg.prg_handler = "/usr/bin/nano";\
	// 	program(_ixr_prg, IXR&->x/README.md);\
	// 	dprg_run(_ixr_prg);\
	// }
	#define checkef_file(x,y) ((ulong)__stres(x)&&(ulong)__stres(y))
	#define checkef_dir(x) ((ulong)__stres(x))
	#define check_caller(x) ((ulong)__exact_match(__address(x), uni_address))
	// base for charms
	#define __LBB__(a,b,...) lbb_load(a,b)


	#define arg_offset(a, ...) {\
		int i=0,c=0,temp,__temp;\
		char *__args=(char *)&#__VA_ARGS__, *__base, *__name;\
		do {\
			printf("args : %s\n", &__args[c]);\
			__temp = __sep_atoff(&__args[c], ",");\
			if(__temp==-1) {break;};\
			printf("Do loop : %d :: %d\n", i,__temp);i+=1;\
			__name=(char *)b4offset(__args+c, __temp);\
			__base=(char *)a4offset(__args+c, __temp);\
			c+=++__temp;\
			temp = __sep_atoff(__name, #a);\
			printf("name :: %s\n", b4offset(__name, temp));\
			temp = __sep_atoff(__name, __into_call);\
			printf("path :: %s\n", a4offset(__name, temp));\
		} while(__temp!=-1);\
		return run_bcall(#__VA_ARGS__);\
	};

	//arg_offset(:, __VA_ARGS__, Next:NULL);\

	#define __IXR__(p,...) Alpha_ixr &___header;\
		__shard__();\
		img_argc(#__VA_ARGS__);\
		printf("IXR: %s :: %lu\n",#p, ixr_img_argc);\

	
	#define __ATP__(a,d,...) Alpha_atp &___buffer; {\
		__dbuf__();\
		memmove(_atp_domain, #d, str_rwings(#d));\
		__TEXT(0, @-Protocol);\
		const void **ARGS=(const void**)&#__VA_ARGS__;\
		int x=lbb_argument(#__VA_ARGS__);\
		switch(x) {\
			case __lbb_none__: 		x = __no_entry__(#__VA_ARGS__);\
			case __lbb_charms__: 	x = __field__(#__VA_ARGS__);\
			case __lbb_variable__:	x = __point__(#__VA_ARGS__);\
			case __lbb_info__:		x = __info__(#__VA_ARGS__);\
			case __lbb_yeild__:		x = __w3__(#__VA_ARGS__);\
			case __lbb_atp__:		x = get_atp_type(#__VA_ARGS__);\
			default: break;\
		};\
		void *_ptr;\
		into(temp, x, __FILE__, ARGS);\
		switch(x) {\
			case aip_base:		_ptr = ixr_export(#__VA_ARGS__);\
			case aip_return:	_ptr = ixr_prun(temp);\
			case aip_retreive:	_ptr = ixr_pcollect(temp);\
			case aip_retain:	_ptr = ixr_psave(temp);\
			case aip_set:		_ptr = atp_set(#__VA_ARGS__);\
			case aip_get:		_ptr = atp_get(#__VA_ARGS__);\
			case aip_next:		_ptr = get_ixr_type(#__VA_ARGS__);\
			default: break;\
		};\
		switch(x) {\
			case 1: printf("1 arg"); break;\
			case 2: printf("2 args"); break;\
			default: printf("2+ args"); break;\
		};\
	};\

	#define ixr_info() {\
		printf("ixr=1>getting shard\t.:%s:.\n",uni_address);\
		printf("ixr=2>getting alias\t(%s)\n", loc_address);\
		printf("ixr=3>getting domain\t//%s\n", glo_address);\
		printf("ixr=4>getting network\t:%s\n", mac_address );\
	};
	#define __book__() {\
		memset(_lbb_author, 0, __author);\
		memset(_lbb_public_key, 0, __pubkey);\
		memset(_lbb_publisher, 0, __publisher);\
	};
	#define __shard__() {\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
	};
	#define __dbuf__() {\
		memset(_atp_data, 0, sizeof(__atp_data));\
	};
	#define __arch__(x) !check_archfile(arch_fld(#x))?arch_att(arch_fld(#x), 3, __API_LEN):0
	#define __call__(a,l) str_a4offset(a, sep_offset(#a, l))+str_rwings(l)-1
	#define run_bcall(x)		__combine_str(run_mod, __call_base(x))
	#define lbb_bcall(i,x)		__combine_str(lbb_mod, __call_base(__address(i,x)))
	/**
	 * out should be i,x,y ? interpreter, runnable filename, args
	 * src
	 */
	#define __call_base(...) __call__(__VA_ARGS__,__into_call)
	#define Scratch(...) printf("%s\n", __call_base(#__VA_ARGS__))
	#define s_into(x) (char const *)(x)[0]
    #define info() __ASCII(1,__os_name);__ASCII(1,__FILE__)
	#define zero(x)  ((char const *)(&(zero_address)));
	#define d512_read(d,o) (char const *)__readb(512,fd,fo*512)
	#define sz8(x)		((ulong)__8sz(x))
	#define iosze(x)	((ulong)__iosize(x))
	#define dmde(x)		((ulong)__dmode(x))
	#define inn(x)		(ulong)__inodenum(x)
	#define status(x) __statusof(x)
    #define len_ustrze(x) (((ulong)x)*(sizeof(uchar)))
	#define ixr_h_size(x) (x.shared_size)
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
	#define __init_method__(x, ...) x==0?&info:&zero;
	#define __INFO__(x,...) { info(); }

	#define Modules(x) {\
		dout("network",_Generic((x), \
			laddr: "@modules",\
			default: "#err"));\
		ladder_walk(x);\
		arch_att(#x, 1, 512);\
	};\

	#define Ark(x, ...) {\
		__ASCII(3, #x);\
		__ASCII(0, _Generic((__VA_ARGS__[0]), \
			int: "run &->",\
			char const *: "@-Protocol",\
			char const **: "C-Program",\
			d_into const *: "D-Program",\
			d_ark const *: dark(int),\
			IXR: "Indexer => ",\
			default:"default"));\
	};
	#define gprg_handler(...) ((char const *)__handler_str(#__VA_ARGS__))
	#define ARGS(...) __store(__VA_ARGS__) 


	#define TRAVERSE(a,b,...) int x=a;do {\
		OUT_ENK_A(x, __VA_ARGS__);x+=1;\
	}while(x<b);
	#define __TRAV(x, a,b) do {\
		OUT_ENK_A(x, #a);\
		OUT_ENK_A(x, #b);\
	} __dPER;
	

	



#endif		
