// 无名管道


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>

int main(void)
{
	pid_t pid1, pid2;
	char buf[32];

	int pfd[2];
	if ( pipe(pfd) < 0 )
	{
		perror("pipe");
		exit(-1);
	}
	if ( (pid1 = fork()) < 0 )
	{
		perror("fork");exit(-1);
	}else if (  pid1 == 0 )
	{
		//子进程1
		strcpy(buf, "Im process_1");
		write(pfd[1], buf, 32);
		exit(0);
	}else{
		//父进程
		if ( (pid2 = fork() ) < 0 )
		{
			perror("fork");exit(-1);
		}
		else if ( pid2 == 0 ){
			//子进程2
			sleep(10);
			strcpy(buf, "Im process_2");
			write(pfd[1], buf, 32);
		}else{
			wait( NULL );
			read(pfd[0], buf, 32);
			printf("%s\n", buf);
			wait( NULL );
			read(pfd[0], buf, 32);
			printf("%s\n", buf);
		}

	}
	
	return 0;
}