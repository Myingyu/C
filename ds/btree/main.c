#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(int argc, char const *argv[])
{
	btree_node * t;
	 t = create_list();
	// create_in_list(&t);
	printf("先序遍历\n");
	pre_order(t);
	printf("\n");



	return 0;
}