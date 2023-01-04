
all:
	gcc @source/main.c -o @
	./@
	gcc @source/compiler.c -o compiler
	./compiler

clean:
	@rm @
	@rm compiler