#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
void showdata(int data);
int main(int argc, char const *argv[])
{
	listnode n1;
	listnode *p, *q;

	// linklist p,q; //listnode *p, *q; 另一种写法


	n1.data = 10;
	n1.next = NULL;




	p = &n1;
	p->data = 20;
	showdata(n1.data);
	q = (linklist)malloc(sizeof(listnode));
	q ->data =30;
	q ->next = NULL;
	free(q);
	q = NULL;

	return 0;

}

void showdata(int data)
{
	printf("数据结果\n");
	for (int i = 0; i < sizeof(data); i++)
	{
		printf("%d, ", data[i]);
	}
}