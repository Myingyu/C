#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//消息的格式
typedef struct {
	long mtype;
	char mtext[64];
}MSG;

#define LEN (sizeof(MSG) - sizeof(long)) //正文消息长度

#define M_TYPEA 100
#define M_TYPEB 200

void *send_function(void *arg);
void *receive_function(void *arg);


int main(int argc, char const *argv[])
{
	pid_t pid_send;
	pid_t pid_receive;
	int msgid;
	key_t key;

	if ( (pid_send = fork()) < 0){
		perror("pid_send fork");exit(-1);
	}
	if ( (pid_receive = fork()) < 0){
		perror("pid_receive received"); exit(-1);
	}
	if ( (key=ftok("./", 'q')) == -1){
		perror("ftok");exit(-1);
	}
	if ( (msgid=msgget(key, IPC_CREAT|0666)) < 0){
		printf("msgget failed! \n");exit(-1);
	}

	if ( pid_send == 0){
		// 发送进程
		MSG buf;

		while(1){
			buf.mtype = M_TYPEB;
			fgets(buf.mtext, 64, stdin);
			if ( msgsnd(msgid, &buf, LEN, 0) == -1 ){
				perror("msgsnd failed"); exit(-1);
			}
		}
	}	
	if ( pid_receive == 0){
		MSG buf;

		while(1){
			msgrcv(msgid, &buf, LEN, M_TYPEA, 0);
			printf("received message: %s", buf.mtext);
			
		}

	}
	while(1){
		sleep(1);
	}
	return 0;
}
