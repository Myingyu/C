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
#if 0
	while(1){
		bzero(&buf, BUFSIZE-1);
		fgets(buf, BUFSIZE-1, stdin);
		write(sockfd, buf, strlen(buf));
	}
	close(sockfd);
#else
	fd_set rset;
	struct timeval tout;
	int ret = -1;
	tout.tv_sec = 5;
	tout.tv_usec = 0;
	int maxfd = 0;

	while(1){
		FD_ZERO(&rset);
		//标准输入采用的文件描述符是0；
		FD_SET(0, &rset);
		FD_SET(sockfd, &rset);
		maxfd = sockfd;
		select(maxfd+1, &rset, NULL, NULL, &tout);
		if (FD_ISSET(0, &rset)){ // 判断键盘上是否有标准输入
			//读区键盘输入，发送到网络套接字fd
			//...FIXME!
			bzero(buf, BUFSIZE);
			do{
				ret = read(0, buf, BUFSIZE-1);
			}while(ret < 0 && EINTR == errno);

			if ( ret < 0){
				perror("read");
				exit(-1);
			}
	 			if ( write(sockfd, buf, BUFSIZE-1) < 0){
				perror("write to sockfd");
				exit(-1);
			}
		}
		if (FD_ISSET(sockfd, &rset)){ //判断服务器是否有数据发送过来
			bzero(buf, BUFSIZE-1);
			do{
				ret = read(sockfd, buf, BUFSIZE-1);
			}while(ret < 0 && EINTR == errno);

			if (ret == 0){
				printf("服务器断开连接！\n");
				break;
		 	}

			if ( ret < 0){
				perror("read from socket");
				exit(-1);
			}
			
			printf("From Server %s:%d, %s",servipaddr, SERV_PORT, buf);


		}


	}




	close(sockfd);

#endif


	return 0;
}