#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[] = {10, 20 , 30 ,40};

	const int * p; // 指针可以移动，但是值无法改变
	int * const  q = &a[0]; //声明的时候就要赋值，除了声明无法再次赋值。指针无法移动,但是值可以更改



	p = &a[0];

	*q = 11;


	printf("%d\n", *p);
	printf("%d\n", *q);
	printf("p: %p, p++: %p\n", p, p++);
	// printf("q: %p, q++: %p\n", q, q++);

	return 0;
}