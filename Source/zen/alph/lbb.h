/// lbb \\\
little black book

#define __lbb_name ""
#include "hbar.h"
#include "enk.h"
#include "display.h"


static const char *ccc_names[] = {
	"att","bal","ccc","dig","exs","fmt","git","hlv","inc","jab",
	"kei","lbb","mrv","nop","ops","pub","que","rdl","sok","trv",
	"usr","vik","wln","xol","ybn","zai"
};
static const unsigned ccc_count = arr_size(ccc_names);
static const unsigned _l_idx = 11;
static const char lbb_fname[5] = ".lbb\0";

enum _lbb_checkres {
	__return_n = 0 ,
	__return_d = 1 ,
	__retrieve
};

#define __check enum _lbb_checkres


__check lbb_idx() {
	return super_fast_hash(ccc_names[_l_idx],3) == super_fast_hash("lbb",3) ? \
		__return_d : __return_n;
}

char *get_3c_dir() {

	return ccc_dir;
}

struct _3c_hat ter_hat(char const*lbb_fname) {
	struct _3c_hat __hat;
	memset(&__hat,0,sizeof(__hat));
	memmove(*(&(__hat.__name)), (uchar *)lbb_fname, 5);
	__hat.__hash = hash8(1,lbb_fname,4);
	return __hat;
}


unsigned lbb_hash(char *lbb_p,char *att_p) {
	char const *__lbb_hash = fhash(3,(char const*)lbb_p);
	uchar p_buf[3+strlen(__lbb_hash)];
	unsigned p_size = pack(p_buf,"s",(char *)__lbb_hash);
	size_t lsize = f_log(att_p,((uchar *)(p_buf)),p_size);
	return (unsigned)lsize;
}


ulong lbb_resolve(uchar core_name[4]){
	return 0xa9;
}
