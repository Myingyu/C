//打印指定目录下所有文件的名称

#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	DIR *dirp;
	struct dirent* dp;
	if ( (dirp = opendir("../search")) == NULL){
		perror("opendir");
		return -1;
	}
	while( (dp = readdir(dirp)) != NULL){
		printf("%s\n", dp->d_name);
	}

	closedir(dirp);

	return 0;
}