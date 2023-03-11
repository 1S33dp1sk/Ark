

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
