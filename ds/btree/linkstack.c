#include "linkstack.h"

link_stack* InitStack(void){
	link_stack* pStack;
	if ( (pStack = (link_stack*)malloc(sizeof(link_stack))) == NULL ){
		printf("malloc failed !\n");
		return NULL;
	}

	pStack->top = pStack->bottom = NULL;
	pStack->height = 0;
	return pStack;
}
void LinkstackPop(link_stack* pStack, datatype_ls *D){
	stack_node *Second;
	if (IsStackEmpty(pStack) ){
	 	printf("Stack is empty\n");
	 	return;
	 }
	 if (pStack->top->next == NULL ){
	 	*D = pStack->top->data;
	 	free(pStack->top);
	 	pStack->top = pStack->bottom = NULL;
	 	pStack->height--;
	 	printf("最后一个元素出栈: %c\n", *D);
	 	return;	
	 }
	 *D = pStack->top->data;
	 Second = pStack->top->next;
	 free(pStack->top);
	 pStack->top = Second;
	 pStack->height--;
	 printf("正常出栈: %c\n",*D);
	 return;
}


void LinkstackPush(datatype_ls value, link_stack* pStack){
	stack_node * temp;
	if ( (temp = (stack_node*)malloc(sizeof(stack_node))) == NULL){
		printf("malloc failed\n");
		return;
	}
	temp->next = pStack->top;
	pStack->top = temp;
	pStack->top->data = value;
	pStack->height++;
	return;



}
int IsStackEmpty(link_stack * pStack){
	if ( pStack->height == 0){
		return 1;
	}else{
		return 0;
	}
}

void DisplayStack(link_stack* pStack){
	if ( IsStackEmpty(pStack)){
		printf("stack is empty!\n");
		return;
	}
	while(pStack->top != NULL){
		printf("%c", pStack->top->data);
		pStack->top = pStack->top->next;
	}
	printf("\n");
}







