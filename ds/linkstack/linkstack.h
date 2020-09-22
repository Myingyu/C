#ifndef _LINKSTACK_H
#define _LINKSTACK_H 
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

typedef char datatype_ls;

typedef struct linknode{
	datatype_ls data;
	struct linknode *next;
}stack_node;

typedef struct linkstack
{
	stack_node *top;
	stack_node *bottom;
	int height;
	
}link_stack;


link_stack* InitStack(void);
void LinkstackPop(link_stack* pStack, datatype_ls *D); //出栈
void LinkstackPush(datatype_ls value, link_stack* pStack);
int IsStackEmpty(link_stack * pStack);
void DisplayStack(link_stack* pStack);
#endif