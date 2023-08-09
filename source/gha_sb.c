#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#ifdef WIN32
#include <fcntl.h>
#endif

#if defined(WIN32) && defined(WITH_SYSTEM_ICU)
#include <icu.h>
#else
#include <unicode/uversion.h>
#include <unicode/utypes.h>
#endif

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "v0.00"
#endif

#ifdef WIN32
# ifdef _MSC_VER
#  define IMPLEMENTATION            "Microsoft(R) C/C++ for Win32"
# elif defined(__MINGW32__)
#  define IMPLEMENTATION            "MinGW32 C/C++ for Win32"
# else
#  define IMPLEMENTATION            "Unknown C/C++ for Win32"
# endif                         /* _MSC_VER */
#define WRITE_MODE "wb"
#else
#define WRITE_MODE "w"
#endif

#ifdef  UNIX
# ifndef IMPLEMENTATION
#  define IMPLEMENTATION            "C for Unix"
# endif
#endif                          /* UNIX */

#ifndef IMPLEMENTATION
#  define IMPLEMENTATION            "Unknown"
#endif

int main(int argc, char **argv){

    char *name;
    FILE *fp;

#ifdef WIN32
  _setmode (fileno(stdout), _O_BINARY);
#endif

  if (argc>1 && strcmp(argv[1],"--version")==0) {
    printf("package_version: %s\n", PACKAGE_VERSION);
    printf("implementation: %s\n", IMPLEMENTATION);
    return 0;
  }

  if (argc>1 && strcmp(argv[1],"--printenv")==0) {
    char *var = getenv("TESTENV");
    printf("env TESTENV: %s\n", var ? var : "()");
    return 0;
  }

  if (argc>1 && strcmp(argv[1],"--icuversion")==0) {
    UVersionInfo icuVersion;
    char icu_version[U_MAX_VERSION_STRING_LENGTH] = "";
    u_getVersion(icuVersion);
    u_versionToString(icuVersion, icu_version);
    printf("Compiled with:  ICU version %s\n", icu_version);
    return 0;
  }

  if (argc==2 && strcmp(argv[1],"--stdio")==0) {
    struct stat sti, sto;
    int fdi = fileno(stdin), fdo = fileno(stdout);
    printf("STDIN  : %d %d %d\n", isatty(fdi), fstat(fdi, &sti), S_ISFIFO(sti.st_mode));
    printf("STDOUT : %d %d %d\n", isatty(fdo), fstat(fdo, &sto), S_ISFIFO(sto.st_mode));
  }

  if (argc>1) {
    name = argv[1];
    fp = fopen(name, WRITE_MODE);
    if (fp == NULL) {
      fprintf(stderr, "cannot open file %s\n", name);
      return 16;
    }
  } else {
    fp = stdout;
  }
  fprintf(fp, "this is test.\n");

  return 0;
}
