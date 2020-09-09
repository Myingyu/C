#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct student
{
	int id;
	char name[N];
	float score;
	
}Stu;

Stu * get_info(){

	Stu *p;
	if ( (p = (Stu*) malloc(sizeof(Stu))) == NULL )
	{
		printf("malloc failed\n");
		/* code */
	}
	p->id = 1;
	strcpy(p->name, "Tom");
	p->score = 90;
	return p;
}

int main(int argc, char const *argv[])
{
	Stu * s;

	if ( (s = get_info()) == NULL )
	{
		return 0;
		/* code */
	}
	printf("Student Info: %d, %s, %f\n",s->id, s->name, s->score );
	free(s);
	s = NULL;

	return 0;
}