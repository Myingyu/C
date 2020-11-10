#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_IP_ADDR "192.168.1.8"
#define SERV_PORT 50002

#define CLIENT_IP_ADDR "192.168.1.8"
#define CLIENT_PORT 50010

#define BUFSIZE 64