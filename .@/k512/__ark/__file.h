

/************************ d-files ************************/

#ifndef _D_FILE
	#define _D_FILE 1

	uchar const *__dbook(char const *__cpath, ulong __size) {
		m_stat cm_st;
		int res=get_mstat(__cpath, &cm_st);
		if(res!=0){
			return NULL;
		}
		return __readb(__size, __dgetfd(__cpath), 0);
	};

	uchar const *__readb(ulong f_size, ulong f_d, ulong r_o){
		ulong __res=r_o,__fsz=f_size,__fd=f_d;
		uchar lbb_content[__fsz+1];
		int __tempres=read(__fd,lbb_content,__fsz);
		if(__tempres==-1){
			printf("cannot read lbb\n");
			return NULL;
		};
		__res=(ulong)__tempres;
		lbb_content[__fsz+1]='\0';
		if((__res<__fsz)&&(__res>0)){
			// means that reading was interuptted
			// for some reason, like a pipe or sig
			// so we can read from where we left off
			__res=pread(__fd,(lbb_content+__res),(__fsz-__res),__res);
		};
		return (uchar const *)strdup((char*)lbb_content);
	};


	ulong __writeb(uchar *content,ulong c_size, ulong __fd) {
		if(__fd!=0){
			long _size = write(__fd,content,c_size);
			#ifdef DEBUG
				printf( "resof write :: %ld\n",_size);
			#endif
			return (ulong)_size;
		}	
		return 0;
	};


	void *__statusof(char const *__path) {
	    struct stat __;
	    memset(&__,0,sizeof(struct stat));
	    if(stat(__path,&__)==0){
	        return (void *)__path;
	    }
	    return NULL;
	};

	int __stres(char const *__path){
		int __res=access(__path, F_OK);
		#ifdef DEBUG
			printf("checking cpath :: %s\n", __path);
			printf("result of access = %d\n", __res);
		#endif
		return __res==0;
	};

	ulong fsize_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_size;
	};

	ulong iosize_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_blksize;
	};

	ulong dmode_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_mode;
	};

	ulong inn_st(void *st){
	    struct stat *__=(struct stat*)st;
	    return __->st_ino;
	};

	ulong __fsize(char const *__fpath){
		struct stat __;
		memset(&__,0,sizeof(struct stat));
		if(stat(__fpath,&__)!=0){return 0;}
		return __.st_size;
	};

	ulong __iosize(char const *__fpath){
		struct stat __;
		memset(&__,0,sizeof(struct stat));
		if(stat(__fpath,&__)!=0){return 0;}
		return __.st_blksize;
	};

	ulong __inodenum(char const *__fpath){
		struct stat __;
		memset(&__,0,sizeof(struct stat));
		if(stat(__fpath,&__)!=0){return 0;}
		return __.st_ino;
	};

	ulong __dmode(char const *__fpath){
		struct stat __;
		memset(&__,0,sizeof(struct stat));
		if(stat(__fpath,&__)!=0){return 0;}
		return __.st_mode;
	};

	ulong __file_r(char const *__cpath){
		if (access(__cpath,R_OK)==0){
			return 1;
		}
		return 0;
	};

	ulong __file_w(char const *__cpath){
		if (access(__cpath,W_OK)==0){
			return 2; 
		}
		return 0;
	};

	ulong __file_x(char const *__cpath){
		if (access(__cpath,X_OK)==0){
			return fsze(__cpath);
		}
		return 0;
	};

	int __dgetfd(char const *__fpath) {
		return open(__fpath, __lock_reader);
	};

#endif

