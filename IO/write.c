#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define STR_HEAD "Hello"

int main(int argc, char const *argv[])
{
	char buf[20] = "world";
	char buf_read[200];
	int fd;

	if( (fd = open("new1",O_CREAT)) < 0 ){
		perror("open failed!");
	}
	write(fd, buf, strlen(buf));
	read(fd,buf_read,strlen(buf));
	printf("%s\n", buf);
	printf("fd:%d, %s\n", fd, buf_read);




	close(fd);


	return 0;
}