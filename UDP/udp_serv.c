#include "net.h"

int main(int argc, char const *argv[])
{
	int sockfd;

	if ( (sockfd = socket(AF_INET,SOCK_DGRAM,0)) == -1){
		perror("socket");
		exit(1);
	}
	//填充服务端 结构体
	struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	//填充客户端 结构体
	struct sockaddr_in cin;
	cin.sin_family = AF_INET;



	if(inet_pton(AF_INET, SERV_IP_ADDR, (void*)&sin.sin_addr.s_addr) != 1){
		perror("inet_pton failed!");
		exit(1);
	}
	// if(inet_pton(AF_INET, CLIENT_IP_ADDR, (void*)&cin.sin_addr.s_addr) != 1){
	// 	perror("inet_pton failed!");
	// 	exit(1);
	// }
	if(bind(sockfd , (struct sockaddr*)&sin, sizeof(sin)) != 0){
		perror("bind");
		exit(1);
	}

	char buf[BUFSIZE];
	socklen_t sin_addrlen = sizeof(sin);
	socklen_t cin_addrlen = sizeof(cin);
	char client_ipv4[16];
	while(1){
		bzero(buf, BUFSIZE);
		if(recvfrom(sockfd, buf, BUFSIZE-1, 0, (struct sockaddr*)&cin, &cin_addrlen) < 0){
			perror("recvfrom!");
			continue;
		}
		inet_ntop(AF_INET, (void*)&cin.sin_addr, client_ipv4, cin_addrlen);
		printf("From %s:%d in receiving: %s\n", client_ipv4, ntohs(cin.sin_port),buf);

		sleep(2);
		// sendto(sockfd, buf, BUFSIZE-1, MSG_CMSG_CLOEXEC, (struct sockaddr*)&sin, sin_addrlen);
	}

	return 0;
}