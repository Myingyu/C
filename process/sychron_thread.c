#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

char buf[32];
sem_t sem;
void *function(void *arg);


int main(int argc, char const *argv[])
{
	pthread_t a_thread;
	if ( sem_init(&sem, 0, 0) < 0)
	{
		perror("sem_init");
		exit(-1);
	}
	if ( pthread_create(&a_thread, NULL, function, NULL) != 0)
	{
		perror("pthread_create failed");
		exit(-1);
	}
	do{
		fgets(buf, 32, stdin);
		sleep(5);
		sem_post(&sem);
	}while(strncmp(buf, "quit", 4) != 0);

	
	return 0;
}
void *function(void *arg){
	while(1){
		sleep(5);
		sem_wait(&sem);
		sleep(5);
		printf("your enter %lu characters\n", strlen(buf) );
	}

}
