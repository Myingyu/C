#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	FILE * fp;
	char  data[10];
	char buf[64];
	int year, month, day; 
	if ( (fp = fopen("test.txt","a+")) == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	time_t second;
	struct tm *date;
	while(1){
		time(&second);
		date = localtime(&second);
		fprintf(fp, "%2d:%2d:%02d\n", date->tm_hour,date->tm_min, date->tm_sec);
		fflush(fp);
		sleep(1);
	}






	fclose(fp);



	return 0;
}

 