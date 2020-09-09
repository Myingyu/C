#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[10][10]={{0}};
	int count = 10;
	a[0][0] = 1; 
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[i][j] = 1;
			
			/* code */
		}

	}


	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < i+1; j++)
		{
			// printf("%d ", i+j);
			a[i][j] = a[i-1][j]+a[i-1][j-1];
		}
		// printf("\n");
	}


	printf("杨辉三角----------------result-----------------\n");
	for (int i = 0; i < count ; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%-8d  ", a[i][j]);
			/* code */
		}
		printf("\n");
	}
	return 0;
}