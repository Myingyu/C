#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
// 不带锁：编译 gcc -o mutex mutex.c -lpthread
// 带锁：编译 gcc -o mutex mutex.c -lpthread -D_LOCK_


unsigned int value1, value2, count;
pthread_mutex_t lock;

void *function(void * arg);

int main(int argc, char const *argv[])
{
	count = 0;
	pthread_t a_thread;

	if ( pthread_mutex_init(&lock, NULL)!= 0 )
	{
		perror("mute init failed!");
		exit(-1);
	}
	if ( pthread_create(&a_thread, NULL, function, NULL) != 0 )
	{
		printf("failed to pthread_creat!\n");
		exit(-1);
	}
	while(1){
		count++;
		#ifdef _LOCK_
		pthread_mutex_lock(&lock);
		#endif
		value1 = count;
		value2 = count;
		#ifdef _LOCK_
		pthread_mutex_unlock(&lock);
		sleep(2);
		#endif
	}
	return 0;
}

void *function(void *arg){
	while(1){
		#ifdef _LOCK_
		pthread_mutex_lock(&lock);
		#endif

		printf("value1 = %u, value2 = %u\n",value1,value2 );

		#ifdef _LOCK_
		pthread_mutex_unlock(&lock);
		#endif
		sleep(2);
	}
	return NULL;
}

/*
主线程 sleep(2)
副线程 sleep(2)
value1 = 1, value2 = 1
value1 = 2, value2 = 2
value1 = 2, value2 = 2
value1 = 4, value2 = 4
value1 = 5, value2 = 5
value1 = 5, value2 = 5
value1 = 7, value2 = 7
value1 = 8, value2 = 8


*/










