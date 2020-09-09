#include <stdio.h>
#include <sqlite3.h>

#define DATABASE "std.db"


int do_insert(sqlite3* db);
int do_delete();
int do_query();
int do_update();
int do_quit();

int main(int argc, char const *argv[])
{
	sqlite3 *db;
	char * errmsg;


	if ( sqlite3_open(DATABASE, &db) != SQLITE_OK)
	{
		printf("%s\n",sqlite3_errmsg(db) );
	}
	else{
		printf("Open DATABASE success\n");
	}
	//创建表格

	if ( sqlite3_exec(db, "create table stu (id Integer, name char, score Integer);", NULL, NULL, &errmsg) != SQLITE_OK )
	{
		printf("%s\n", errmsg);
		/* code */
	}
	else
	{
		printf("create table success\n");
	}

	while(1)
	{
		printf("************************************************\n");
		printf("1:insert 2:delete 3:query 4:update 5:quit.\n");
		printf("************************************************\n");

		int cmd;
		scanf("%d",&cmd);
		getchar();


		switch(cmd)
		{
			case 1:
				do_insert(db);
				break;
			case 2:
				// do_delete();
				break;
			case 3:
				// do_query();
				break;
			case 4:
				// do_update();
				break;
			default:
				break;
		}

	}





	return 0;
}


int do_insert(sqlite3* db){
	int id;
	char name[32] ={};
	int score;
	char sql[128] = {};
	char * errmsg;

	printf("Input ID\n");
	scanf("%d", &id);
	getchar();

	printf("Input Name \n");
	scanf("%s", name);
	getchar();

	printf("Input Score \n");
	scanf("%d", score);
	getchar();

	sprintf(sql,"insert into stu values(%d, '%s', %d)", id, name, score);

	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg)!= SQLITE_OK )
	{
		printf("insert failed\n");
		/* code */
	}
	else{
		printf("insert done\n");
	}

	return 0;
}

