#include <unistd.h>

#define BUFSIZE 4

int main (void) {
  int n;
  char buf[BUFSIZE];

  // Ex: what happens if either of those two lines are uncommented out?
  // close(STDIN_FILENO);
  // close(STDOUT_FILENO);

  while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      // write error
      return -1;
    }
    if (n < 0) {
      // read error
      return -1;
    }
  }

  buf[0] = 'a';
  buf[1] = '\n';
  buf[2] = '\0';

  write(STDOUT_FILENO, buf, 3);

  return 0;
}
