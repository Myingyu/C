#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node * next;
}listnode, *linklist;

linklist list_create();
void list_show(linklist H);
int list_head_insert(linklist H, datatype value);
int list_tail_insert(linklist H, datatype value);
linklist list_create2();
linklist list_get(linklist H, int pos);//通过序号查找值
int list_locate(linklist H, datatype value); //通过值查找地址
int list_insert(linklist H, int pos, datatype value);
int list_order_insert(linklist H,datatype value);
void list_sort(linklist H);  
#endif