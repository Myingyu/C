#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[2][3] = {
		{1, 4, 6},
		{12, 9, 7}
	};

	int * p [2] = {a[0], a[1]};
	// p = a

	printf("%d\n", a[0][1]);
	// 4
	printf("%d\n", *(a[0]+1) );
	// 4
	printf("%d\n", *(p[0]+1));
	// 4
	printf("%d\n", *(p[1]-1));
	// 6
	printf("%d\n", *(p[0]+5));
	int sum = 0;

	int * * q;
	q = p;
	printf("%d\n", **(q+1));
	printf("%d\n", *( *(q) +1 ) );

	int m = 10;
	int * j = &m;
	int ** k = &j;

	printf("%p, %p\n", j, &m);
	printf("%p, %p\n", k, &j);
	printf("%p\n", &k);

	return 0;
}