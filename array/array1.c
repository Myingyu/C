#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[6]={1, 3, 5}, i ;

	for (int i = 0; i < 6; i++)
	{
		printf("%p %d\n", &a[i], a[i]);
	}
	
	printf("数组a起始地址:%p \n",a);
	printf("数组a长度: %d \n", sizeof(a) );
	return 0;
}

//