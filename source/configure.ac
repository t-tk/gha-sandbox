#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([gha-sandbox], [0.00], [issue@aaa.com])
AC_CONFIG_SRCDIR([gha_sb.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CHECK_HEADERS([unicode/uversion.h unicode/utypes.h icu.h])
#AC_CHECK_LIB(icuuc, [u_getVersion_73, u_versionToString_73])
#AC_CHECK_LIB(icuuc, [u_getVersion_72, u_versionToString_72])
#AC_CHECK_LIB(icuuc, [u_getVersion_71, u_versionToString_71])
#AC_CHECK_LIB(icuuc, [u_getVersion_70, u_versionToString_70])
AC_SEARCH_LIBS([_u_getVersion],[icuuc],[],[
AC_SEARCH_LIBS([u_getVersion_74],[icuuc],[],[
 AC_SEARCH_LIBS([u_getVersion_73],[icuuc],[],[
  AC_SEARCH_LIBS([u_getVersion_72],[icuuc],[],[
   AC_SEARCH_LIBS([u_getVersion_71],[icuuc],[],[
    AC_SEARCH_LIBS([u_getVersion_70],[icuuc],[],[
     AC_SEARCH_LIBS([u_getVersion_69],[icuuc],[],[
      AC_SEARCH_LIBS([u_getVersion_69],[icu],[],[
       AC_MSG_ERROR([Unable to find icuuc, make sure ICU is installed.])
      ])
     ])
    ])
   ])
  ])
 ])
])
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
