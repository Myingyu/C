#include "seqstack.h"

sqstack* create_list(int len){
	sqstack* s;

	if( ( s = (sqstack*)malloc(sizeof(sqstack))) == NULL){
		printf("create_list: malloc failed!\n");
		return NULL;
	}
	if ( (s->data = (datatype*)malloc(sizeof(datatype) * len)) == NULL){
		printf("create_list s->data: malloc failed\n");
		return NULL;
	}

	s->maxlen = len;
	s->top = -1;
	return s;
}
int is_stack_empty(sqstack * s){
// 空返回1
	return(s->top == -1? 1:0);
}

int is_stack_full(sqstack* s){
	return(s->top == s->maxlen-1 ? 1:0);

}
void stack_clear(sqstack* s){
	s->top = -1;
}
int stack_push(sqstack* s, datatype value){
	if ( is_stack_full(s) ){
		printf("stack is full\n");
		return -1;
	}
	s->data[s->top+1] = value;
	s->top++;  
	return 0;
}

datatype stack_pop(sqstack * s){
	s->top--;
	return s->data[s->top+1];
}

void stack_free(sqstack* s){
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}








