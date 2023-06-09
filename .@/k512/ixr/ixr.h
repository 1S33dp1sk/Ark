/// ixr \\\
The indexer

#ifndef __IXR__H
	#define IXR_FILE "@charms/d.run/mods"

	#define d_mod "run/\0"
	#define IXR_BASE (ulong)str_rwings(d_ixr)
	#define __ixr_reject 0x228
	#define ixr_h_args ___header.img_size, ___header.img_mcount, ___header.img_name
	// unistd flags for `open`&`creat`
	#define __ixr_start_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW)
	#define __ixr_access_flags (O_RDWR|O_NOFOLLOW)
	#define __ixr_pmode (S_IRWXU|S_IXGRP|S_IXOTH)
	#define ULONG_MAX_DIGITS 21
	#define ULONG_SIZE ((ulong)(sizeof(ulong)))
	#define LONG_SIZE ULONG_SIZE

	#define fsze(x)		((ulong)__fsize(x))

	#define INDEXER(x) char const *x!=NULL?__indexer__(x):__ixr_strt(x)
	#define indexer_check() if (!checkef_file){INDEXER(NULL);};

    #define len_ustrze(x) (((ulong)x)*(sizeof(uchar)))
	// IXR
	#define ixrh_size(x) (ulong)(x->shared_size)
	#define ixrh_dcount(x) (ulong)(x->mods_count)
	#define ixrh_checksum(x) (char const *)(x->pub_key)
	#define ixrh_head(x) ((uchar *)x->head)

	#define into_argc(x) ((int)(x->switcher))
	#define index_reference(...) __REF__(__VA_ARGS__)
	#define uc_size(x) ((ulong)(x*sizeof(uchar)))
	#define __eixrh(x) x.shared_size, x.mods_count, x.pub_key
	#define __ihsz(x) x->__size

	#define __RUN__(x) __dPRG __INDEXER__(x)
	#define __REF__(...) ref_point(__VA_ARGS__, #__VA_ARGS__, IXR_FMT(__VA_ARGS__))
    #define KV_FORMAT(...) __generic_fmt(__key_value, ##__VA_ARGS__) 



	char const * __ixr_strt(char const *alias);
	d_point ref_point(void const *__key, char const *__value, char const *__format);
	char const *ixr_format(ixr_t idx_type);
	void *get_ixr_type(void const *__args);
	char const *__kaddress(char const *__hash);
	void *__erv(char const *__key,char const *__val);
	ulong __set_next_p(void *__);
	char const *__generic_fmt(fmt_t __format, ...);
	uchar const *__urv(uchar const *__key, char const *__value);
	char const *__irv(char const *__key, char const *__value);
	ulong __control_inc();
	ulong __set_next(char const *__head);
	ulong __idx_start();
	char const *__xreference(char const *__);
	int __index_r(char const *idxnr);
	int __index_irn(char const *key, char const *val);
	int __index_ixn(char const *key);
	int __index_caller();
	ulong __set_unext(uchar const *__head);
	ulong __index_urn(uchar const *_key, char const *_val);
	ulong __index_point(d_point *dst);	
	int __header_in();
	int __load_header();
	int __rd_img();
	int __header_out(uchar *__header_content, ulong __header_size);
	int __write_header();
	int __refresh_header();
	int refresh_h();
	ixr_h *indexer_header();
	int refer_index(void *__ptr, void *__ref, char *__prname);
    ulong __ixr_argument(char const *__format, void const *__);
    int __store(ulong __idx, char const *__format, char const *data);

	void *ixr_get(d_into ist);
	void *ixr_set(d_into ist);
	void *ixr_prun(d_into ist);
	void *ixr_psave(d_into ist);
	void *ixr_pcollect(d_into ist);
	void *img_run(d_into ist);

	void *ixr_export(void *_intro);
	void *ixr_run(void *_intro);
	void *ixr_save(void *_intro);
	void *ixr_collect(void *_intro);
	int indexer_end();
	int indexer_pause();
	void log_header();
	
	#define __IXR__H 1

#endif
