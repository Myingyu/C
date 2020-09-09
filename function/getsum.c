#include <stdio.h>
int getsum(int *, int);
int main(int argc, char const *argv[])
{
	int a [] = { 1, 3, 5, 7, 8};
	int count = sizeof(a)/sizeof(int);

	int sum = getsum(a, count);

	printf("%d\n", sum);


	return 0;
}

int getsum(int * data, int count)
{
	int ret = 0;

	for (int i = 0; i < count; i++)
	{
		ret += *data;
		data++;
	}
	return ret;

}