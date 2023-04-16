/// lbb \\\
little black book

#ifndef __LBB__H
	#define BOOK_INDEX(x) return __set_next(x);
	#define lbb(x) comb(__lbb_,x)
	#define LBB(...) __LBB__ {__VA_ARGS__;} 
	
	int __ap_file(char const *__path);
	int __ap_fifo(char const *__path);
	ulong __ap_writer();
	ulong __ap_reader();
	ulong __lbb_file_r(char const *__path);
	ulong __lbb_file_w(char const *__path);
	ulong __lbb_file_n(char const *__path);
	int lbb_argument(char const *__arg);
	void purge_shard();
	ulong __run_ap(ulong __size);
	ulong __writeb(uchar *__content, ulong __size);
	char const *__readb(ulong __fsize, ulong __fd, ulong __ro);
	void __readin(char *buffer, ulong __size, ulong __stfd);
	void lbb_close();
	ulong __fillb();

	ulong write_book(char *content, ulong csize);
	char const *read_book(char const *__cpath);
	ulong reset_book();
	ulong lbb_print(char *kaddr);
	
	int lock_lbb(char const *__cpath, ulong __lock);


	int get_sstat(char const *__path, s_stat *sfile);
	ulong __get_long_digits(ulong num);
	char *__get_cfname(char const *__fname, ulong __iter);
	char const*__get_fcontents(char *__content, ulong __size);

	void free_fields(c_fld **flds);
	char const *__conv_fields(char const *__fn, ulong __fd, ulong __count);

	ulong __flds_count(int c);
	char const *conv_fields(m_stat *mst);
	int get_freader(m_stat *mst);

	char const *__lbb_command(char const *__cpath, char const *__args);
	char const *__lbb_filepath(char const *__fpath, aip_sterm __term);
	void const *__lbb_function(char const *__name, void const *__in_type, void const *__cast_out);

	void __free_ptr(void const *__);

	void const *__lbb_field(char const *__keyname, void const *__content);
	void const *__lbb_address(void *__);
	void const *__lbb_type_args(lbb_at __atype);

	int __init_field(char const *__);
	char *flds(char const *__fldname);

	void *__into__(d_into *st);
	lbb_entry __decode_arg(char const *__);

	int __no_entry__(void *proto_call);
	int __info__(void *proto_call);
	int __pointer__(void *proto_call);
	int __field__(void *proto_call);
	int __w3__(void *proto_call);
	int __point__(void *proto_call);
	d_into *dcloud(void *proto_call);
	int act2args(aip_st *proto_call);

	#define __LBB__H 1


	#define __lbb_command_args (char const *, char const *)
	#define __lbb_filepath_args (char const *, aip_sterm)
	#define __lbb_function_args (char const *, void *, void *)
	#define __lbb_field_args (void const *)
	#define __lbb_cc char const *
	#define __lbb_vp void *

	#define __lbb_call_args(...) __VA_ARGS__
	#define lbb_add(x,...) __lbb_typd_args(x)

	#define __lbb_c_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*\\)$"
	#define __lbb_mode__ (S_IRWXU|S_IRWXG|S_IRWXO)
	#define __lbb_shard_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW)
	#define __lbb_lock_new (O_RDWR|O_CREAT|O_EXCL)
	#define __lbb_default_flags (S_IRUSR|S_IWGRP|S_IWOTH)
	#define __lbb_lock_reader (O_RDONLY)
	#define __lbb_lock_writer (O_WRONLY)
	#define __lbb_share_flags (O_RDONLY)
	#define __lbb_private_mode (S_IRWXU|S_IXGRP|S_IXOTH)
	#define __lbb_share_mode (S_IRWXU|S_IWGRP|S_IXGRP|S_IWOTH|S_IXOTH)
	#define __lbb_public_mode (S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)


    #define LBB_FMT_SPEC(lbb_type) _Generic((lbb_type), \
    	ixr_h: "%lu bytes\n %lu@%lu dpoints\n head : %s\n",\
    	default: "no lbb_type matched\n"\
    )

    #define LBB_SPEC(lbb_arg) _Generic((lbb_arg), \
    	ixr_h*: &ixrh_size(lbb_arg), ixrh_dcount(lbb_arg), ixrh_checksum(lbb_arg), ixrh_head(lbb_arg),\
	    default: NULL\
    )

    #define lbb_indexer_address indexer_header()

    #define LBB_GET(a) __OUT_ASCII(0, lbb_##a)
    #define IXR_GET(a, type) (type *)lbb_##a 

    // #define LBB_EVAL(type, varname) LBB_FMT_OUT(0, type, varname)

    #define IXR_OUT(fd, type, val) do {\
        printf("%d@lbb<%s>(%s)\n", fd, #type, #val);\
	} __dPER

    #define LBB_OUT(fd, mthd, valu) do {\
    	printf("%d@lbb<%s>{%s}\n", fd, mthd, #valu);\
	} __dPER

    #define _OUT_ASCII(fd,x) do { \
    	ulong len=str_rwings(x);\
        long ws=write(fd,x,len);\
    	printf("lbb@<fd:%lu>(%lu) {%s} = \n", fd, len, x, ws);\
    } __dPER

   #define OUT_ASCII(fd,x) do { \
    	ulong len=str_rwings(#x);\
    	long ws=pwrite(fd,#x,len,___lbb_offset);\
    	if(ws>0){ ___lbb_offset += ws; };\
        printf("%ld@lbb<w>{ %s } \n", ws, #x);\
    } __dPER

 	#define __OUT_ASCII(fd,x) do { \
    	ulong len=str_rwings(#x);\
    	long ws=pwrite(fd,#x,len,___lbb_offset);\
    	if(ws>0){ ___lbb_offset += ws; };\
    	LBB_OUT(0, #x, x);\
    } __dPER

	#define __ARR_OUT(x, x_size) int _=0; do {\
		printf("%s", x[_].arg);\
		_+=1;\
	}while(_<x_size);
	#define ARR_OUT(x) __ARR_OUT(x, arr_size(x))
	#define DUPCAT(c,x,y) c##x#y
	#define _ARR_OUT(x, y_delim, x_size) int _=0; char *res; do {\
		printf("%s%c", x[_].arg, y_delim);\
		_+=1;\
	} while(_<x_size-1);\
	printf("%s", x[x_size-1].arg);\

	#define ARR_SEP(x,y) _ARR_OUT(x, y, arr_size(x))


	#define PACK_IN(fld,siz,fmt,...) do {\
	    uchar __[siz];memset(&__,0,siz);\
	    ulong sz=(ulong)pack(__,fmt,#__VA_ARGS__);\
	    printf("\n\n\n\n\npacking size :: %lu", sz);\
	    write(fld,__,sz);\
	} __dPER

	#define pth_shard(x) ((char *)((x.c_stat).m_path))
	#define fld_shard(x) ((ulong)(x.c_fd))
	#define sze_shard(x) ((ulong)((x.c_stat).m_size))
	#define ioz_shard(x) ((ulong)((x.c_stat).m_blksz))

	#define shd_fd fld_shard(lbb_shard)
	#define shd_sze sze_shard(lbb_shard)
	#define shd_io ioz_shard(lbb_shard)
	#define shd_path pth_shard(lbb_shard)
	#define shd_key hashof(1,lbb_mstat,sizeof(m_stat))

	#define inodenum ((ulong)(lbb_mstat->m_inn))
	#define ifilesize ((ulong)(lbb_mstat->m_size))
	#define idmode ((ulong)(lbb_mstat->m_mode))
	#define iblkio ((ulong)(lbb_mstat->m_blk))

	#define __NOT_FOUND "Not-Found \xE2\x9C\x95"
	#define __FOUND "Found \xE2\x9C\x93"
	#define FND_NTFND(x) x==0?__NOT_FOUND:__FOUND

	#define __LBB_START__(...) __DPRG__(__VA_ARGS__)

	#define __LBB_WRITER__ do {\
		memset(l_shard,0,sizeof(c_shard));\
		w_start_ap();\
	} __dPER

	#define LBB_INFO do{\
		printf("Linked Binary Book {a.k.a %s}\n","lbb");\
		printf("book:home  ::  lbb/  ::: %s\n",FND_NTFND(checkef_dir));\
		printf("book:lock  ::  lock  ::: %s\n",FND_NTFND(checkef_file));\
		printf("book:tern  ::  .lbb  ::: %s\n",FND_NTFND(checkef_lo));\
	} __dPER

	#define __LBB_READER__ do{\
		memset(l_shard,0,sizeof(c_shard));\
		if(!checkef_lo) {__ap_fifo(__lbb_locking);};\
		r_start_ap();\
	} __dPER

	#define __lbb_buffer_size 512
	#define LBB_BUFFER_SIZE ((ulong)__lbb_buffer_size)


	#define __lbb__(x) void *res;\
		switch(__switcher(x)){\
			case 0:\
				return __info__(x);\
			case 1:\
				return __pointer__(x);\
			case 2:\
				return __field__(x);\
			case 3:\
				return __point__(x);\
			case 4:\
				return dcloud(x);\
			default: \
				return __no_entry__(x);\
		}\



#endif
