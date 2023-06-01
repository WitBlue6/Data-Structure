#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX_SIZE 50

typedef char Elemtype;

// �������������Ͷ��� 
typedef struct BiNode
{
	Elemtype data;
	struct BiNode *lchild;
	struct BiNode *rchild;
	
}BiNode, *BiTree;

//ǰ��������������� 
void CreateBiTree(BiTree *T);  
//����ʱ���ʺ���
Elemtype Visit(BiTree T);
//����������������
void InOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));
//���������������� 
void LastOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));
//���������������� 
void LevelOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T));

//������ 
int main()
{
	BiTree *T;
	printf("�����������ǰ������(��#���������):");
	CreateBiTree(T);
	printf("\n����������:");
	InOrderTraverse(*T, Visit);
	printf("\n����������:"); 
	LastOrderTraverse(*T, Visit);
	printf("\n����������:");
	LevelOrderTraverse(*T, Visit);
	return 0;
}

//ǰ��������������� 
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

//����ʱ���ʺ���
Elemtype Visit(BiTree T)
{
	printf("%c",T->data);
	return T->data;
} 

//����������������
void InOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T))
{
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T);
		InOrderTraverse(T->rchild, Visit);
	}
}

//����������������
void LastOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T))
{
	if(T)
	{
		LastOrderTraverse(T->lchild, Visit);
		LastOrderTraverse(T->rchild, Visit);
		Visit(T);
	}
}

//���������������� 
void LevelOrderTraverse(BiTree T, Elemtype (*Visit)(BiTree T)) 
{
	int in = 0, out = 0;  //ʹ����������ʾ����	
	BiTree queue[TREE_MAX_SIZE] = {0};
	if(T)
		queue[in++] = T;
	while(in - out > 0) //���в�Ϊ��
	{
		BiTree cur = queue[out++];
		Visit(cur);
		//ÿ��cur�����У������������������ 
		if(cur->lchild)
			queue[in++] = cur->lchild;
		if(cur->rchild)
			queue[in++] = cur->rchild;
	} 
}
