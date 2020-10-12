#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	alarm(5);
	pause();
	printf("i haven been waken up!\n");

	return 0;
}