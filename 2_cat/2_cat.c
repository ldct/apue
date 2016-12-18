// getc
#include <stdio.h>
// exit
#include <stdlib.h>
// STDIN_FILENO
#include <unistd.h>

void err_sys(const char* x) {
  perror(x);
  exit(1);
}

int main (void) {
  int c;

  // Ex: what happens if either of those two lines are uncommented out?
  // close(STDIN_FILENO);
  // close(STDOUT_FILENO);

  while ((c = getc(stdin)) != EOF) {
    if (putc(c, stdout) == EOF) {
      err_sys("output error");
    }
  }

  if (ferror(stdin)) {
    err_sys("input error");
  }

  exit(0);
}