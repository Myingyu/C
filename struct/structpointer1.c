#include <stdio.h>

struct student
{
	int id;
	char name[20];
	float score;
	
};

int main(int argc, char const *argv[])
{
	int i;
	struct student s1[] = {
		{1, "fist", 90},
		{2, "second", 85},
		{3, "third", 75}
	};
	struct student *p;

	p = s1;
	printf("int: %d, char: %d, flaot: %d\n", sizeof(int), sizeof(char), sizeof(float) );
	printf("%d, %d\n", sizeof(s1), sizeof(struct student) );
	// sizeof(student) = 28, sizeof(s1) = 84
	//不移动指针的写法
	for (int i = 0; i < sizeof(s1)/sizeof(struct student); ++i)
	{
		//printf("%d, %s, %f\n", s1[i].id , s1[i].name, s1[i].score);
		printf("not move pointer: %d, %s, %f\n", (p+i)->id, (p+i)-> name, (p+i)->score);
	}



	//下面写法会移动指针
	for (int i = 0; i < sizeof(s1)/sizeof(struct student); ++i)
	{
		//printf("%d, %s, %f\n", s1[i].id , s1[i].name, s1[i].score);
		printf("pointer: %d, %s, %f\n", p->id, p-> name, (*p).score);
		p++;
	}



	return 0;
}