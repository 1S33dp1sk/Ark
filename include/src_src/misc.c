


unsigned check_all() {

	int __check_res = lbb_exsists();

	printf("lbb exsists :: %d\n",__check_res);


	return __check_res;
}

int main( int argc , char **argv ) {

	int pre_pendrun = 0;

	if ( argc > 1 ) {
		if (strstr(argv[2],"check_all")!=NULL) {
			unsigned acc = check_all();
			printf("all checks checked ? %d\n",acc);
		}
	}

}