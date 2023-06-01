#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int num;
	struct Node* next;
}Node;

Node* CreateList(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->num = -1;
	head->next = NULL;
	return head;
}
Node* InsertList(Node* head, int n)
{	
	Node* p = head;
	while(p->next != NULL)
		p = p->next;
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->num = n;
	p->next = newnode;
	newnode->next = NULL;
	return newnode;
}
void PrintList(Node* head)
{
	Node* p = head;
	while(p->next != NULL)
	{	
		if(p != head)
	 		printf("%d ",p->num);
	 	p=p->next;
	}
	if(p != head)
		printf("%d \n",p->num);
}
int DeleteList(Node* head, int n)  //ɾ���ý��
{
	Node* p = head;
	Node* q = head; // ��¼p��ǰһ��� 
	while(p->next != NULL)
	{
		if(p->num == n)
		{
			q->next = p->next;
			free(p);
			return 1;
		}
		q = p;
		p = p->next;
	}
	printf("�Ҳ����ýڵ�\n");
	return 0;
}
void DeleteXy(Node* head, int x, int y)  //ɾ�����������Դ���x��С��y�Ľ�� 
{
	Node* p = head;
	Node* q = head; // ��¼p��ǰһ��� 
	while(p != NULL)
	{
		if(p->num > x && p->num < y)
		{	
			if(p->next!=NULL)
			{
				q->next = p->next;
				free(p);
				p = q->next;
			}
			else
			{
				q->next = NULL;
				free(p);
				p = NU
			}
		}
		else
		{
			q = p;
			if(p->next != NULL)
				p = p->next;
			else
				break;
		}
	}
}
Node* UnionList(Node* LA, Node* LB)  // ��LA,LB���� 
{
	Node* LC = (Node*)malloc(sizeof(Node));
	int flag = 0;
	LC->next = NULL;
	LC->num = -1;
	Node* p = LC;
	Node* a = LA;
	Node* b = LB;
	while(a != NULL) //����ѭ�������ȶ� 
	{	
		for(b=LB;b!=NULL;)
		{
			if(a->num == b->num && a!=LA && b!=LB)  // LC����½��
			{
				Node* newnode = (Node*)malloc(sizeof(Node));
				newnode->num = a->num;
				p->next = newnode;
				newnode->next = NULL;
				p = p->next;
				flag =1;
			}
			if(b->next!=NULL)
				b=b->next;
			else
				break;
		}
		if(a->next!=NULL)
			a = a->next;
		else
			break;
	}
	if(flag==1)
		return LC;
	else
		return NULL;
}
int main()
{	
	int n;
	Node* head = CreateList();
	do
	{
		scanf("%d",&n);
		InsertList(head, n);
	}while(getchar()!='\n');
	int x, y;
	scanf("%d%d",&x,&y);
	DeleteXy(head, x, y);
	PrintList(head);
	return 0;
}

