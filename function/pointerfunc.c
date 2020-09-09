#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * del_space( char *);
char * hello();

int main(int argc, char const *argv[])
{
	char str[] = "abcs asdgr   adfgadf";

	printf("%s\n", str);

	char * pc = hello();

	printf("%s\n", pc);



	// del_space(str);
	char * strpointer = del_space(str);



	printf("%s\n", strpointer);
	return 0; 
}

char * del_space( char * str){
	char * strp = str;
	while(*strp != '\0'){

		if (isspace(*strp))
		{
			strp++;
			/* code */
		}else{
			strp++;
			str++;
		}
		*str = *strp;

	}
	return str;
}

char * hello(){
	static char str[20] = "hello"; // 如果函数要返回这个数组，这个数组必须是static
	// char str[20] = "hello" 编译不会报错，但是输出是乱码。所以跨函数块返回数组必须是static变量

	return str;
}






