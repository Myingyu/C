#include "linkqueue.h"
linkqueue* create_queue(void){
	linkqueue * q;
	linknode * p;
	if ( (q = (linkqueue*)malloc(sizeof(linkqueue))) == NULL){
		printf("create_list: malloc failed\n");
		return NULL;
	}
	if ( (p = (linknode*)malloc(sizeof(linknode))) == NULL){
		printf("create_list: malloc failed\n");
		return NULL;
	}
	p->data = 0;
	p->next = NULL;
	q->front =p;
	q->rear = p;

	return q;
}
int insert_list(datatype value, linkqueue* q){
	linknode * p;
	if ( (p = (linknode*)malloc(sizeof(linknode))) == NULL){
		printf("insert_list: malloc failed!\n");
		return 0;
	}
	p->data = value;
	p->next = NULL;
	q->rear->next = p;
	q->rear = q->rear->next;

	return 1;
}
int is_empty_list(linkqueue *q){
	return(q->front->next == NULL ? 1:0); //返回：1为空，0位非空
}
int out_list(linkqueue* q, datatype* D){
	if (is_empty_list(q)){
		printf("empty list\n");
		return 0;
	}
	linknode* 	leaver;
	leaver = q->front->next;
	q->front->next = leaver->next;
	*D = leaver->data;
	free(leaver);
	leaver = NULL;
	return 1;
}

void show_list(linkqueue* q){
	linknode* p;
	p = q->front;
	while(p->next){
		printf("%c\n", p->next->data->data);
		p = p->next;
	}

}



