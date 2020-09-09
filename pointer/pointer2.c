#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[5] = {1, 3, 5, 6, 10};
	int b[] = {5, 8, 7, 6, 2, 7, 3};
	// printf("%ld\n", sizeof(int));
	int y, * p = &b[1];

	y = (*--p)++;// ++在后面， y= (*--p)之后再 ++。 先y = b[0]，后b[0]++
	(*p)++;
	printf("%d\n", y);
	printf("%d\n", b[0]);
	return 0;

}