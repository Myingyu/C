#include <stdio.h>
int fib (int n);

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 11; i++)
	{
		printf("%d, ", fib(i));
	}
	
	return 0;
}

int fib(int n){
	if (n == 1 || n ==2)
	{
		return 1;//此处
	}
	return fib(n-1) + fib(n-2);
} 