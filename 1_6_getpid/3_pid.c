#include <stdio.h>
#include <unistd.h>

int main (void) {
	printf("hello world from pid %d\n", getpid());
}