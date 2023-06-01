//输入数字，输出26个字母的序列(小题大做)
//例1：3
//DEFGHIJKLMNOPQRSTUVWXYZABC
//例2: -3
//XYZABCDEFGHIJKLMNOPQRSTUVW
#include <stdio.h>
typedef struct DulNode//双向循环链表 
{
	char ch;
	struct DulNode* prior;
	struct DulNode* next;
}DulNode;

DulNode* CreateList(int n)//创建A-B-C-……-Z双向循环链表 
{	
	//头指针创建 
	DulNode* head = (DulNode*)malloc(sizeof(DulNode));
	head->next = head;
	head->prior = head;
	
	DulNode* p = head;
	
	int i;
	char c = 'A';
	for(i=0;i<n;i++)
	{
		DulNode* newnode = (DulNode*)malloc(sizeof(DulNode));
		//节点连接 
		newnode->prior = p;
		p->next = newnode;
		newnode->next = head->next;
		head->next->prior = newnode;
		//赋值 
		newnode->ch = c++;
		
		if(p->next != NULL)
			p=p->next;
		else
			exit(0);
	}
	return head;
}

void ShowList(DulNode* head, int n, int total)//从n开始打印链表后total个数据 
{	
	DulNode* p = head;
	int i;
	//对n分类处理，初始化打印起始节点 
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
	for(i=0;i<total;i++)//打印节点 
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
