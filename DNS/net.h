#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/select.h>
#include <netdb.h>


#define SERV_IP_ADDR "222.129.35.58"
#define SERV_DOMAIN	"y3550814l0.qicp.vip"
#define SERV_PORT 50002
#define BACKLOG 5
#define SERV_RESP_STR "Server: "
// #define CLIENT_IP_ADDR "192.168.1.6"
// #define CLIENT_PORT 50010

#define BUFSIZE 128