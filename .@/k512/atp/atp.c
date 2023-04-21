/// ATP- \\\
@-protocol

#ifndef __ATP__H
	#include "headers/atp.h"
#endif



#ifndef __aip__
	#define __aip__ {};


	void __aip_send(aip_sock *sock, char *msg_to_send){
		ulong msglen=str_rwings(msg_to_send);
		#ifdef DEBUG
			printf("message sent :: %s\n", msg_to_send);
		#endif
		if(send(sock_fd(sock),msg_to_send,msglen,0)==-1){
			#ifdef LOG_ERR
				printf("send : failed :: payload { %s }\n", msg_to_send);
			#endif
		};
	};


	char *__aip_sock_raw(){

		return (char *)&__sok.aip_sockst;
	};



	void *__aip_sock__(aip_sock *sok) {

		return memset(sok, 0, sizeof(aip_sock));
	};


	struct sockaddr *aip2sockaddr(){

		return __aip2sockaddr(&__sok);
	};

	int aip_recv(aip_sock *sock, uchar *buf) {
		int numbytes=0;
		memset(buf,0,512);
		if ((numbytes = recv(sock_fd(sock), buf, 512, 0))==-1) {
			#ifdef LOG_ERR
				printf("aip : recv :: failed\n");
			#endif
			return -1;
		};
		return numbytes;
	};

	void *aip_send(aip_sock *sock, void *msg_to_send){
		// char const *__msg=__combine_str("@KaramJ:",msg_to_send);
		char const *__msg=(char const *)msg_to_send;
		ulong msglen=str_rwings(__msg);
		long __res=send(sock_fd(sock),__msg,msglen,0);
		if(__res==-1){
			#ifdef LOG_ERR
				printf("send : failed :: payload { %s }\n", __msg);
			#endif
			return NULL;
		}
		else {
			#ifdef DEBUG
				printf("sent message : %s\n", __msg);
			#endif
			memset(msg_to_send, 0, 512);
			return (void *)hashof(1, __msg, msglen);
		};
	};

	char *aip_rcv_msg(int rlen, void *__rmsg) {
		int res=0, i;
		uchar *ur_msg=(uchar *)__rmsg;
		uchar pld_mask[4];
		for(i=0;i<4;i++){pld_mask[i]=0;};
		#ifdef DEBUG
			printf("decoding msg of %d bytes\n", rlen);
		#endif
		if(ur_msg==NULL) {
			#ifdef LOG_ERR
				printf("aip : recv :: msg ::: NULL\n");
			#endif
			return NULL;
		};

		uchar _fro=ur_msg[0];
		res+=1;
		uchar _pyl=ur_msg[1];
		res+=1;

		int pld_masked=PLD_MASKED(_pyl);
		int pld_size=PLD_SIZE(_pyl);

		if(pld_size==126){
			pld_size=0;
			for(i=0; i<2; i++) {
				pld_size+=ur_msg[res+i];
			};
			res+=2;
		}
		else if(pld_size==127) {
			pld_size=0;
			for(i=0; i<8; i++) {
				pld_size+=ur_msg[res+i];
			};
			res+=8;
		};
		if(pld_masked) {
			for(i=0; i<4; i++) {
				pld_mask[i]=ur_msg[res+i];
				#ifdef DEBUG
					printf("MASK[%d]=%u\n", i, pld_mask[i]);
				#endif
			};
			res+=4;
		};

		uchar a_msg[pld_size+1];
		for(i=0; i<pld_size; i++) {
			a_msg[i]=((ur_msg[res+i])^(pld_mask[i%4]));
		};
		a_msg[pld_size]='\0';

		#ifdef DEBUG
			printf("FIN     : %u\n", FRAME_FIN(_fro));
			printf("RSV 1   : %u\n", FRAME_RSV1(_fro));
			printf("RSV 2   : %u\n", FRAME_RSV2(_fro));
			printf("RSV 3   : %u\n", FRAME_RSV3(_fro));
			printf("OPCODE  : %u\n", FRAME_OPCODE(_fro));
			printf("MASKED  : %u\n", pld_masked);
			printf("PLD LEN : %u\n", pld_size);
			printf("Payload { %s }\n", a_msg);
		#endif

		return strdup((char *)a_msg);
	};


	struct sockaddr *__aip2sockaddr(aip_sock *sock){
		struct sockaddr_storage *saddrst=((struct sockaddr_storage *)(&(sock->aip_sockst)));
		return (struct sockaddr *)saddrst;
	};

	int __aip_listen(ulong aipsfd){
		int res=listen(aipsfd,ATP_BACKLOG)==-1?1:0;
		if(res==-1){
			printf("err number:\n");
			printf("%d\n",errno);
			return 1;   
		}
		return 0;
	};

	void *__aip_recieve(aip_sock *sock) {
		int numbytes;
		char buf[512];
		memset(&buf,0,sizeof(buf));
		if ((numbytes = recv(sock_fd(sock), buf, 512, 0))==-1) {
			#ifdef LOG_ERR
				printf("aip : recv :: failed\n");
			#endif
			exit(1);
		};
		return (void *)strdup(buf);
	};

	void *__aip_activate(aip_sock *sock, char *msg_to_send, char const *msg_hash){
		char const *_hmsg=__combine_str(wss_acc_h, msg_hash);
		char const *__msg=__combine_str(msg_to_send, _hmsg);
		#ifdef DEBUG
			printf("activation MESSAGE :: \n%s\n", __msg);
		#endif
		ulong msglen=str_rwings(__msg);
		if(send(sock_fd(sock),__msg,msglen,0)==-1){
			#ifdef LOG_ERR
				printf("send : failed :: payload { %s }\n", __msg);
			#endif
			return NULL;
		};
		return (void *)strdup(__msg);
	};

	void *__atp_pointer() {
		atp_pointer *atp_p=malloc(sizeof(atp_pointer));
		memset(atp_p, 0, sizeof(atp_pointer));
		__arcpid();
		#ifdef PROCESS
			printf("ATP<arcpid> = %lu\n", __arc.__pid);
		#endif
		atp_p->ptr = atp_p;
		sprintf(atp_p->addr, "%lu", __arc.__pid);
		atp_p->chkref = hash_follow(0, atp_p->addr);
		#ifdef DEBUG
			printf("%p<%s>(%s)\n", atp_p->ptr, atp_p->addr, atp_p->chkref);
		#endif
		return atp_p->ptr;
	};

	void _socket_address_free(d_portal *aip_st){

		free(aip_st->s_address);
	};

	void _socket_free_fd(aip_sock *sok_t) {

		close(sok_t->aip_sockfd);
	};

#endif


#ifndef __http__
	content_st *crt_http_content(char const *__, content_pm __type) {
		ulong __size=str_rwings(__);
		void *__content_string=malloc(__size*sizeof(char));
		memmove(__content_string, __, __size);
		content_st *content=(content_st *)malloc(sizeof(content_st));
		if(content==NULL){
			#ifdef LOG_ERR
				printf("cannot allocate enough memory for content\n");
			#endif
			return NULL;
		};
		content->c_size=__size;
		content->content=__content_string;
		content->__type=__STRING(http_content_type(__type));
		return content;
	};

	content_pm proto_from_status(ulong __status) {
		switch(__status) {
		case 200:
			return __http_request;
		case 101:
			return __http_switch;
		default:
			return __http_request;
		}
		return __http_request;
	};

	char const *form_http_request(http_req req_type, char const *__path) {
		if(__path==NULL){
			#ifdef LOG_ERR
				printf("unable to create request : path is null\n");
			#endif
			return NULL;
		};
		char const *request_name=__http_names(req_type);
		if(request_name==NULL){
			#ifdef LOG_ERR
				printf("unable to create request : request type is unknown\n");
			#endif
			return NULL;
		};
		char const *temp=expand_atoffset(__http_request_base, request_name, 0);
		ulong p_offset=sep_offset(temp, "P");
		temp=expand_atoffset(temp, __path, p_offset);
		ulong v_offset=sep_offset(temp, "V");
		temp=expand_atoffset(temp, __http_protocol_version, v_offset);
		return strdup(temp);
	};

	char const *form_http_response(ulong res_type, char const *req_result) {
			ulong b_offset=sep_offset(__http_response_base, "B");
		char const *temp=expand_atoffset(__http_response_base, __http_protocol_version, b_offset);
			ulong s_offset=sep_offset(temp, "S");
			temp=expand_atoffset(temp, num2char(res_type), s_offset);
			ulong r_offset=sep_offset(temp, "R");
			temp=expand_atoffset(temp, req_result, r_offset);
			return strdup(temp);
	};

	char const *http_response(ulong http_status, char const *http_result) {
		
		return form_http_response(http_status, http_result);
	};

	char const *http_config(char const *c_key, char const *c_val) {

		return __config_prop(c_key, c_val);
	};
#endif



#ifndef __atp__
	#define __atp_name "@-Protocol"
	// void *__aip_start__(aip_sock *sock) {
	// 	#ifdef OUTPUT
	// 		printf("atp : %s : start\n", __atp__);
	// 	#endif
	// 	void *varc=__arc_address(hashof(1, sock, sizeof(aip_sock)));
	// 	__handle_convo(sock);
	// 	return varc;
	// };
	#define __atp__(x) aip_sock * {\
		printf("atp : @-Porotocol :: strt");\
		void *varc = __arc_address(hashof(1, #x, sizeof(aip_sock)));\
		__handle_convo(x);\
		return varc;\
	}
		
	


	void *__sok_addr(struct sockaddr *sa) {
		if (sa->sa_family == AF_INET) {
			return &(((struct sockaddr_in*)sa)->sin_addr);
		}
		else {
			return &(((struct sockaddr_in6*)sa)->sin6_addr);
		};
		return NULL;
	};

	ulong __sok_fd() {

		return __arc.__sok.aip_sockfd;
	};

	ulong __sok_len(){

		return __arc.__sok.aip_socklen;
	};

	void __err_socket(char const *__, int __errno) {
		printf("%s ::: %d", __, __errno);
		switch(__errno) {
		     case EBADF         : printf( "socket is not a valid file descriptor."); break;
		     case ECONNABORTED  : printf( "The connection to socket has been aborted."); break;
		     case EFAULT        : printf( "The address parameter is not in a writable part of the user address space."); break;
		     case EINTR         : printf( "The accept() system call was terminated by a signal."); break;
		     case EINVAL        : printf( "socket is unwilling to accept connections."); break;
		     case EMFILE        : printf( "The per-process descriptor table is full."); break;
		     case ENFILE        : printf( "The system file table is full."); break;
		     case ENOMEM        : printf( "Insufficient memory was available to complete the operation."); break;
		     case ENOTSOCK      : printf( "socket references a file type other than a socket."); break;
		     case EOPNOTSUPP    : printf( "socket is not of type SOCK_STREAM and thus does not accept connections."); break;
		     case EWOULDBLOCK   : printf( "socket is marked as non-blocking and no connections are present to be accepted."); break;
		}
		printf("\n");
	};
	
	aip_sock __address() {
		aip_sock __sok; 
		memset(&__sok,0,sizeof(aip_sock));

		struct addrinfo hints;
		memset(&hints, 0,sizeof(hints));
		hints.ai_flags=AI_PASSIVE;
		hints.ai_socktype=SOCK_STREAM;
		hints.ai_family=PF_UNSPEC;

		struct addrinfo *srvinfo, *aip;
		struct sockaddr_storage ss_addr;
		int __sfd, __res=1, __yes=1;

		if ((__res=getaddrinfo(__loc_i4,ATP_PORT,&hints,&srvinfo))){
			#ifdef DEBUG
				printf("getaddrinfo error : %s\n", gai_strerror(__res));
			#endif
			memset(&__sok,0,sizeof(aip_sock));
			return __sok;
		};

		for(aip=srvinfo;aip!=NULL;aip=aip->ai_next){
			if((__sfd=socket(aip->ai_family,aip->ai_socktype,aip->ai_protocol))==-1){
				#ifdef DEBUG
					printf("server :: socket\n");
				#endif
				continue;
			}
			if(setsockopt(__sfd,SOL_SOCKET,SO_REUSEADDR,&__yes,2)==-1){ // 2 = sizeof(unsigned)
				#ifdef DEBUG
					printf("setsockopt\n");
				#endif
				#ifdef LOGOUT_ERR
					exit(1);
				#endif
				continue;
			}
			if(bind(__sfd,aip->ai_addr,aip->ai_addrlen)==-1){
				close(__sfd);
				#ifdef DEBUG
					printf("server: bind\n");
				#endif
				continue;
			}
			#ifdef DEBUG
				printf("aip->next\n");
			#endif
			break;
		};
		freeaddrinfo(srvinfo);

		if(aip==NULL){
			#ifdef DEBUG
				printf("cannot connect to any socket\n");
			#endif
			_exit(1);
		};

		__sok.aip_sockfd=__sfd;
		__sok.aip_socklen=(ulong)(aip->ai_addrlen);
		struct sockaddr_storage *sasp=(struct sockaddr_storage*)aip->ai_addr;
		memmove(&(__sok.aip_sockst), sasp, sizeof(struct sockaddr_storage));

		return __sok;
	};

	void __handle_convo(aip_sock *sock) {
		int rbytes=aip_recv(sock, dbuf);
		char *smsg=aip_send(sock, (char *)dbuf);
		while(smsg){
			rbytes=aip_recv(sock, dbuf);
			printf("aip_recv : %d\n", rbytes);
			if((rbytes==-1)||(!rbytes)){
				printf("breaking\n");
				break;
			}
			smsg=aip_rcv_msg(rbytes, dbuf);
			smsg=decode_and_reply(sock, smsg, rbytes);
		};
		#ifdef OUTPUT
			printf("closing socket\n");
		#endif
		_socket_free_fd(sock);
		_exit(0);
	};

	void *__atp_cell(void *c_stp) {
		aip_sock *__socket =__arc_socket(c_stp);
		log_socket(__socket);
		d_portal saddr_st=__sock_addr(__aip2sockaddr(__socket));

		ulong socket_fd=socket_fd(__socket);
		ulong socket_len=socket_len(__socket);

		#ifdef DEBUG
			printf("starting ell, <%p>\n", c_stp);
			printf("fd=%lu",socket_fd);
			log_socket(&__socket);
		#endif

		if(__aip_listen(socket_fd)) {
			#ifdef DEBUG
				printf("error : listen\n");
				printf("err number:\n");
				printf("%d\n",errno);
			#endif
			_exit(1);
		};

		__ellrun(socket_fd);

		return c_stp;
	};

	d_portal __sock_addr(struct sockaddr *sa) {
		// get sockaddr, IPv4 or IPv6:
		d_portal __sa; memset(&__sa,0,sizeof(d_portal));

		if (sa->sa_family==AF_INET) {
			__sa.s_protocol=__at_4;
			__sa.s_address=&(((struct sockaddr_in*)sa)->sin_addr);
		}
		else {
			__sa.s_protocol=__at_6;
			__sa.s_address=&(((struct sockaddr_in6*)sa)->sin6_addr);
		};
		char s[INET6_ADDRSTRLEN];
		ulong __s_size=str_rwings(__sa.s_ascii);
		memset(__sa.s_ascii,0,__s_size);
		memset(&s,0,sizeof(s));
		char const *sockname=inet_ntop((int)__sa.s_protocol, __sa.s_address, s, sizeof(s));
		memmove(__sa.s_ascii, sockname, __s_size);
		#ifdef DEBUG
			printf("socket @%s\n",sockname);
		#endif
		return __sa;
	};
	
	char *__pia_http(d_pia *pst) {
		#ifdef OUTPUT
			printf("starting http parser (pia) :: \n");
		#endif
		char __[__API_LEN], *__ptr=memset(&__,0,sizeof(__));
		char *__interpt=pst->interpreter;
		ulong __ilen=str_rwings(__interpt);
		memmove(__ptr, __interpt, __ilen);
		#ifdef OUTPUT
			printf("GET /%s", pst->pointer);
			printf("\nInterpreter:%s", pst->interpreter);
			printf("\nArgs:%s\n", pst->args);
		#endif
		return (char *)strdup(__);
	};

	int __read_ft(char *dbuffer, ulong dbuf_len) {
	// read from till
	    int __direction=0;
	    ulong __flags=0, c__=0, __c=dbuf_len;
	    char const *arg=(char const *)dbuffer;
	    ulong main_offset=0, __alen=str_rwings(arg);
		pia(pst, "temp");
	    char const *ptr_interchange, *__ptrname, *__interpreter, *__args, *__payload;
	    do {
	        c__+=1;
	        if(!__flags) {
	            #ifdef DEBUG
	                printf("-----\n");
	            #endif
	            if(dbuffer[c__]=='@') {
	                __direction+=1;
	                __flags|=ATP_FLAG;
	                #ifdef DEBUG
	                    printf(">%c__", dbuffer[c__]);
	                #endif
	                #ifdef LOG_FLAGS
	                    printf("FLAG START #%lu#\n", __flags);
	                #endif
	            }
	            else if(dbuffer[__c]=='}') {
	                __direction-=1;
	                __flags|=ATP_FLAG_ES;
	                #ifdef DEBUG
	                    printf("__%c<", dbuffer[__c]);
	                #endif
	                #ifdef LOG_FLAGS
	                    printf("FLAG END #%lu#\n", __flags);
	                #endif       
	            }else {
	            #ifdef DEBUG
	                printf("direction unknown ::: \n");
	            #endif
	            };
	           
	        } else { 
	        ulong temp;
	           if((__flags==ATP_FLAG_INTRPT)||(dbuffer[c__]=='@')) {
	            main_offset+=c__;
	                __flags|=ATP_FLAG_START;
	                #ifdef LOG_FLAGS
	                    printf("FLAG START #%lu#\n", __flags);
	                #endif
	                #ifdef LOG_ATT
	                    printf("__@%lu\n", main_offset);
	                #endif
	                temp=sep_offset(arg, "<");
	                // we increment the `arg` to get rid of the @ & then
	                // seperate offset considers the `<` included in str_b4
	                // so we decrement the count
	                temp-=1;
	                __ptrname=stn_b4offset(arg, temp);
	                #ifdef DEBUG
	                    printf("pointer name ::: %s\n", __ptrname);
	                #endif
	                memmove(via_ptr(pst), __ptrname, str_rwings(__ptrname));
	                temp=str_rwings(__ptrname);
	                if(temp>__P_LEN){
	                    #ifdef LOG_ERR
	                        printf("pointer names must be 8 bytes\n");
	                    #endif
	                    #ifdef DEBUG
	                        printf("pointer contents iteration ::\n");
	                        for(int i=0;i<temp; i++){
	                            printf("%d(%c)\n", __ptrname[i],__ptrname[i]);
	                        }
	                    #endif
	                    return 2;
	                };
	            }
	            else if((__flags==ATP_FLAG_IS)&&(dbuffer[c__]=='<')) {
	                __flags|=ATP_FLAG_C;
	                #ifdef LOG_FLAGS
	                    printf("INTERPRETER FLAG #%lu#\n", __flags);
	                #endif
	                // recenter the `arg` to be able to extract the correct offset
	                ptr_interchange=str_a4offset(arg, temp);
	                ptr_interchange+=(temp);
	                temp=sep_offset(ptr_interchange, ">");
	                #ifdef LOG_ATT
	                    printf("__@%lu\n", temp);
	                #endif
	                __interpreter=stn_b4offset(ptr_interchange, temp);
	                #ifdef DEBUG
	                    printf("interpreter :: %s\n", __interpreter);
	                #endif
	                memmove(via_interp(pst), __interpreter, str_rwings(__interpreter));
	                ulong temp=str_rwings(via_ptr(pst)+str_rwings(__interpreter));
	                if(temp>__I_LEN){
	                    #ifdef LOG_ERR
	                        printf("interpreters always have a maximum of 64 bytes for a reference call\n");
	                    #endif
	                    #ifdef DEBUG
	                        printf("__interpreter :: %s : %lu\n", __interpreter,temp);
	                    #endif
	                    return 3;
	                };
	            }
	            else if((__flags==ATP_FLAG_HANDLER)&&(dbuffer[c__]=='(')) {
	                __flags|=ATP_FLAG_IEPS;
	                #ifdef LOG_FLAGS
	                    printf("FLAG ARGS START #%lu#\n", __flags);
	                #endif
	                // seperate the bracket insides by seperating the `{`
	                // and making use of the fact that `}` should be at end of data inp (eodi)
	                ptr_interchange=str_a4offset(arg, temp);
	                temp=sep_offset(ptr_interchange, "(");
	                __args=str_a4offset(ptr_interchange, temp);
	                temp=str_rwings((char const *)__args);
	                // if(__args[temp]!='}'){
	                //     #ifdef LOG_ERR
	                //         printf("err : malformat :: no closing arg sequence `}Z`\n");
	                //     #endif
	                //     return 1;
	                // };
	            }
	            else if((__flags==ATP_FLAG_HANDLER)&&(dbuffer[c__]=='{')) {
	                __flags|=ATP_FLAG_ES;
	                #ifdef LOG_FLAGS
	                    printf("FLAG PAYLOAD START #%lu#\n", __flags);
	                #endif

	                ptr_interchange=str_a4offset(arg, temp);
	                ptr_interchange+=(temp);
	                temp=sep_offset(ptr_interchange, "}");
	                #ifdef DEBUG
	                    printf("payload : %s\n", ptr_interchange);
	                #endif

	                // // get the actual args inside the brackets
	                // ptr_interchange=str_a4offset(ptr_interchange, temp);
	                // temp=sep_offset(ptr_interchange, "{");
	                // __payload=str_b4offset(ptr_interchange, temp);
	                // memmove(__p_args(pst), __payload, __A_LEN);
	                // temp=_p_args_len(pst);
	                // if(temp>__A_LEN){
	                //     #ifdef LOG_ERR
	                //         printf("payloads are restricted to 512bytes max\n");
	                //     #endif
	                //     #ifdef DEBUG
	                //         printf("interchange :: %s\n", ptr_interchange);
	                //         printf("intra arguments :: %s\n", ptr_interchange);
	                //         printf("start args offset :: %lu\n", temp);
	                //         printf("main args :: %s\n", __args);
	                //     #endif
	                //     return 4;
	                // };
	                // #ifdef DEBUG
	                //     printf("pointer name := %s\n", p_pointer(pst));
	                //     printf("interpreter  := %s\n", p_interpreter(pst));
	                //     printf("arguments    := %s\n", p_args(pst));
	                // #endif
	            };
	        };
	        __c--;
	    }while(__c>0);

	    return 0;
	};

	char const *__http_names(http_req __http_r_type) {
		switch(__http_r_type) {
		case __http_rget: return "GET";
		case __http_rpost: return "POST";
		default: return NULL;
		};
	};

	void __free_content(content_st *__) {
		free(__);
	};

	char const *__config_prop(char const *str1, char const *str2) {
		ulong _lstr1=str_rwings(str1),_lstr2=str_rwings(str2);
		ulong __len=_lstr1+_lstr2+3;
		char __[__len];memset(&__, 0, sizeof(__));
		__[__len-1]='\r';
		__[__len]='\n';
		memmove(__, str1, _lstr1);
		memmove((__+_lstr1), str2, _lstr2);
		return strdup(__);
	};

	char const *__check_wss_key(char const *__msg) {
		ulong __len=str_rwings(__msg);
		ulong __offset=sep_offset(__msg, "Sec-WebSocket-Key: ");
		if(!__offset){
			#ifdef LOG_ERR
				printf("no wss key found\n");
			#endif
			return NULL;
		}
		char const *temp=str_a4offset(__msg, __offset+str_rwings(wss_key_h));
		__offset=sep_offset(temp, "\n");
		temp=str_b4offset(temp, __offset);
		#ifdef DEBUG
			printf("WSS KEY : %s\n", temp);
		#endif
		return strdup(temp);
	};

	char const *__get_hash(char const *__key) {
		int x=fork();
		#ifdef DEBUG
			printf("fork res : %d\n", x);
		#endif
		if(!x){
			char **_s=malloc(sizeof(char *)*3);
			char const *__sname= __charm_call(NULL, "hash1.py");
			#ifdef DEBUG
				printf("charm call : %s\n", __sname);
			#endif
			char *__sarg=(char *)__key;
			char *__send=NULL;
			_s[0] = (char *)__sname;
			_s[1] = __sarg;
			_s[2] = __send;
			#ifdef OUTPUT
				printf("getting hash\n");
				printf("0 : %s\n", _s[0]);
				printf("1 : %s\n", _s[1]);
				printf("2 : %s\n", _s[2]);
			#endif
			int __eres=execve(_s[0], _s, environ);
			return "@\0";
			// _exit(0);
		}
		else {
			int __zen=0;
			waitpid(x, &__zen, 0);
			char __[30];memset(&__,0, sizeof(__));
			int fd=__dgetfd("temp.sha1");
			#ifdef OUTPUT
				printf("access to file : %d\n", access("temp.sha1", F_OK));
			#endif
			long b_read=read(fd, __, sizeof(__));
			#ifdef DEBUG
				printf("bread : %ld\n", b_read);
			#endif
			close(fd);
			if(b_read<=2){
				#ifdef LOG_ERR
					printf("read less than 2 bytes\n");
				#endif
				return NULL;
			};
			__[b_read]='\r';
			__[b_read+1]='\n';
			return strdup(__);
		};
	};

	int check_addr(const char *_addr) {
		
		return __check_allowed(_addr)==0;
	};

	int check_command(d_into into) {
		if(__read_hash__(in_argument(into))) {
			__TEXT(Read : );
			// printf("will read the hash\n");
			return 0;   
		}
		else if (__write_hash__(in_argument(into))){
			__TEXT(Write : );
			// printf("will write a message to hash\n");
			return 0;       
		}
		else if(__execute_hash__(in_argument(into))) {
			__TEXT(Execute : );
			// printf("should execute the command \n");
			return 0;
		}
		else if (__send_hash__(in_argument(into))) {
			__TEXT(Send : );
			// printf("will send msg to hash\n");
			return 0;
		}
		else if (__connect_hash__(in_argument(into))) {
			__TEXT(Connect : );
			// printf("will try to connect to address\n");
			return 0;
		}
		else if (__listen_hash__(in_argument(into))) {
			__TEXT(Listen : );
			// printf("will try to listen on the address\n");
			return 0;
		}
		else {
			__TEXT(No Match);
			// printf("none of them matched\n");
			return 1;
		};
	};

	int decode_lbb_addr(char const *__arg) {
		ulong _addr_len=str_rwings(__arg);
		if(check_addr(__arg)==-1){
			#ifdef LOG_ERR
				printf("address is not correctly formatted\n");
			#endif
			return 1;
		};
		ulong _addr_max=LBB_BASE+_addr_len;
		char __address[_addr_max];
		memset(&__address, 0, sizeof(__address));
		memmove(__address, d_lbb, LBB_BASE);
		memmove((__address+LBB_BASE), __arg, _addr_len);
		__address[_addr_max]='\0';
		#ifdef DEBUG
			printf("decoding lbb address :: \n");
		#endif
		if(!__stres(__address)){
			#ifdef LOG_ERR
				printf("address doesn't exist ( %s ) \n", __address);
			#endif
			return 2;
		};
		m_stat cm_st; memset(&cm_st, 0, sizeof(m_stat));
		#ifdef DEBUG
			printf("getting mstat :: \n");
		#endif
		// get_mstat(__address, &cm_st);
		#ifdef DEBUG
			log_mstat(&cm_st);
		#endif
		return 0;
	};

	char *decode_and_reply(aip_sock *sock, char *smsg, int rbytes) {
		printf("decoding msg : %d :: %s\n", rbytes , smsg);
		if(*smsg=='@'){
			printf("should initiate ATP for : ");
			log_socket(sock);
		};

		return "@\0";
	};

	char *decode_pointer(d_into into) {
		#ifdef DEBUG
			printf("decoding pointer :: \n");
		#endif

		char const *arg=in_argument(into);
		ulong __argflen=str_rwings(arg);
		// d_pia(pst, @)
		// d_pia *pst; __pia__(pst);

		ulong ptr_name_offset=sep_offset(arg, "<");
		// we increment the `arg` to get rid of the @ & then
		// seperate offset considers the `<` included in str_b4
		// so we decrement the count
		char *__ptrname=str_b4offset(++arg, ptr_name_offset-1);
		pia(pst, __ptrname);
		ulong __pointer_len=str_rwings(__ptrname);
		if(__pointer_len>__P_LEN){
			#ifdef LOG_ERR
				printf("pointer names must be 8 bytes\n");
			#endif
			#ifdef DEBUG
				printf("pointer contents iteration ::\n");
				for(int i=0;i<__pointer_len; i++){
					printf("%d(%c)\n", __ptrname[i],__ptrname[i]);
				}
			#endif
			return NULL;
		};

		// recenter the `arg` to be able to extract the correct offset
		char const *_ptrcomplete=str_a4offset(--arg, ptr_name_offset);
		ulong intrpt_path_offset=sep_offset(_ptrcomplete, ">");
		char *__interpreter=str_b4offset(_ptrcomplete, intrpt_path_offset);
		memmove(via_ptr(pst), __interpreter, __I_LEN);
		ulong __interpreter_len=str_rwings(via_ptr(pst));
		if(__interpreter_len>__I_LEN){
			#ifdef LOG_ERR
				printf("interpreters always have a maximum of 64 bytes for a reference call\n");
			#endif
			#ifdef DEBUG
				printf("__interpreter :: %s : %lu\n", __interpreter,__interpreter_len);
				printf("offset is @ %lu\n", intrpt_path_offset);
			#endif
			return NULL;
		};

		// seperate the bracket insides by seperating the `{`
		// and making use of the fact that `}` should be at end of data inp (eodi)
		char const *_intrargs=str_a4offset(_ptrcomplete, __interpreter_len);
		ulong args_path_offset=sep_offset(_intrargs, "{");
		char const *__args=str_a4offset(_intrargs, args_path_offset);
		ulong arg_length=str_rwings((char const *)__args);
		ulong __arg_offset=arg_length-1;
		if(__args[__arg_offset]!='}'){
			#ifdef LOG_ERR
				printf("err : malformat :: no closing arg sequence `}Z`\n");
			#endif
			return NULL;
		};

		// get the actual args inside the brackets
		char *args=str_b4offset(__args, arg_length);
		memmove(via_args(pst), args, __A_LEN);
		arg_length=str_cdelims(args, ",");
		if(arg_length>__A_LEN){
			#ifdef DEBUG
				printf("payloads are restricted to 512bytes max\n");
			#endif
			#ifdef DEBUG
				printf("ptr complete :: %s\n", _ptrcomplete);
				printf("intra arguments :: %s\n", _intrargs);
				printf("start args offset :: %lu\n", args_path_offset);
				printf("main args :: %s\n", __args);
			#endif
			return NULL;
		};

		#ifdef DEBUG
			printf("pointer name := %s\n", (char *)via_ptr(pst));
			printf("interpreter  := %s\n", (char *)via_interp(pst));
			printf("arguments    := %s\n", (char *)via_args(pst));
		#endif

		return __pia_http(&pst);
	};

	char *decode_point(d_into into) {
		#ifdef DEBUG
			printf("decoding point :: \n");
		#endif
		ulong pnt_offset=sep_offset(in_argument(into), charms_d);
		char const *point_name=str_a4offset(in_argument(into), pnt_offset);
		return strdup(point_name);
	};

	char const *atp_name(int __type) {
		char __name[__I_LEN];
		memset(__name, 0, sizeof(__name));
		sprintf(__name, __atp_names(__type), __type);
		return strdup((char *)__name);
	};

	void log_proto(int retval, char const *bufin) {
		if(!retval) {
		}else {
			switch(retval) {
			case 0: printf("::: @-call is not correctly formatted"); break;
			case aip_set: printf("::: Storage Number (%s)", bufin); break;
			case aip_get: printf("::: Subprotocol -> %s", bufin); break;
			case aip_retain: printf("::: @<%s>", bufin); break;
			case aip_next: printf("::: &->%s\n", bufin); break;
			default: printf("::: exit(%d)", retval); break;
			}
		}
	}

	int get_atp_type(char const *bufin) {
		/**
		 * AT-protocol entries always start with '@'
		 */
		if(*bufin++!=__at__) {
			return 0;
		};
		/**
		 * payloads always start with
		 * numbers
		 * 
		 * which is basically the address
		 */
		if((*bufin>=0x30)&&(*bufin<=0x39)){
			return aip_get;
		}
		/**
		 * protocol requests always start with
		 * CAPITAL ASCII
		 *
		 * examples including the http
		 * GET & POST & LBB & ATP & ATM ...
		 */
		else if((*bufin>=0x41)&&(*bufin<=0x5a)){
			return aip_set;
		}
		/**
		 * interpreters are always called using 
		 * small leter ascii
		 * to complement the entire suite of the call, 
		 * so an interpreter doesn't
		 * have to be a specific call, could be a * 
		 * such as a prg, or a prg entry point.
		 */
		else if((*bufin>=0x61)&&(*bufin<=0x7a)) {
			return aip_retain;
		}
		/**
		* will exit with grace if unknown
		*/
		else {
			return aip_next;
		};
	};

	atp_t stype_to_atype(sAF_t __stype) {
		switch(__stype) {
			case __sAF_INET: return __at_4;
			case __sAF_INET6: return __at_6;
			default: return __at_4;
		}
	};

	void free_arc() {
		void *d2ptr, *dptr=__arc.__points;
		for(ulong i=0;i<points_c;i++){
			d2ptr=(d_point *)dptr;
			free((d2ptr+i));
		};
	};

	void free_sok(){ 

		_socket_free_fd(&__sok);
	};

	void free_args() {
		free_arc();
		free_sok();
	};

	int atp_set(void *args) {
		printf("%s : \n", (char const *)args);

		return 1;
	};
	
	int atp_get(void *args) {
		printf("GET : %s\n", (char const *)args);

		return 2;
	};
	
	int atp_rdo(void *args) {
		printf("do {%s} r;", (char const *)args);

		return 3;
	};
	
	int atp_next(void *args) {
		printf("NXT : %s\n", (char const *)args);

		return 4;
	};

#endif


#ifndef __arc__
	#define __arc__ {\
		static const *__arc_p = \
		memset(__arc, __CHAR_NULL, sizeof(arc_st));\
	};


	void __arcpid(){

		__arc.__pid=(ulong)getpid();
	};

	int __check_allowed(char const *__){ 
		int __nallowed[]={'\\', '/', '.'};
		while(*__++){
			for(int i=0;i<arr_size(__nallowed); i++){
				int __cmp=*(__);
				if (__cmp==__nallowed[i]){
					return 0;
				};
			};
		};
		return 1;
	};

	void *__arc_pointer(void const *aipd){
		atp_pointer *atp_p=malloc(sizeof(atp_pointer));
		memset(atp_p, 0, sizeof(atp_pointer));
		__arcpid();
		#ifdef PROCESS
			printf("ATP<arcpid> = %lu\n", __arc.__pid);
		#endif
		atp_p->ptr = atp_p;
		sprintf(atp_p->addr, "%lu", __arc.__pid);
		atp_p->chkref = hash_follow(0, atp_p->addr);
		#ifdef DEBUG
			printf("%p<%s>(%s)\n", atp_p->ptr, atp_p->addr, atp_p->chkref);
		#endif
		__arc.__next = atp_p -> ptr;

		return __arc.__next;
	};

	void *__arc_address(void const *cert){
		__arc.__fork=fork();
		return __arc.__next;
	};

	void *__arc_socket(char const *pname) {
		__arc.__sok=__address();
		printf("d-cloud : atp {les}\n");

		int sockfd, temp_fd, __yes=1, __rv;
		struct addrinfo hints,*__servinfo, *temp;
		memset(&hints, 0,sizeof(struct addrinfo));
		hints.ai_flags=AI_PASSIVE;
		hints.ai_socktype=SOCK_STREAM;
		hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
		struct sockaddr_storage __caddr;

		socklen_t __sin_size;
		char __saddr[INET6_ADDRSTRLEN];

		if ((__rv=getaddrinfo(NULL,ATP_PORT,&hints,&__servinfo))!=0){
			#ifdef DEBUG
				fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(__rv));
			#endif
			return NULL;
		};
		for(temp=__servinfo;temp!=NULL;temp=temp->ai_next){
			if((sockfd=socket(temp->ai_family,temp->ai_socktype,temp->ai_protocol))==-1){
				#ifdef DEBUG
					__TEXT(Err : Server :: Socket);
					// perror("server :: socket\n");
				#endif
				continue;
			};
			if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&__yes,sizeof(int))==-1){
				#ifdef DEBUG
					__TEXT(Err : Server :: Setsockopt);
					// perror("setsockopt\n");
				#endif
				exit(1);
			};
			if(bind(sockfd,temp->ai_addr,temp->ai_addrlen)==-1){
				close(sockfd);
				#ifdef DEBUG
					__TEXT(Err : Server :: bind);
					// perror("server :: bind");
				#endif
				continue;
			};
			break;
		};
		freeaddrinfo(__servinfo);
		if(temp==NULL){
			printf("les : failed to bind, another instance is probably running.\n");
			exit(1);
		}else {
			if(!__aip_listen(sockfd)) {
				__ellrun(sockfd);
			}
		}
		return __arc.__next;
	};	

	void *__arc_point(char const *to, char const *type, void *data) {
		// ATP(request, @self);
		printf("d-cloud : atp {mor} :: %p\n", to);
		char const *request_base=(char const *)to;
		#ifdef PROCESS
			printf("address : %s\n", request_base);
		#endif
		int sockfd, temp_fd, __yes=1, __rv;
		struct addrinfo hints,*__servinfo, *temp;
		memset(&hints, 0,sizeof(struct addrinfo));
		hints.ai_flags=AI_PASSIVE;
		hints.ai_socktype=SOCK_STREAM;
		hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
		struct sockaddr_storage __caddr;

		socklen_t __sin_size;
		char buf[INET6_ADDRSTRLEN];

		if ((__rv=getaddrinfo(request_base,ATP_PORT,&hints,&__servinfo))!=0){
			#ifdef DEBUG
				fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(__rv));
			#endif
			return NULL;
		};
		for(temp=__servinfo;temp!=NULL;temp=temp->ai_next){
			if((sockfd=socket(temp->ai_family,temp->ai_socktype,temp->ai_protocol))==-1){
				#ifdef DEBUG
					__TEXT(Err : Mor :: Socket);
				#endif
				continue;
			};
			if(connect(sockfd,temp->ai_addr,temp->ai_addrlen)==-1){
				close(sockfd);
				#ifdef DEBUG
					__TEXT(Err : Mor :: connect);
				#endif
				continue;
			};
			break;
		};
		if(temp==NULL) {
			#ifdef LOG_ERR
				__TEXT(Err : Mor :: Cannot establish connection);
			#endif
			return NULL;
		}		
		memset(&buf, 0, sizeof(buf));
		inet_ntop(temp->ai_family, __sok_addr((struct sockaddr *)temp->ai_addr), buf, sizeof buf);
		freeaddrinfo(__servinfo);
		#if OUTPUT
			printf("client: connecting to %s\n", buf);
		#endif
		__ellcall(sockfd, (char *)&buf, sizeof(buf)-1);
		close(sockfd);
		return __arc.__next;
	};

	void *__arc_node(char const *idkey, void **args) {

		return __arc.__next;
	};

#endif


#ifndef __ell__
	#define __ell__ {\
		static const *__arc_b = \
		__dbuf__();\
	};

	void __ellget(ulong __sockfd, char *reusable, ulong reu_size) {
		memset(reusable, 0, reu_size);
		int __recvd_num=recv(__sockfd, reusable, reu_size, 0);
		if(__recvd_num==-1) {
			#ifdef OUTPUT
				printf("ATP : ell :: err<recv>(%d)\n", errno);
			#endif
			_exit(1);
		};
		reusable[__recvd_num] = '\0';
	};

	void __ellsend(ulong __sockfd, char *reusable, ulong r_size) {
		#ifdef OUTPUT
			printf("reading input\n");
		#endif
		int __tempres=0;
		while(__tempres!=-1) {
			#ifdef OUTPUT
				printf("ATP : ell :: sending ::: %s\n", reusable);
			#endif
			__tempres=send(__sockfd, reusable, r_size, 0);
			__ellget(__sockfd, reusable, ATP_BUFFER_SIZE);
			break;
		};
		#if OUTPUT
			printf("ATP : ell :: recieving ::: %s\n", reusable);
		#endif
		close(__sockfd);
	};

	void __ellrun(ulong __fd) {
		char const *__wsskey, *__wsshash;
		aip_sock temp_sok; memset(&temp_sok,0,sizeof(aip_sock));
		#ifdef OUTPUT
			printf("running ell <%lu> \n", __fd);
		#endif

		while(1) {
			socklen_t *__len=((socklen_t *)&(temp_sok.aip_socklen));
			ulong *temp_sockefd=((ulong *)&(temp_sok.aip_sockfd));
			struct sockaddr *temp_sockeaddr=((struct sockaddr *)&(temp_sok.aip_sockst));
			*__len=sizeof(temp_sockeaddr);
			int __tempfd=accept(__fd, temp_sockeaddr, __len);
			#ifdef DEBUG
				printf("accepted connection :: %d\n", __tempfd);
			#endif
			if(__tempfd==-1) {
				#ifdef LOG_ERR
					__err_socket("ellrun : accept :: ", errno);
				#endif
				break;
			};
			temp_sok.aip_sockfd=tonum(__tempfd);
			#ifdef DEBUG
				log_socket(temp_sok);
			#endif
			if(!fork()){
				close(__fd);
				char *msg_recvd=__aip_recieve(&temp_sok);
				#ifdef DEBUG
					printf("recieved => \n%s\n", msg_recvd);
				#endif
				__wsskey=__check_wss_key(msg_recvd);
				if(__wsskey!=NULL) {
					__wsskey=__combine_str(__wsskey, __cwss);
					__wsshash=__get_hash(__wsskey);
				};
				void *temp=__aip_activate(&temp_sok, __upgrade, __wsshash);
				__handle_convo(&temp_sok);
			}
			_socket_free_fd(&temp_sok);
		};
	};

	void __ellcall(ulong __sockfd, char *reusable, ulong r_size) {
		#ifdef OUTPUT
			printf("reading input\n");
		#endif
		int __tempres=0;
		memset(reusable, 0, r_size);
		while(__tempres!=-1) {
			__tempres=read(0, reusable, r_size);
			#ifdef OUTPUT 
				printf("ATP : ell :: read&send ::: %s\n", reusable);
			#endif
			__tempres=send(__sockfd, reusable, r_size, 0);
		};
		close(__sockfd);
	};

#endif




