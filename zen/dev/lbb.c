//. little black book \\
The book
#include "fields.h"

/**
 * should ONLY return the value
 * of the key in the current lbb
 * instance.
**/
uchar *lbb_key(uchar const *__){
	int __flags=__get_process_flags();
	return "";
}

/**
 * will calculate the size needed
 * for a new record iterativly
 * char = 1b
 * int 	= 2b
 * long = 4b
**/
ulong calc_fmtsize(char *fmt){
	static ulong __rsze=0;
	size_t __fmtlen=strlen(fmt);
	if(__fmtlen>16){return 0;}
	uns maxstrlen=0;
	while(*fmt++){
		switch(*fmt){
			case 'S':
				__rsze+=maxstrlen;
				break;
      		default:
                if (isdigit(*fmt)) { // track max str len
                	printf("digit :: ");
                    maxstrlen = maxstrlen * 10 + (*fmt-'0');
                    printf("%u",maxstrlen);
                }
		}
        if (!isdigit(*fmt)) maxstrlen = 0;
	}
	return __rsze;
}

/**
 * levels :
 * 0 -> device
 * 1 -> athernet
 * 2 -> owner		
 * 3 -> public
 */
uns islvl(uchar _){
	if((_>=060)&&(_<=071)){return _-48;}
	return 0;
}

int check_key(ulong key){

	return 0;
}

int __ref_exsits(char *__path){

	return access(__path,F_OK)==0;
}

int __sok_connect(char *__sock){

	return 1;
}

int __addr_available(char *__addr){
	size_t _a_len = strlen(__addr);
	ulong h_addr = hash8(3,__addr,_a_len);
	return check_key(h_addr)==0;
}

int init_field(uns lvl,char const*kei,char const*ftypes,...) {
	// initialize the record
	// memset(&__record,0,sizeof(__record));

	// process key 	
	size_t _k_len = strlen(kei);
	ulong __key = hash8(lvl,kei,_k_len);
	printf("key  :: %lu\n",__key);
	// check key if exsits
	int chkval=0;
	if((chkval=check_key(__key))!=0){
		return chkval;
	}
	// init possible values
	char *s,*ref,*desc;
	int i;
	long l;
	long long d;
	// we can extract references and
	// initalize them from the above defs
	//
	// init incoming variable(s)
	va_list __vlist;
	char *fmt = (char *)ftypes;
	va_start(__vlist,ftypes);
	while(*fmt){
		switch(*fmt++){
		case 'S':
			s=va_arg(__vlist,char*);
			printf("str   :: %s\n",s);
			break;
		case 'I':
			i=va_arg(__vlist,int);
			printf("int   :: %d\n",i);
			break;
		case 'L':
			l=va_arg(__vlist,long);
			printf("lng   :: %ld\n",l);
			break;
		case 'D':
			d=va_arg(__vlist,long long);
			printf("llng  :: %lld\n",d);
			break;
		case 'P':
			ref=va_arg(__vlist,char*);
			if(!__ref_exsits(ref)){printf("ref dir doesn't exist\n");return -1;}
			printf("path  :: %s\n",ref);
			break;
		case 'F':
			ref=va_arg(__vlist,char*);
			if(!__ref_exsits(ref)){printf("ref file doesn't exist\n");return -1;}
			printf("file  :: %s\n",ref);
			break;
		case 'K':
			ref=va_arg(__vlist,char*);
			if(!__sok_connect(ref)){printf("cannot establish connection\n");return -1;}
			printf("sock  :: %s\n",ref);
			break;
		case 'A':
			ref=va_arg(__vlist,char*);
			if(!__addr_available(ref)){printf("address is busy\n");return -1;}
			printf("addr  :: %s\n",ref);
			break;
		case 'C':
			desc=va_arg(__vlist,char*);
			printf("dscrpt:: %s\n",desc);
			break;
		}
	}
	va_end(__vlist);
	return 0;
}

int usage(){
	printf("usage :: lbb [get|set] [key] [record|value|type|address|description]\n");
	return 0;
}

int lbb_level(){
	return 0;
}

int process_args(int argc, char const *argv[]){
	if((argc==1)&&(strstr(argv[0],"lbb"))!=NULL){
		printf("%lu\n",__LBB_HASH);
		return 0;
	}
	// argc==2 
	// check if level from now
	unsigned __lvl=islvl(argv[1][0]);
	if(__lvl){
		printf("level :: %u\n",__lvl);
		return lbb_level(__lvl);
	}
	// all other scenarios 
	if(argc==2){
		char *rcrd=lbb_key(argv[2]);
		printf("rcrd :: %s\n",rcrd);
	}
	// 1 more case for `lbb [level][kei]`
	// 
	if(argc>3){
		int res=0;
		printf("should append record\n");
		res = init_field(0,"kei","L",12);
		printf("result :: %d\n",res);
	}

	return 0;
}



int lbb_pack(void *__field,size_t __ftype,char *__fmt,...){


}

size_t lbb_fill(void *__field,size_t __ftype,char const *__fpath){

}

char const *lbb_sign(/*socket_t or similar*/){
	
}


/**socket_t lbb_point(char const *paddr)**/



/**
The book
	a.k.a little black book
 *
 * 
 * 
**/ 
int lbb(int argc,char const*argv[]){
	printf("checking lbb\n");
}
