//�������֣����26����ĸ������(С�����)
//��1��3
//DEFGHIJKLMNOPQRSTUVWXYZABC
//��2: -3
//XYZABCDEFGHIJKLMNOPQRSTUVW
#include <stdio.h>
typedef struct DulNode//˫��ѭ������ 
{
	char ch;
	struct DulNode* prior;
	struct DulNode* next;
}DulNode;

DulNode* CreateList(int n)//����A-B-C-����-Z˫��ѭ������ 
{	
	//ͷָ�봴�� 
	DulNode* head = (DulNode*)malloc(sizeof(DulNode));
	head->next = head;
	head->prior = head;
	
	DulNode* p = head;
	
	int i;
	char c = 'A';
	for(i=0;i<n;i++)
	{
		DulNode* newnode = (DulNode*)malloc(sizeof(DulNode));
		//�ڵ����� 
		newnode->prior = p;
		p->next = newnode;
		newnode->next = head->next;
		head->next->prior = newnode;
		//��ֵ 
		newnode->ch = c++;
		
		if(p->next != NULL)
			p=p->next;
		else
			exit(0);
	}
	return head;
}

void ShowList(DulNode* head, int n, int total)//��n��ʼ��ӡ�����total������ 
{	
	DulNode* p = head;
	int i;
	//��n���ദ����ʼ����ӡ��ʼ�ڵ� 
	if(n>=0)
	{
		for(i=0;i<n;i++)
		{
			p=p->next;
		}
	}
	else
	{	
		n= -n;
		p=p->next;
		for(i=0;i<n+1;i++)
		{
			p=p->prior;
		}
	}
	for(i=0;i<total;i++)//��ӡ�ڵ� 
		{
			if(p->next != NULL)
			{
				p=p->next;
				printf("%c",p->ch);
			}
			else
				exit(0);
		}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	DulNode* L = CreateList(26);
	ShowList(L,n,26);
	
	return 0;
}
