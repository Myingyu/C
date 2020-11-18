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
	sin.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP_ADDR, &sin.sin_addr.s_addr);

	socklen_t addr_len = sizeof(sin);
	if ( bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) ==-1){
		perror("bind");
		exit(-1);
	}
	listen(sockfd, BACKLOG);





	char buf[BUFSIZE];
	int accept_fd;




	struct sockaddr_in cin;
	bzero(&cin, sizeof(cin));
	cin.sin_family =AF_INET;

	char serv_ipv4_addr[16];
	char client_ipv4_addr[16];

	if ( (accept_fd = accept(sockfd, (struct sockaddr*)&cin, &addr_len)) == -1){
	perror("accpet");
	exit(-1);
}

	inet_ntop(AF_INET, (void *)&cin.sin_addr.s_addr, serv_ipv4_addr, addr_len);
	printf("Server IP: %s\n", serv_ipv4_addr);



	while(1){
		int ret = -1;
		bzero(buf, BUFSIZE-1);


		do{
			if((ret = read(accept_fd, buf, BUFSIZE-1)) == -1){
				perror("read");
				exit(-1);
			}
		}while(ret > 0 && EINTR == errno);

		inet_ntop(AF_INET, (void *)&sin.sin_addr.s_addr, serv_ipv4_addr, addr_len);
		// inet_ntop(AF_INET, (void *)&cin.sin_addr.s_addr, client_ipv4_addr, sizeof(cin));
		printf("Server IP:%s %d \n", serv_ipv4_addr, ntohs(sin.sin_port));
		printf("Client IP:%s %d \n", client_ipv4_addr, ntohs(cin.sin_port));
		// read(accept_fd, buf, BUFSIZE-1);
		printf("%s", buf);

	}

	close(accept_fd);
	close(sockfd);
	






	return 0;
}