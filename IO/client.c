#include "net.h"

int main(int argc, char const *argv[])
{
	int sockfd;

	if ( (sockfd =socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
		perror("socket");
	}

	struct sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP_ADDR, &sin.sin_addr.s_addr);
	socklen_t addrlen = sizeof(sin);

	if(connect(sockfd, (struct sockaddr *)&sin, addrlen) == -1){
		perror("connect");
		exit(-1);
	}
	char servipaddr[16];
	inet_ntop(AF_INET, (void *)&sin.sin_addr, servipaddr, sizeof(sin));
	printf("connect with server %s:%d\n", servipaddr, ntohs(sin.sin_port));

	char buf[BUFSIZE];

	while(1){
		bzero(&buf, BUFSIZE-1);
		fgets(buf, BUFSIZE-1, stdin);
		write(sockfd, buf, strlen(buf));
	}
	close(sockfd);





	return 0;
}