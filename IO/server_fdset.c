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

	pid_t readproc;

	while(1){
		bzero(client_ipv4_addr, sizeof(client_ipv4_addr));

		if ( (accept_fd = accept(sockfd, (struct sockaddr*)&cin, &addr_len)) == -1){
			perror("accpet");
			exit(-1);
		}

		readproc = fork();
		if ( readproc < 0)
		{
			perror("read fork");
			exit(-1);
		}else if ( readproc = 0)
		{
			//子进程客户端
			inet_ntop(AF_INET, (void *)&cin.sin_addr.s_addr, client_ipv4_addr, addr_len);
			printf("ACCEPT  New Client is connected %s:%d \n", client_ipv4_addr, ntohs(cin.sin_port));
			dataTransfer(&accept_fd);
			return 0;
		}



	}


	close(sockfd);
	

	return 0;
}

void *dataTransfer(void* arg_fd){
	int accept_fd = *(int *)arg_fd;
	int ret = -1;
	char buf[BUFSIZE];
	char res_buf[BUFSIZE+10];

	while(1){

		//读客户端
		bzero(buf, BUFSIZE);
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

		//写入客户端
		bzero(res_buf,BUFSIZE+10);
		strncpy(res_buf, SERV_RESP_STR, strlen(SERV_RESP_STR));
		strcat(res_buf, buf);
		do{
			read(stdin, buf, BUFSIZE-1);
			if((ret = write(accept_fd, res_buf, BUFSIZE-1)) == -1){
				perror("read"); 
				exit(-1);
			}
			if( ret == 0){
				goto  disconnect;
			}

			// printf("From ACFD %d: %s", accept_fd,buf);

		}while(ret > 0 && EINTR == errno);




	}

disconnect:
	printf("ACFD: %d disconnect\n", accept_fd);
	close(accept_fd);

	return 0;


}


