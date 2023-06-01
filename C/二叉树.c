#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct BTree
{
	struct BTree *lchild;
	struct BTree *rchild;
	Elemtype data;
}BiNode, *BiTree;

void CreateBiTree_by_Pre(BiTree *T)  //先序遍历创建二叉树 
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

void TraversalBiTree_by_Pre(BiTree T) //先序遍历二叉树
{
	if(T)
	{	
		printf("%c ",T->data);
		TraversalBiTree_by_Pre(T->lchild);
		TraversalBiTree_by_Pre(T->rchild);
	}
} 

void TraversalBiTree_by_In(BiTree T) //中序遍历二叉树
{
	if(T)
	{	
		TraversalBiTree_by_In(T->lchild);
		printf("%c ", T->data);
		TraversalBiTree_by_In(T->rchild);
	}
} 

void TraversalBiTree_by_Post(BiTree T) //后序遍历二叉树
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
	printf("前序遍历结果：");
	TraversalBiTree_by_Pre(T);
	printf("\n中序遍历结果：");
	TraversalBiTree_by_In(T);
	printf("\n后序遍历结果：");
	TraversalBiTree_by_Post(T);
	printf("\n");
	return 0;
}
