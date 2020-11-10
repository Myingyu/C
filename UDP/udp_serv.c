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
	sin.sin_port = htonl(SERV_PORT);
	//填充客户端 结构体
	struct sockaddr_in cin;
	cin.sin_family = AF_INET;
	cin.sin_port = htonl(CLIENT_PORT);


	if(inet_pton(AF_INET, SERV_IP_ADDR, (void*)&sin.sin_addr.s_addr) != 1){
		perror("inet_pton failed!");
		exit(1);
	}
	if(inet_pton(AF_INET, CLIENT_IP_ADDR, (void*)&cin.sin_addr.s_addr) != 1){
		perror("inet_pton failed!");
		exit(1);
	}
	if(bind(sockfd , (struct sockaddr*)&sin, sizeof(sin)) != 0){
		perror("bind");
		exit(1);
	ß

	char buf[BUFSIZE];
	socklen_t sin_addrlen = sizeof(sin);
	socklen_t cin_addrlen = sizeof(cin);
	while(1){

		recvfrom(sockfd, buf, BUFSIZE-1, MSG_DONTWAIT, (struct sockaddr*)&cin, sin_addrlen);
		printf("receiving: %s\n", buf);
		sendto(sockfd, buf, BUFSIZE-1, MSG_DONTWAIT, (struct sockaddr*)&sin, sin_addrlen);
	}

	return 0;
}