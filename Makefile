
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
ca:
	if [ ! -d shared ]; then mkdir shared; fi
	cc -c -fpic @source/point/point.c -o shared/point.o
	cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	cc -c -fpic @source/nai/nai.c -o shared/nai.o
	cc -shared shared/*.o -o shared/libpoint.so
=======
ca:
	if [ ! -d shared ]; then mkdir shared; fi
	cc -c -fpic @source/point/point.c -o shared/point.o
<<<<<<< HEAD
	cc -shared shared/point.o -o shared/libpoint.so
>>>>>>> 757e790 (shared library for point)
=======
	cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	cc -c -fpic @source/nai/nai.c -o shared/nai.o
	cc -shared shared/*.o -o shared/libpoint.so
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
	cc @source/ather.c -o ather ./shared/libpoint.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
<<<<<<< HEAD
<<<<<<< HEAD
	if [ -f ather ]; then rm ather; fi


old:
	cc @source/lbb/main.c -o @lbb
	cc @source/hbar/main.c -o @hbar
	cc @source/point/main.c -o @point
	cc @source/entry/main.c -o @entry



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
=======
all:
=======

=======
	if [ -f ather ]; then rm ather; fi
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)


old:
>>>>>>> 757e790 (shared library for point)
	cc @source/lbb/main.c -o @lbb
	cc @source/hbar/main.c -o @hbar
	cc @source/point/main.c -o @point
	cc @source/entry/main.c -o @entry



rall:
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
	rm .lbb
	rm atherpoint

clean:
<<<<<<< HEAD
	rm -rf bin
>>>>>>> 13f79da (.pipes are used to communicate between sockets of different types based on @levels)
=======
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
>>>>>>> 4947f52 (v0.01-NS)
=======

=======
>>>>>>> b78d224 (@)
all:
	gcc @source/main.c -o @
	./@
	gcc @source/compiler.c -o compiler
	./compiler

<<<<<<< HEAD
	
purge:
	rm -rf @
>>>>>>> eb99d6a (0xather)
=======
clean:
	@rm @
	@rm compiler
>>>>>>> b78d224 (@)
