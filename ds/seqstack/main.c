#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

int main(int argc, char const *argv[]){ 
	sqstack * s;
	int n = 4;
	s = create_list(n);

	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);
	stack_push(s, 40);
	while(!is_stack_empty(s)){
		printf("%d\n", stack_pop(s));
	}
	printf("--------------------------\n");
	return 0;
}