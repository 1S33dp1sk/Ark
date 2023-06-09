

/************************ d-architicture ************************/


#ifndef _D_ARCH
	#define _D_ARCH 1

	int __is_module(char const *__in) {
		if(__in[0]=='&'){
			if (__in[1]=='=') {
				if (__in[2]=='>') {
					return 1;
				};
			};
		};
		return 0;
	};

	int __is_file(char const *__in){
		if(__in[0]=='&'){
			if (__in[1]=='-') {
				if (__in[2]=='>') {
					return 1;
				};
			};
		};
		return 0;
	};

	int __is_ref(char const *__in) {
		if(__in[0]=='&'){
			return 1;
		};
		return 0;
	};

	ulong *__indices(char const *__temp) {
		__uptr[0] = (ulong)1204912;
		ulong x[10] = {1204912,120491,12049,1204,5910,385,120,1295410,215019250,19325912510};
		for(int i=0;i<arr_size(x); i+=1) {
			__uptr[i] = x[i];
		};
		printf("indecies : %s\n", __temp);
		return __uptr;
	};

	char const *__walk(int ladder_s, int ladder_e, char const **__ter) {
		ulong __tlen=0;
		while(ladder_e-->ladder_s) {
			__tlen+=str_rwings(__ter[ladder_e]);
			#ifndef DEBUG
				printf("%s\n", __ter[ladder_e]);
			#endif
		};
		#ifndef DEBUG
			printf("total length : %lu\n", __tlen);
		#endif
		return __ter[ladder_s];	
	};

	char const *__address(int __level, char const *__filename) {

		return hashof(__level, __filename, str_rwings(__filename));
	};

	char const *__uname(const char *__u) {

		return hashof(2,__u,str_rwings(__u));
	};

	char const *__get_atname(char const *__naming) {
		if(!__atchar(*__naming)){

			return temp_name;
		};
		return __naming++;
	};

	char const *__getcaller(){
		// get the calling file
		return (char const *)__FILE__;
	};

	char const *__caller_hash(int __level) {
		if((__level>4)||(__level<0)){
			#ifdef DEBUG
				printf("caller hash levels can only be postive");
			#endif
			return NULL;
		};
		char const *__caller=__getcaller();
		char const *__hash=hashof(__level, __caller, str_rwings(__caller));
		return strdup(__hash);
	};

	char const *caller_l(int _l) {
		char const *__=__getcaller();
		char *__hash;
		switch(_l){
		case 0:
			__hash = (char *)hashof(_l, __, str_rwings(__));
			return expand("lbb0x",(char const *)__hash);
		case 1:
			__hash = (char *)hashof(_l, __, str_rwings(__));
			return expand("lbb1x", (char const *)__hash);
		case 2:
			__hash = (char *)hashof(_l, __, str_rwings(__));
			return expand("lbb2x", (char const *)__hash);
		case 3:
			__hash = (char *)hashof(_l, __, str_rwings(__));
			return expand("lbb3x", (char const *)__hash);
		default:
			return NULL;
		};
	}
	char const *caller() {
		char const *__=__getcaller();
		char const *__hash=hashof(1, __, str_rwings(__));
		return expand("lbb", __hash);
	};

	int __check_alias(char const *__alias) { 
		ulong temp = str_rwings(__alias);
		if((temp==0)||(temp>8)) 	{
			return 0;
		};
		return __entry_valid(__alias);
	};

	int at_entry(char const *__) {
		char c=*__;
		if(!__atchar(c)){
			#ifdef DEBUG
				printf("entries start with @\n");
			#endif
			return 0;
		};
		return __entry_nvalid(__);
	};

	int __entry_valid(char const *__) {
		#ifdef DEBUG
			printf("entry is '%s'\n", __);
		#endif
		char c=*__;
		do {
			if (((!__numchar(c))&&(!__smchar(c))&&(!__capchar(c)))) {
				#ifdef DEBUG
					printf("alias is nvalid : %d\n\n", c);
				#endif
				return 0;
			};
			c=*__++;
		}while(c);
		#ifdef DEBUG
			printf("alias is valid\n");
		#endif
		return 1;
	};

	int __entry_nvalid(char const *__) {
		char c=*__;
		do {
			c=*__++;
			if ((__nullchar(c))||((!__numchar(c))&&(!__smchar(c))&&(!__capchar(c)))) {
				return 0;
			};
		}while(c);
		printf("alias is valid\n");
		return 1;
	};

	ulong vcontent_count(void const **__vc) {
		ulong c=0;
		while(__vc[c]!=NULL) {
			c+=1;
		};
		return c;
	};

	ulong content_count(char const **__content) {
		ulong c=0;
		while(__content[c]) {
			c+=1;
		};
		return c;
	};


	/********* base8 *********/

	ulong lexical_args(void **__vars) { 
		char const *temp = (char const *)__vars;
		#ifdef DEBUG
			printf("vars : %s\n", temp);
		#endif
		ulong arg_count=arr_cdelims(temp);
		return arg_count;
	};

	ulong __size8(int _){
		if(_<0){
			return 0;
		}
		else {
			ulong __=1;
			do {
				__*=8;
				_--;
			}while(_>0);
			return __;
		};
	};

	ulong lbb_type2size(lbb_t lbb_type){
	
		return lbb_size(lbb_type);
	};


	/********* fld *********/

	int __check_fld(char const *__path, lbb_t __path_type){
		if(fsze(__path)==lbb_type2size(__path_type)){
			return 0;
		};
		return 1;
	};

	/********* mods *********/

	char const *__charm_call(char const *entryhash, char const *__cname) {
		ulong cname_len=str_rwings(__cname), eff_len=str_rwings(run_mod);
		char __[CHARMS_BASE+cname_len+2]; memset(&__, 0, sizeof(__));
		memmove(__, run_mod, eff_len);
		memmove((__+eff_len), __cname, cname_len);
		#ifdef DEBUG
			printf("charmcall :: %s\n", __);
		#endif
		return strdup(__);
	};

	char const *__mod_call(char const *__mname) {
		char const *__caller=__getcaller();
		ulong __clen=str_rwings(__caller), __flen=str_rwings(__mname);
		ulong c_length=__clen+__flen, c_sep=sep_offset(__caller, charms_d);
		
		char charmcall[c_length];
		void *cc_ptr=memset(&charmcall, 0, sizeof(charmcall));

		if((!c_sep)||(__flen<3)) {
			#ifdef DEBUG
				printf("f:length=%lu, c:sep=%lu\n", __flen, c_sep);
			#endif
			return NULL;
		};

		memmove(cc_ptr, __caller, c_sep);
		memmove((cc_ptr+c_sep), __mname, __flen);

		#ifdef DEBUG
			printf("mod : call :: %s\n", charmcall);
		#endif

		return strdup(charmcall);
	};

	char const *__fcall(char const *__filename) {

		return __combine_str(__os_delim, __filename);
	};

	char const *__dcall(char const *__dirname) {

		return __combine_str(__dirname, __os_delim);
	};

	char const *__ecall(char const *__mod, char const *__name) {
		char const *__callbase=__dcall(__charm_call(NULL,__mod));
		return __combine_str(__callbase, __name);
	};

	int __check_ectx(char const *__mod, char const *__name) {
		char const *__ccc=__ecall(__mod, __name);
		return stres(__ccc);
	};

	int __check_entry(char const *entry) {
		int __res=__entry_valid(entry);
		int __ds_offset=__sep_atoff(entry, d_sep);
		if((!__res)||(__ds_offset==-1)) {
			#ifndef DEBUG
				printf("entry invalid : %s\n", entry);
			#endif
			return -1;
		};
		char const *__cmod=str_b4offset(entry, __ds_offset);
		char const *__entry=str_a4woffset(entry, __ds_offset);

		return __check_ectx(__cmod, __entry);
	};

	ulong arch_ufile(char const *__cpath) {
		// gets file size in ( x << n*3 ) 
		// gets file types in ( x >> n*3 )
		ulong usize=0, __size=__fsize(__cpath);
		do {
			usize+=1;
			__size>>=(3*usize);
		}while(__size>=1);
		return usize;
	};

	lbb_t arch_tfile_lbb(char const *__cpath) {
		
		return (lbb_t)arch_ufile(__cpath);
	};
	
	char const *arch_szfile(char const *__cpath){
		// gets file size number 
		// representation in characters

		return num2char(__fsize(__cpath));
	};

	int get_mstat(char const *__path, m_stat *mfile) {
		/**
		 * the reason im currently not using the following logic
		 *  mfile -> m_size = __fsze(...)
		 * is due to a feature that can be implemented into a
		 * single interface call regardless of the execution context(high level interface)
		 * i.e : language, compilier, etc...
		 * so im dividing them into functions for now.
		**/
		memset(mfile,0,sizeof(m_stat));
		ulong path_len=str_rwings(__path);
		if(path_len>512){
			#ifdef LOG_ERR
				printf("path specified is 512+ \n");
			#endif
			return -1;
		}
		memmove(mfile->m_path,__path,path_len);
		struct stat temp;
		memset(&temp,0,sizeof(struct stat));
		if(stat(mfile->m_path,&temp)!=0){
			// check file status
			// if file does not exist create it
			#ifdef DEBUG
				printf("cannot determine `stat` call :: %s\n", mfile->m_path);
			#endif
			return 1;
		}
		else {
			// pass for now
		};
		mfile->m_size=fsize_st(&temp);
		mfile->m_mode=dmode_st(&temp);
		mfile->m_blksz=iosize_st(&temp);
		mfile->m_inn=inn_st(&temp);
		return 0;
	};

	int arch_att(char const *__path, ulong __perm, ulong __fldsize) {
		int res=stres(__path);
		if(!res){
			res=open(__path, shard_flags, shard_share);
			if(res==-1) {
				// cannot create file 
				// no unistd support
				#ifdef LOG_ERR
					printf("cannot arch @%s\n:: create(err:%d)", __path, errno);
				#endif
				return 0;
			}
			else {
				// file created
				m_stat __pmstat;
				get_mstat(__path, &__pmstat);
				printf("mode : %01lu\n", cm_mode(__pmstat));
				ulong __pszie=cm_size(__pmstat);
				ulong __bsize=cm_iosz(__pmstat);
				if(__pszie) {
					#ifdef LOG_ERR
						printf("err : non-zero archs\n");
					#endif
					_exit(1);
				}
				else {
					// returns write result in bytes
					ulong __init_size=__fldsize>__bsize?__bsize:__fldsize;
					uchar __content[__init_size];
					if(__init_size==__bsize) {
						memset(__content, 0x40, __bsize);
					}
					else {
						memset(&__content, 0x5e, __fldsize);
					};
					ulong __flag=0, b_written=0;
					long temp=0;
					while(b_written<__fldsize) {
						temp=pwrite(res, __content, __init_size, b_written);
						if(temp<0) {
							#ifdef DEBUG
								printf("err : cannot init enough memory for archfile : %s\n", __path);
							#endif
							return -1;
						}
						else if(!temp) {
							__flag+=1;
							if(__flag==3) {
								#ifdef DEBUG
									printf("err : arch struck on file @%s\n", __path);
								#endif
								return -1;
							}else {
								continue;
							};
						}
						else {
							b_written+=temp;
						};
					};
					return b_written;
				};	
			};
		}
		else {
			res=0;
			if(__perm==1) {
				res|=shard_lock_reader;
			}
			else if(__perm==2) {
				res|=shard_lock_writer;
			}
			else if(__perm==3) {
				res|=shard_nolock;
			};
			return open(__path, res);
		};
	};

    char const *arch_dfile(char const *__name, ulong arch_perm, ulong tfile_size) {
        // generate file name from path and size
        char const *__cpath=__ecall("var", __name);
        
        if(stres(__cpath)){
            #ifdef DEBUG
                printf("file already exists\n");
            #endif
            return zero_address(3);
        };

        char const *tlbb_name=(char const *)typed_lbbfilename(fsize);
        char const *__raw_fname=__combine_str(__cpath, tlbb_name);
        char const *__arch_filename=arch_namehash(__raw_fname);
        
        if(!arch_att(__arch_filename, arch_perm, tfile_size)){
            #ifdef DEBUG
                printf("failed to create dfile\n");
            #endif
            return zero_address(3);
        };

        return __arch_filename;
    };

	int arch_cfile(char const *cf_name, lbb_t lbb_ftype){
		// creates the arch file needed
		
		return arch_att(cf_name, 3, lbb_size(lbb_ftype));
	};

	int arch_fperm(char const *__cpath, aip_sterm __sterm){
		// checks the arch permissions for the requested path
		m_stat c_mstat; memset(&c_mstat, 0, sizeof(m_stat));
		get_mstat(__cpath, &c_mstat);
		if(__sterm==Public){
			return ARCH_MADE(cm_mode(c_mstat));
		}else{
			return ARCH_SAVE(cm_mode(c_mstat));
		};
	};

	void *__mstat__(m_stat *st) {

		return memset(st, 0, sizeof(m_stat));
	};


// _Generic((&__str[sep_idx]), 
// 				char *: base[c]=(char const *)__str,
// 				char const *: base[c]=(char const *)__str,
// 				default: base[c]=(void const *)__str
// 			);
void const **variable_args(ulong d_count, char const *__str, char const *__delim) {
		ulong d_comp = d_count + 2;
		void const **base=malloc((sizeof(void *)*d_comp));
		base[0] = (void const *) mac_address;
		ulong _c=0,_sep=0;
		void *temp;
		do {
			_sep=sep_offset(__str, __delim);
			printf("seperator @%lu\n", _sep);
			temp=malloc(_sep);
			memmove(temp, __str, _sep);
			if(!_c) {
				__str+=_sep;++__str;
			}
			else {
				__str+=_sep+1;
			}
			_c+=1;
			printf("string : %lu :: %s\n", _c, __str);
			base[_c]=(char const *)temp;
		} while (_c<d_count-1);
		return &base[0];
	};









	


#endif

