#include "linklist.h"

listnode* create_list(datatype value){
	listnode*  H;
	if ( (H = (listnode*)malloc(sizeof(listnode))) == NULL){
		printf("create_list : malloc failed\n");
		return NULL;
	}
	H->data = value;
	H->next = H;
	return H;
}

void list_insert(listnode* H, datatype value){
	listnode *p, *t;
	if ( (p = (listnode*)malloc(sizeof(listnode))) == NULL){
		printf("list_insert: malloc failed\n");
		return;
	}
	t = H;
	while(t->next != H){
		t = t->next;
	}
	p->data = value;
	t->next = p;
	p->next = H;
	return;
}

void list_show(listnode *H){
	listnode *p;
	p = H;
	do{
		printf("%d\n", p->data);
		p = p->next;
	}while(p->next != H->next);

	return;
}

// m 为起点，k为步长
void list_solver(listnode * H, int m, int k){

	listnode *leaver;

	for (int i = 1; i < m; i++){
		H = H->next;
	}
	printf("start at: %d\n", H->data);
	while(H != H->next){

		for (int i = 1; i < k; i++){
			H = H->next;
		}
		leaver = H->next;
		H->next = leaver->next;

		printf("%d, next: %d, next->next: %d\n", leaver->data, leaver->next->data,leaver->next->next->data);
		free(leaver);
		leaver = NULL;
	}

	printf("---%d---\n", H->data);
	printf("---%d---\n", H->next->data);
	// list_show(H);
	// free(p);
	// p = NULL;
	return;
}

// // m 为起点，k为步长
// void list_solver(listnode * H, int m, int k){

// 	listnode * p, *leaver;

// 	p = H;
// 	for (int i = 1; i < m; i++){
// 		p = p->next;
// 	}
// 	printf("start at: %d\n", p->data);
// 	while(p != p->next){

// 		for (int i = 1; i < k; i++){
// 			p = p->next;
// 		}
// 		leaver = p->next;
// 		p->next = leaver->next;

// 		printf("%d\n", leaver->data);
// 		free(leaver);
// 		leaver = NULL;
// 	}
// 	printf("---%d---\n", p->data);
// 	printf("---%d---\n", p->next->data);
// 	// list_show(H);


// 	// free(p);
// 	// p = NULL;
// 	return;
// }




