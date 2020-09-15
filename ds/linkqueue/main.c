#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

int main(int argc, char const *argv[])
{
	linkqueue* Q;
	datatype D;
	Q = create_list();

	insert_list(1, Q);
	insert_list(2, Q);
	insert_list(3, Q);
	insert_list(4, Q);
	insert_list(5, Q);
	insert_list(6, Q);
	insert_list(7, Q);
	insert_list(8, Q);
	insert_list(9, Q);
	insert_list(10, Q);
	show_list(Q);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	printf("out:%d\n", D);
	out_list(Q, &D);
	out_list(Q, &D);
	out_list(Q, &D);
	out_list(Q, &D);
	show_list(Q);

	return 0;
}