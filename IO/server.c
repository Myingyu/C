#include "net.h"

int main(int argc, char const *argv[])
{
	int sockfd;
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket!");
		exit(-1);
	}
	//创建服务器网络结构体
	struct sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = SERV_PORT;
	inet_pton(AF_INET, SERV_IP_ADDR, &sin.sin_addr.s_addr);

	socklen_t addr_len = sizeof(sin);
	if ( bind(sockfd, (struct sockaddr *)&sin, addr_len)){
		perror("bind");
		exit(-1);
	}
	listen(sockfd, BACKLOG);

	struct sockaddr_in cin;
	bzero(&cin, sizeof(cin));
	cin.sin_family =AF_INET;


	char client_ipv4_addr[16];

	char buf[BUFSIZE];
	int accept_fd;


	while(1){
		bzero(buf, BUFSIZE-1);

		if ( (accept_fd = accept(sockfd, (struct sockaddr*)&sin, &addr_len)) == -1){
			perror("accpet");
			exit(-1);
		}
		inet_ntop(AF_INET, (void *)&cin.sin_addr.s_addr, client_ipv4_addr,addr_len);
		printf("%s\n", client_ipv4_addr);
		
		read(accept_fd, buf, BUFSIZE-1);
		printf("%s", buf);
	}
	






	return 0;
}