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


#define SERV_IP_ADDR "81.70.145.175"
#define SERV_PORT 50002
#define BACKLOG 5
// #define CLIENT_IP_ADDR "192.168.1.6"
// #define CLIENT_PORT 50010

#define BUFSIZE 64