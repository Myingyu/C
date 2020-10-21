#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>


#define N 64
#define READ 0
#define WRITE 1

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *arrar;
	struct seminfo *_buf;
};
void init_sem(int semid, int s[], int n);
void pv_op(int semid, int num, int op);

int main(int argc, char const *argv[])
{
    int semid, shmid, s[]={0,1};
    key_t key;
    pid_t pid;
    char *shmaddr;

    if ( (key=ftok("./", 'p')) == -1 ){
    	perror("ftok");exit(-1);
    }
    //创建共享内存
    if ( (shmid=shmget(key, N, IPC_CREAT|0666))){
    	perror("shmget");exit(-1);
    }
    //创建信号灯集合
	if ( (semid = semget(key, 2, IPC_CREAT|0666|IPC_EXCL)) < 0 ){
		perror("semget");
		goto _erro1;
	}
	init_sem(semid, s, 2);
	if( (shmaddr = (char*)shmat(shmid, NULL, 0)) == (char*) -1){
		perror("shmat");
		goto _erro2;
	}
	_erro1:
	shmctl(semid, IPC_RMID, NULL);
	_erro2:
	semctl(shmid, 0, IPC_RMID);

	//创建子进程
	if ( (pid = fork()) == -1){
		perror("fork");
	}else if(pid == 0){
		//子进程
		char *p, *q;
		while(1){
			 pv_op(semid, READ, -1);
			 p = q =shmaddr;
			 while( *q ){
			 	if ( *q != ' '){
			 		*p++ = *q;
			 	}
			 	q++;
			 } 
			 *p = '\0';
			 printf("%s\n", shmaddr);
			 pv_op(semid, WRITE, 1);
		}


	}
	else{
		//父进程
		while( 1 ){
			//判断缓冲区是否可写
			pv_op(semid, WRITE, -1);
			printf("input > ");
			fgets(shmaddr, N, stdin);
			if(strcmp(shmaddr, "quit\n") == 0){
				break;
			}
			pv_op(semid, READ, 1);

		}
		kill(pid, SIGUSR1);

	}
	return 0;
}

void init_sem(int semid, int s[], int n){
	int i;
	union semun  myun;
	for (int i = 0; i < n; i++){
		myun.val = s[i];
		semctl(semid, i , SETVAL, myun);
	}
}

void pv_op(int semid, int num, int op){
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = 0;
	buf.sem_flg = 0;
	semop(semid, &buf, 1);

}

