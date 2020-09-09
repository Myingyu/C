#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char ch[100] = "welcome";
	char * p = "hello world";

	int pos = strlen(ch);
	int count = strlen(p);
	printf("pos: %d,count: %d\n", pos, count );

	for (int i = 0; i < count+1; i++)
	{
		ch[pos+i]= *p;
		p++;
	}
	printf("%s\n", ch);


	return 0;
}