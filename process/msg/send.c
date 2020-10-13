#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//消息的格式
typedef struct {
	long mtype;
	char mtext[64];
}MSG;

#define LEN (sizeof(MSG) - sizeof(long)) //正文消息长度

#define M_TYPEA 100
#define M_TYPEB 200


int main(void)
{
	int msgid;
	key_t key;
	int shmid;

	MSG buf;

	//生成key
	if ( (key=ftok("./", 'q')) == -1 ){
		perror("ftok");exit(-1);
	}

	//消息队列创建
	if( (msgid = msgget(key, IPC_CREAT|0666)) < 0 ){
		printf("msgget failed!\n");exit(-1);
	}
	while(1){	
		buf.mtype = 100; // 发送消息
		fgets(buf.mtext, 64, stdin);

		if ( msgsnd(msgid, &buf, LEN, 0) == -1 ){
			perror("msgsnd failed");exit(-1);
		}
		printf("send message: %s", buf.mtext);
		//接受消息
		buf.mtype = M_TYPEA;
		msgrcv(msgid, &buf, LEN, M_TYPEA, 0);
		printf("received message: %s\n", buf.mtext);
	}
	return 0;
}