_TEST_ADDR = 8421cd07d7e77c6eea

__alphadef__ := a b c d e f g h i j k l m n o p q r s t u v w x y z
#__bdef__ := a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__filedef__ := .att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai


ifeq (0,${MAKELEVEL})
__cdir := $(shell pwd)
__rend := ${__cdir}/active
__sor := ${__cdir}/sourcer
__sur := ${__cdir}/summer
__me := $(shell whoami)
__host := $(shell arch)
__sharedir := ${__cdir}/shared
__bindir := ${__cdir}/bin
__sopath := ${__bindir}/libather.so
MAKE := ${MAKE} host-type=${__host}
__welcome = SockEp0 :: \n\n
__ZEN__ := 0x
endif

#ifeq (1,${MAKELEVEL})
_active:=./active
MAKE:= ${MAKE}
zen:=zen
_zen:=${zen}0x
_charms:=charms
_chrms:=chrms
__zdir:=$(subst ${_zen},${_charms},${__cdir})
__rmsdir:=$(subst ${_zen},${_chrms},${__cdir})
__3c:=${__rmsdir}/.
__ccc:=${__zdir}/.
__zen:=${_active}/${_zen}
#endif


Z-edp:


zidx: libather
	cc dev/zidx.c -o active/zen2K ${_active}/libather.so
	${_active}/${zen}2K ${__ccc}


zmods: libather
	cc dev/zmods.c -o active/zen1F ${_active}/libather.so
	${_active}/${zen}1F ${__ccc}


zenv: libather
	cc dev/zenv.c -o active/zen0x ${_active}/libather.so
# 	${_active}/zen0x


main: libather lbb
	${_active}/lbb

tests: main t0 t1 t2

t0:
	#all
	${_active}/lbb kei mrkj -t S 

t1:
	#kei
	${_active}/lbb mykey 

t2:
	#level
	${_active}/lbb 2 

lbb:
	@cc dev/lbb.c -o active/lbb ${_active}/libather.so

libather: clean idxer hbar shared

clean:
	if [ -d active/ ]; then rm -rf active;mkdir active;fi

shared:
	cc -shared active/*.o -o active/libather.so

hbar:
	cc -c -fpic dev/hbar.c -o active/hbar.o

idxer:
	cc -c -fpic dev/idxer.c -o active/idxer.o
