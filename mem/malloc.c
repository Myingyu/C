#include <stdio.h>
#include <stdlib.h>

char * get_string(){
	//char s[] = "welcome"; //编译不会报错，运行出现乱码。因为函数放在栈内存上，当函数执行完毕时，函数内的局部变量会销毁
	//static char * s[] = "welcome";// 静态变量 存在与程序的时间相同，这样内存的利用率不高，浪费资源
	//char * s = "welcome" // 指针常量，后面无法对内容进行修改，
	char * s;

	s = (char *)malloc(10 * sizeof(char));
	if (s == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	printf("input: \n");
	scanf("%s",s);
	return s;
}


int main(int argc, char const *argv[])
{
	char * p;
	p = get_string();
	printf("%s\n", p);

	free(p);
	p = NULL;
	return 0;
}