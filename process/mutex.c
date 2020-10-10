#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


unsigned int value1, value2, count;
pthread_mutex_t lock;

void *function(void * arg);

int main(int argc, char const *argv[])
{
	pthread_t a_thread;

	if ( pthread_mutex_init(&lock, NULL)!= 0 )
	{
		perror("mute init failed!");
		exit(-1);
	}
	if ( pthread_creat(&a_thread, NULL, function, NULL) != 0 )
	{
		printf("failed to pthread_creat!\n");
		exit(-1);
	}
	while(1){
		count++;
		#ifdef _LOCK_
		pthread_muex_lock(&lock);
		#endif
		value1 = count;
		value2 = count;
		#ifdef _LOCK_
		pthread_muex_unnlock(&lock);
		#endif
	}
	return 0;
}

void *function(void *arg){
	while(1){
		#ifdef _LOCK_
		pthread_muex_lock(&lock);
		#endif
		if (value1 != value2)
		{
			printf("value1 = %u, value2 =%u\n",value1,value2 );
			usleep(10000);
		}
		#ifdef _LOCK_
		pthread_muex_unnlock(&lock);
		#endif
	}
	return NULL;
}









