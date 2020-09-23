#include "btree.h"
#include "linkqueue.h"
#include "linkstack.h"

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
	// insert_list(t, q);
	// printf("%c", t->data);
	while( t!= NULL ){
		// out_list(q, &t);
		printf("%c", t->data);
		//当T的指针不为空，则入队
		if ( t->lchild != NULL ){
			if(!insert_list(t->lchild, q)){
				printf("insert_list failed\n");
			}
			// printf("lchild:%c\n", t->lchild->data);
			// show_list(q);
		}

		if (t->rchild != NULL ){
			// printf("rchild: %c\n", t->rchild->data);
			if(!insert_list(t->rchild, q)){
				printf("insert_list failed\n");
			}
		}

		// printf("%c\n", q->front->next->data->data);

			// show_list(q);
		if (is_empty_list(q)){
			break;
		}
			out_list(q, &t);
			// printf("%c", t->data);

	};
	if ( t->lchild){
		printf("%c", t->lchild->data);
	}
	if (t->rchild){
		printf("%c", t->rchild->data);
	}
	
	
	
	printf("\n");

}
//先序非递归算法
void stack_pre_order(btree_node* t){
	link_stack *q;
	q = InitStack();
	while( t != NULL || !IsStackEmpty(q)){
		if (t != NULL){
			printf("%c", t->data);
			if (t->rchild != NULL){
				LinkstackPush(t->rchild, q);
			}
			t = t->lchild;
		}else{
			LinkstackPop(q,&t);
		}
	}


	printf("\n");
	return;
}
void stack_mid_order(btree_node* t){
	link_stack *q;
	q = InitStack();

	while( t != NULL || !IsStackEmpty(q)){
		while(t!= NULL){
			LinkstackPush(t, q);
			t = t->lchild;
		}
		if ( !IsStackEmpty(q)){
			LinkstackPop(q, &t);
			printf("%c", t->data);
			t = t->rchild;
		}
	}
	printf("\n");
	return;

}

void stack_post_order(btree_node* t){
	link_stack *q, *s;
	q = s = InitStack();
	while( t != NULL || !IsStackEmpty(q)){

	}
}










