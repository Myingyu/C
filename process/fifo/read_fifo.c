#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/uio.h>


#define N 32

int main(int argc, char const *argv[])
{
	char buf[N];
	int pfd;


	if ( (pfd = open("myfifo", O_RDONLY)) < 0 )
	{
		perror("open failed!");
		exit(-1);
	}
	printf("read fifo was opened!\n");
	while( read(pfd, buf, N) > 0 ){
		printf("the length of string is %lu\n", strlen(buf));
	}
	printf("read fifo exit!\n");

	close(pfd);
	return 0;

}