#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[3][2] = {
		{1, 6},
		{9, 12},
		{61, 12}
	};

	int n = sizeof(a) / sizeof(int);
	int *p;
	p = a[0];

	printf("%d\n", *p);
	printf("%d\n", *(p+1));
	printf("%d\n", a[1]);





	return 0;
}