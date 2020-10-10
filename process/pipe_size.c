// 计算无名管道的大小

//MAC OS: 管道大小为64k bytes
//LINUX: 管道大小为64k bytes


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
// #include <wait.h>

int main(void)
{
	int count = 0;
	char buf [1024];
	int pfd[2];
	if ( pipe(pfd) < 0)
	{
		perror("pipe failed!");
		exit(-1);
	}
	while( 1 ){
		write(pfd[1], buf, 1024);
		printf("wrote %dk bytes\n", ++count);
	}

	
	return 0;
}