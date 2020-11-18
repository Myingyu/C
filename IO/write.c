#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STR_HEAD "Hello"

int main(int argc, char const *argv[])
{
	char buf[20] = "world";
	int fd;

	if( (fd = open(".",O_CREAT)) < 0 ){
		perror("open failed!");
	}
	write(fd, buf, strlen(buf));

	close(fd);


	return 0;
}