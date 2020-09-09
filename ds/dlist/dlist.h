#include <stdlib.h>
#include <stdio.h>

#ifndef _DLIST_H_
#define _DLIST_H_ 
typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * prior;
	struct node * next;
}dlistnode;

dlistnode * dlist_create();
void dlist_show(dlistnode * H);
void dlist_insert(dlistnode * H, datatype value);




#endif