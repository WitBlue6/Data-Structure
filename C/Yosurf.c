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
	//初始化 
	CList *head = (CList*)malloc(sizeof(CList));
	head->next = head;
	CList *p = head;
	int i = 0;
	for(i=1;i<=m;i++) //开始插入节点 
	{
		CList *new = (CList*)malloc(sizeof(CList));
		new->num = i;
		p->next = new;
		new->next = head;
		p = p->next;
	}	
	return head;
}
Elemtype DeleteList(CList **head, int no)  //删除链表中第no个结点,并将结点的编号返回 
{
	CList *p = *head;
	int i;
	for(i=1;i<no;i++)
		p=p->next;
	//此时p指向第no-1个结点
	CList *q = p->next;
	p->next = q->next;
	int e = q->num;
	free(q);
	q = NULL;
	
	return e;
} 
void Yorsuf(CList *head, int m, int s , int n) 
{
	//约瑟夫问题，从第s个结点开始计数为1， 计数到n时输出结点，直至为空
	int no = 0; //输出结果 
	int i = 0; //约瑟夫轮数 
	int del = 0; //要删除的元素 
	while(head->next != head) //链表不为空
	{	
		if(m-i!=0)
			del = (s+n-1)%(m-i);
		if(del==0)
			del=m-i; //恰好是最后一个结点 
		no = DeleteList(&head, del);
		++i; //轮数加一 
		
		if(m-i!=0) 
			s = del%(m-i); //下次开始计算的点 
		if(s==0)
			s=m-i; //恰好是最后一个结点 
		printf("%d,  ",no);
	} 
} 
int main()
{	
	int m,s,n;
	printf("请输入环的长度:\n ");
	scanf("%d",&m);
	CList *head = CreateList(m);
	printf("请输入开始点s和计数n:\n");
	scanf("%d%d",&s,&n);
	
	if(m>0 && s>0 && n>0)
		Yorsuf(head,m,s,n);
	else
		printf("请输入正确的数据!\n");
	return 0;
}

