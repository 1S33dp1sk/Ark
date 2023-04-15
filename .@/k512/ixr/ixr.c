/// ixr \\\
The indexer


#ifndef __IXR__H
	#include "headers/ixr.h"
#endif

#ifndef __ixr_name 
	#define __ixr_name "indexer"



	#define IXR_FILE __d_lock

	/********* d-types *********/

	d_point ref_point(void const *__arg, char const *__key, char const *__format) {
		if(__key[0]=='&') {
			++__key;
		};
		ulong keylen=str_rwings(__key);
		d_point __point; memset(&__point, 0, size_dpoint);
		ulong packedlen=__ixr_argument(__format, __arg);
		#ifdef DEBUG
			printf("packed length :: %lu\n", packedlen);
		#endif
		__point.c_index=__cindex;
		__point.c_name=__key;
		__point.c_ref=__arg;
		__point.c_fmt=__format;

		return __point;
	};

	char const *ixr_format(ixr_t idx_type) {
		switch(idx_type) {
		case __ixr_header:	return __head_fmt;
		case ixr_point:		return __value_fmt;
		case ixr_file:		return __file_fmt;
		case ixr_dprg:		return __dprg_fmt;
		case ixr_fld:		return __fld_fmt;
		default: return NULL;
		};
	};

	char const *__kaddress(char const *__hash) {
	    ulong __len=str_rwings(__hash)+3;
	    char temp[__len];memset(&temp, 0, sizeof(temp));
	    temp[0]='k';
	    switch((__len-3)) {
	    case 8:  temp[1]='C'; break; // command 
	    case 16: temp[1]='I'; break; // interpreter
	    case 32: temp[1]='P'; break; // payload
	    default: temp[1]='-'; break; // K-address
	    };
	    memmove((temp+2), __hash, __len);
	    temp[__len]='\0';
	    return (char const *)strdup(temp);
	};

	void *__erv(char const *__key,char const *__val) {
		ulong __sz=str_rwings(__key)+str_rwings(__val)+5;
		ulong __len=len_ustrze(__sz);
		void *__=malloc(__len);
		memset(__, 0, __len);
		ulong psz=pack(__, ixr_format(ixr_point), __cindex, __key, __val);
		return __;
	};

	ulong __set_next_p(void *__) {
		ulong retres=__set_next((char const *)(__));
		free(__);
		return retres;
	};

	char const *__generic_fmt(fmt_t __format, ...) {

		return NULL;
	};

	uchar const *__urv(uchar const *__key, char const *__value) {
		char const *__rv=__generic_fmt(__keyval__, __key, __value);
		ulong urv_len=__rwings((void *)__rv)+ULONG_MAX_DIGITS;
		char urv[urv_len];memset(&urv, 0, sizeof(urv));
		sprintf(urv, "%lu:%s", __cindex, __rv);
		return (uchar const *)strdup(urv);
	};

	// irv
	char const *__irv(char const *__key, char const *__value) {
		char const *__rv=__generic_fmt(__keyval__, __key, __value);
		ulong irv_len=str_rwings(__rv)+ULONG_MAX_DIGITS;
		char irv[irv_len];memset(&irv, 0, sizeof(irv));
		sprintf(irv, "%lu:%s", __cindex, __rv);
		return (char const *)strdup(irv);
	};
	
	// start the indexer
	ulong __idx_start(){
		if(__cindex!=0){
			return 0;
		};
		return __index_increment();
	};
	

	// create a xreference for the current indexer
	char const *__xreference(char const *__) {

		return hashof(1,(void *)__,str_rwings(__));
	};
	

	// generic fmt -> xreference -> setnext
	int __index_r(char const *idxnr) {
		char const *_rfmt=__generic_fmt(__keyval__,  __xreference(idxnr), idxnr);
		return __set_next(_rfmt);
	};
	

	// irv -> __setnext -> (key, val)
	int __index_irn(char const *key, char const *val) {

		return __set_next(__irv(key, val));;
	};
	

	// irv -> __setnext -> (key, __xreference)
	int __index_ixn(char const *key) {

		return __index_irn(key, __xreference(key));
	};
	

	// irv -> __setnext -> (__xreference, caller)
	int __index_caller() {
		char const *caller=__getcaller();
		return __index_irn(__kaddress(__xreference(caller)), caller);
	};
	

	ulong __set_unext(uchar const *__head){
		ulong __len=__rwings(__head);
		if((__head==NULL)||__len==1){
			return 0;
		};
		long _res=pwrite(__ixr_fd,__head,__len,___offset);

		if(_res!=-1){
			___offset+=__len;
		};
		#ifdef DEBUG
			printf("\nnext -->\n");
			printf("head   :: %s\n", __head);
			printf("length :: %lu\n", __len);
			printf("result :: %ld\n", _res);
			printf("offset ::: %lu\n", ___offset);
		#endif
		return __index_increment();
	};

	int __index_urn(uchar const *_key, char const *_val) {

		return __set_unext(__urv(_key, _val));
	};

	// irv -> __setnext -> (reference, name)
	int __index_point(d_point *dst) {

		return __index_urn(dst->c_ref, dst->c_name);
	};

	/********* indexer IO *********/

	// initiate and set memory to zero for the header struct
	ixr_h *__header__() {

		return (ixr_h *) memset(&___header, 0, sizeof(ixr_h));
	};

	// read the indexer header \\
	OFFSET ALWAYS 0
	int __header_in() {

		return 0;
	};

	#define tostr(x) #x

	int __load_header() {
		__header__();
		#ifdef PROCESS
			printf("read :::");
		#endif
		uchar *__head=ixr_ubuf;
		int __rbytes=pread(__ixr_fd, (void *)__head, __I_LEN, 0);
		if (__rbytes==-1) {
			#ifdef LOG_ERR
				printf("%s : err :: cannot write header to indexfile ::: %d\n", __FILE__, errno);
			#endif
			return -1;
		};
		#ifdef DEBUG
			printf("read %d bytes for idx header\n", __rbytes);
		#endif
		__head[__I_LEN-1]='\0';
		unpack(__head, ixr_format(ixr_point), __rbytes);

		___header.shared_size=u[0];
		___header.mods_count=u[1];
		___header.pub_key=tostr(u[2]);
		___offset=(ulong)__rbytes;
		#ifdef DEBUG
			printf("attempting %d @indexfile: %lu\n", __rbytes, u[0]);
			log_ixrh(&___header);
		#endif	
		return __header_in();
		return 0;		
	};

	int __rd_ixrh() {
		#ifdef DEBUG
			printf("reading :::\n");
		#endif
		uchar __head[29];ulong __hsz=sizeof(__head);memset(&__head, 0, __hsz);
		ulong __hfsize=fsze(IXR_FILE);
		if(__hfsize<__hsz) {
			__hsz=__hfsize;
		};
		int __tempres=pread(__ixr_fd, (void *)__head, __hsz, 0);
		if(__tempres==-1) {
			#ifdef LOG_ERR
				printf("cannot read header\n");
			#endif
			return -1;
		};
		unpack(__head, ixr_format(ixr_point), ixr_h_size(___header));
		___header.shared_size=u[0];
		___header.mods_count=u[1];
		___header.pub_key=tostr(u[2]);
		___offset=(ulong)__tempres;
		#ifdef DEBUG
			printf("attempting %d @indexfile: %lu\n", __tempres, __hfsize);
			log_ixrh(&___header);
		#endif
		return 0;
	};

	// write the indexer header \\
	OFFSET ALWAYS 0
	int __header_out(uchar *__header_content, ulong __header_size) {
		if(__header_size>__I_LEN){
			#ifdef LOG_ERR
				printf("cannot pack more than 64 bytes in the header\n");
			#endif
			return -1;
		};
		int __bytes_w=pwrite(__ixr_fd, (void *)__header_content, __header_size, 0);
		if(__bytes_w==-1){
			#if LOG_ERR
				printf("%s : err :: cannot write header to indexfile ::: %d\n", __FILE__, errno);
			#endif
			return -1;
		};
		#ifdef DEBUG
			printf("wrote %d bytes for idx header\n", __bytes_w);
		#endif
		___offset=(ulong)__bytes_w;
		return 0;
	};

	int __write_header() {
		#ifdef PROCESS
			printf("@IXR<write>(header)\n");
		#endif
		uchar __head[__I_LEN];memset(&__head, 0, sizeof(__head));
		unsigned __temp=pack(__head, ixr_format(__ixr_header), ixr_h_args);
		__head[__I_LEN-1]='\0';
		__header_out(__head, __temp);
		#ifdef DEBUG
			printf("packed %d bytes for idx header\n", __temp);
		#endif
		return 0;
	};

	// obtain header properties { ENVIROMENT }
	int __refresh_header() {
		___header.shared_size=fsze(IXR_FILE);
		___header.mods_count=__cindex;
		___header.pub_key=tostr(fhash16(1, IXR_FILE));
		return 0;
	}
	// check if header exsits then retain 
	// new header properties
	int refresh_h() {
		if(!__stres(IXR_FILE)) {
			#ifdef LOG_ERR
				printf("indexfile does not exist\n");
			#endif
			return 1;
		};
		return __refresh_header();
	};

	// start the indexer 
	int indexer_start() {
		// if the indexer has not been instantiated but has
		// a different value than the original constant
		if(__ixr_fd!=0x228){
			#ifdef LOG_ERR
				printf("trying to instantiate indexer that is not on %d", 0x228);
			#endif
			return -1;
		};
		if(__stres(IXR_FILE)) {
			#ifdef LOG_ERR
				printf("indexer already exists\n");
			#endif
			return -1;
		};
		__header__();
		int ixr_fd=-1;
		ixr_fd=open(IXR_FILE, __ixr_start_flags, __ixr_pmode);
		if(ixr_fd==-1){
			#ifdef LOG_ERR
				printf("err : ixr :: failed to create index file ::: %s\n", IXR_FILE);
			#endif
			return -1;
		};
		__ixr_fd=(ulong)ixr_fd;
		#ifdef DEBUG
			printf("Indexer started ::: %lu\n",__ixr_fd);
		#endif
		__refresh_header();
		if(__write_header()) {
			#ifdef LOG_ERR
				printf("cannot write indexer header\n");
			#endif
			return -1;
		};
		#ifdef DEBUG
			printf("@offset %lu\n",___offset);
		#endif
		return 0;
	};

	// index any incoming idrs
	int __indexer__(char const *idr) {
		if(idr==NULL){
			#ifdef LOG_ERR
				printf("requested to index NULL\n");
			#endif
			return -1;
		};
		if(__ixr_fd==0x228) {
			int ixr_fd=-1;
			ixr_fd=open(IXR_FILE, __ixr_access_flags, __ixr_pmode);
			if(ixr_fd==-1){
				#ifdef LOG_ERR
					printf("Cannot open indexer file\n");
				#endif
				return -1;
			};
			__ixr_fd=(ulong)ixr_fd;
			#ifdef DEBUG
				printf("Parsing index file :: %s\n", IXR_FILE);
				printf("file descriptor :open::%d\n",ixr_fd);
			#endif
		};
		__header__();
		if(__rd_ixrh()) {
			#ifdef LOG_ERR
				printf("cannot read indexer header\n");
			#endif
			return -1;
		};
		#ifdef DEBUG
			printf("@offset %lu\n",___offset);
		#endif
		return 0;
	};
	ixr_h *indexer_header() {
		ulong header_size=sizeof(___header);
		ixr_h *temp = malloc(header_size);
		memmove(temp, &___header, header_size);
		return (ixr_h *)temp;
	};


	int refer_index(void *__ptr, void *__ref, char *__prname) {
		char *rname=(char *)__ref;
		if(__exact_match(rname, __prname)) {
			printf("exact match\n");
		};

		printf("ptr  : %p\n", __ptr);
		printf("lbbr : %p\n", __ref);
		printf("ref  : %s\n", rname);
		printf("name : %s\n", __prname);
		return 0;
	};
	

    ulong __ixr_argument(char const *__format, void const *__) {
    	char const arg_fmt=__format[0];
    	uchar pbuf[__A_LEN];
    	memset(pbuf, 0, sizeof(pbuf));
    	ulong ps=0;

    	switch(arg_fmt) {
    	case 's': ps=pack(pbuf, __format, (char *)__); break;
    	case 'h': ps=pack(pbuf, __format, (int *)__); break;
    	case 'H': ps=pack(pbuf, __format, (ulong *)__); break;
    	case 'l': ps=pack(pbuf, __format, (long*)__); break;
    	case 'L': ps=pack(pbuf, __format, (ulong*)__); break;
    	case 'Q': ps=pack(pbuf, __format, (ullong*)__); break;
    	case '_': ps=pack(pbuf, __format, (void *)__); break;
    	default: return 0;
    	};
    	return ps;
    };


ixr_h *ixr_get(d_into ist) {
	ixr_h *header=__header__();
	char const *var_name=(char const *)in_arg_n(ist, 1);
	#ifdef PROCESS
		printf("@ATP<get>(%s)\n", var_name);
	#endif
	return header;
};


ixr_h *ixr_set(d_into ist) {
	ixr_h *header=__header__();
	char const *var_name=(char const *)in_arg_n(ist, 1);
	char const *var_val=(char const *)in_arg_n(ist, 2);
	#ifdef PROCESS
		printf("@ATP<set>(%s){%s}\n", var_name, var_val);
	#endif
	return header;
};

ixr_h *ixr_prun(d_into ist) {
	ixr_h *header=__header__();

	char const *p_name=(char const *)in_arg_n(ist, 1);
	#ifdef PROCESS
		__TEXT(Run :: );
	#endif
	return header;
};

ixr_h *ixr_psave(d_into ist) {
	ixr_h *header=__header__();
	char  const *d_name=(char const *)in_arg_n(ist, 1);
	#ifdef PROCESS
		__TEXT(Save :: );
	#endif
	return header;
};

ixr_h *ixr_pcollect(d_into ist) {
	ixr_h *header=__header__();
	char  const *f_att=(char const *)in_arg_n(ist, 1);
	#ifdef PROCESS
		__TEXT(Collect :: );
	#endif
	return header;
};


ixr_h *ixr_export(aip_st *_intro) {
	printf("IXR&->export ::\n");
	return (ixr_h *)ne;
};

ixr_h *ixr_run(aip_st *_intro) {
	return (ixr_h *)ne;

};

ixr_h *ixr_save(aip_st *_intro) {
	return (ixr_h *)ne;

};

ixr_h *ixr_collect(aip_st *_intro) {
	return (ixr_h *)ne;

};


ixr_h *args3head(d_into ist) {
	switch(in_switch(ist)) {
		case 2:
			return ixr_get(ist);
		case 3:
			return ixr_set(ist);
		case 4:
			return ixr_prun(ist);
		case 5:
			return ixr_pcollect(ist);
		case 6:
			return ixr_psave(ist);
		default:
			return __header__();
	};
};




	#define __ixr_name "indexer"
#endif