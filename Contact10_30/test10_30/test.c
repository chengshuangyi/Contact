#define _CRT_SECURE_NO_WARNINGS 1
//��ҵ����
//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
/*�ṩ������
�����ϵ����Ϣ
ɾ��ָ����ϵ����Ϣ
����ָ����ϵ����Ϣ
�޸�ָ����ϵ����Ϣ
��ʾ������ϵ����Ϣ
���������ϵ��
����������������ϵ��*/
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
	//����ͨѶ¼
	Contact con = { 0 };
	//��ʼ��ͨѶ¼
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�\n");
			break;
		default:
			printf("û�д˹��ܣ�����������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;  
}
