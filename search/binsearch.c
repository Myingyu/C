#include <stdio.h>
#include <stdlib.h>
#define N 12

int binsearch(int *array, int key);

int main(int argc, char const *argv[]){
	int a[N] = {3, 12, 18, 20, 32, 55, 60, 68, 80, 86 , 90, 100};
	int key;
	key = 90;
	int pos = binsearch(a,key);
	printf("pos: %d\n", pos);

	// printf("array size:%lu\n", sizeof(a)/sizeof(int));

	return 0;
}
int binsearch(int *array, int key){
	int low =0; 
	int high = N-1;
	int mid;
	// printf("array size:%lu\n", sizeof(array)/sizeof(int));
	while(low <= high){
		mid = (low + high)/2;
		// printf("mid:%d\n", mid);
		if (key == array[mid]){
			return mid;
			
		}
		if (key > array[mid]){
			low = mid+1;
		}
		if (key < array[mid]){
			high = mid-1;
		}
	}
	printf("not founded\n");
	return -1;
}