#include <stdio.h>
#include <unistd.h>

int main (void) {
	printf("uid = %d\n", getuid());
	printf("gid = %d\n", getgid());
}