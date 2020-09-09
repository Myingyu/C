#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main(int argc, char const *argv[])
{
	listnode n1,*p, *H;
	int pos;
	int n = 3;


	n1.data =10;
	n1.next = NULL;

	p = &n1;
	p -> data = 20;


	H = list_create();
	// printf("data:%d, next: %d\n", p->data, * (p->next) ); 
	list_head_insert(H,91);	 
	list_head_insert(H,13);
	list_head_insert(H,12);


	list_tail_insert(H,24);	
	list_tail_insert(H,26);
	list_tail_insert(H,25);
	// p = list_create2();
	list_show(H);

	printf("n:%d, isdigit(n): %d\n", n, isdigit(n));

	if ( (p = list_get(H, n)) !=NULL )
	{
		printf("at post[%d]node data: %d\n",n, p->data );
	}

	pos = list_locate(H, 11 );
	printf("%d\n",pos );

	list_insert(H, 6, 42);
	list_show(H);

	list_order_insert(H,10);
	list_order_insert(H,20);
	list_order_insert(H,30);
	list_sort(H);
	printf("after sort:\n");
	list_show(H);


	return 0;
}