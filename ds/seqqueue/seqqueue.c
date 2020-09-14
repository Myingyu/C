#include "seqqueue.h"

seqqueue* init_seqqueue(void){
	seqqueue* q;
	if ( (q =(seqqueue*)malloc(sizeof(seqqueue))) == NULL){
		printf("init_seqqueue: malloc failed\n");
		return NULL;
	}
	q->front = MAXSIZE-1;
	q->rear = MAXSIZE-1;
	return q;
}
bool is_full_seqqueue(seqqueue* q){
	return( (q->rear+1) % MAXSIZE == q->front ? 1:0);
}
bool is_empty_seqqueue(seqqueue* q){
	return( q->front == q->rear ? 1:0);
}

bool insert_seqqueue(datatype data, seqqueue* q){
	//判断队列是否已满
	if ( is_full_seqqueue(q) ){
		printf("insert_seqqueue: full！\n");
		return 0;
	}
	//入队
	q->rear = (q->rear+1) % MAXSIZE;
	q->data[q->rear] = data;
	return 1;
}

bool out_seqqueue(seqqueue* q, datatype *D){
	if (is_empty_seqqueue(q)){
		printf("seqqueue already empty!\n");
		return 0;
	}
	//出队
	q->front = (q->front+1) % MAXSIZE;
	* D = q->data[q->front];
	return 1;
}

void show_seqqueue(seqqueue* q){
	if ( is_empty_seqqueue(q) ){
		printf("empty list\n");
		return;
	}
	for (int i = (q->front+1)%MAXSIZE; i != (q->rear+1)%MAXSIZE; i= (i+1)%MAXSIZE){
		printf("%d, ", q->data[i]);
	}
	printf("\n");
	return;
}



