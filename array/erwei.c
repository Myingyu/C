#include <stdio.h>

int main(int argc, char const *argv[])
{
	int data[3][4]={
		{1, 54, 4, 5},
		{2, 9, 34, 3},
		{19, 10, 13, 21}
	};
	int row = 3, col = 4;
	int max, max_i, max_j;
	max = data[0][0];


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col ; j++)
		{
			if (max < data[i][j])
			{
				max = data[i][j];
				max_i = i;
				max_j = j;
			}
		}

	}

	printf("最大值：%d，坐标：%d，%d \n", max, max_i+1, max_j+1);

	return 0;
}