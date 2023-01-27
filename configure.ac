#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#

CURRENT VERSION
AC_PREREQ([2.70])
AC_INIT([ATHERNET], [0.96], [https://bugs.athernet.com/report])
AC_CONFIG_SRCDIR([Lockfile])
AC_CONFIG_HEADERS([charm.h])
AC_DEFINE([HAVE_PROBE_H], [1], [defines the ather probe header file as the MAIN probe file `probe.h`])
AC_CHECK_HEADERS([unistd.h stdio.h stdlib.h sys/stat.h sys/socket.h sys/types.h arpa/inet.h netdb.h string.h fcntl.h dirent.h ctype.h ifaddrs.h stdarg.h netinet/in.h stdint.h sys/socket.h])
AC_CHECK_FUNCS([getcwd open write gethostbyname inet_ntoa memmove memset mkdir mkfifo munmap regcomp select socket strchr strdup strstr])
abh=hba hba="cc -c -fpic alph/hbar.c -o ../share/.objs/hbar.o"
sfo=sba sba="cc -c -fpic alph/ccc.c -o ../share/.objs/ccc.o"
nso=osn osn="cc -shared ../share/.objs/*.o -o ../share/.libs/libanet.so"
idx=xdi xdi="cc alph/index.c -o ../share/index ./../share/.libs/libanet.so && ./../share/index"
AC_SUBST([__probe__h], [probe.h])
AC_SUBST([__lbb_fname], [.lbb])
AC_SUBST([__ccc__h], [../charm.h])
AC_SUBST([__charms__], [../charms/])
AC_SUBST([connected_c_compiler], [ccc])
AC_SUBST([__lbb__h], [lbb.h])
AC_SUBST([__lbb_name__], [little_black_book])
AC_SUBST([__addr_alias__], [atherpoint])
AC_SUBST([__addr_loc__], [127.0.0.1])
AC_SUBST([pkgname], [ATHERNET])
AC_SUBST([pkgversion], [0x96])
AC_DEFINE([CCC_HEADERS], [1], [defines a strict header check to be used when building `alph`])
AC_DEFINE([ATT_VERSION], [0x9], [defines the current running <athernet.h> {a.k.a `att`} header file version])
AC_DEFINE([__sa__m], [m4_eval(8**1)], [define the L-0 {m=(machine)} address size])
AC_SUBST([__slot_size__0], [__sa__m])
AC_DEFINE([__sa__pi], [m4_eval(8**2)], [defines the L-1 {pi=(pseudo_interface)} address size])
AC_SUBST([__slot_size__1], [__sa__pi])
AC_DEFINE([__sa__npr], [m4_eval(8**3)], [defines the L-2 {npr=(network point request)} address size])
AC_SUBST([__slot_size__2], [__sa__npr])
AC_DEFINE([__sa__dsls], [m4_eval(8**4)], [defines the L-3 {dsls=(data storage location space)} address size])
AC_SUBST([__slot_size__3], [__sa__dsls])
AC_DEFINE([__sa__b2pie], [m4_eval(8**5)], [defines the L-4 {b2pie=(binary position-independent executable)} address size])
AC_SUBST([__slot_size__4], [__sa__b2pie])
AC_DEFINE([__sa__tflb3d], [m4_eval(8**6)], [defines the L-5 {tflb3d=(ternary field lock base:3 descriptor)} address size])
AC_SUBST([__slot_size__5], [__sa__tflb3d])
AC_DEFINE([__sa__htkaian], [m4_eval(8**7)], [defines the L-6 {htkaian=(hash ternary kei at in athernet)} address size])
AC_SUBST([__slot_size__6], [__sa__htkaian])
AC_DEFINE([__sa__alphadef], [m4_eval(8**8)], [defines the L-7 {alphadef=(alphabet definition)} address size])
AC_SUBST([__slot_size__7], [__sa__alphadef])
AC_DEFINE([__sa__kconalpha], [m4_eval(8**9)], [defines the L-8 {kconalpha=(k controller alpha)} address size])
AC_SUBST([__slot_size__8], [__sa__kconalpha])
AC_SUBST([MAX_SLOTS], [8])
AC_CONFIG_FILES([alph/probe.h alph/hbar.h alph/hbar.c alph/enk.h alph/display.h alph/lbb.h alph/resolver.c alph/ccc.c alph/index.c])
AC_DEFUN([ALPH_RUN],
[AS_LITERAL_IF([$1],
  [eval "$$1"],
  [AS_VAR_COPY([var], [$1])
   echo "$var"],
  [echo 'eval "$'"$1"\"])])
AC_OUTPUT
ALPH_RUN([hba])
ALPH_RUN([osn])
ALPH_RUN([sba])
ALPH_RUN([xdi])



