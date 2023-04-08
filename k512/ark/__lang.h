
/************************ d-language ************************/

#ifndef _D_LANG
	#define _D_LANG 1
	#define __dPRG int main(int argc, char const*argv[]) 
	#define __ARGC__ argc
	#define __ARGV__ argv
	#define d_charms "@charms/d.\0"
	#define d_lbb "@charms/d.lbb\0"
	#define d_atlbb "@charms/d.lbb/.lbb\0"
	#define d_lock "@charms/lock\0"
	#define d_sep ":\0"
	#define checkef_file ((ulong)__stres(d_atlbb))
	#define checkef_dir ((ulong)__stres(d_lbb))
	#define checkef_lo ((ulong)__stres(d_lock))
	#define INDEXER(x) x!=NULL?__indexer__(x):indexer_start()
	#define __INDEXER__(...) {\
		if(!checkef_file){INDEXER(NULL);}\
		__ARGC__;\
		__ARGV__;\
		__VA_ARGS__;\
		return 0;\
	}
    #define dPRG(...) __dPRG __INDEXER__(__VA_ARGS__)
	#define __DPRG__(...) __LBB__(__VA_ARGS__) __dPER
	#define __LBB__(...) {\
		__BASE__\
		__VA_ARGS__;\
		INDEX_END("\n");\
	}
	#define __BASE__ {\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
		printf("getting shard .:%s:. \n",__lbb_indexfile);\
		if(!checkef_file){INDEXER(NULL);}\
		get_mstat(__lbb_indexfile,lbb_mstat);\
	}
	#define __TYPD__(d) {\
		__BASE__\
		printf("sizeof type-d : %lu\n",sizeof(d));\
	}
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
	#define arch_filename d_atlbb
	#define __init_method__(...) (#__VA_ARGS__)()
	#define __base_address ((char const *)hashof(0, __FILE__, str_rwings(__FILE__)-1))


	#define __INIT__(t) __ASCII(hash(1, "okok", 3));

<<<<<<< HEAD
=======
	#define __ATP__(...) {\
		__ARGC__;\
		__ARGV__;\
		get_atp_type(__VA_ARGS__);\
		return 0;\
	}
	#define __IXR__ {\
		static char dbuf[__A_LEN];memset(&dbuf, 0, sizeof(dbuf));\
		memset(lbb_mstat, 0, sizeof(m_stat));\
		memset(l_shard,0,sizeof(c_shard));\
		printf("getting shard .:%s:. \n",d_atlbb);\
		if(!checkef_file){INDEXER(NULL);}\
		get_mstat(d_atlbb,lbb_mstat);\
	}
	#define __BASE__(d_atp, d_lbb, d_ixr, argc, entry, ...) {\
		switch((*d_atp)) {\
			case '1': printf("<ATP> : scratch-space\n"); break;\
			case '9': printf("<lbb> : %s\n", (char const *)(d_atp)); break;\
			default: printf("<draft>: %s\n", (char const *)(d_atp)); break;\
		};\
		__ATP__(entry[2]);\
		__TEXT(Storage Size =>);\
		__ASCII(d_lbb);\
		__TEXT(Indexer-);\
		__ASCII(entry);\
		__TEXT(@-Protocol =>);\
		__ASCII(d_atp);\
		do {\
		_Generic((*entry), \
			const char *: printf("var[%d]: %s\n", argc, entry[argc]));\
		}while(--argc!=0);\
	}
	#define __ARK__(...) {\
		__ARGC__; __ARGV__;\
		char const *__ARGS__=#__VA_ARGS__;\
		void const **__VARGS__=vcontent(__VA_ARGS__);\
		ulong __VA_SIZE__=__rwings(__VARGS__);\
		__BASE__(__ARGS__, __VA_SIZE__, __VA_ARGS__, __ARGC__, __ARGV__);\
	}
	#define __LBB__(...) {\
		__ARK__(__VA_ARGS__);\
		__VA_ARGS__;\
		INDEX_END("\n");\
	}

	#define __ZERO__(x, ...) ((char const *)(zero_address(x)))

	#define handler *(*_fname)(void *x) {\
		m_stat ms = (m_stat *)(aptr);\
		log_mstat(ms);\
	}






>>>>>>> b21fe21 (Threeway convos {LBB,IXR,ATP})
#endif		
