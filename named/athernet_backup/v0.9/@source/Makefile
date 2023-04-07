
all:
	mkdir bin
	gcc entries/comms.c -o bin/@coms
	gcc entries/fmt.c -o bin/@fmt
	gcc k/key.c -o bin/@key
	gcc hbar/auth.c -o bin/@auth
	


ca_point:
	gcc point/main.c -o bin/@point
	./bin/@point atherpoint



complete:
	@./tests/fmt_test
	@./tests/auth_test 





clean:
	rm -rf bin
