#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char data[]="init";// = {0};

	// gets(data);
	scanf("%s",data);

	// int count1 = sizeof(data)/sizeof(char); count1 = 5 是data定义的size； 
	int count = strlen(data); //strlen(char data[])这里可以输出字符串的正常size。 统计长度遇到\0停止
	printf("%d\n", count1);

	for (int i = count-1; i >= 0; i--)
	{
		putchar(data[i]);

	}
	return 0;
}
