#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upperco(char * , int *);
int main(int argc, char const *argv[])
{
	char s[]  = "heLLo";
	char c[] ="";

	char * p = s;
	int num = 0;

	upperco(p, &num);


	printf("%s,%d\n", s, num);


	return 0;
}

void upperco(char * charset, int * count)
{
	int length = strlen(charset);
	
	for (int i = 0; i < length; i++)
	{
		if (islower(*charset))
		{
			(*count)++;
			// printf("count : %d\n", *count);
			*charset = toupper(*charset);
		}
		charset++;
	}
}






