#include <stdio.h>
int main(int argc, char const *argv[])
{
	int array[] = {97, 38, 76, 49, 13, 27,30};
	
	int count = sizeof(array)/sizeof(int);

	for (int i = 0; i < count; i++)
	{

		for (int j = 0; j < count - i ; j++)
		{
			int temp;
			
			if (array[j] < array[j+1])
			{

				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp; 
				/* code */
			}

		
					/* code */
		}
		// array[count-i-1] = array[j];

	}


	for (int i = 0; i <count; i++)
	{
		printf("%d\n", array[i]);
	}







	return 0;
}