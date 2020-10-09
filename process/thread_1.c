#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// gcc -o thread_1 thread_1.c -lpthread

void *thread_func(void * arg);
// char message[32] = "Hellow world";

int main(int argc, char const *argv[])
{
	char message[32] = "Hellow world";
	pthread_t a_thread;
	void *result;
	printf("before thread: %s\n", message);

	if ( pthread_create(&a_thread, NULL, thread_func, message) != 0)
	{
		perror("thread_create failed");
		exit(-1);
	}
	pthread_join(a_thread, &result);
	printf("%s\n", result);
	printf("after thread: %s\n", message);

	
	return 0;
}

void *thread_func(void * arg){
	sleep(1);
	strcpy(arg, "marked by thread with argument");
	pthread_exit("message while pthread_exit");
}