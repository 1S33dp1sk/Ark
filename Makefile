
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
	mkdir bin
	gcc coms.c -o bin/@coms
	gcc levels.c -o bin/@levels
	gcc auth.c -o bin/@auth

clean:
	rm -rf bin
>>>>>>> 13f79da (.pipes are used to communicate between sockets of different types based on @levels)
