
all:
	mkdir bin
	gcc coms.c -o bin/@coms
	gcc levels.c -o bin/@levels
clean:
	rm -rf bin
