#include <stdio.h>

int main(int argc, char const *argv[])
{	
	int m = 10;
	double n = 3.14;

	void * pv1, * pv2;

	pv1 = &m; //pv1 = (void *) &m;

	pv2 = &n; // pv2 = (void * ) &n;
	
	//强制类型转换
	printf("%.2lf, .%.2lf\n",n , *(double *) pv2 );
	printf("%d, .%d\n",m , *(int *) pv1 );

	int a [] = { 5, 9, 1, 6, 9, 10};
	int i, t;

	void *p = a;
	int count = sizeof(a) / sizeof(int);
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", *(int *)p + i );
	}
	return 0;
}