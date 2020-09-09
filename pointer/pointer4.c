#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[] = { 1, 6, 9, 12, 42, 32, 4, 29};

	int *p, * q;

	int count = sizeof(a) /sizeof(int);

	p = a;
	q = &a[count-1];

	while( p < q){
		int t = *p;
		*p = *q;
		* q = t;
		p++;
		q--;
	}
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", a[i]);
		/* code */
	}


	return 0;
}