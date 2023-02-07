/// little black book \\\
The book
#ifndef __LBB__H
#include "lbb.h"
#endif
#ifndef __lbb_name
	#define __lbb_name "little_black_book"

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

	int arg_field(uns lvl,char const*kei,char const*ftypes,...) {
		// initialize the record

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



#endif