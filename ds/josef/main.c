#include "linklist.h"
int main(int argc, char const *argv[])
{
	listnode * H;

	H = create_list(1);

	list_insert(H,2);
	list_insert(H,3);
	// printf("%d, %d, %d, %d\n",H->data, H->next->data, H->next->next->data, H->next->next->next->data);
	list_insert(H,4);
	list_insert(H,5);
	list_insert(H,6);
	list_insert(H,7);
	list_insert(H,8);
	list_show(H);
	printf("-----------------------------\n");
	list_solver(H,1,2);
	// printf("H->data:%d\n", H->data);
	// printf("H->next->data:%d\n", H->next->data);
	// printf("H->next->next->data:%d\n", H->next->next->data);
	// list_show(H); // 添加后报段错误！

	// list_show(H);

	return 0;
} 