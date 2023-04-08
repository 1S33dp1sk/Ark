/// ATP \\\
@-protocol

#ifndef __ATP__H
	#define __AT_DEFINED '@'
	#if __AT_DEFINED!=64
		#define AT_DEFINED 64
	#else
		#define AT_DEFINED __AT_DEFINED
	#endif
	#define ATP_FLAG_START 0x1
	#define ATP_FLAG_FS 0x2
	#define ATP_FLAG_IEPS 0x3
	#define ATP_FLAG_ES 0x4
	#define ATP_FLAG_IS 0x5
	#define ATP_FLAG 0x10
	#define ATP_FLAG_INTRPT 0x1f
	#define ATP_FLAG_INDEXER 0xe4
	#define ATP_FLAG_C 0x100
	#define ATP_FLAG_HANDLER 0x105
	#define ATP_FLAG_PAYLD 0x111
	#define __ATP_A4_ALIAS "localhost"
	#define __ATP_A6_ALIAS "::1"
	#define __PASS_ATP_D 0x1000
	#define __PASS_MAX_D 0x200
	#define __PASS_MID_D 0x40
	#define __PASS_MIN_D 0x8
	#define __PASS_MIN_C 3
	#define __D_CHARMS 4
	#define __LBB_BASE_LEN (ulong)str_rwings(d_atlbb)
	#define PLD_MASKED(x)   x&10000000
	#define PLD_SIZE(x)     x&1111111
	#define FRAME_FIN(x)    x&1
	#define FRAME_RSV1(x)   x&01000000
	#define FRAME_RSV2(x)   x&00100000
	#define FRAME_RSV3(x)   x&00010000
	#define FRAME_OPCODE(x) x&00001111
	#define HTTP_ACCEPT http_response(200, "OK")
	#define HTTP_SWITCH http_response(101, "Switching Protocols")
	#define HTTP_FORBID http_response(404, "Forbidden")
	#define ATP_SPEC_SIZE (__PASS_MIN_D<<0x3)
	#define ATP_BUFFER_SIZE (ATP_SPEC_SIZE<<0x3)
	#define ATP_BACKLOG 10 // instances of the same id
	#define ATP_PORT "9999" // The common ATP port
	#define __ATP_ENV "="
	#define __ATP_KEY ":"
	#define __ATP_AT "@"
	#define __ATP_STR "*"
	#define __ATP_AETH "Aether(cid)"
	#define __PASS_D(x, y) _Generic((x),\
		d_pointer: __generic_hash__(__PASS_MIN_D, x, y),\
		d_portal: __generic_hash__(__PASS_MID_D, x, y),\
		d_point: __generic_hash__(__PASS_MAX_D, x, y),\
		d_pyld: __generic_hash__(__PASS_ATP_D, x, y),\
	)
	#define __PASS_C(x, y) switch((str_rwings(x)>>__PASS_MIN_C), __PASS_D())
	
	#define __generic_hash__(l,x,y) (__exact_match(hashof(1, #x, __PASS_MID_D), hashof(1, #y, __PASS_MID_D)))
	#define __read_hash__(x) (__exact_match(x, (char const *)hashof(0, "read\0", __PASS_MIN_D)))
	#define __write_hash__(x) (__exact_match(x, (char const *)hashof(0, "write\0", __PASS_MIN_D)))
	#define __execute_hash__(x) (__exact_match(x, (char const *)hashof(0, "execute\0", __PASS_MIN_D)))
	#define __connect_hash__(x) (__exact_match(x, (char const *)hashof(0, "connect\0", __PASS_MIN_D)))
	#define __send_hash__(x) (__exact_match(x, (char const *)hashof(0, "send\0", __PASS_MIN_D)))
	#define __listen_hash__(x) (__exact_match(x, (char const *)hashof(0, "listen\0", __PASS_MIN_D)))


	#define srwings(x) str_rwings(x)

	#define __p_args(p) ((void *)(&(p.args)))
	#define p_args(p) ((char const *)(p.args))
	#define _p_args_len(p) ((ulong)(str_rwings(p_args(p))))
	#define pst_args(p) ((char const *)(p->args))
	#define pst_args_len(p) ((ulong)str_rwings(pst_args(p)))

	#define __p_pointer(p) ((void *)(&(p.pointer)))
	#define p_pointer(p) ((char const *)((p.pointer)))
	#define _p_pointer_len(p) ((ulong)(str_rwings(p_pointer(p))))

	#define __p_interpreter(p) ((void *)(&(p.interpreter)))
	#define p_interpreter(p) ((char const *)(p.interpreter))
	#define _p_interpreter_len(p) ((ulong)(str_rwings(p_interpreter(p))))

	#define socket_fd(x) (ulong)(x.aip_sockfd)
	#define sock_fd(x) (ulong)(x->aip_sockfd)
	#define socket_len(x) (ulong)(x.aip_socklen)
	#define sock_len(x) (ulong)(x->aip_socklen)
	#define socket_staddr(x) (struct sockaddr *) sock_aip_to_sa(&x)

	#define addr_args(x) ((x->ptr),(x->addr), #x)
    #define len_strze(x) (((ulong)x)*(sizeof(char)))

	#define R_INDEXER(x,y) {\
		if(x==y) { refer_index(x,#x,#x); }\
		else { refer_index(x,y,#x); }\
	}
	#define hash_follow(l,...) ((char const *)hashof(l, #__VA_ARGS__, str_rwings(#__VA_ARGS__)))
	#define __protocol__(x) void *res;\
		switch(__switcher(x)){\
			case __lbb_none__:\
				return __no_entry__(x);\
			case __lbb_charms__: \
				return __field__(x);\
			case __lbb_yeild__:\
				return __w3__(x);\
			case __lbb_info__:\
				return __info__(x);\
			case __lbb_variable__:\
				return __pointer__(x);\
			case atp_base:\
				return __point__(x);\
			case atp_return:\
				return ixr_run(x);\
			case atp_retain:\
				return ixr_save(x);\
			case atp_retreive:\
				return ixr_collect(x);\
			default: \
				return 0;\
		}\

	#ifndef __ATP__C
		static ulong step_c=0;
		static ulong points_c=0;
		static ulong p_pid;
		static ulong c_pid;
		#define __ATP__C 1
	#endif

	char const *__http_names(http_req_t __http_r_type);
	char const *atp_name(int __type);
	int __check_allowed(char const *__);
	int check_addr(char const *__addr);
	int check_command(d_into *into);
	char const *uname(const char *__filename);
	int __read_ft(char *__buffer, ulong __len);

	char const *form_http_request(http_req_t req_type, char const *__path);
	char const *form_http_response(ulong res_type, char const *req_result);
	char const *http_response(ulong __http_status, char const *http_result);
	char const *__pia_http(d_pia *pia_st);
	char const *decode_pointer(d_into *into);
	char *decode_point(d_into *into);
	content_st *crt_http_content(char const *__, content_pm __type);
	void __free_content(content_st *__);
	content_pm proto_from_status(ulong __http_status);
	char const *__config_prop(char const *__str_1, char const *__str_2);
	char const *http_config(char const *cfg_key, char const *cfg_val);

	void *__arc__(aip_arc *__aip_arc);
	void __arcfork();
	void __arcsok();
	ulong __aipfd();
	ulong __aiplen();
	void __arcpid();
	aip_sock __arcsocket();
	void *__atp_pointer();
	void *__atp_address();
	void *__atp_field();
	void __hints(struct addrinfo *info);
	d_portal __sock_addr(struct sockaddr *sa);
	struct sockaddr *sock_aip_to_sa(aip_sock *sock);
	int __aip_listen(ulong aipsfd);
	void *__aip_recieve(aip_sock *sock);
	void *__aip_activate(aip_sock *sock, char *msg, char const *msg_hash);
	void _socket_free_fd(aip_sock *sock);
	int aip_recv(aip_sock *sock, uchar *buffer);
	void *aip_send(aip_sock *sock, void *__to_send);
	void __aip_send(aip_sock *sock, char *msg);
	char *aip_rcv_msg(int __rlen, void *__rmsg);
	char *decode_and_reply(aip_sock *sock, char *msg, int bytes);
	void __aip_start__(aip_sock *sock);

	char const *__check_wss_key(char const *__msg);
	char const *__get_hash(char const *__key);
<<<<<<< HEAD:k512/atp/atp.h

	void __ellrun(ulong __fd);
	void *__arcell(void *c_arc);
	void *__arcstart(void *c_arc);
	void *__sok_addr(struct sockaddr *sa);
	void __ellcall(ulong __sockfd, char *reuse, ulong rsize);

	int mor(c_req *request);
	void *atp_step(arc_sizes arc_size);
	int *__point_run();
	lbb_entry __decode_arg(char const *__);
	int __proto_at(char const *__);
	int get_atp_type(char const *__call);
	int decode_lbb_addr(char const *__addr);


	void *__aip_sock__(aip_sock *sock);

	atp_t stype_to_atype(sAF_t __stype);
	void _socket_address_free(d_portal *__aip_portal);
	char *__aip_sock_raw();
	struct sockaddr *__aip_sock_addr_sa();
	void sock_errs();
	void __ellget(ulong __sockfd, char *reuse, ulong rsize);
	void __ellsend(ulong __sockfd, char *reuse, ulong rsize);

	void free_arc();
	void free_sok();
	void free_args();

=======

	void __ellrun(ulong __fd);
	void *__arcell(void *c_arc);
	void *__arcstart(void *c_arc);
	void *__sok_addr(struct sockaddr *sa);
	void __ellcall(ulong __sockfd, char *reuse, ulong rsize);

	int mor(c_req *request);
	void *atp_step(arc_sizes arc_size);
	int *__point_run();
	lbb_entry __decode_arg(char const *__);
	int __proto_at(char const *__);
	int get_atp_type(char const *__call);
	int decode_lbb_addr(char const *__addr);


	void *__aip_sock__(aip_sock *sock);

	atp_t stype_to_atype(sAF_t __stype);
	void _socket_address_free(d_portal *__aip_portal);
	char *__aip_sock_raw();
	struct sockaddr *__aip_sock_addr_sa();
	void sock_errs();
	void __ellget(ulong __sockfd, char *reuse, ulong rsize);
	void __ellsend(ulong __sockfd, char *reuse, ulong rsize);

	void free_arc();
	void free_sok();
	void free_args();

>>>>>>> 1250eda (renaming&restructure):k512/atp/h
	int les(void *__args);

	aip_st *h2act(ixr_h *h_request);
	ixr_h *act2h(aip_st *action);

	#define __ATP__H 1
#endif

