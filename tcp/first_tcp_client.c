#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>


#define SERV_PORT 5001
#define SERV_IP_ADDR "192.168.1.120"
#define BACKLOG 5
#define BUFSIZE 64


int main(int argc, char const *argv[])
{
	int fd = -1;
	struct sockaddr_in sin;
	// 1. 创建fd
	if( (fd = socket(AF_INET, SOCK_STREAM, 0) )== -1){
		perror("socket");
		exit(-1);
	}

	// 2. 绑定
	// 2.1 填充struct sockaddr_in
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	if(inet_pton(AF_INET, SERV_IP_ADDR, (void *)&sin.sin_addr.s_addr) < 1){
		perror("inet_pton");
		exit(-1);
	}

	if ( connect(fd, (struct sockaddr *)&sin, sizeof(sin) ) == -1 ){
		perror("connect");
		exit(-1);
	}

	// 3. 读写数据
	char buf[BUFSIZE];
	while(1){
		bzero(buf, BUFSIZE);
		if ( fgets(buf, BUFSIZE-1, stdin) == NULL){
			perror("fgets");
			exit(-1);
		}
		if ( !strncasecmp(buf, "quit", strlen(buf)) ){
			printf("client is exiting!\n");
			break;
		}
		write(fd, buf, strlen(buf));
	}


	return 0;
}




