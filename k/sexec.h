
int sexec( char **argv ){
	// if ( argc != 3 ) { printf( "usage :: @sexec /interperter/path /to/entry.ath" ); return 1; }
	char **__e = *(&argv)+1;
	char *__env[] = {""};
	if ( __sys_entry( argv[0] ) == 0 ) {
		printf("cannot access file\n\n" );
		return 2;
	}
	int _execval = execve( argv[0] , __env , __e );
	printf("executed\n");
}



