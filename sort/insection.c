#include <stdio.h>
#include <stdlib.h>


void InsectionSort(int *array,int count);
void show(int * array, int count);
void directInsection(int * array, int count);
void shellsort(int * array, int count);
int quickpass(int a[], int i, int j);
void quicksort(int a[], int low, int high);

int main(int argc, char const *argv[])
{
	int a[8] = {50, 36, 66,76, 95, 12, 25, 36};
	int count = sizeof(a)/sizeof(int);
	show(a, count);
	// shellsort(a, count);
	quicksort(a, 0, count -1);
	// InsectionSort(a, count);
	// directInsection(a, count);
	show(a, count);


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
			// step++;		
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
void shellsort(int * array, int count){
	int i, j, temp;
	int d;
	for ( d = count/2; d > 0; d= d/2){
		for ( i = d; i < count; i++){
			temp = array[i];
			for ( j = i-d; j  >= 0; j = j-d){
				if ( temp < array[j]){
					array[j+d] = array[j];
				}else{
					break;
				}
			}
			array[j+d] = temp;
		}
	}
}
int quickpass(int a[], int i, int j){
	int temp;
	temp = a[i];
	while(i < j){
		//从上界比较
		while(i < j && temp <= a[j]){
			j--;
		}
		//将a[j]交换到左边
		if (i < j){
			a[i] = a[j];
		}
		//从下界比较
		while(i < j && temp >= a[i]){
			i++;
		}
		//将a[i]交换到右边
		if (i < j){
			a[j] = a[i];
		}
	}
	a[i] = temp; //将基准放到最终的位置
	return i; //返回基准的下标
}


void quicksort(int a[], int low, int high){
	int mid;
	if ( low < high){
		mid = quickpass(a, low, high);
		// printf("mid: %d,", mid);
		quicksort(a, low, mid-1);
		quicksort(a, mid+1, high);

	}
}








