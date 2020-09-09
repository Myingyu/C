#include <stdio.h>

int main(int argc, char const *argv[])
{
	char string[10] = "string";

	int num = 1000;
	int b = 120;

	int * p = &num;
	int * q = &b; 

	printf("string: %p, %ld, %c ,%o\n", &string, sizeof(string), string[0],string[0] );

	printf("%d, %p, %ld\n", *p, p, sizeof(p) );

	printf("%d, %p, %p, %d\n", *q, q, q+1, *(q+1) );
	
	printf("%ld\n",p-q );








	return 0;
}