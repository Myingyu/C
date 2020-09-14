#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__ 
	
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
#define MAXSIZE 7

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front, rear;
}seqqueue;

seqqueue* init_seqqueue(void);
bool insert_seqqueue(datatype data, seqqueue* q);

bool insert_seqqueue(datatype data, seqqueue* q);
bool is_full_seqqueue(seqqueue* q);
bool is_empty_seqqueue(seqqueue* q);
bool out_seqqueue(seqqueue* q, datatype *D);
void show_seqqueue(seqqueue* q);
#endif