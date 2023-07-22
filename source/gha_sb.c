#include <stdio.h>
#ifdef WIN32
#include <fcntl.h>
#endif

int main() {

#ifdef WIN32
  _setmode (fileno(stdout), _O_BINARY);
#endif

  printf("this is test.\n");

  return 0;
}
