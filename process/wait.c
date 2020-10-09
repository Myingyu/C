#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	int status;
	pid_t pid;
	if ( (pid = fork() ) < 0){
		perror("fork");
		exit(-1);
	}
	else if ( pid == 0)
	{
		sleep(1);
		exit(2);
	}
	else{
		wait(&status);
		printf("%x\n", status);
	}
	
	return 0;
}



