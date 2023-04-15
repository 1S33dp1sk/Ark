

/************************ d-architicture ************************/

#ifndef _D_ARCH
	#define _D_ARCH 1
	#define charm_mod __mod_call(charms_d)
	#define run_mod __combine_str(charm_mod, "run/")

	char const *uname(const char *__filename) {

		return hashof(2,__filename,str_rwings(__filename));
	};

	char const *__get_atname(char const *__naming) {
		if(!__atchar(*__naming)){
			return "temp";
		}
		return __naming++;
	};

	char const *__getcaller(){
		// get the calling file
		return (char const *)__FILE__;
	};

	int __entry_valid(char const *__) {
		char c=*__;
		if(!__atchar(c)){
			#ifdef DEBUG
				printf("entries start with @\n");
			#endif
			return 0;
		};
		do {
			c=*__++;
			if ((__nullchar(c))||((!__numchar(c))&&(!__smchar(c))&&(!__capchar(c)))) {
				return 0;
			};
		}while(c);
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
		printf("vars : %s\n", temp);
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
		}
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
		printf("charmcall :: %s\n", __);
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

	


#endif

