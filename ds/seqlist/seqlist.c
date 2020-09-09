#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

seqlist_t * create_seqlist(void)
{
	seqlist_t *L = NULL;
	L = (seqlist_t *)malloc(sizeof(seqlist_t));
	if (L ==NULL)
	{
		puts("malloc failed");
		/* code */
		return NULL;
	}
	L -> last = -1;
	return L;
}

void clear_seqlist(seqlist_t *L) 
{
	if (L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return;
	}
	free(L);
	L = NULL;
}

int is_empty_seqlist(seqlist_t *L)
{
	if ( L == NULL)
	{
		puts("seqlist_t *L is NULL");
		free(L);
		return -1;
	}

	return(L -> last == -1);
}

int is_full_seqlist(seqlist_t *L)
{
	if (L == NULL)
	{
		puts("seqlist_t * L is NULL");
	}
	return(L->last == MAXSIZE-1);
}

int set_empty_seqlist(seqlist_t *L)
{
	if (L == NULL)
	{
		puts("seqlist_t already NULL");
	}
	L -> last = -1;
	return 0;

}
int get_length_seqlist(seqlist_t *L)
{
	if (L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return -1;
	}
	return(L ->last+1);

}

void show_seqlist(seqlist_t *L)
{
	int i = 0;
	if (L ==NULL)
	{
		puts("seqlist_t *L is NULL");
		return;
	}
	for (i = 0; i <= L->last; i++)
	{
		printf("data[%d] = %d\n", i, L->data[i]);
	}
	return;
}

int insert_seqlist(seqlist_t *L, data_t x, int pos)
{
	int i = 0;
	if (is_full_seqlist(L) || (pos<0)||(pos > L->last+1))
	{
		puts("input argv is invalid");
		return -1;
	} 
	//往后移一位
	for ( i = L->last; i >= pos; i--)
	{
		L ->data[i+1] = L ->data[i];
		 
	}
	//在 pos 位置插入x
	L->data[pos] = x;
	L->last++;
	return 0;

}

int delete_seqlist(seqlist_t *L, int pos)
{
	if ( (pos < 0) || (pos > L->last) )
	{
		puts("input pos is invalid");
		return -1;
	}
	for (int i = pos; i >0 ; i--)
	{
		L -> data[i] = L->data[i+1];		
	}
	L -> last--;
	return 0;  
}
int change_seqlist(seqlist_t *L, data_t x, int pos);
int search_seqlist(seqlist_t *L, data_t x)
{
	for (int i = 0; i <= L->last; i++)
	{
		if ( L->data[i] == x )
		{
			return i; 
		}
	}
	return -1; 
}





