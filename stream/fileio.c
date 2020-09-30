#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	struct stat statbuf;
	stat("est.txt",&statbuf);
	printf("%s\n", statbuf->st_mode-);

	return 0;
}