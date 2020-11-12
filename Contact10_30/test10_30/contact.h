#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_QQ 13
#define MAX_SEX 6
#define MAX 1000

//���Ͷ���ͺ�������

//������Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	int age;
}PeoInfo;

//ͨѶ¼
typedef struct Contact
{
	PeoInfo date[MAX];    //����
	int sz;            //��Ч����
}Contact;

//����ָ����ϵ��
void add_contact(Contact *pc);
//��ʾͨѶ¼��Ϣ
void show_contact(Contact *pc);
//ɾ��ָ����ϵ��
void del_contact(Contact *pc);
//����ָ����ϵ��
void search_contact(Contact *pc);
//�޸�ָ����ϵ��
void modify_contact(Contact *pc);
//����ͨѶ¼��Ϣ
void sort_contact(Contact *pc);