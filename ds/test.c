#include "linklist.h"

int main(int argc, char const *argv[])
{
	linklist H;
	H = list_create();
	list_show(H);
	printf("以上初始数据链表\n");
	list_head_insert(H,10);
	printf("%p\n", &H->next);
	list_head_insert(H,20);
	list_head_insert(H,30);
	list_show(H);
	printf("%p\n", &H->next);
	// printf("%s", H);


	return 0;
}