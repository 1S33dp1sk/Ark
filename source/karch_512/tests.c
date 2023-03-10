

#ifdef __HTTP_TESTS
int main(){
	char const *request=form_http_request(__http_get, "/index.html");
	printf("request : %s\n", request);

	char const *response=form_http_response(200, "OK");
	printf("response : %s\n", response);
	return 0;
};
#endif


