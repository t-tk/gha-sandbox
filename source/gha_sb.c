#include <stdio.h>
#include <string.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#ifdef WIN32
#include <fcntl.h>
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
