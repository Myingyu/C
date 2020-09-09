#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char ch1[] = "Hello World!";
	char ch2[] = "Hello World!";

	char * p;
	p = ch1;
	if (isalpha(*p))
	{
		if (isupper(*p))
		{
			*p = tolower(*p);
		}
	}

	printf("%s\n", p);

	char * p1 ="Hello World";
	char * p2 ="Hello";

	printf("%d\n", sizeof(p1));
	printf("%d\n", strlen(p1));

	printf("%p, %s\n", p1, p1);
	printf("%p, %s\n", p2, p2);




	return 0;
}