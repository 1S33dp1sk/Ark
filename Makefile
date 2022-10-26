
all:
	mkdir bin
	gcc coms.c -o bin/@coms
	gcc levels.c -o bin/@levels
	gcc auth.c -o bin/@auth

clean:
	rm -rf bin
