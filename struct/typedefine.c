#include <stdio.h>

typedef struct node 
{
	int data;
	struct node * next;
	
}listnode, *linklist ;




int main(int argc, char const *argv[])
{
	listnode n1, n2, n3; // listnode = struct node
	linklist p;  // linklist =  struct node *

	n1.data = 10;
	n1.next = n2.data;
	n2.data = 20;
	n2.next = n3.data;
	n3.next = NULL;

	p = &n1;


	/* code */
	return 0;
}