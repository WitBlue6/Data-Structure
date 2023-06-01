#include <stdio.h> 
#include <stdlib.h>

typedef int Elemtype;

typedef struct CList
{
	Elemtype num;
	struct CList *next;
}CList;

CList* CreateList(int m)
{	
	//��ʼ�� 
	CList *head = (CList*)malloc(sizeof(CList));
	head->next = head;
	CList *p = head;
	int i = 0;
	for(i=1;i<=m;i++) //��ʼ����ڵ� 
	{
		CList *new = (CList*)malloc(sizeof(CList));
		new->num = i;
		p->next = new;
		new->next = head;
		p = p->next;
	}	
	return head;
}
Elemtype DeleteList(CList **head, int no)  //ɾ�������е�no�����,�������ı�ŷ��� 
{
	CList *p = *head;
	int i;
	for(i=1;i<no;i++)
		p=p->next;
	//��ʱpָ���no-1�����
	CList *q = p->next;
	p->next = q->next;
	int e = q->num;
	free(q);
	q = NULL;
	
	return e;
} 
void Yorsuf(CList *head, int m, int s , int n) 
{
	//Լɪ�����⣬�ӵ�s����㿪ʼ����Ϊ1�� ������nʱ�����㣬ֱ��Ϊ��
	int no = 0; //������ 
	int i = 0; //Լɪ������ 
	int del = 0; //Ҫɾ����Ԫ�� 
	while(head->next != head) //����Ϊ��
	{	
		if(m-i!=0)
			del = (s+n-1)%(m-i);
		if(del==0)
			del=m-i; //ǡ�������һ����� 
		no = DeleteList(&head, del);
		++i; //������һ 
		
		if(m-i!=0) 
			s = del%(m-i); //�´ο�ʼ����ĵ� 
		if(s==0)
			s=m-i; //ǡ�������һ����� 
		printf("%d,  ",no);
	} 
} 
int main()
{	
	int m,s,n;
	printf("�����뻷�ĳ���:\n ");
	scanf("%d",&m);
	CList *head = CreateList(m);
	printf("�����뿪ʼ��s�ͼ���n:\n");
	scanf("%d%d",&s,&n);
	
	if(m>0 && s>0 && n>0)
		Yorsuf(head,m,s,n);
	else
		printf("��������ȷ������!\n");
	return 0;
}

