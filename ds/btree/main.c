#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(int argc, char const *argv[])
{
	btree_node * t;
	 // t = create_list();
	create_in_list(&t);
	// printf("先序遍历: ");
	// pre_order(t);
	// printf("\n");
	// stack_pre_order(t);
	// printf("\n");
	printf("中序遍历: ");
	mid_order(t);
	printf("\n");
	// stack_mid_order(t);

	// printf("\n");
	// printf("后序遍历: ");
	// stack_post_order(t);
	printf("\n");
	printf("等级遍历：\n");
	level_order(t);



	return 0;
} 