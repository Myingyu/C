#include <stdlib.h>
#include <stdio.h>

int compar(const void *, const void *);
int main(int argc, char const *argv[])
{
	int a[] = { 20, 134, 121, 12, 412, 50};

	int length = sizeof(a) / sizeof(int);
	qsort(a, length, sizeof(int),compar);

	for (int i = 0; i < length; i++)
	{
		printf("%d\n", a[i]);

	}


	return 0;
}

int compar(const void * p, const void * q){
	return *(int *)q - *(int *)p;
}