#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a [3][2] = {
		{1,6},
		{9,12},
		{61,12}
	};

	int n = sizeof(a)/sizeof(int);
	printf("n: %d\n", n);

	int * p , i;
	n = sizeof(a) / sizeof(int);

	//p = a ,会报错。
	p = a[0];

	for(int i = 0; i < n; ++i)
	
		printf("%d\n", *(p+i))  ;
	







	return 0;
}