#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

int main(int argc, char const *argv[]){ 
	seqstack * s;
	int n = 3;
	s = stack_create(n);

	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);
	stack_push(s, 40);
	while(!is_stack_empty){
		printf("%d\n", stack_pop(s));
	}
	return 0;
}