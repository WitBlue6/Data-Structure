#include <stdio.h>

typedef struct Node//�����ڵ� 
{
	int num;
	struct Node* next;
}Node;

Node* CreateCirList(int n)//����n���ڵ��ѭ������ 
{
	Node* head =(Node*)malloc(sizeof(Node));
	Node* p = head;
	int i;
	for(i=1;i<=n;i++)
	{
		Node* new = (Node*)malloc(sizeof(Node));
		new->num = i;
		p->next = new;
		new->next = head->next;
		p=p->next;
	}
	return head;
}
void ShowCirList(Node* head, int a, int n)//�ӵ�a��Ԫ�ؿ�ʼ�������n��Ԫ�� 
{	
	if(a>n)
		return;
	int i;
	Node* p = head;
	for(i=0;i<a;i++)
	{
		p=p->next;
	}
	//��ʱpָ���a���ڵ�
	for(i=0;i<n;i++)
	{
		printf("%-2d ",p->num);
		p=p->next;
	} 
	printf("\n");
}

int main()
{
	int n;
	printf("���������������:>");
	scanf("%d",&n);
	//����ѭ������ 
	Node* head = CreateCirList(n);
	//����������� 
	int i;
	for(i=1;i<=n;i++)
		ShowCirList(head,i,n);
		
	return 0;
}
