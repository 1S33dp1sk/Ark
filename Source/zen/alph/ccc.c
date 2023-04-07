/// ccc \\\
connected c compilier

#define __ccc_name "@ccc"
#include "probe.h"
#ifdef CCC_HEADERS
	#define att_dir __current_dir
	#define ccc_dir "../charms/"

	char *__current_dir() {
		char *actv_dir, __activity_dir[__sa__dsls];memset(&__activity_dir,0,__sa__dsls);
		actv_dir = getcwd(__activity_dir,__sa__dsls);
		return strdup(__activity_dir);
	}

	char *__charm_name(char const*fname){
		unsigned dlen = strlen(ccc_dir), flen = strlen(fname), len=dlen+flen; 
		if(len>__sa__npr){return 0;}
		char fpath[len], *p=fpath;
		memset(&fpath,0,len);
		memmove(p,ccc_dir,dlen); memmove(p+dlen,fname,flen);
		return strdup(fpath);
	}
	unsigned __file_exsits(char const*fname){
		return access(__charm_name(fname),1)==0;
	}
	// #include <stdio.h>


	// void *_fopen()
	unsigned __file_r(char const*fname){
		return access(__charm_name(fname),2)==0;
	}
	unsigned __file_w(char const*fname){
		return access(__charm_name(fname),4)==0;
	}
	unsigned __file_x(char const*fname){
		return access(__charm_name(fname),7)==0;
	}

	struct _3c_hat {
		uchar __name[5];
		ulong __hash;
	};
	struct _3c_addr {
		ulong __ref;
		ulong _c_hash;
	};
	#define _3c_bal unsigned long long 
	struct _3c {
		struct _3c_hat hat;
		struct _3c_addr att;
		_3c_bal bal;
	};
	#include "lbb.h"


	#include <stdio.h>
	int ccc(){
		char *activity_dir = att_dir();
		#define alph_att activity_dir
		printf("checking lbb index @%d -> res=%u\n",_l_idx,lbb_idx());
		for (int i=0;i<26;i++) {
			char const *cname = ccc_names[i];
			char const ccname[5] = {'.',cname[0],cname[1],cname[2],'\0'};
			printf("does charms/%s exist ? %d :: %u\n",cname,__file_x(ccname),hash4(0,ccname,4));
		}


		printf("total amount of names :: %d\n",ccc_count);
		printf("activity directory :: %s\n",activity_dir);
		printf("lbb hash res :: %u\n",lbb_hash(__charm_name(".lbb"),__charm_name(".att")));
		printf("lbb resolve :: %u\n",lbb_resolve(".jab"));
	}

#endif
