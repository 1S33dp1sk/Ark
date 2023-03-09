
#ifdef __KVS_TRAVERSE_TESTS
int main(int argc, char **argv) {
	keyvals *kvs=__kvs__(": ", "\r\n");
	kvs_add_pair("_keynumber1\0","value_number16\0");
	kvs_add_pair("_keynumber2\0","value_number12\0");
	kvs_add_pair("_keynumber3\0","value_number11\0");
	kvs_add_pair("_keynumber5\0","value_number31\0");
	kvs_add_pair("_keynumber7\0","value_number11\0");
	kvs_add_pair("_keynumber1\0","value_number14\0");
	kvs_add_pair("_keynumber6\0","value_number19\0");
	char const *all_lines=kvs_traverse(kvs);
	printf("%s\n", all_lines);
	free_kvs(kvs);
};
#endif




#ifdef __KVS_TESTS
int main(int argc, char **argv) {
	keyvals *kvs=__kvs__(": ", "\r\n");
	kvs_add_pair("_keynumber1\0","value_number16\0");
	kvs_add_pair("_keynumber2\0","value_number12\0");
	kvs_add_pair("_keynumber3\0","value_number11\0");
	kvs_add_pair("_keynumber5\0","value_number31\0");
	kvs_add_pair("_keynumber7\0","value_number11\0");
	kvs_add_pair("_keynumber1\0","value_number14\0");
	kvs_add_pair("_keynumber6\0","value_number19\0");
	log_kvs(kvs);
	free_kvs(kvs);
};
#endif


#ifdef __HTTP_TESTS
int main(){
	char const *request=form_http_request(__http_get, "/index.html");
	printf("request : %s\n", request);

	char const *response=form_http_response(200, "OK");
	printf("response : %s\n", response);
	return 0;
};
#endif


