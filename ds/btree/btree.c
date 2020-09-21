#include "btree.h"
#include "linkqueue.h"

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

void mid_order(btree_node* t){
	if (t != NULL){
		//先序遍历左子树
		mid_order(t->lchild);
		//访问根节点
		printf("%c", t->data);
		//先序遍历右子树
		mid_order(t->rchild);
	}
}

void post_order(btree_node* t){
	if (t != NULL){
		//先序遍历左子树
		post_order(t->lchild);
		//先序遍历右子树
		post_order(t->rchild);
		//访问根节点
		printf("%c", t->data);
	}
}

void level_order(btree_node * t){
	linkqueue* q;
	q = create_queue();
	printf("层次排序：");
	while( t != NULL){
		printf("%c", t->data);
		//当T的指针不为空，则入队

		if ( t->lchild != NULL ){
			if(!insert_list(t->lchild, q)){
				printf("insert_list failed\n");
			}
			// show_list(q);
		}
		if (t->rchild != NULL ){
			// printf("rchild: %c\n", t->rchild->data);
			if(!insert_list(t->rchild, q)){
				printf("insert_list failed\n");
			}
			// show_list(q);

		}
		// printf("%c\n", q->front->next->data->data);
		if ( !is_empty_list(q) ){
			// show_list(q);
			out_list(q, &t);
	
		}else{
			// printf("%c%c\n",t->lchild->data, t->rchild->data);
			// out_list(q, &t);
			// printf("else: q\n");
			// show_list(q);
			// printf("else: %c, %c, %c \n", t->data, t->lchild->data, t->rchild->data);
			// // printf("q: %c\n",q->front->next->data->data);
			break; 
		}
	}
	printf("\n");

}


















