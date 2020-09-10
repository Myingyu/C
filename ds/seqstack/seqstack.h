#include <stdio.h>
#include <stdlib.h>

#ifndef _SQSTACK_H_
#define _SQSTACK_H_ 

typedef int datatype;

typedef struct {
	datatype *data;
	int maxlen;
	int top;
}sqstack;

sqstack* create_list(int len);
int is_stack_empty(sqstack * s);
int is_stack_full(sqstack* s);
int stack_clear(sqstack* s);
int stack_push(sqstack* s, datatype value);
void stack_free(sqstack);



#endif