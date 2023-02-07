#################################
#			Base-26				#
#################################
all:
__alphadef__ := a b c d e f g h i j k l m n o p q r s t u v w x y z
__bdef__ := a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__fieldsdef__ := .att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai
__clevels__ := c cc 3c
__FNAME_L_S__ = \n__Makefile_001F_001A_\n\tabcdefghijklmnopqrstuvwxyz\n__0x\n
#################################
#			Shell				#
#################################
__me:=$(shell whoami)
__host:=$(shell arch)
__cdir:=$(shell pwd)
__home:=athernet
#################################
#		  C Directories			#
#################################
_@:=${__cdir}/@
__dev:=${__cdir}/dev
__0xadir:=${__cdir}/0xa
__bindir:=${__cdir}/bin
__share:=${__cdir}/shared
__libsdir:=${__cdir}/libs
__charms:=${__cdir}/charms
att:=${__share}/@source
@fld:=${_@}/fld
#################################
#			Shorts				#
#################################
__empty:=
__binobjs:=${__bindir}/*.o
__devheaders:=${__dev}/*.h
atherlib__:=libather.so
anetlib__:=libathernet.so
atherlib:=${__libsdir}/${atherlib__}
anetlib:=${__libsdir}/${anetlib__}
#################################
#			@Source				#
#################################

__bin_clean:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

__@_clean:
	if [ -d ${_@} ]; then rm -rf ${_@}; fi

__att_clean:
	if [ -d ${att} ]; then rm -rf ${att}; fi

d_make:
	if [ ! -d ${__bindir} ]; then mkdir ${__bindir}; fi
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi
	if [ ! -d ${att} ]; then mkdir  ${att}; fi


_d_clean: __bin_clean __@_clean __att_clean d_make



syster_start: fresh_start sek_start
sek_start: clean_start clean_libathernet libathernet
fresh_start: clean_start clean_libather libather
clean_start:
	if [ -d ${att} ]; then rm -rf ${att}; fi
start: clean_start
	if [ ! -d ${att} ]; then mkdir ${att}; fi
	$_ clear_common
clear_common:
	# maybe should iterate over them delete &-> copy
	cp ${__devheaders} ${att}
#################################
#			libather.so			#
#################################
lib_ather:= hbar enk idxer zenv lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_zenv clean_lbb
	@printf "clean :(cc): libather\n"
	if [ -f ${o_hbar} ]; then rm ${o_hbar}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	if [ -f ${o_enk} ]; then rm ${o_enk}; fi
	if [ -f ${o_zenv} ]; then rm ${o_zenv}; fi
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${atherlib} ]; then rm ${atherlib}; fi
	@printf "\n"

libather: start ${__lib_ather__}
	cc -shared $(addprefix ${__bindir}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
#################################
#			Hash bar 			#
#################################
hbar:=hbar
# file output
@hbar:=${att}/${hbar}
__hbar:=${__dev}/${hbar}
hbar__:=${__hbar}/${hbar}
hbar_c:=${__hbar}/c
hbar_h:=${__hbar}/h
o_hbar:=${__bindir}/hbar.o
clean_hbar:
	@printf "clean :: Hash bar\n"
	if [ -f ${@hbar}.c ]; then rm ${@hbar}.c; fi
	if [ -f ${@hbar}.h ]; then rm ${@hbar}.h; fi
	@printf "\n"

__hbar__:
	cat ${hbar_h} > ${@hbar}.h
	cat ${hbar_c} > ${@hbar}.c
	cc -c -fpic $(addsuffix .c,${@hbar}) -o ${o_hbar}
#################################
#			Indexer				#
#################################
ir:=ixr
ixr:=idxer
idxer:=indexer
# file output
xer_o:=${__bindir}/${ixr}.o
# field for input
@idxer:=${__dev}/${ir}
cidxer:=${@idxer}/c
hidxer:=${@idxer}/h
# field for output
_idxer:=${att}/${ixr}
# for fields
idxer_:=${_idxer}/${idxer}
idxeroc:=${_idxer}.c
idxeroh:=${_idxer}.h
# idxer@:=${_@}/${idxer}
clean_ixr: clean_idxer clean_indexer
clean_idxer:
	@printf "clean : out : The ${idxer}\n"
	if [ -f ${idxer_}.c ]; then rm ${idxer_}.c; fi
	if [ -f ${idxer_}.h ]; then rm ${idxer_}.h; fi
	@printf "\n"
clean_indexer:
	@printf "clean : in : The ${idxer}\n"
	if [ -d ${_idxer} ]; then rm -rf ${_idxer}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	@printf "\n"
__idxer__: 
# 	if [ ! -d ${_idxer} ]; then mkdir -p ${_idxer}; fi
	cat ${hidxer} > ${idxeroh}
	cat ${cidxer} > ${idxeroc}
	cc -c -fpic ${idxeroc} -o ${xer_o}
#################################
#			Zenviroment			#
#################################
zenv:=zenv
@zenv:=${att}/${zenv}
__zenv:=${__dev}/${zenv}
zenv__:=${__zenv}/${zenv}
zenv_c:=${__zenv}/c
zenv_h:=${__zenv}/h
o_zenv:=${__bindir}/zenv.o

clean_zenv:
	@printf "clean :: Z enviroment\n"
	if [ -f ${@zenv}.c ]; then rm ${@zenv}.c; fi
	if [ -f ${@zenv}.h ]; then rm ${@zenv}.h; fi
	@printf "\n"

__zenv__:
	cat ${zenv_h} > ${@zenv}.h
	cat ${zenv_c} > ${@zenv}.c
	cc -c -fpic $(addsuffix .c,${@zenv}) -o ${o_zenv}
#################################
#		Little Black Book		#
#################################
lbb:=lbb
@lbb:=${att}/${lbb}
__lbb:=${__dev}/${lbb}
lbb__:=${__lbb}/${lbb}
lbb_c:=${__lbb}/c
lbb_h:=${__lbb}/h
o_lbb:=${__bindir}/lbb.o

clean_lbb:
	@printf "clean :: Little black book\n"
	if [ -f ${@lbb}.c ]; then rm ${@lbb}.c; fi
	if [ -f ${@lbb}.h ]; then rm ${@lbb}.h; fi
	@printf "\n"

__lbb__:
	cat ${lbb_h} > ${@lbb}.h
	cat ${lbb_c} > ${@lbb}.c
	cc -c -fpic $(addsuffix .c,${@lbb}) -o ${o_lbb}
#################################
#			Enkoder				#
#################################
enk:=enk
@enk:=${att}/${enk}
__enk:=${__dev}/${enk}
enk__:=${__enk}/${enk}
enk_c:=${__enk}/c
enk_h:=${__enk}/h
o_enk:=${__bindir}/enk.o
clean_enk:
	@printf "clean :: Enkoding\n"
	if [ -f ${@enk}.c ]; then rm ${@enk}.c; fi
	if [ -f ${@enk}.h ]; then rm ${@enk}.h; fi
	@printf "\n"

__enk__:
	cat ${enk_h} > ${@enk}.h
	cat ${enk_c} > ${@enk}.c
	cc -c -fpic $(addsuffix .c,${@enk}) -o ${o_enk}
#################################
#			Y-binary			#
#################################
MAKE:=${MAKE} host-type=${__host}
__ybin:=${__dev}/ybin
3c_temp:=${att}/temp.c
ybinary: clean_ylink ybin_hash8 ybin_zcharms

clean_ylink:
	if [ -f ${3c_temp} ]; then rm -rf ${3c_temp}; fi

ybin_hash8: clean_ylink
	link ${__ybin}/hash8.c ${3c_temp}
	cc ${3c_temp} -o ${@dir}/hash_it ${atherlib}
	unlink ${3c_temp}

ybin_zcharms: clean_ylink
	link ${__ybin}/charms.c ${3c_temp}
	cc ${3c_temp} -o ${@dir}/zcharms ${atherlib}
	unlink ${3c_temp}
#################################
#		  libathernet.so		#
#################################
clean_libathernet: clean_fld clean_ter

libathernet: fields ter_cm
#################################
#			Ternary				#
#################################
t2:=ter
ter:=3c
ccc:=ternary
# output file
ter@:=${_@}/${t2}
#####################
#implement header file#
#####################
ter_o:=${_@}/3c.o
# field for input 
ter__:=${__dev}/${t2}
ter_c:=${ter__}/c
ter_h:=${ter__}/h
# field for output
ater:=${att}/${ccc}
ter_cm: clean_ter @ter_  
ternary:=${ter@} checkmake
clean_ter:
	@printf "Ternary UD\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${ter_o} ]; then rm ${ter_o}; fi
	if [ -f ${ater}.c ]; then rm ${ater}.c; fi
	if [ -f ${ater}.h ]; then rm ${ater}.h; fi
	@printf "\n"

__ter__:
	cat ${ter_h} > ${ater}.h
	cat ${ter_c} > ${ater}.c
	if [ -f ${idxeroh} ]; then \
	cc ${ater}.c -o ${ter@} ${atherlib};fi

@ter_: 
	if [ -f ${ter@} ] && [ -f ${ter_o} ];\
		then \
			$(ternary); \
		else \
			$_ __ter__; \
	fi
#################################
#			  Fields			#
#################################
f3:=fld
fld:=field
field:=linked
# output files
attfld:=${att}/${fld}
#####################
#implement header file#
#####################
fld_o:=${__bindir}/${f3}.o
# field for input 
fld__:=${__dev}/${f3}
fld_c:=${fld__}/c
fld_h:=${fld__}/h
# field for output
fields: clean_fld __fld__
clean_fld:
	@printf "\nLinked Active Fields\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${fld_o} ]; then rm ${fld_o}; fi
	if [ -f ${attfld}.c ]; then rm ${attfld}.c; fi
	@printf "\n"
# 	if [ -f ${attfld}.h ]; then rm ${attfld}.h; fi

__fld__:
	cat ${fld_h} > ${attfld}.h
	cat ${fld_c} > ${attfld}.c
	cc -c -fpic $(addsuffix .c,${attfld}) -o ${fld_o}
	cc $(addsuffix .c,${attfld}) -o ${@fld}

















#################################
#		 top level clean		#
#################################
clean_exits: clean_bindir

clean_bindir:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi



# \
mr. karam jaber.