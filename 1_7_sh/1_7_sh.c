#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 4096

int main (void) {

  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% ");

  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;

    pid = fork();
    if (pid < 0) {
      printf("system error\n");
      return -1;
    } else if (pid == 0) {
      execlp(buf, buf, (char*) 0);
      printf("couldn't execute: %s", buf);
      exit(127);
    }

    pid = waitpid(pid, &status, 0);
    if (pid < 0) {
      printf("waitpid error\n");
      return -1;
    }
    printf("%% ");
  }



  return -1;
}
