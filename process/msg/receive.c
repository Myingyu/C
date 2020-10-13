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

#define M_TYPEA 100
#define M_TYPEB 200


int main(int argc, char const *argv[])
{
	int msgid;
	key_t key;
	int shmid;

	MSG buf;


	//生成key
	if ( (key=ftok(".", 'q')) == -1 ){
		perror("ftok");exit(-1);
	}

	if ( (msgid = msgget(key, IPC_CREAT|0666)) == -1)
	{
		perror("msgget failed");exit(-1);
	}

	while(1){	
		buf.mtype = M_TYPEB
		if ( msgrcv(msgid, &buf, LEN, M_TYPEB, 0)  == -1 ){
				perror("msgrcv failed");exit(-1);
			}
	
		printf("received message: %s\n", buf.mtext);
		buf.mtype = M_TYPEA;
		fgets(buf.mtext, 64, stdin);
		msgsnd(msgid, &buf, LEN, 0);
	}





	return 0;
}
