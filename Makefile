misc:
	cc @source/misc.c -o shared/programs/misc ./shared/libather.so
	./shared/programs/misc
	
nothing:

# `run()`ing compile will create a new version of whatever is getting \
compiled because.
running:
	$_ run_check

run_anet:
	./shared/programs/athernet

run_kurl:
	./shared/programs/kurl

executables:
	@cc @source/athernet.c -o shared/programs/athernet ./shared/libather.so
	@cc @source/kurl/kurl.c -o shared/programs/kurl ./shared/libather.so

run_check:
	#checking
	@if [ ! -d shared ]; then $_ run_compile; fi
	@if [ ! -f .lbb ]; then $_ run_kurl; fi

run_clean:
	@if [ -d shared ]; then rm -rf shared; fi
	@if [ -f .lbb ]; then rm -rf .lbb; fi
	@if [ -f athernet ]; then rm -rf athernet; fi
	@if [ -f kurl ]; then rm -rf kurl; fi

run_compile:
	@mkdir -p shared/{compiled,programs} && printf "compling..\n";
	# ather 
	# a
	@printf "att point [:=] address\n"
	@cc -c -fpic @source/point/point.c -o shared/compiled/point.o
	# t
	@printf "tkurl (  )\n"
	@cc -c -fpic @source/kurl/kurl.c -o shared/compiled/kurl.o
	# h
	@printf "hbar ( hash whatever )\n"
	@cc -c -fpic @source/hbar/hbar.c -o shared/compiled/hbar.o
	# e
	@printf "eai ( electronic ather interface )\n"
	@cc -c -fpic @source/nai/nai.c -o shared/compiled/nai.o
	# r
	@printf "read( little black book )\n"
	@cc -c -fpic @source/lbb/lbb.c -o shared/compiled/lbb.o
	@cc -shared shared/compiled/*.o -o shared/libather.so
	$_ executables



run_asyemtric:
	$_ run_check










run_symetric:










kurl_test:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	@if [ -f .lbb ]; then rm .lbb; fi
	@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	@cc @source/kurl/kurl.c -o kurl ./shared/libather.so
	./kurl

ca:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ -f kurl ]; then rm kurl; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	#@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	#@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	#@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	#@cc @source/kurl/kurl.c -o kurl ./shared/libather.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
	if [ -f .lbb ]; then rm .lbb; fi
	if [ -f athernet ]; then rm athernet; fi
	if [ -f kurl ]; then rm kurl; fi
	rm atherpoint

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
