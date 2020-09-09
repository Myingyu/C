#include "dlist.h"


dlistnode * dlist_create(){
	dlistnode * H;

	if ( (H = (dlistnode *)malloc(sizeof(dlistnode))) == NULL)
	{
		printf("dlist_create malloc failed\n");
		return H;
	}
	H->prior = H;
	H->next = H;
	H->data =0;

	return H;

}

void dlist_show(dlistnode * H){

	dlistnode * p = H;
	while( p->next != H )
	{
		printf("%d\n", p->next->data); //不打印初始值0；
		// printf("%d\n", p->data);//打印初始值为0；
		p = p->next;
	}
	return;
}

void dlist_insert(dlistnode * H, datatype value){
	dlistnode * p, *r;
	r = H;

	if ( (p = (dlistnode *)malloc(sizeof(dlistnode))) == NULL ){
		return;
	}

	while( r->next != H ){
		r = r->next;
	}

	p->data = value;


	p->next = r->next;
	r->next = p;
	p->prior =r;
	r->next->prior= p; // r = p;
	return;
};

