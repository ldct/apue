#include <errno.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {
  for (int i=1; i<107; i++) {
    fprintf(stderr, "%d %s\n", i, strerror(i));
  }
  fprintf(stderr, "ENOTRECOVERABLE: %s\n", strerror(ENOTRECOVERABLE));
  errno = EACCES;
  perror(argv[0]);
  return 0;
}
