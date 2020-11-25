#include "net.h"


void *dataTransfer(void* arg_fd);
int main(int argc, char const *argv[])
{
	int sockfd;
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket!");
		exit(-1);
	}
	//创建服务器网络结构体
	char serv_ipv4_addr[16];
	struct sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = INADDR_ANY;
	// inet_pton(AF_INET, SERV_IP_ADDR, &sin.sin_addr.s_addr);
	int b_reuse = 1;
	//允许发送广播数据包
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &b_reuse, sizeof(b_reuse));

	socklen_t addr_len = sizeof(sin);
	if ( bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) ==-1){
		perror("bind");
		exit(-1);
	}

	listen(sockfd, BACKLOG);
	inet_ntop(AF_INET, (void *)&sin.sin_addr.s_addr, serv_ipv4_addr, sizeof(sin));
	printf("Server %s : %d  is built up!\n", serv_ipv4_addr, ntohs(sin.sin_port));


	int accept_fd;




	struct sockaddr_in cin;
	bzero(&cin, sizeof(cin));
  	cin.sin_family =AF_INET;

	
	char client_ipv4_addr[16];
	while(1){
		bzero(client_ipv4_addr, sizeof(client_ipv4_addr));

		if ( (accept_fd = accept(sockfd, (struct sockaddr*)&cin, &addr_len)) == -1){
			perror("accpet");
			exit(-1);
		}


		inet_ntop(AF_INET, (void *)&cin.sin_addr.s_addr, client_ipv4_addr, addr_len);
		printf("ACCEPT  New Client is connected %s:%d \n", client_ipv4_addr, ntohs(cin.sin_port));

		pthread_t sock_thread;
		pthread_create(&sock_thread, NULL, dataTransfer, (void *)&accept_fd);

		// read(accept_fd, buf, BUFSIZE-1);


	}


	close(sockfd);
	

	return 0;
}

void *dataTransfer(void* arg_fd){
	int accept_fd = *(int *)arg_fd;
	int ret = -1;
	char buf[BUFSIZE];

	while(1){
		bzero(buf, BUFSIZE-1);
		do{
			if((ret = read(accept_fd, buf, BUFSIZE-1)) == -1){
				perror("read");
				exit(-1);
			}
			if(strlen(buf) == 0){
				goto disconnect;
			}

			printf("From ACFD %d: %s", accept_fd,buf);

		}while(ret > 0 && EINTR == errno);

	}

disconnect:
	printf("ACFD: %d disconnect\n", accept_fd);
	close(accept_fd);

	return 0;


}


