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


int main(void)
{
	int msgid;
	key_t key;
	int shmid;

	MSG buf;
	buf.mtype = 200;
	fgets(buf.mtext, 64, stdin);
	//生成key
	if ( (key=ftok(".", 'm')) == -1 ){
		perror("ftok");exit(-1);
	}
	//消息队列创建
	if( (msgid = msgget(key, IPC_CREAT|0666) == -1 )){
		printf("msgget failed!\n");exit(-1);
	}
	if ( msgsnd(msgid, &buf,LEN,0) ==-1 )
	{
		perror("msgsnd failed");exit(-1);
	}

	printf("send message: %s\n", buf.mtext);

	return 0;
}