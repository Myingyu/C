#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	seqqueue* q;
	datatype out;

	q = init_seqqueue();
	if ( !insert_seqqueue(0, q)){
		printf("insert failed: 0\n");
	}
	show_seqqueue(q);
	if ( !insert_seqqueue(1, q)){
		printf("insert failed: 1\n");
	}

	if ( !insert_seqqueue(2, q)){
		printf("insert failed: 2\n");
	}
	if ( !insert_seqqueue(3, q)){
		printf("insert failed: 3\n");
	}
	if ( !insert_seqqueue(4, q)){
		printf("insert failed: 4\n");
	}

	if ( !insert_seqqueue(5, q)){
		printf("insert failed: 5\n");
	}

	show_seqqueue(q);

	
	return 0;
}