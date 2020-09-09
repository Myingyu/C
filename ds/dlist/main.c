#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main(int argc, char const *argv[])
{
	dlistnode * H;
	H = dlist_create();
	dlist_show(H);

	dlist_insert(H, 10);
	dlist_insert(H, 11);
	dlist_insert(H, 12);
	dlist_insert(H, 13);
	dlist_insert(H, 14);
	dlist_show(H);


	return 0;
}