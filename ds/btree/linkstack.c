#include "linkstack.h"


void init_linkstack(link_stack **Top){
	if ((*Top = (link_stack*)malloc(sizeof(link_stack)))  == NULL){
		printf("malloc failed\n");
	}
	*Top->next = NULL;
	return;
}{
int push_linkstack(datatype_ls value, link_stack Top){
	linkstack* new;
	if ( new = (link_stack*)malloc(sizeof(link_stack))){
		printf("malloc failed!\n");
		return 0;
	}
	new->data = value;
	new->next = Top;
	Top = new;

	return 1;
}
int is_stack_empty(sqstack *Top){
	return(Top->next == NULL ? 1:0);

}

sqstack* del_stack(sqstack * Top){
	if ( is_stack_empty(Top) ){
		printf("stack is emputy!\n");
	}
	sqstack* leaver = Top;
	Top = Top->next;
	free(leaver);
	leaver = NULL;
}

void show_stack(sqstack *Top){
	sqstack * printer;
	while(printer->next){
		printf("%c\n", printer->data);
		printer = printer->next;
	}

}




















