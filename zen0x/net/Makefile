_TEST_ADDR = 8421cd07d7e77c6eea

ifeq (0,${MAKELEVEL})
__welcome = Welcome To ATHERNET\n Setting everything up...\n\n
__cdir := $(shell pwd)
__rend := ${__cdir}/rendezvous
__sor := ${__cdir}/sourcer
__sur := ${__cdir}/summer
__me := $(shell whoami)
__host := $(shell arch)
__sharedir := ${__cdir}/shared
__bindir := ${__cdir}/bin
__sopath := ${__bindir}/libathernet.so
MAKE := ${MAKE} host-type=${__host}
endif

all: welcome shared_bin hash8 sor rend test

server:
	cc ${__sharedir}/morles.c -o ${__bindir}/the_server

welcome:
	@printf "${__welcome}"
	@printf "current dir	:: ${__cdir}\n"
	@printf "builder		:: ${__me}\n"
	@printf "architicture	:: ${__host}\n"

rend:
	cc rendezvous/main.c -o ${__bindir}/rendezvous ${__sopath}

test:
	@./bin/rendezvous ${_TEST_ADDR}

sor:
	cc sourcer/main.c -o ${__bindir}/sourcer ${__sopath}

hash8:
	cc ${__sharedir}/hash8.c -o ${__bindir}/hash8 ${__sopath}


shared_bin:
	if [ ! -d "${__bindir}" ]; then mkdir ${__bindir}; fi
	cc -c -fpic ${__sharedir}/hbar.c -o ${__bindir}/hbar.o
	cc -shared ${__bindir}/*.o -o ${__sopath}
