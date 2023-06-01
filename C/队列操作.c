#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct QNode
{
	int num;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* rear;
}Queue;

int InitQueue(Queue **Q)
{
	*Q = (Queue*)malloc(sizeof(Queue));
	if(!Q)
		return 0;
	(*Q)->head = NULL;
	(*Q)->rear = NULL;
	return 1;
}

int CreateQueue(Queue *Q)
{	
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if(!newnode)
		return 0;
	
	Q->head = newnode;
	Q->head->next = NULL;
	Q->rear = Q->head;
	Q->rear->next = NULL;
	return 1;
}

int InsertQueue(Queue *Q, Elemtype* e)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if(!newnode)
		return 0;
		
	newnode->num = *e;
	newnode->next = NULL;
	Q->rear->next = newnode;
	Q->rear = newnode;
	return 1;
}

Elemtype DeleteQueue_head(Queue *Q)  //删除队列中第一个元素，并将其作为返回值返回 
{
	Elemtype e = Q->head->next->num;
	QNode* a = Q->head->next;
	Q->head->next = a->next;
	free(a);
	return e;
}

int IsEmpty(Queue *Q)  //判断队列是否为空 (1为空)
{
	return (Q->head->next==NULL);
} 
int main()
{
	Queue *Q1, *Q2, *Q3;  
	InitQueue(&Q1);
	InitQueue(&Q2);
	InitQueue(&Q3);
	CreateQueue(Q1);
	CreateQueue(Q2);
	CreateQueue(Q3);
	
	int n;
	Elemtype a;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a<60)
			InsertQueue(Q1, &a);
		else if(a>=60 && a<100)
			InsertQueue(Q2, &a);
		else
			InsertQueue(Q3, &a);
	}
	if(!IsEmpty(Q1))
	{
		printf("60>x:");
		while(!IsEmpty(Q1))
			printf("%d ",DeleteQueue_head(Q1));
	}
	if(!IsEmpty(Q2))
	{
		printf("\n60<=x<100:");
		while(!IsEmpty(Q2))
			printf("%d ",DeleteQueue_head(Q2));
	}
	if(!IsEmpty(Q3))
	{
		printf("\nx>=100:");
		while(!IsEmpty(Q3))
			printf("%d ",DeleteQueue_head(Q3));
	}
		printf("\n");
	
	return 0;
}
