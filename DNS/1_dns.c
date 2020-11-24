#include "net.h"

int main(int argc, char const *argv[])
{
	struct hostent *hs = NULL;

	char serv_ip[16];
	inet_ntop(hs->h_addrtype, (void *)&hs->h_addr, serv_ip, hs->h_length);
	printf("IP from gethostbyname: %s\n", serv_ip);


	if((hs = gethostbyname(SERV_DOMAIN)) == NULL){
		herror("gethostbyname");
		exit(-1);
	}
	printf("hs->h_addr: %s\n", hs->h_addr);

	int sockfd = socket(AF_INET,  SOCK_STREAM, 0);

	struct sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = *(uint32_t *)hs->h_addr;

	endhostent();
	hs = NULL;

	if ( connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == -1){
		perror("connect failed!");
		exit(-1);
	}
	char buf[BUFSIZE];
	while(1){
		bzero(buf,BUFSIZE);
		fgets(buf, BUFSIZE-1, stdin);
		write(sockfd, buf, BUFSIZE-1);


	}
	close(sockfd);



	return 0;
}