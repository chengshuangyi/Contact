#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_QQ 13
#define MAX_SEX 6
#define MAX 1000

//类型定义和函数声明

//个人信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	int age;
}PeoInfo;

//通讯录
typedef struct Contact
{
	PeoInfo date[MAX];    //数据
	int sz;            //有效个数
}Contact;

//增加指定联系人
void add_contact(Contact *pc);
//显示通讯录信息
void show_contact(Contact *pc);
//删除指定联系人
void del_contact(Contact *pc);
//查找指定联系人
void search_contact(Contact *pc);
//修改指定联系人
void modify_contact(Contact *pc);
//排序通讯录信息
void sort_contact(Contact *pc);