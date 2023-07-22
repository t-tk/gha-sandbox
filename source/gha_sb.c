#include <stdio.h>
#include <getopt.h>

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
  int opt, longindex;

#ifdef WIN32
  _setmode (fileno(stdout), _O_BINARY);
#endif

  struct option longopts[] = {
      { "help",    no_argument,      NULL, 'h' },
      { "version", no_argument,      NULL, 'v' },
      { 0,         0,                0,     0  },
  };

  while ((opt = getopt_long_only(argc, argv, "hv", longopts, &longindex)) != -1) {
    //    printf("%d %s\n", longindex, longopts[longindex].name);
    switch (opt) {
      case 'h':
      case 'v':
        printf("package_version: %s\n", PACKAGE_VERSION);
        printf("implementation: %s\n", IMPLEMENTATION);
        return 0;
      default:
        printf("unknown option\n");
        return 1;
    }
  }

  printf("this is test.\n");

  return 0;
}
