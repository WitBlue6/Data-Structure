#include <stdio.h>

typedef struct Node//创建节点 
{
	int num;
	struct Node* next;
}Node;

Node* CreateCirList(int n)//创建n个节点的循环链表 
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
void ShowCirList(Node* head, int a, int n)//从第a个元素开始往后遍历n个元素 
{	
	if(a>n)
		return;
	int i;
	Node* p = head;
	for(i=0;i<a;i++)
	{
		p=p->next;
	}
	//此时p指向第a个节点
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
	printf("输入拉丁方阵阶数:>");
	scanf("%d",&n);
	//创建循环链表 
	Node* head = CreateCirList(n);
	//输出拉丁方阵 
	int i;
	for(i=1;i<=n;i++)
		ShowCirList(head,i,n);
		
	return 0;
}
