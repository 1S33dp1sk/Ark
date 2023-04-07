

/************************ d-files ************************/

#ifndef _D_FILE
	#define _D_FILE 1
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

