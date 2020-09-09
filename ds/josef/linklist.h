#include <stdio.h>
#include <stdlib.h>

#ifndef _single_linklist_h
#define _single_linklist_h 

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * next;

}listnode;

listnode* create_list(datatype value);
void list_insert(listnode* H, datatype value);
void list_show(listnode *H);
void list_solver(listnode * H, int m, int k);
#endif

