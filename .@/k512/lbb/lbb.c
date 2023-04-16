/// lbb \\\
little black book

#ifndef __LBB__H
	#include "headers/lbb.h"
#endif

#ifndef __lbb_name
	#define __lbb_name "linked binary book"


// increment the cindex
ulong __index_increment() {
	__cindex+=1;
	return __cindex;
};

// set the next header at a new entry
ulong __set_next(char const *__head){
	ulong __len=str_rwings(__head);
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



// try to create a { SHARED } file
// get the mounted status of said file
// load into `lbb_shard`
int __ap_file(char const *__path){
	int __fd=open(__path,__lbb_shard_flags);
	if(__fd==-1){
		#ifdef LOG_ERR
			printf("cannot create share file, %s\n", __path);
		#endif
		return __fd;
	}
	lbb_shard.c_fd=__fd;
	if(get_mstat(__path, lbb_mstat)) {
		#ifdef LOG_ERR
			printf("cannot get the mounted status of file %s\n", __path);
		#endif
		return -1;
	};
	return __fd;
};

// try to create an FIFO engine 
int __ap_fifo(char const *__path){
	if(mkfifo(__path,__lbb_mode__)==0){
		return 1;
	}
	return -1;
};

// try to open a previously created
// engine as a writer, this can be any
// socket connections or commands , etc..
ulong __ap_writer() {
	ulong retres;
	int __fd=open(__d_lock,__lbb_lock_writer);
	if(__fd==-1){
		#ifdef LOG_ERR
			printf("cannot open writer\n");
		#endif
		retres=0;
		_exit(2);
	};
	ulong _fd=(ulong)__fd;
	#ifdef DEBUG
		printf("Writer : fifo opened :: %lu\n",_fd);
	#endif
	lbb_shard.c_fd=_fd;
	if(get_mstat(__d_lock, lbb_mstat)) {
		#ifdef LOG_ERR
			printf("cannot obtain mounted status for Writer on FIFO\n");
		#endif
		_exit(1);
	}
	return _fd;	
};

// try to open a recently created engine \
MUST NOT HAVE ANY LOCKING BITS
ulong __ap_reader() {
	ulong retres=0;
	int __fd=open(__d_lock,__lbb_lock_reader);
	if(__fd==-1){
		printf("cannot open reader\n");
		_exit(1);
	};
	ulong _fd=(ulong)__fd;
	#ifdef DEBUG
		printf("Reader : fifo opened :: %lu\n",_fd);
	#endif
	lbb_shard.c_fd=_fd;
	if(get_mstat(__d_lock, lbb_mstat)) {
		#ifdef LOG_ERR
			printf("cannot obtain mounted status for READER on FIFO\n");
		#endif
		_exit(2);
	};
	return _fd;
};

ulong __lbb_file_r(char const *__fpath) {
	ulong retres=0;
	int __fd=open(__fpath,__lbb_lock_reader);
	if(__fd==-1){
		#ifdef LOG_ERR
			printf("cannot open reader\n");
		#endif
		_exit(1);
	};
	retres=(ulong)__fd;
	#ifdef DEBUG
		printf("Reader : fifo opened :: %lu\n",retres);
	#endif
	return retres;
};

ulong __lbb_file_w(char const *__fpath) {
	ulong retres=0;
	int __fd=open(__fpath,__lbb_lock_writer);
	if(__fd==-1){
		#ifdef LOG_ERR
			printf("cannot open reader\n");
		#endif
		_exit(1);
	};
	retres=(ulong)__fd;
	#ifdef DEBUG
		printf("Reader : fifo opened :: %lu\n",retres);
	#endif
	return retres;
};

ulong __lbb_file_n(char const *__fpath) {
	ulong retres=0;
	ulong temp=str_rwings(__fpath), __total=temp;
	__total+=str_rwings(__FILE__);
	ulong __offset_f=sep_offset(__fpath, "@charms");
	ulong __offset_p=sep_offset(__FILE__, "@charms")+1;

	char const *__=__combine_str(str_b4offset(__FILE__, __offset_p), str_a4woffset(__fpath, __offset_f));

	printf("__ ::: %s\n", __);

	if((__offset_f)) {
		#ifdef LOG_ERR
			printf("cannot obtain dual offset\n");
		#endif
		_exit(2);
	};

	int __fd=open(__,__lbb_shard_flags);
	if(__fd==-1){
		#ifdef LOG_ERR
			printf("cannot open reader\n");
		#endif
		_exit(1);
	};
	retres=(ulong)__fd;
	#ifdef DEBUG
		printf("shard : file opened :: %lu\n",retres);
	#endif
	return retres;
};


// close the lbb filedescriptor currently
// opened under the lbb_shard structure
void purge_shard() {
	#ifdef DEBUG
		printf("Purging lbb shard\n");
	#endif
	close(lbb_shard.c_fd);
};


ulong __run_ap(ulong __size){
	if(__size>=512){
		ulong r_bytes=0,__FLAG=0;
		char __buffer[512];
		while(!__FLAG) {
			r_bytes=read(lbb_shard.c_fd,__buffer,512);
			if(r_bytes<=2){
				printf("read less than 3 bytes :: %s\n",__buffer);
				__FLAG=1;
			};
			r_bytes=0;memset(&__buffer,0,sizeof(__buffer));
		};
		purge_shard();
		return __FLAG;		
	}
	else {
		ulong w_bytes=0,__FLAG=0;
		char *__buffer="hello world";
		memset(&__buffer,0,sizeof(__buffer));
		while(!__FLAG) {
			w_bytes=write(lbb_shard.c_fd,__buffer,64);
			if(w_bytes<=2){
				printf("write less than 3 bytes :: %s\n",__buffer);
				__FLAG=1;
			};
			w_bytes=0;memset(&__buffer,0,sizeof(__buffer));
		};
		purge_shard();
		return __FLAG;				
	}
};


/*******************************************************************/


ulong __writeb(uchar *content,ulong c_size) {
	ulong __fd=shd_fd;
	if(__fd!=0){
		ulong _size = (ulong)write(__fd,content,c_size);
		#ifdef DEBUG
			printf( "resof write :: %lu\n",_size);
		#endif
		return _size;
	}	
	return 0;
};

char const *__readb(ulong f_size, ulong f_d,ulong r_o){
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
	return (char const *)strdup((char*)lbb_content);
};

void __readin(char *buffer, ulong size, ulong stfd) {
	ulong __res=0,__fsz=size,__fd=stfd;
	int __tempres=0;
	do {
		__tempres=pread(__fd, (buffer+__res), (__fsz-__res), __res);
		__res+=__tempres>0?__tempres:0;
	}while(__tempres!=0);
	buffer[__fsz]='\0';
};


void lbb_close(){
	close(shd_fd);
	memset(&lbb_shard,0,sizeof(c_shard));
};


ulong __fillb(){ // create &-> fill the book
	ulong __res=__writeb((uchar*)shd_key,LBB_BUFFER_SIZE);
	lbb_close();
	return __res;
};



ulong write_book(char *content, ulong csize) {

	return __writeb((uchar*)content,csize);
};

char const *read_book(char const *__cpath){ 
	m_stat cm_st;
	int res=get_mstat(__cpath, &cm_st);
	if(res!=0){
		return NULL;
	}
	return __readb(cm_st.m_size, __dgetfd(__cpath), 0);
};

ulong reset_book(){

	return __fillb();
};

ulong lbb_print(char *kaddr){
	ulong res=__writeb((uchar *)kaddr,str_rwings(kaddr));
	return res;
};

int lock_lbb(char const *__cpath,ulong __lock){
	ulong res=0;
	#if defined(locked)
		SET_LBB_PATH(__cpath);
		SET_LBB_FD(__lock);
	#endif
	char *LOCKING="locked\n";
	__writeb((uchar *)LOCKING,str_rwings(LOCKING));
	lbb_close();
	return res;
};





/*******************************************************************/


int get_sstat(char const *__path, s_stat *sfile) {
	memset(sfile,0,sizeof(s_stat));
	ulong path_len=str_rwings(__path);
	if(path_len>512){
		return -1;
	};
	memmove(sfile->s_path,__path,path_len);
	char *_path=(char *)__path;
	ulong off_at=sep_offset(_path,"@");
	if(off_at==0){
		return -1;
	};
	#if DEBUG
		printf("offset of @ is %lu characters\n", off_at);
	#endif

	char const *_baddr=str_b4offset(_path,off_at);
	sfile->sa_len=str_rwings(_baddr);

	char const *_4addr=str_a4offset(_path,off_at);
	sfile->se_len=str_rwings(_4addr);

	memmove((&sfile->s_addr),_baddr,sfile->sa_len);
	memmove((&sfile->s_ipv),_4addr,sfile->se_len);

	if(_4addr==NULL){
		return -1;
	}

	if(sfile->sa_len>8){sfile->s_term=Public;}else{ sfile->s_term=Private;}

	return 0;
};




ulong __get_long_digits(ulong num) {
	ulong cnum=((ulong)(num/10));
	ulong res=0;
	while(cnum!=0){
		res+=1;
		cnum=((ulong)(num/10));
	};
	return res+=1;
};
char *__get_cfname(char const *__fname, ulong __iter) {
	#ifdef DEBUG
		printf("cfname : %s :: %lu", __fname, __iter);
	#endif
	ulong __flen=str_rwings(__fname);
	char __[64];memset(&__,0,sizeof(__));
	sprintf(__,"%s:%lu",__fname,__iter);
	return strdup(__);
};

char const *__get_fcontents(char *__conts, ulong __size) {
	char __[__size];
	memset(&__,0,__size);
	sprintf(__,"{%s}",__conts);
	return (char const *)strdup(__);
};

void free_fields(c_fld **flds){
	ulong c=0;
	while(*flds++){
		free(flds[c]);
		c+=1;
	};
};


char const *__conv_fields(char const *__fn, ulong __fd, ulong __fld_count) {
	#ifdef DEBUG
		printf("fld ((conv)) ::\n");
		printf("fld name  : %s\n", __fn);
		printf("fld file  : %lu\n", __fd);
		printf("fld count : %lu\n", __fld_count);
	#endif
	char const *fld_name=__combine_str(d_lbb, __fn);
	ulong c=0,_res=0,__offset=0;

	// create entry in lbb
	ulong lbb_dd=__lbb_file_n(fld_name);

	// reset the fld to be to 0
	c_req request; memset(&request,0,size_creq);
	char *__buffer=(char *)request.data.etc;


	c_conv cst;
	while(c<__fld_count){
		memset(&cst, 0, sizeof(c_conv));
		memset(__buffer,0,4024);
		#ifdef DEBUG
			printf("Conv Fields DEBUG :: %lu\n", c);
		#endif
		// read size
		int __tempres=pread(__fd,(void *)__buffer,4096,__offset);
		if(__tempres==-1) {
			#ifdef LOG_ERR
				printf("%s : convolution :: could not read file ::: %s\n", "@LBB", shd_path);
			#endif
			return NULL;
		}
		else if (__tempres==0) {
			#ifdef LOG_ERR
				printf("%s : convolution :: file is empty ::: %s\n", "@LBB", shd_path);
			#endif
			continue;
		}
		else {
		// get the total size of file contents
			cst.chksize=(ulong)__tempres;
			__offset+=cst.chksize;		
		};
		
		// get the charms file path
		cst.chkname=__get_cfname(__fn, c);
		// get checksum for entire file
		cst.chksum=(char *)hashof(1,req_content(request),req_contlen(request));
		#ifdef DEBUG
			printf("fld : file path      :: %s\n", cst.chkname);
			printf("fld : read size      :: %lu\n", cst.chksize);
			printf("fld : file checksum  :: %s\n", cst.chksum);
		#endif
		// #ifdef OUTPUT
		// 	OUT_ASCII(lbb_dd, cst.chksize);		
		// 	OUT_ASCII(lbb_dd, cst.chkname);
		// 	OUT_ASCII(lbb_dd, cst.chksum);
		// 	OUT_ASCII(lbb_dd, field_content(field));
		// #endif		
		// pack the contents as binary with s indicator
		c+=1;
	};
	
	close(lbb_dd);

	return strdup(fld_name);
};


ulong __flds_count(int c) {
	int __c=(int)c;
	ulong count=0;
	do {
		count+=1;
		__c-=4096;
	}while(__c>4096);
	return count;
}

char const *conv_fields(m_stat *m_st){
	ulong __fd=open(m_st->m_path,__lbb_share_flags), __size=(m_st->m_size), __count=__flds_count(__size);

	return __conv_fields(hashof(1,m_st,sizeof(m_stat)),__fd,__count);
};


char *flds(char const *__fldname) {
	// convolute through the file to get
	// the fields
	if(__fldname==NULL){
		#ifdef LOG_ERR
			__TEXT(API : flds :: fld is null);
		#endif
		return NULL;
	};
	ulong __fld_n_size=strlen(__fldname);
	#ifdef DEBUG
		printf("flds : fldname :: %s ::: %lu\n", __fldname, __fld_n_size);
	#endif

	m_stat cm_st;
	__mstat__(&cm_st);
	int res=get_mstat(__fldname,&cm_st);
	if(res==-1){
		#ifdef LOG_ERR
			__TEXT(Field not found);
		#endif
		return NULL;
	};
	#ifdef DEBUG
		log_mstat(&cm_st);
	#endif

	
	char const *cflds_head=conv_fields(&cm_st);
	if(cflds_head==NULL){
		#ifdef LOG_ERR
			printf("cflds header is null\n");
		#endif
		return NULL;
	};
	// needs to index here

	#ifdef OUTPUT
		printf("'%s'\n",cflds_head);
	#endif

	return strdup(cflds_head);
};

/*******************************************************************/


int get_freader(m_stat *mst) {
	int _fd=open(mst->m_path,__lbb_lock_reader);
	if(_fd==-1){
		#ifdef LOG_ERR
			printf("cannot open reader for : %s\n", mst->m_path);
		#endif
		return -1;
	};
	ulong __fd=(ulong)_fd;
	lbb_shard.c_fd=__fd;
	#ifdef DEBUG
		printf("Reader : file opened :: %lu\n",shd_fd);
	#endif
	return 0;
};


char const *__lbb_command(char const *__cpath, char const *__args) {
	printf("lbb command @%s<%s>\n", __cpath, __args);
	int __res=-1;
	__res=get_mstat(__cpath, lbb_mstat);
	if(__res==-1) {
		#ifdef LOG_ERR
			printf("cannot obtain file @%s\n", __cpath);
		#endif
		return NULL;
	};
	return __args;
};

char const *__lbb_filepath(char const *__fpath, aip_sterm __term) {
	#ifdef PROCESS
		printf("lbb filepath :%s+%c\n", __fpath, __term);
	#endif
	// check the file requested
	int __res=-1;
	__res=get_mstat(__fpath, lbb_mstat);
	if(__res==-1) {
		#ifdef LOG_ERR
			printf("cannot obtain file @%s\n", __fpath);
		#endif
		return NULL;
	};
	// log the stats of the file requested
	#ifdef DEBUG
		log_mstat(lbb_mstat);
	#endif
	// get a reader for the file
	// if stat is obtained but reader
	// is not, most likely already added
	// or no permissions
	__res=get_freader(lbb_mstat);
	if(__res==-1) {
		#ifdef LOG_ERR
			printf("%s : filepath :: cannot open reader ::: %s \n", "@LBB", __fpath);
		#endif
		return NULL;
	};
	#ifdef PROCESS
		printf("lbb@%lu<%lu>\n", shd_fd, shd_sze);
	#endif
	ulong count=__flds_count(shd_sze);
	char const *convres=__conv_fields(shd_key,shd_fd,count);

	lbb_close();
	if(convres==NULL) {
		#ifdef LOG_ERR
			printf("could not do a convolution for path : %s\n", __fpath);
		#endif
		return shd_path;
	};
	#ifdef OUTPUT
		printf("@lbb%s\n filepath : %s\n", shd_key, __fpath);
	#endif
	return shd_key;
};

void const *__lbb_function(char const *__name, void const *__intype, void const *__castout) {

	printf("lbb function ::%s(%s)=%s\n", __name, __lbb_call_generic(__intype), __lbb_resp_generic(__castout));

	return ne;
};

void __free_ptr(void const *__) {
	free((void *)__);
}

void const *__lbb_field(char const *__keyname, void const *__content) {

	printf("lbb field <%s> ::: %p \n", __keyname, __content);

	__free_ptr(__content);
	return ne;
};

void const *__lbb_address(void *__) {

	printf("lbb address @%p", __);

	return ne;
};

void const *__lbb_type_args(lbb_at __atype) {
	switch(__atype){

	case __command: return (char const *(*)(char const *, char const *))&__lbb_command;

	case __filepath: return (char const *(*)(char const *, aip_sterm))&__lbb_filepath;

	case __function: return (void *(*)(char const *, void *, void *))&__lbb_function;

	case __field: return (void *(*)(char const *))&__lbb_field;

	default: return (void *(*)(__lbb_vp))&__lbb_address;

	};
	return ne;
};

int __init_field(char const *arg) {
	m_stat cm_st;
	get_mstat(arg, &cm_st);
	printf("argument : %s\n", arg);
	conv_fields(&cm_st);
	return 0;
};


void *__into__(d_into *st) {
	
	return memset(st, 0, sizeof(d_into));
};

	int __no_entry__(void *proto_call) {
		#ifdef PROCESS
			printf("No Entry.\n");
		#endif
		_exit(1);
		return ne__;
	}


	#define evaluate(...) __VA_ARGS__;

	#define debug(...) do {\
		ulong __len=str_rwings(#__VA_ARGS__);\
		ulong __delims=arr_cdelims(#__VA_ARGS__);\
		if(__delims>1) {\
			void const **__vargs = variable_args(__delims, #__VA_ARGS__, ARR_DELIM);\
			ulong c=0; do {\
				printf("vargs[%lu] : %s\n", c, (char const *)__vargs[c]);\
				c+=1;\
			}while(c<=__delims);\
			char const *__var=evaluate(__vargs[1]);\
			printf("%s",__var);\
		};\
	} __dPER;

	int __info__(void *proto_call) {
		#ifdef PROCESS
			printf("@info\n");
		#endif

		return ne__;
	};

	int __pointer__(void *proto_call) {
		char const *ptr_name = base_address(0);
		#ifdef PROCESS
			printf("@pointer:%s\n", ptr_name);
		#endif
		return ne__;
	};

	int __field__(void *proto_call) {
		char const *fld_name = base_address(1);
		#ifdef PROCESS
			printf("@field: %s\n", fld_name);
		#endif
		debug("Field",fld_name,"temp",ne__)
		return ne__;
	};

	int __w3__(void *proto_call) {

		return ne__;
	}

	int __point__(void *proto_call) {
		char const *point_name = base_address(2);
		#ifdef PROCESS
			printf("@point: %s\n", point_name);
		#endif
		return ne__;
	};

	d_into *dcloud(void *proto_call) {
		char const *dc_address=base_address(3);
		#ifdef PROCESS
			printf("d-%s\n", dc_address);
		#endif
		return NULL;
	};

	#define p_switcher(x) (x->switcher)

	int act2args(aip_st *proto_call) {
		switch(p_switcher(proto_call)) {
		case -1 : return __no_entry__(proto_call);
		case 0  : return __info__(proto_call);
		case 1  : return __pointer__(proto_call);
		case 2  : return __field__(proto_call);
		case 3  : return __pointer__(proto_call);
		default: return ne__;
		};
	};

	lbb_entry __decode_arg(char const *argument) {
		char const *point_buffer=argument;
		printf("lbb: decode :: %s\n", point_buffer);
		// __info__
		if(point_buffer==NULL) {
			#ifdef PROCESS
				printf("Info (%s)\n", base_address(0));
			#endif
			return __lbb_info__;
		}
		else if(*point_buffer=='@') { // AT_DEFINED '@' => __@__
			// @
			int __flag=0, i=0;
			point_buffer = &point_buffer[1];
			for(; i<3; i++) {
				if (point_buffer[i]==d_lbb[i]){
					// lbb
					__flag+=1;
				}
				else if(point_buffer[i]==d_charms[i]) {		
					// charms
					__flag+=4;
				};
			};
			if(__flag==3) {
				#ifdef PROCESS
					printf("Book (%s)\n", base_address(1));
					printf("@Query\n");
				#endif
				return __lbb_variable__;
			}
			else if (__flag==12) {
				for(i=0; i<6; i++) {
					if(point_buffer[i]==d_charms[i]) {
						__flag+=8;
					};
				};
				if(__flag==60) {
					#ifdef PROCESS
						printf("@charms-pointer : %s\n", &point_buffer[i]);
					#endif
					return __lbb_charms__;
				};
				#ifdef PROCESS
					printf("unknown point : %s\n", &point_buffer[i]);
				#endif
				return 0;
			}
			else {
				#ifdef PROCESS
					printf("ATP ::: %s\n", argument);
				#endif
				return __lbb_atp__;
			};
		}
		else {
			return __lbb_yeild__;
		};
	};

	int lbb_argument(char const *__arg) {

		return (int)__decode_arg(__arg);
	};


#endif