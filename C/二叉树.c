#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct BTree
{
	struct BTree *lchild;
	struct BTree *rchild;
	Elemtype data;
}BiNode, *BiTree;

void CreateBiTree_by_Pre(BiTree *T)  //����������������� 
{
	Elemtype tmp;
	scanf("%c",&tmp);
	
	if(tmp == '#')
		(*T) = NULL;
	else
	{
		(*T) = (BiTree)malloc(sizeof(BiNode));
		(*T)->data = tmp;
		CreateBiTree_by_Pre(&(*T)->lchild);
		CreateBiTree_by_Pre(&(*T)->rchild);
	}
}

void TraversalBiTree_by_Pre(BiTree T) //�������������
{
	if(T)
	{	
		printf("%c ",T->data);
		TraversalBiTree_by_Pre(T->lchild);
		TraversalBiTree_by_Pre(T->rchild);
	}
} 

void TraversalBiTree_by_In(BiTree T) //�������������
{
	if(T)
	{	
		TraversalBiTree_by_In(T->lchild);
		printf("%c ", T->data);
		TraversalBiTree_by_In(T->rchild);
	}
} 

void TraversalBiTree_by_Post(BiTree T) //�������������
{
	if(T)
	{	
		TraversalBiTree_by_Post(T->lchild);
		TraversalBiTree_by_Post(T->rchild);
		printf("%c ",T->data);
	}
} 

int main()
{	
	BiTree T;
	CreateBiTree_by_Pre(&T);
	printf("ǰ����������");
	TraversalBiTree_by_Pre(T);
	printf("\n������������");
	TraversalBiTree_by_In(T);
	printf("\n������������");
	TraversalBiTree_by_Post(T);
	printf("\n");
	return 0;
}
