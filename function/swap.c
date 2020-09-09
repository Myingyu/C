#include <stdio.h>

void swap(int*, int*);

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;

	printf("%d, %d\n", a, b);

	swap(&a, &b);






	printf("%d, %d\n", a, b);




	return 0;
}

void swap(int * x, int * y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}