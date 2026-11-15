# configure.ac for irc-2.9.5b4
# Modernized version of the original configure.in

AC_PREREQ([2.72])  # Require modern autoconf
AC_INIT([irc],[2.9.5b4])
AC_CONFIG_SRCDIR([../ircd/ircd.c])
AC_CONFIG_HEADERS([setup.h:../support/setup.h.in])
AC_CONFIG_AUX_DIR([../support])

# Initialize automake
AM_INIT_AUTOMAKE([foreign])

# Check for basic programs
AC_PROG_CC
AC_PROG_CPP
AC_PROG_AWK
AC_PROG_INSTALL
AC_PATH_PROGS([SUM], [sum cksum], [true])

# Check for compiler characteristics
#m4_warn([obsolete],[AC_PROG_CC_STDC is obsolete; use AC_PROG_CC])dnl
#AC_REQUIRE(AC_PROG_CC)
AC_C_BIGENDIAN
AC_C_CONST

# Check for required headers
m4_warn([obsolete],
[The preprocessor macro 'STDC_HEADERS' is obsolete.
  Except in unusual embedded environments, you can safely include all
  C89 headers unconditionally.])dnl
# Autoupdate added the next two lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP

AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([
    stdio.h
    stdlib.h
    sys/types.h
    stddef.h
    stdarg.h
    unistd.h
    ctype.h
    memory.h
    curses.h
    term.h
    errno.h
    sys/errno.h
    pwd.h
    math.h
    utmp.h
    fcntl.h
    signal.h
    sys/ioctl.h
    sys/file.h
    sys/socket.h
    sys/stat.h
    sys/resource.h
    sys/select.h
    sys/poll.h
    netdb.h
    netinet/in.h
    sys/un.h
    arpa/inet.h
    sys/param.h
    syslog.h
    sys/syslog.h
    string.h
    strings.h
    sys/time.h
    time.h
    sys/times.h
    netinet/in_systm.h
])

# Check for required types
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
m4_warn([obsolete],
[your code may safely assume C89 semantics that RETSIGTYPE is void.
Remove this warning and the 'AC_CACHE_CHECK' when you adjust the code.])dnl
AC_CACHE_CHECK([return type of signal handlers],[ac_cv_type_signal],[AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([#include <sys/types.h>
#include <signal.h>
],
		 [return *(signal (0, 0)) (0) == 1;])],
		   [ac_cv_type_signal=int],
		   [ac_cv_type_signal=void])])
AC_DEFINE_UNQUOTED([RETSIGTYPE],[$ac_cv_type_signal],[Define as the return type of signal handlers
		    ('int' or 'void').])

AC_TYPE_SIZE_T
AC_TYPE_UID_T

# Check for required libraries
AC_CHECK_LIB([crypt], [crypt])
AC_CHECK_LIB([socket], [socket])
AC_CHECK_LIB([nsl], [socket])

# Check for required functions
AC_CHECK_FUNCS([
    setpgrp
    strchr
    strrchr
    memcmp
    memset
    memmove
    memcpy
    select
    inet_ntoa
    inet_aton
    inet_addr
    inet_netof
    getrusage
    times
    strerror
    strtoken
    strtok
    sigaction
    sigset
])

# Custom checks for system-specific features
AC_MSG_CHECKING([for working stdarg])
AC_COMPILE_IFELSE([
    AC_LANG_PROGRAM([
        #include <stdarg.h>
        #include <stdio.h>
    ], [
        va_list ap;
        va_start(ap, 0);
        va_end(ap);
    ])
], [
    AC_DEFINE([USE_STDARG], [1], [Define if stdarg works])
    AC_MSG_RESULT([yes])
], [
    AC_MSG_RESULT([no])
])

# Check for zlib
AC_ARG_WITH([zlib],
    [AS_HELP_STRING([--with-zlib],
        [Enable compressed links (default is yes)])],
    [],
    [with_zlib=yes])

AS_IF([test "x$with_zlib" != "xno"], [
    AC_CHECK_LIB([z], [inflate], [
        AC_CHECK_HEADER([zlib.h], [
            AC_DEFINE([USE_ZLIB], [1], [Define if zlib is available])
            IRC_ZLIB_LIBRARY="-lz"
        ])
    ])
])

# Check for curses/termcap
AC_ARG_WITH([ncurses],
    [AS_HELP_STRING([--with-ncurses],
        [Use ncurses library (default is yes)])],
    [],
    [with_ncurses=yes])

AS_IF([test "x$with_ncurses" != "xno"], [
    AC_CHECK_LIB([ncurses], [initscr], [
        AC_DEFINE([USE_NCURSES], [1], [Define if ncurses is available])
        IRC_CURSES_TERMCAP_LIBRARY="-lncurses"
    ], [
        AC_CHECK_LIB([curses], [initscr], [
            AC_DEFINE([USE_CURSES], [1], [Define if curses is available])
            IRC_CURSES_TERMCAP_LIBRARY="-lcurses"
        ])
    ])
])

# Check for resolver configuration
AC_MSG_CHECKING([for resolver configuration file])
AC_CACHE_VAL([irc_cv_path_resconf], [
    for irc_file in /etc/resolv.conf; do
        if test -r "$irc_file"; then
            irc_cv_path_resconf="$irc_file"
            break
        fi
    done
])

AS_IF([test -n "$irc_cv_path_resconf"], [
    AC_DEFINE_UNQUOTED([IRC_RESCONF], ["$irc_cv_path_resconf"])
    AC_MSG_RESULT([$irc_cv_path_resconf])
], [
    AC_DEFINE([IRC_RESCONF], ["/etc/resolv.conf"])
    AC_MSG_RESULT([not found, using default])
])

# Output files
AC_CONFIG_FILES([
    Makefile:../support/Makefile.in
    version.c.SH:../ircd/version.c.SH.in
    sums:../ircd/crypt/sums.in
])

AC_OUTPUT
