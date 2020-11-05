#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>



#define SERV_PORT 5001
#define SERV_IP_ADDR "192.168.1.120"
#define BACKLOG 5
#define BUFSIZE 64


int main(int argc, char const *argv[])
{
	int fd = -1;
	struct sockaddr_in sin;

	//创建fd
	if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket failed!");
		exit(-1);
	}
	//绑定
	// 2.1 填充 struct sockaddr_in 结构体变量
	// sin 结构体清零
	bzero(&sin, sizeof(sin));
	// 优化1 ： 自动识别服务器IP，并且绑定主机IP
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT); // 网络字节序的端口号

	// sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_addr.s_addr = htonl(SERV_IP_ADDR);
#if 0
	sin.sin_addr.s_addr = inet_addr(SER_IP_ADDR);  // 将点分形式的IP地址转换成网络字节序
#else
	// if(inet_pton(AF_INET, SERV_IP_ADDR, &sin.sin_addr.s_addr) < 1 ){
	// 	perror("socket failed!");
	// }
#endif	

	// 2.2 绑定	
	if ( bind(fd, (struct sockaddr *) &sin,sizeof(sin)) == -1 )
	{
		  perror("bind");
		  exit(-1);
	}


	// 3. 调用listen() 把 主动套接字变成被动套接字
	listen(fd, BACKLOG);
	
	char ipv4_addr_serv[16];
	if ( (inet_ntop(AF_INET, (void*)&sin.sin_addr, ipv4_addr_serv,sizeof(sin))) == 0){
		perror("inet_ntop");
	}

	printf("Host %s:%d is build up !\n", ipv4_addr_serv, ntohs(sin.sin_port));



	// 4. 阻塞等待客户端请求连接

	// 优化2.2 通过程序获取刚建立连接的socket的客户端的IP地址和端口号
	int newfd = -1;
#if 1
	struct sockaddr_in cin;
	socklen_t addr_len = sizeof(cin);
	if((newfd = accept(fd, (struct sockaddr*)&cin, &addr_len) ) < 0){
		perror("accept");
		exit(-1);
	}
	char ipv4_addr_client[16];

	if (inet_ntop(AF_INET, (void*)&cin.sin_addr, ipv4_addr_client,sizeof(cin)) == 0){
		perror("inet_ntop");
	}

	printf("Client from %s:%d connected!\n", ipv4_addr_client, ntohs(cin.sin_port));

#else
	if ( (newfd = accept(fd, NULL, NULL)) < 0){
		perror("accept");
		exit(-1);
	}
#endif
	// 5. 读写
	// 与newfd进行数据的读写 
	int ret = -1;
	char buf[BUFSIZE];

	while(1){
		bzero(buf, BUFSIZE);
		do{
			if((ret = read(newfd, buf, BUFSIZE-1)) == -1){
				perror("read");
				exit(-1);
			}
		}while(ret > 0 && EINTR == errno);
		if ( ret < 0){
			perror("read");
			exit(-1);
		}
		if ( !ret ){ //接受到0个字符
 			break;
		}

		printf("Received data: %s", buf);


	}
	printf("client has disconnected!\n");
	
	close(newfd);
	close(fd);







	return 0;
}










