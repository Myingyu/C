#include <stdio.h>
#include <stdlib.h>


void InsectionSort(int *array,int count);
void show(int * array, int count);
void directInsection(int * array, int count);

int main(int argc, char const *argv[])
{
	int a[8] = {50, 36, 66,76, 95, 12, 25, 36};
	int count = sizeof(a)/sizeof(int);
	// show(a, count);

	InsectionSort(a, count);
	// directInsection(a, count);
	// show(a, count);


	return 0;
}
void InsectionSort(int *array,int count){
	int step = 0;
	for (int i = 0; i < count; i++){
		for (int j = i+1; j < count; j++){
			if ( array[i] > array[j]){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			// printf("i:%d|",i);
			// show(array, count);
			step++;

		}
		// show(array, count);
	}
	printf("step %d\n", step);
}

void show(int * array, int count){
		for (int i = 0; i < count; i++){
		printf("%d,", array[i]);
	}
	printf("\n");
}

void directInsection(int * array, int count){
	for (int i = 1; i < count; i++){
		int temp = array[i];
		int j;
		for ( j = i-1; j >= 0; j--){
			step++;		
			if ( temp < array[j]){
				array[j+1] = array[j];
			}else{
				break;
			}
		}
		array[j+1] = temp;
		show(array, count);
	}
}








