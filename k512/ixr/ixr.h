/// ixr \\\
The indexer

#ifndef __IXR__H

	#define ixr_mem 	((void *)&___header.head)
	#define ixr_ubuf	((uchar *)&___header.head)
	#define ixr_buf		((char *)&___header.head)
	#define ixr_head	((char const *)&___header.head)
	#define ixr_h_args ___header.__size, ___header.d_count, ___header.checksum
	
	// unistd flags for `open`&`creat`
	#define __ixr_start_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW)
	#define __ixr_access_flags (O_RDWR|O_NOFOLLOW)
	#define __ixr_pmode (S_IRWXU|S_IXGRP|S_IXOTH)
	#define ULONG_MAX_DIGITS 21
	#define ULONG_SIZE ((ulong)(sizeof(ulong)))
	#define LONG_SIZE ULONG_SIZE

	#define fsze(x)		((ulong)__fsize(x))

    #define len_ustrze(x) (((ulong)x)*(sizeof(uchar)))
	#define ixr_h_size(x) (x.__size)
	#define ixrh_size(x) (ulong)(x->__size)
	#define ixrh_dcount(x) (ulong)(x->d_count)
	#define ixrh_checksum(x) (ulong)(x->checksum)
	#define ixrh_head(x) ((uchar *)x->head)
	#define into_argc(x) ((int)(x->switcher))
	#define index_reference(...) __REF__(__VA_ARGS__)
	#define uc_size(x) ((ulong)(x*sizeof(uchar)))
	#define __eixrh(x) x->__size, x->d_count, x->checksum
	#define __ihsz(x) x->__size

	#define __RUN__(x) __dPRG __INDEXER__(x)
	#define __REF__(...) ref_point(__VA_ARGS__, #__VA_ARGS__, IXR_FMT(__VA_ARGS__))
    #define KV_FORMAT(...) __generic_fmt(__key_value, ##__VA_ARGS__) 
	#define INDEX_END(x) return __set_next(x);


	d_point ref_point(void const *__key, char const *__value, char const *__format);
	char const *ixr_format(ixr_t idx_type);
	char const *__kaddress(char const *__hash);
	void *__erv(char const *__key,char const *__val);
	ulong __set_next_p(void *__);
	char const *__generic_fmt(fmt_t __format, ...);
	uchar const *__urv(uchar const *__key, char const *__value);
	char const *__irv(char const *__key, char const *__value);
	ulong __index_increment();
	ulong __set_next(char const *__head);
	ulong __idx_start();
	char const *__xreference(char const *__);
	int __index_r(char const *idxnr);
	int __index_irn(char const *key, char const *val);
	int __index_ixn(char const *key);
	int __index_caller();
	ulong __set_unext(uchar const *__head);
	int __index_urn(uchar const *_key, char const *_val);
	int __index_point(d_point *dst);	
	ixr_h *__header__();
	int __header_in();
	int __load_header();
	int __rd_ixrh();
	int __header_out(uchar *__header_content, ulong __header_size);
	int __write_header();
	int __refresh_header();
	int refresh_h();
	ixr_h *indexer_header();
	int indexer_start();
	int __indexer__(char const *idr);
	int refer_index(void *__ptr, void *__ref, char *__prname);
    ulong __ixr_argument(char const *__format, void const *__);

	ixr_h *ixr_get(d_into *ist);
	ixr_h *ixr_set(d_into *ist);
	ixr_h *ixr_prun(d_into *ist);
	ixr_h *ixr_psave(d_into *ist);
	ixr_h *ixr_pcollect(d_into *ist);
	ixr_h *args3head(d_into *in_args);

	#define __IXR__H 1



#endif
