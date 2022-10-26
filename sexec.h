

int sexec() {

	char __buf;

	while( read( 0 , &__buf , 1 ) > 0 ) {
		write( 0 , &__buf , 1 );
	}
	write( 0 , "\n" , 1 );
	return 0;
}


