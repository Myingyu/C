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
	char buf [N];
	int pfd;

	if ((pfd = open("myfifo", O_WRONLY)) < 0)
	{
		perror("open");exit(-1);
	}
	printf("write fifo was opened!\n");
	while( 1 ){
		fgets(buf, N, stdin);
		if ( strcmp(buf, "quit\n") == 0)
		{
			break;
		}
		write(pfd, buf, N); 	
	}
	close(pfd);
	return 0;
}