#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree
{
	int data;
	struct BiTree* lchild;
	struct BiTree* rchild;
}BiNode,*BiTree;

void CreateBiTree(BiTree* T) //先遍历创建二叉树 
{
    int a;
    scanf("%d", &a);
	while(getchar() != '\n');
    if (a == -1)
        (*T) = NULL;
    else
    {
        (*T) = (BiTree)malloc(sizeof(BiNode));
        (*T)->data = a;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void TravelBiTree(BiTree T) //前序遍历二叉树
{
	if(T)
	{
		TravelBiTree(T->lchild);
		printf("%d ", T->data);
		TravelBiTree(T->rchild);
	}
} 

int main()
{	
	BiTree T;
	CreateBiTree(&T);
	TravelBiTree(T);
	return 0;
}
