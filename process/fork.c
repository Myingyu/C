#include <stdio.h>
#include <unistd.h>





int main(int argc, char const *argv[])
{
	pid_t pid;
	if ( (pid = fork()) < 0)
	{
		perror("fork");
		return -1;
	}else if ( pid == 0 )
	{
		printf("chlid process: my pid %d\n", getpid());
		/* code */
	}else{
		printf("parent process: my pid %d\n",getpid());
	}
	while(1){
		sleep(10);

	}
	/* code */
	return 0;
}