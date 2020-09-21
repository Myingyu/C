#ifndef _LINKSTACK_H
#define _LINKSTACK_H 
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

typedef char datatype_ls

typedef struct linkstack{
	datatype_ls data;
	struct linkstackt next;
}link_stack;

void init_linkstack(link_stack* Top);
int push_linkstack(datatype_ls value, link_stack Top);
int is_stack_empty(sqstack *Top);
sqstack* del_stack(sqstack * Top);
void show_stack(sqstack *Top);
#endif