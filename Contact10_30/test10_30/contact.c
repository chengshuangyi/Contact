#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void add_contact(Contact *pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������->");
		scanf("%s", pc->date[pc->sz].name);
		printf("������绰->");
		scanf("%s", pc->date[pc->sz].tele);
		printf("�������ַ->");
		scanf("%s", pc->date[pc->sz].addr);
		printf("������QQ->");
		scanf("%s", pc->date[pc->sz].qq);
		printf("�������Ա�->");
		scanf("%s", pc->date[pc->sz].sex);
		printf("����������->");
		scanf("%d", &(pc->date[pc->sz].age));
		pc->sz++;
		printf("��ӳɹ�\n");
	}
}

void show_contact(Contact *pc)
{
	printf("%10s %13s %20s %5s %13s %5s\n", "����", "�绰", "��ַ", "����", "QQ", "�Ա�");
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
		printf("��Ǹ��ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("������Ҫɾ���˵����֣�");
		scanf("%s", &name);
		//�ҵ�ָ����ϵ�˵�λ��
		int pos = find_peo_by_name(pc,name);
		if (pos == -1)
		{
			printf("���ź���ɾ���˲�����\n");   //û�ҵ�
		}
		else
		{
			//ɾ����ϵ��
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->date[j] = pc->date[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void search_contact(Contact *pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵����֣�");
	scanf("%s", &name);
	int pos= find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%10s %13s %20s %5s %13s %5s\n", "����", "�绰", "��ַ", "����", "QQ", "�Ա�");
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
	printf("������Ҫ�޸��˵����֣�");
	scanf("%s", &name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else 
	{
		printf("�������µ�����->");
		scanf("%s", pc->date[pos].name);
		printf("�������µĵ绰->");
		scanf("%s", pc->date[pos].tele);
		printf("�������µĵ�ַ->");
		scanf("%s", pc->date[pos].addr);
		printf("�������µ�QQ->");
		scanf("%s", pc->date[pos].qq);
		printf("�������µ��Ա�->");
		scanf("%s", pc->date[pos].sex);
		printf("�������µ�����->");
		scanf("%d", &(pc->date[pos].age));
		printf("�޸ĳɹ�\n");
	}
}

void sort_contact(Contact *pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz-1; i++)
	{
		int flag = 1;  //����������
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