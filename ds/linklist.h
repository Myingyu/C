#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node {
	datatype data;
	struct node * next;
}listnode, *linklist;

extern linklist list_create();
extern void list_show(linklist H);
extern int list_head_insert(linklist H, datatype value);


#endif