#ifndef _LINKQUEUE_
#define _LINKQUEUE_ 
#include <stdlib.h>
#include <stdio.h>


typedef int datatype;

typedef struct node{
	datatype data;
	struct node * next;
}linknode;

typedef struct {
	linknode * front, *rear;
}linkqueue;

linkqueue* create_list(void);
int insert_list(datatype value, linkqueue* q);
int is_empty_list(linkqueue *q);
void show_list(linkqueue* q);
int out_list(linkqueue* q, datatype* D);

#endif

