#include <stdio.h>
#include <ctype.h>
#include <string.h>

void del_space(char *);

int main(int argc, char const *argv[])
{ 
	char s[] = "  2  h   sasdd fs               ";
	char * p = s;
	del_space(p);
	printf("%s\n", s);
	return 0;
}
void del_space(char *str){

	char * p, *q;
	p = str;
	q = str;

	while(*q != '\0'){
		if (isspace(*q))
		{
			q++;
		}
		else{
			p++;
			q++;
		}
		*p = * q;		
	}
};