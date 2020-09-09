#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char src[] = "source";
	char dest[10];
	char dest1[10];
	char *pc;
	char s1[10] = "asazxz";
	int ch = 'z';
	char s2[20] = "how are you";
	char sub[6] = "ar";


	printf("strlen(s2): %d\n",strlen(s2) );
	printf("sizeof(s2): %d, sizeof(sub): %d\n", sizeof(s2),sizeof(sub) );

	printf("%p, %p, %d \n", s2, sub,s2-sub );

	printf("sub: %s\n", sub);


	pc = strcpy(dest, src);



	printf("%s\n", dest);

	printf("strlen: %d\n", strlen(dest));

	printf("dest:%p, src: %p, pc: %p\n", dest, src, pc);	

	printf("strncpy: %s\n",strncpy(dest1, src, 3));

	printf("strcat: %s\n", strcat(dest1,dest) );

	printf("dest1: %s, dest: %s , strncmp(dest1, dest, 3): %d\n", dest1, dest, strncmp(dest1, dest, 3) );

	printf("%p, %p, %d \n", s1, strchr(s1, ch), strchr(s1,ch)-s1 );
	printf("%p, %p, %d \n", s1, strrchr(s1, ch), strrchr(s1,ch)-s1 );

	printf("strstr(s2, sub) - s2: %c, %c\n", *strstr(s2, sub), *(strstr(s2, sub)+1) );

	return 0;
}