#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int main(int argc, char const *argv[])
{
	link_stack *pStack;
	datatype_ls D;
	pStack = InitStack();
	LinkstackPush('1', pStack);
	LinkstackPush('2',pStack);
	LinkstackPush('c',pStack);
	// DisplayStack(pStack);

	LinkstackPop(pStack, &D);
	printf("%c\n", D);
	LinkstackPop(pStack, &D);
	printf("%c\n", D);
	LinkstackPop(pStack, &D);
	// printf("%c\n", D);
	// LinkstackPop(pStack, &D);
	// printf("%c\n", *D);
	// LinkstackPop(pStack, &D);
	// printf("%c\n", *D);



	return 0;
}	