	#replace with encoding next ;
#ather processor := _u_charm 
#/** 			@	   #\
 address 		: att =uchar*		:=lbb{ [fd,inn] , path }\
 balance 		: bal =ulong			:=query( att )\
 charm 		: chm =char const*	:=charm\
 digital 		: dig =ulong			:=#def\
 execs		: exs =sizeof		:=void *\
 formation	: fmn =ulong		:=#usedef\
 gvailability	: gvy =args_t[2]	:=l_args,args_r\
 hevel		: hvl =ulong	:=1|hashlvl\
 include		: ine =uchar*[]		:=files||strings\
 jcall		: jck =ulong[]		:=call_(j)\
 katt			: ktt =struct _u_,ulong*,void *:=__id,charms,__kargs(seed__,...)\
 laddr		: lar =union __nai*				:=native_ather_interface\
 mcall		: mca =addr_t,callre_t*,void *	:=kmem,ket,krgs\
 nope			: nop =sizeof			:=entry_t\
 operatingsys	: sys =sizeof			:=sys_call()\
 pdetails		: pds =sizeof			:=point_t\
 qlbb			: qlt =sizeof			:=lbb_query(type_t)\
 rlbb 		: rlb =struct __lbb		:=book\
 sandbox		: sbp =char *[]			:=playground\
 traverse		: tra =number			:={ de , en }code(base)\
 user			: usr =sizeof			:=home\
 vik			: vik =struct vik_t** 	:=viks\
 welkommen	: wln =ulong			:=connect(loc)\
 xolve		: xol =sizeof			:=request\
 ybins		: ybi =char *[]			:=bins\
 z 			: log =int&struct __privacy	:=_yes,_no,_maybe,def\
#**/


// the number of tabs control the access level allowed
# 0 -> nodef
const static char __control = '\t';
# 2 -> command ( default_args || supplied_args )
const static char _ignored[6] = { '@' , '#' , ':' , '=' , '\s' }; // "\s" for formatting freaks in code beauty
# 3 -> define
unsigned long count_tabs( void *__ , unsigned char _ ) {
	unsigned char *__c = (unsigned char *) __;
	unsigned long _r = 0;
	while ( __c != '\t' ) {
		if ( _ == 'l' ) {
			__c-=2;
		}
		_r+=1;
		__c+=1;
	}
	return _r;
}
# 4 -> kmem_alloc( base_ , _size )
void *kmem_alloc( unsigned long _b , unsigned long _s ) {
	struct __kmem = {
		.__base = _b;
		.__size = _s;
		.__start = katt( struct __kmem )
		.lock = retrieve()
	}
	unsigned long total = 0;
	while ( _s > 0 ) {
		total += _b * _s;
		_s-=1;
	}
}

static long __lbb__error__ = 0;

__lbb_errors[] = { 
	"not enough storage\n", //_0xf=
}

void const *lbb_error() {
	return *__lbb_errors[__lbb__error__];
}

void const *katt( unsigned long _size ) {
	if ((lbb_reserve(_size)) < 0 ) {
		return lbb_error();
	}
	return lbb_point();
}

static unsigned long f_reserve = 0; // wrong to have f_reserves should be automated as in sequencial


// long to indicate error on -ve returns
long lbb_reserve(unsigned long _size) {
	unsigned long _reserve = __reserve(_size);
	if ( _reserve == 0 ) {
		__lbb__error__ = -1;
		return __lbb__error__;
	}
	return _reserve >= _size ? _reserve : f_reserve ; 
}

void const *lbb_point() { 
	
} 

struct __lbb_loc {
	unsigned long offset,
	unsigned long subsize,
	void const* __start;
};

struct __kmem {
	unsigned long __base;
	unsigned long __size;
	void const* __start;
	struct __lbb_loc lock;
};

struct __lbb_loc retrieve() {

	struct __lbb_loc = {
		.offset = __lbb_cur_offset,
		.subsize = __lbb_cur_size,
		.__start = __lbb_att
	};

	return &__lbb_loc
}

union __lbb__ {
	struct _fd_inn {
		unsigned long fd;
		unsigned long inn;
	} _fdinn;
	struct _path {
		unsigned char const* p;
		unsigned long l;
	} _path;
}



# ather processors always have 2 or more point{s,ers} a tracker of the type 
# and a tracker for the referenced execution params, notice here that execution
# params include binaries, ternaries, and any new numbering system&|encoding 
# including two or more step executions such as compile, link & run using a combination of 
# `cc`, `[ar,nm, cc -fpic]` , `./` 
#in general the following:
	# `./shared/programs/[interpreter:python3,node,sh,...] args..` 

# a 2nd level ather processor can be fully connected on a full grid, with max bit change being the 
# correct amount of balance between latency and complete change.
# the type of, defined for this, is ternary which is 3. it's VERY important to note that 3 means,
# 3 different `ent`|entities in the ather processor and not the same ather processor into more than 1,
# it's also very important to note that the ather processor is always changing but 1 change at a time
# and that's the charm.

# a 3rd level ather processor can relay latency and change to other ather processors connected on the
# athernet.
#	the athernet uses blockchain for historical data, the internet to connect, ternary for lockation, binary to execute \
by mr.kj 

# an athernet processor is able to define itself or mimic any other type of athernet processor, nonetheless
# a processor is not limited, except by it's balance. Unlike in the traditional sense the hardware is the limitation, 
# no sir, 
# a device running athernet can execute commands comming from processors that it's not running on, as a vik, 
# and each vic contributes xol to get the { cpu , gpu } execution to the output device, delivered and executed.
# the amount,lockation,latency of the combined laddr processors that run any charm determines a part of that charm.
# 
# 




address:
	@if [ ! -d @charms ]; then printf "no charms\n run \`charm\`\n"; \
		else printf "att;" > @charms/.address; fi

balance:
	@if [ ! -f @charms/.balance ]; then printf "no balance found\n"; \
		else printf "0" > @charms/.balance; fi

charms_:
	att=$( address )
	bal=$( balance )
	chm=$( charm )

charm__:
	$_ _charms
	$_ __charms
	$_ charms_

_charms:
	rm -rf @charms

__charms:
	if [ ! -d "@charms" ]; then mkdir @charms; fi
	touch @charms/.address
	touch @charms/.balance
	touch @charms/.charm

charm:
	$_ charm__
	@printf "\n@charm:0xkaram#\n" > @charms/.charm

^digital:
	@cat @charms/.charm

digital:
	#modules
# 	so_athernet=
#fifo coms

execs:
	exs
#execute c on socket




formation:
#hash( "left" , "right" )
	$( c__ )shared/programs/kurl
pre:
	c=@
	c__=./
	c_bash=/bin/bash
	cc=/usr/bin/cc
	ch=#

runs:
	_anet=$( c__ )shared/programs/athernet
	_kurl=$( c__ )shared/programs/kurl







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
