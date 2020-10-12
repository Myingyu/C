#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
//消息的格式
typedef struct {
	long mtype;
	char mtext[64];
}MSG;

#define LEN (sizeof(MSG) - sizeof(long)) //正文消息长度


int main(int argc, char const *argv[])
{
	int msgid;
	key_t key;
	int shmid;

	MSG buf;
	buf.mtype = 100;

	//生成key
	if ( key=ftok(".", 'm') == -1 ){
		perror("ftok");exit(-1);
	}
	//创建私有内存
	if ( shmid = shmget(key, 1024, IPC_CREAT|06666) < 0 )
	{
		perror("shmget error!");exit(-1);
	}

	if ( (msgid = msgget(key, IPC_CREAT|0666)) == -1)
	{
		perror("msgget failed");exit(-1);
	}
	if ( msgrcv(msgid, &buf, LEN, 0)  == -1 )
	{
		perror("msgrcv failed");exit(-1);
	}

	printf("received message: %s\n", buf.mtext);






	return 0;
}
