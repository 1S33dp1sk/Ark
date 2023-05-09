
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __D_CHARMS 4
	#define README __readme
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
	#define _ARK =ARK
	#define Alpha ixr_h *IXR = 
	#define __dPRG ixr_h *main(int argc, char const*argv[])
	#define charm_mod __mod_call(charms_d)
	#define run_mod __combine_str(charm_mod, "run/")
	#define lbb_mod __combine_str(charm_mod, "lbb/")
	#define out_mod __combine_str(charm_mod, "out/")
	#define src_mod __combine_str(charm_mod, "src/")
	#define CHARMS_BASE (ulong)str_rwings(charms_d)
	#define SRC_BASE (ulong)str_rwings(d_src)
    #define ixr_shared_size ((ulong)___header.shared_size)
    #define ixr_mods_count	((ulong)___header.mods_count)
    #define ixr_pub_address	((char const *)___header.pub_key)
	#define checkef_lo ((ulong)__sokres(arch_callport))
	#define checkef (ulong)__stres(arch_filename)
	#define check_archfile(x) (get_mstat(x, lbb_mstat)!=1)
	#define __r_operation &
	#define __into_call "&->"
	#define __t_operation 3
	#define __ECHO__ __TEXT(0, Ark)
	#define __PAGE_CLEAR "\n\n\n\n\n\n\n"
	#define ATP __ATP__
	#define __ARK__ __LBB__ ATP
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
	#define lbb_out(fmt, ...) __TRAV(3, \n, json_handler(__VA_ARGS__))
	#define lbb_putAddr(a,b) __TRAV(3, \n, lbb##a=:#b)
	#define lbb_putPath(a,b) __TRAV(3, \n,#a:=b)
	#define lbb_putJson(a,b) __TRAV(3, \n,#a:b)
	#define lbb_putVar(a,b) __TRAV(3, \n,#a=#b)
	#define lbb_putTag(a,b) __TRAV(3, \n<a>b,</a>)
	#define handler *(*_fname)(void *x) {\
		m_stat ms = (m_stat *)(aptr);\
		log_mstat(ms);\
	};
	#define __LBB__(a,b,...) Alpha &___header;\
		___header.alias = __ixr_strt(#a);\
		___header.pvt_key = #b;\
		printf("IXR: %s ::%d\n",#a,__arch__(___header.alias));\
		__TRAV(3,@charms:a,lbb<#b>);\
		__VA_ARGS__;\
		indexer_end();\

	#define __IXR__ {\
		__shard__();__dbuf__();\
	};
	#define M_ARG(...) (__VA_ARGS__)[0]
	#define F_ARG(...) (__VA_ARGS__)[1]
	#define dPRG(...)  __cPRG {__VA_ARGS__;}
	#define mod(...) mod_##__VA_ARGS__
	#define readme(x) #x##"/README.md"
	#define __readme(x){\
		_ixr_prg.prg_handler = "/usr/bin/nano";\
		program(_ixr_prg, IXR&->x/README.md);\
		dprg_run(_ixr_prg);\
	}
	#define checkef_file(x,y) ((ulong)__stres(x)&&(ulong)__stres(y))
	#define checkef_dir(x) ((ulong)__stres(x))
	#define check_caller(x) ((ulong)__exact_match(__address(x), uni_address))
	// base for charms
	#define __ATP__(...) const void **temp; {\
		__TEXT(0, @-Protocol);\
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
		printf("ixr=1>getting shard\t.:%s:.\n",uni_address);\
		printf("ixr=2>getting alias\t(%s)\n", loc_address);\
		printf("ixr=3>getting domain\t//%s\n", glo_address);\
		printf("ixr=4>getting network\t:%s\n", mac_address );\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
	};
	#define __dbuf__() {\
		memset(&dbuf, 0, sizeof(dbuf));\
	};
	#define __arch__(x) !check_archfile(arch_fld(x))?arch_att(arch_fld(x), 3, __API_LEN):0
	#define __call__(a,l) str_a4offset(a, sep_offset(#a, l))+str_rwings(l)-1
	#define __call_base(...) __call__(__VA_ARGS__, __into_call)
	#define modbase_call(x) __combine_str(run_mod, __call_base(x))
	#define Scratch(...) printf("%s\n", modbase_call(#__VA_ARGS__))
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
