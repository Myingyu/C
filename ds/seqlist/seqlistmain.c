#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"


int main(int argc, char const *argv[])
{
	int i;

	seqlist_t *L;
	L = create_seqlist();
	for (i = 0; i <= 4; i++)
	{
		insert_seqlist(L, i, i);
	}
	show_seqlist(L);
	
	printf("search_seqlist:data[%d]",search_seqlist( L,3));
	


	
	clear_seqlist(L);
	return 0;
} 