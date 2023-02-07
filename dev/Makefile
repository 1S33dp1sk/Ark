_TEST_ADDR = 8421cd07d7e77c6eea

__alphadef__ := a b c d e f g h i j k l m n o p q r s t u v w x y z
#__bdef__ := a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__fieldsdef__ := .att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai
__clevels__ := c cc 3c c3


# ifeq (0,${MAKELEVEL})
__me := $(shell whoami)
__cdir := $(shell pwd)
__host := $(shell arch)
__home := athernet
__so:=libather.so
__nso:=libathernet.so
__att := ${__cdir}/active
__dev := ${__cdir}/dev
__lbb := ${__cdir}/lbb
__sdir := ${__cdir}/shared
__zdir := ${__cdir}/
__bindir := ${__cdir}/active
__sopath := ${__bindir}/${__so}
__nsopath := ${__bindir}/${__nso}
MAKE := ${MAKE} host-type=${__host}
__ZEN__ := 0x
# endif

#ifeq (1,${MAKELEVEL})
_active:=./active
zen:=zen
_zen:=${zen}0x
_charms:=charms
__zdir:=$(subst ${_zen},${_charms},${__cdir})
#use `ccc` to read dir
__ccc:=${__zdir}/.
#use `c2` to run files
__c2:=cc ${__zdir}/. 
__zen:=${_active}/${_zen}
MAKE:= ${MAKE} 
#endif

# ifeq (2,${MAKELEVEL})
__welcome = \n\t\tWelcome To ATHERNET\n\n
__net := ${__dev}/net
u_les := ${__net}/user.les
l_lbb := ${__net}/mor.lbb
c_def := ${__net}/${n}.ulml
__sharedir := ${__cdir}
MAKE := ${MAKE} host-type=${__host}
# endif


#ifeq (3,${MAKELEVEL})
#use `3c` to compile the dir
_aso :=${_active}/${__so}
_nso :=${_active}/${__nso}
__3c:=3c
#endif





ternary:
	#protection guard
	if [ -f lbb.out ]; then rm lbb.out;fi
	if [ -f out.lbb ]; then rm out.lbb;fi
	#compile @
	cc ${__dev}/ternary.c -o active/@ ${_aso} ${_nso}
	if [ -f .lbb ]; then rm .lbb;fi
	#activatett

sockets: libather libathernet
	cc ${__net}/morles.c -o active/morles ${_nso}

ccc: cca ccb

cca: builder_info libather zenv zmods zidx hash8

libather: clean_libather idxer hbar shared

ccb: capabilities libathernet server

libathernet: clean_libathernet u_les mor_n u_lbb_n usharedn

server: sockets
	
#prompt :: PS1="\d \h $ "
capabilities: welcome

welcome:
	@printf "${__welcome}"

builder_info: welcome
	@printf "@builder\n"
	@printf "\t&name		-> ${__me}\n"
	@printf "\t&current dir	-> ${__cdir}\n"
	@printf "\t&architicture	-> ${__host}\n"

b_les:=${__bindir}/les.o
b_mor:=${__bindir}/mor.o
b_lbb:=${__bindir}/lbb.o
## libathernet.so ##
clean_libathernet: 
	@printf "\n\n(cc)  : clean&->create :: "
	@printf "libathernet\n\n"
	if [ -f ${b_les} ]; then rm ${b_les}; fi
	if [ -f ${b_mor} ]; then rm ${b_mor}; fi
	if [ -f ${b_lbb} ]; then rm ${b_lbb}; fi
	if [ -f ${__nsopath} ]; then rm ${__nsopath}; fi
# 	@printf "\n\n(ccb):connected charm balance :: your athernet balance\n\n"

u_les:
	cc -c -fpic ${__net}/les.c -o ${__bindir}/les.o

mor_n:
	cc -c -fpic ${__net}/mor.c -o ${__bindir}/mor.o

u_lbb_n:
	cc -c -fpic ${__dev}/lbb.c -o ${__bindir}/lbb.o

usharedn:
	cc -shared ${__bindir}/*.o -o ${__nsopath}


## active libather.so ##
hash8:
	cc ${__dev}/hash8.c -o ${yb_hash8}/hash_it ${_aso}

#${_active}/${zen}2K ${__ccc}
zidx: 
	cc ${__dev}/zidx.c -o active/zen2k ${_aso}

#${_active}/${zen}1F ${__ccc}
zmods: 
	cc -c -fpic ${__dev}/zmods.c -o active/zen1f.o ${_aso}

#${_active}/zen0x
zenv: 
	cc -c -fpic ${__dev}/zenv.c -o active/zen0x.o ${_aso}

yb_hash8:=${__bindir}/hash_it
b_hbar:=${__bindir}/hbar.o
b_idxr:=${__bindir}/idxer.o
## libather.so ##
clean_libather: 
	@printf "\n\n(cc)  : clean&->create :: "
	@printf "libather\n\n"
	if [ -f ${b_hbar} ]; then rm ${b_hbar}; fi
	if [ -f ${b_idxr} ]; then rm ${b_idxr}; fi
	if [ -f ${__sopath} ]; then rm ${__sopath}; fi
# 	@printf "\n(cca) : creating charm addresses :: your ather library\n\n"

shared:
	cc -shared ${__bindir}/*.o -o ${__sopath}

hbar:
	cc -c -fpic ${__dev}/hbar.c -o ${__bindir}/hbar.o

idxer:
	cc -c -fpic ${__dev}/idxer.c -o ${__bindir}/idxer.o


clean_all:
	if [ -d active/ ]; then rm -rf active;mkdir active;fi
