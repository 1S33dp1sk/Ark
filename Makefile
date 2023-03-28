<<<<<<< HEAD

ca:
	if [ ! -d shared ]; then mkdir shared; fi
	cc -c -fpic @source/point/point.c -o shared/point.o
	cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	cc -c -fpic @source/nai/nai.c -o shared/nai.o
	cc -shared shared/*.o -o shared/libpoint.so
	cc @source/ather.c -o ather ./shared/libpoint.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
	if [ -f ather ]; then rm ather; fi

=======
ca:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ -f kurl ]; then rm kurl; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	@cc @source/kurl.c -o kurl ./shared/libather.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
	if [ -f .lbb ]; then rm .lbb; fi
	if [ -f athernet ]; then rm athernet; fi
	if [ -f kurl ]; then rm kurl; fi
	rm atherpoint
>>>>>>> in_vik/main

old:
	cc @source/lbb/main.c -o @lbb
	cc @source/hbar/main.c -o @hbar
	cc @source/point/main.c -o @point
	cc @source/entry/main.c -o @entry

<<<<<<< HEAD


=======
>>>>>>> in_vik/main
rall:
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
	rm .lbb
	rm atherpoint

clean:
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
