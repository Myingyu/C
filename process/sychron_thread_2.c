#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

char buf[32];
sem_t sem_w;
sem_t sem_r;
void *function(void *arg);

int main(int argc, char const *argv[])
{
	pthread_t a_thread;


	if ( sem_init(&sem_w,0, 1) < 0 )
	{
		perror("write: sem_init failed");
		exit(-1);
	}
	if ( sem_init(&sem_r,0, 0) < 0 )
	{
		perror("write: sem_init failed");
		exit(-1);
	}
	if ( pthread_create(&a_thread, NULL , function, NULL) != 0)
	{
		perror("pthread_create failed!");
	}
	do{
		sem_post(&sem_w);
		sem_wait(&sem_r);
		fgets(buf, 32, stdin);
		sleep(5);
	}while(strncmp(buf, "quit", 4) != 0);

	return 0;
}

void *function(void * arg){
	while( 1 ){
		sem_wait(&sem_w);
		sem_post(&sem_r);
		printf("your enter %lu characters\n", strlen(buf) );

	}
}












