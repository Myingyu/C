#include <stdio.h>

int main(int argc, char const *argv[])
{
	char * s[] = {"apple", "pear", "potato"};
	int i, n;

	i = 0;
	n = sizeof(s)/sizeof(char *);
	printf("%d\n", n);

	char ** pc = s;

	while(i < n){
		printf("%s\n", pc[i]);
		i++;
	}
	return 0;
}