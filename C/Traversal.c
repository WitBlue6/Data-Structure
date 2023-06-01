#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX_SIZE 50

typedef char Elemtype;

// 二叉树数据类型定义 
typedef struct BiNode
{
	Elemtype data;
	struct BiNode *lchild;
	struct BiNode *rchild;
	
}BiNode, *BiTree;

//前序遍历创建二叉树 
void CreateBiTree(BiTree *T);  
//遍历时访问函数
Elemtype Visit(BiTree T);
//中序遍历输出二叉树
void InOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));
//后序遍历输出二叉树 
void LastOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));
//层序遍历输出二叉树 
void LevelOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));

//主函数 
int main()
{
	BiTree *T;
	printf("输入二叉树的前序序列(以#代表空子树):");
	CreateBiTree(T);
	printf("\n中序遍历结果:");
	InOrderTraverse(*T, Visit);
	printf("\n后序遍历结果:"); 
	LastOrderTraverse(*T, Visit);
	printf("\n层序遍历结果:");
	LevelOrderTraverse(*T, Visit);
	return 0;
}

//前序遍历创建二叉树 
void CreateBiTree(BiTree *T)
{
	Elemtype tmp = getchar();
	if( tmp == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiNode));
		(*T)->data = tmp;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

//遍历时访问函数
Elemtype Visit(BiTree T)
{
	printf("%c",T->data);
	return T->data;
} 

//中序遍历输出二叉树
void InOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T))
{
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T);
		InOrderTraverse(T->rchild, Visit);
	}
}

//后序遍历输出二叉树
void LastOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T))
{
	if(T)
	{
		LastOrderTraverse(T->lchild, Visit);
		LastOrderTraverse(T->rchild, Visit);
		Visit(T);
	}
}

//层序遍历输出二叉树 
void LevelOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T)) 
{
	int in = 0, out = 0;  //使用数组来表示队列	
	BiTree queue[TREE_MAX_SIZE] = {0};
	if(T)
		queue[in++] = T;
	while(in - out > 0) //队列不为空
	{
		BiTree cur = queue[out++];
		Visit(cur);
		//每次cur出队列，让其左右子树入队列 
		if(cur->lchild)
			queue[in++] = cur->lchild;
		if(cur->rchild)
			queue[in++] = cur->rchild;
	} 
}
