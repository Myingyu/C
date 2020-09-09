#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct worker{
    long number;
    char name[20];
    char sex;
    int age;
    float salary;
    char address[80];
}; // 分号不能省却

struct birthday{
	int year;
	int month;
	int day;
};

struct manager
{	int no;
    char name[20];
    float score;
    struct graduate_date{
    	int year;
    	int month;
    	int day;
    }g_date; // 只有manager才有具有g_date这个结构体。
	
};


struct student{
    int no;
    char name[20];
    float score;
    struct birthday date;
}s3 = {1, 90},s4 = {2, "second", 89}; // 只有结构体初始化的时候，才能全部赋值，后面都需要一项一项的修改。




int main(int argc, const char * argv[]){
    struct worker w1, w2;
    
    struct student s1, s2;
    s1.no = 1;
    strcpy(s1.name, "s1");
    s1.score = 90;

    s2 = s1;
    s2.date.year = 1990;
    printf("%d\n", s2.date.year);// 多次嵌套结构，只能从最基础的变量进行修改



    return 0;
}