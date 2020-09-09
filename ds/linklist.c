#include "linklist.h"

linklist list_create(){
	linklist H;

	if ((H = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed!\n");	
		return H;
	}
	H->data = 0;
	H->next = NULL;
	return H;
}

void list_show(linklist H){
	while(H->next){
		printf("%d, ", H->next->data);
		H = H->next;
	} 
}

int list_head_insert(linklist H, datatype value){

	linklist p;

	if ( (p = (linklist)malloc(sizeof(listnode))) == NULL )
	{
		printf("malloc failed\n");
		/* code */
		return -1;
	}
	p->data = value;
	p->next = H->next;
	H->next = p;  
	return 0;

}