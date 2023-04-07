
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __dPRG int main(int argc, char const*argv[]) 
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define checkef_file ((ulong)__stres(__lbb_indexfile))
	#define checkef_dir ((ulong)__stres(__lbb_convdir))
	#define checkef_lo ((ulong)__stres(__lbb_locking))
	#define INDEXER(x) x!=NULL?__indexer__(x):indexer_start()
    #define dPRG(...) __dPRG {__VA_ARGS__;}
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
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
	#define __lock_reader (O_RDONLY)
	#define __lock_writer (O_WRONLY)
	#define d_charms "@charms/d.\0"
	#define d_lbb "@charms/d.lbb\0"
	#define d_atlbb "@charms/d.lbb/.lbb\0"
	#define arch_filename d_atlbb
	#define d_sep ":\0"

	#define __ATP__(...) {\
		__ARGC__;\
		__ARGV__;\
		__VA_ARGS__;\
		return 0;\
	}
	#define __IXR__(...) {\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
		printf("getting shard .:%s:. \n",__lbb_indexfile);\
		if(!checkef_file){INDEXER(NULL);}\
		get_mstat(__lbb_indexfile,lbb_mstat);\
	}
	#define __LBB__(...) {\
		if(!checkef_file){INDEX_START("");}else{INDEX_READ("");};\
		__BASE__ __ARK__(__VA_ARGS__);\
		__VA_ARGS__;\
		INDEX_END("\n");\
	}	
	#define __BASE__(d_atp, d_lbb, d_ixr, entry, ...) {\
		_Generic((d_atp), \
			int: printf("@ATP : %d\n",d_atp));\
		_Generic((entry), \
			const char **: printf("%s\n", entry));\
	}
	#define __ARK__(...) {\
		__ARGC__; __ARGV__; __VA_ARGS__;\
		void const **__VARGS__=vcontent(#__VA_ARGS__);\
		ulong __VA_SIZE__=__rwings(__VARGS__);\
		__BASE__(__ARGC__#__VA_ARGS__, __VARGS__, __VA_SIZE__, __ARGV__, __ARGV__[0]);\
	}
#endif		
