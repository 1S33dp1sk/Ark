
#define __ATP_TESTS 1


#ifdef __HTTP_TESTS
	int main(){
		char const *request=form_http_request(__http_get, "/index.html");
		printf("request : %s\n", request);

		char const *response=form_http_response(200, "OK");
		printf("response : %s\n", response);
		return 0;
	};
#endif

#ifdef __DPRG_TESTS
	char *tmp="/Users/mrkj/Custom/web-socket-app/public/index.html";

	#define addr_size(x) ((ulong)sizeof((x->address)))
	#define paddr(x) &(x.address)
	// first real lbb test
	//
	// lbb command @/Users/mrkj/Custom/web-socket-app/public/index.html<(null)>
	// lbb filepath :/Users/mrkj/Custom/web-socket-app/public/index.html+0
	// lbb function ::/Users/mrkj/Custom/web-socket-app/public/index.html(lbb call)=unknown args
	// lbb field </Users/mrkj/Custom/web-socket-app/public/index.html> ::: 0x60000055c030 
	// lbb address @0x10038393f
	int main(int argc, char const *argv[]) {
		payld_st pyld;
		void *ptr=malloc(8);

	__lbb_command(tmp, NULL);

	__lbb_filepath(tmp, __pub);

	__lbb_function(tmp, paddr(pyld), &pyld);

	__lbb_field(tmp, ptr);

	__lbb_address(tmp);
	};
#endif

#ifdef __ATP_TESTS

	struct __test_arg_t {
		char const *arg;
		const char **extras;
	} test_arg[] = {
		{.arg="@charms/fieldname", .extras=(const char **)("get_fld")},
		{.arg="@lbb1address", .extras=((const char **)(&"read"))},
		{.arg="@GET", .extras=(const char **)(NULL)},
		{.arg="@9398f19a9b2", .extras=(const char **)("type")},
		{.arg="@special_var", .extras=(const char **)("special_val")},
		{.arg="random_var", .extras=(const char **)(&"get")},
		{.arg="RandomVar", .extras=(const char **)("set""val")},
		{.arg="12eRandom", .extras=(const char **)(NULL)},
	};

	int __atp_main(int argc, char const *argv[]) {
		into_st into;
		into_st *__p=__into__(&into);
		into_caller(into, argv[0]);
		into_args(into, &argv[1]);
		into_type(into, get_atp_type(argv[1]));
		__protocol__(into.req_at);
	}

	int __test_arg(char const *arg, char const **args) {
		args[1] = arg;
		args[2]=NULL;
		printf("\n\ntest :: \n");
		int res=__atp_main(2, args);
		printf("d-atp <%s, %s>(%d)\n\n", args[0], args[1], res);
		return res;
	};

	int __test__(struct __test_arg_t __, char const *args[]) {
		args[1] = __.arg;
		args[2]=__.extras;
		printf("\ntest :: %s\n", args[1]);
		int res=__atp_main(2, args);
		printf("<%s, %s>(%d)\n", args[0], args[1], res);
		return res;
	};

	dPRG(
		printf("TESTING ATP ::\n\t");
			ARR_SEP(test_arg, ',');
		printf("\n");
		for(int i=0; i<arr_size(test_arg); i++){
			__test__(test_arg[i], argv);
		};
	)

	
#endif