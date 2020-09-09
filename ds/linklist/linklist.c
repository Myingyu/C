#include "linklist.h"

linklist list_create()
{
	linklist H;
	if ( (H = (linklist)malloc(sizeof(listnode))) == NULL )
	{
		printf("malloc failed\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;
	return H;
}

void list_show(linklist H)
{
	while( H->next != NULL)
	{
		printf("%d, %p\n", H->next->data, &H->next->data);
		H = H->next; // 结构体指针往后移动。
	}
	printf("\n");
}

int list_head_insert(linklist H, datatype value)
{
	linklist p;
	if ( (p = malloc(sizeof(listnode))) ==NULL)
	{
		printf("list_head_insert: malloc failed\n");
		/* code */
		return -1;
	}
	p->data = value;
	p->next = H->next;
	H->next = p;
	return 0;
}

int list_tail_insert(linklist H, datatype value)
{
	linklist p, q;
	if ( (p=malloc(sizeof(listnode))) == NULL || (q=malloc(sizeof(listnode))) == NULL)
	{
		printf("list_tail_insert: malloc failed\n");
		/* code */
		return -1;
	}
	q = H;

	while(q->next != NULL)//找到链表最后的那个位置
	{
		q = q->next;

	}
	p->data = value;
	p->next = NULL;

	q->next = p;
	q = p;


	return 0;
}

linklist list_create2()
{
	linklist H, r, p;
	datatype value;
	if ( (H = (linklist)malloc(sizeof(listnode))) == NULL )
		{
			printf("list_create2: malloc failed!\n");
			return H;
		}

	H->data = 0;
	H->next = NULL;

	r = H;


	while(1)
	{
		printf("input a integer! \n");
		scanf("%d", &value);
		if (value ==-1)
		{
			break;
		}
		if ( (p = (linklist)malloc(sizeof(listnode))) == NULL )
		{
			printf("list_create2: malloc failed!\n");
			return H;
		}
		p->data = value;
		p->next = NULL;

		r->next = p;
		r = p; // r 往后移动一个结点
	}

	return H;
}
//通过序号查找值
linklist list_get(linklist H, int pos)
{
	linklist p = H;
	int i = -1;
	// printf("isdigit pos: %d\n",isdigit(pos) );
	if ( pos < 0  )
	{
		printf("position is invalid: pos < 0\n");
		return NULL;
	}
	if ( isdigit(pos))
	{
		printf("position must be a number\n");
		return NULL;
	}


	while( p->next && i < pos) //将指针节点往后移动到 pos个 次数
	{
		p = p->next;
		i++;
	}

	if ( i == pos)
	{
		return p;
	}
	else
	{
		 printf("position is invalid: pos > \n");
		 return NULL;
	}
 

}
//通过值查找地址
int list_locate(linklist H, datatype value)
{
	int pos = 0;
	linklist p = H->next;
	while(p &&  p->data != value)
	{
		p = p->next;
		pos ++;
	}
	if (p == NULL)
	{
		return -1;
	}
	return pos;
}

int list_insert(linklist H, int pos, datatype value)
{
	linklist p, q;
	if ( pos == 0)
	{
		p = H;
	}
	else{
		p = list_get(H , pos-1);
	}

	if ( p == NULL)
	{
		printf("list_insert faield\n");
		return -1;
	}else{
		if ( (q = (linklist)malloc(sizeof(listnode))) == NULL )
		{
			printf("malloc failed\n");
			return -1;
		}

		q->data = value;
		q->next = p->next;
		p->next = q;


		return 0;

	}

}
 

int list_order_insert(linklist H, datatype value)
{
	if ( H == NULL)
	{
		printf("linklist is NULL\n");
		return -1;
		/* code */
	}
	linklist p, q;
	p = H;
	if ( (q = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("list order insert: failed!\n");
		return -1;
	}
	q->data = value;
	while(p->next && p->next->data < value) //下一节点值 小于 输入的值。 节点往后移动   
	{
		 p = p->next;
	}
	q->next = p->next;
	p->next = q;  
	return 0;

}

void list_sort(linklist H)
{
	linklist p, q, temp;


	p = H->next;
	H->next = NULL;
	while(p){
		q = p;
		p = p->next;
		temp = H;

		while(temp->next && temp->next->data < q->data)
		{
			temp = temp->next;
		}

		q->next = temp->next;
		temp->next = q;
	}

}












