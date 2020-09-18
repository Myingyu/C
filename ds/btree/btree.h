#ifndef _BTREE_H_
#define _BTREE_H_ 


#include <stdlib.h>
#include <stdio.h>

typedef char datatype_bt;

typedef struct btreenode{
	datatype_bt data;
	struct btreenode *lchild;
	struct btreenode *rchild;
}btree_node, *btree_pnode;

void pre_order(btree_node* t);

btree_pnode create_list(void);
void create_in_list(btree_node ** T);

#endif





