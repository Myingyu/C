#include "btree.h"

btree_pnode create_list(void){
	btree_node * new;
	datatype_bt ch;
	scanf("%c", &ch);
	if ( ch == '#' ){
		return NULL;
	}
	else{
		if ( (new = (btree_node*)malloc(sizeof(btree_node))) == NULL ){
			perror("malloc");
			exit(1);
		}
		new->data = ch;
		new->lchild = create_list();
		new->rchild = create_list();
		return new;
	}
}

void create_in_list(btree_pnode * T){
	datatype_bt ch;
	scanf("%c", &ch);
	if ( '#' == ch ){
		*T =  NULL;
	}
	else{
		*T = (btree_node*)malloc(sizeof(btree_node));
		if( *T == NULL){
			perror("malloc");
			exit(1);
		}
		(*T)->data = ch;
		create_in_list(&(*T)->lchild);
		create_in_list(&(*T)->rchild);
	}
}

void pre_order(btree_node* t){
	if (t != NULL){
		//访问根节点
		printf("%c", t->data);
		//先序遍历左子树
		pre_order(t->lchild);
		//先序遍历右子树
		pre_order(t->rchild);
	}
}




