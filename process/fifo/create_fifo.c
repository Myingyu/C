/*
	进程A：循环从键盘输入并写入有名管道myfifo，输入quit时退出
	进程B：循环你统计进程A每次写入myfifo的字符串的长度
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define N 32
int main(void){
	if ( mkfifo("myfifo", 0666) < 0 )
	{
		perror("mkfifo");exit(-1);
	}
	printf("fifo was created\n");

	return 0;

}