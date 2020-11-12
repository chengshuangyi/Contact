#define _CRT_SECURE_NO_WARNINGS 1
//作业内容
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
/*提供方法：
添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人*/
#include"contact.h"
void menu()
{
	printf("*************************************************\n");
	printf("*************   1.add     2.del     *************\n");
	printf("*************   3.searh   4.modify  *************\n");
	printf("*************   5.sort    6.show    *************\n");
	printf("*************       0.exit          *************\n");
	printf("*************************************************\n");
}
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};
void test()
{
	//创建通讯录
	Contact con = { 0 };
	//初始化通讯录
	int input = 0;
	do 
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			printf("退出\n");
			break;
		default:
			printf("没有此功能，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;  
}
