#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void add_contact(Contact *pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名->");
		scanf("%s", pc->date[pc->sz].name);
		printf("请输入电话->");
		scanf("%s", pc->date[pc->sz].tele);
		printf("请输入地址->");
		scanf("%s", pc->date[pc->sz].addr);
		printf("请输入QQ->");
		scanf("%s", pc->date[pc->sz].qq);
		printf("请输入性别->");
		scanf("%s", pc->date[pc->sz].sex);
		printf("请输入年龄->");
		scanf("%d", &(pc->date[pc->sz].age));
		pc->sz++;
		printf("添加成功\n");
	}
}

void show_contact(Contact *pc)
{
	printf("%10s %13s %20s %5s %13s %5s\n", "姓名", "电话", "地址", "年龄", "QQ", "性别");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s %13s %20s %5d %13s %5s\n", pc->date[i].name,
			pc->date[i].tele,
			pc->date[i].addr,
			pc->date[i].age,
			pc->date[i].qq,
			pc->date[i].sex);
	}
}

static int find_peo_by_name(Contact *pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void del_contact(Contact *pc)
{
	if (pc->sz == 0)
	{
		printf("抱歉，通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入要删除人的名字：");
		scanf("%s", &name);
		//找到指定联系人的位置
		int pos = find_peo_by_name(pc,name);
		if (pos == -1)
		{
			printf("很遗憾，删除人不存在\n");   //没找到
		}
		else
		{
			//删除联系人
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->date[j] = pc->date[j + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}

void search_contact(Contact *pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字：");
	scanf("%s", &name);
	int pos= find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%10s %13s %20s %5s %13s %5s\n", "姓名", "电话", "地址", "年龄", "QQ", "性别");
		printf("%10s %13s %20s %5d %13s %5s\n", pc->date[pos].name,
			pc->date[pos].tele,
			pc->date[pos].addr,
			pc->date[pos].age,
			pc->date[pos].qq,
			pc->date[pos].sex);
	}
}

void modify_contact(Contact *pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字：");
	scanf("%s", &name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else 
	{
		printf("请输入新的姓名->");
		scanf("%s", pc->date[pos].name);
		printf("请输入新的电话->");
		scanf("%s", pc->date[pos].tele);
		printf("请输入新的地址->");
		scanf("%s", pc->date[pos].addr);
		printf("请输入新的QQ->");
		scanf("%s", pc->date[pos].qq);
		printf("请输入新的性别->");
		scanf("%s", pc->date[pos].sex);
		printf("请输入新的年龄->");
		scanf("%d", &(pc->date[pos].age));
		printf("修改成功\n");
	}
}

void sort_contact(Contact *pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz-1; i++)
	{
		int flag = 1;  //假设已有序
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->date[j].name, pc->date[j + 1].name) > 0)
			{
				PeoInfo temp = pc->date[j];
				pc->date[j] = pc->date[j+1];
				pc->date[j+1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}