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

#ifdef WIN32
  _setmode (fileno(stdout), _O_BINARY);
#endif

  if (argc>1 && strcmp(argv[1],"--version")==0) {
    printf("package_version: %s\n", PACKAGE_VERSION);
    printf("implementation: %s\n", IMPLEMENTATION);
    return 0;
  }

  printf("this is test.\n");

  return 0;
}
