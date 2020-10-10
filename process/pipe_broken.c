#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


int main(void)
{
	pid_t pid;
	int pfd[2], status;
	char buf[32];
	if ( pipe(pfd) < 0 )
	{
		perror("pipe failed!");exit(-1);
	}
	close(pfd[0]); //关闭读端


	if ( (pid = fork()) < 0)
	{
		perror("fork failed"); exit(-1);
	}else if ( pid == 0)
	{ 	//子进程
		write(pfd[1], buf, 32);
		exit(0);
	}else{
		//父进程
		wait(&status);
		printf("status: %x\n", status);
	}
	return 0;
}