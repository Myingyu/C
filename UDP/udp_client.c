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
	bzero(sin, sizeof(sin));
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

	char buf[BUFSIZE];

	while(1){
		bzero(buf,BUFSIZE);
		fgets(buf, BUFSIZE-1, stdin);
		sendto(sockfd, buf, BUFSIZE-1, 0, (struct sockaddr*)&sin, sizeof(sin));
		// recvfrom(sockfd, buf, BUFSIZE-1, MSG_DONTWAIT, (struct sockaddr*)&cin, sizeof(cin));


	}





	return 0;
}