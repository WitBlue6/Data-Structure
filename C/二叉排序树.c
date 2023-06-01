#include <stdio.h>
#include <stdlib.h>

//相关宏定义
#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)
 
typedef int Elemtype; 

typedef struct BiNode
{
	Elemtype num;
	struct BiNode *lchild;
	struct BiNode *rchild;
	
}BiNode, *BiTree;  //二叉树 

//二叉排序树的搜索
/*
	若搜索到目标， p为目标位置的双亲结点地址, 返回值为目标结点地址 
	若未搜索到目标， p为待插入位置的双亲结点地址 , 返回值为NULL 
*/
BiTree SearchBiTree(BiTree T, Elemtype e, BiTree *p)  
{	
	if(!T)		
		return T;	
	else if EQ(e,T->num)
		return T;	
	else
	{	
		*p = T;
		if LT(e,T->num)	  //目标比该结点元素小，查找左子树 
			return SearchBiTree(T->lchild, e, p);
		else
			return SearchBiTree(T->rchild, e, p);
	}
}

void InsertBiTree(BiTree *T, Elemtype e)  //二叉排序树的搜索及插入
{	
	BiTree p = NULL;
	if(!SearchBiTree(*T, e, &p))  //返回值为NULL, 树中不存在该结点 
	{
		if(!p)  //双亲为NULL，不存在根结点
		{
			*T = (BiTree)malloc(sizeof(BiNode));
			(*T)->num = e;
			(*T)->lchild = NULL;
			(*T)->rchild = NULL;
		} 
		else  //存在根节点，在双亲结点下根据大小关系创建新结点 
		{
			BiTree newnode = (BiTree)malloc(sizeof(BiNode));
			newnode->num = e;
			newnode->lchild = NULL;
			newnode->rchild = NULL;
			if LT(e,p->num)  //e比双亲结点元素小，创建左子树 
				p->lchild = newnode;
			else
				p->rchild = newnode;
		}
	}
}

int DeleteBiTree(BiTree *T, Elemtype e)  //二叉排序树的删除
{	
	BiTree del_p = NULL; //待删除结点的双亲 
	BiTree del = SearchBiTree(*T, e, &del_p);
	if(!del)
		return 0;  //del为空，不存在待删除结点 
	if LQ(e,(*T)->num)  //删除左子树或根节点
	{
		//将删除节点的左子树，转移到按右子树的中序遍历，得到的第一个结点的左子树上 
		BiTree p = del->rchild;
		if(p)  //del存在右子树 
		{
			while(p->lchild != NULL)
				p = p->lchild; //模拟中序遍历过程 
			
			//此时p指向右子树中序遍历的第一个结点 
			p->lchild = del->lchild;
			
			if(del_p)  //del存在双亲 
				del_p->lchild = del->rchild;
			else  //del没有双亲( del为根节点 )
			{
				//将del的右子树作为根节点 
				*T = del->rchild; 
			}
		}
		else  //没有右子树 
		{
			if(del_p)  //del存在双亲 
				del_p->lchild = del->lchild;
			else  //del没有右子树还没有双亲，孤儿一个 
			{
				//将del的左子树作为根节点 
				*T = del->lchild; 
			}
		}
		free(del);
		del = NULL;
		del_p = NULL;
	} 
	else  //删除右子树同理, 转移到左子树的后序遍历第一个结点的右子树上 
	{
		BiTree p = del->lchild;
		if(p)
		{
			while(p->rchild != NULL)
				p = p->rchild;
				
			p->rchild = del->rchild;
			if(del_p)
				del_p->rchild = del->lchild;
			else
				*T = del->lchild;
		}
		else
		{
			if(del_p)
				del_p->rchild = del->rchild;
			else
				*T = del->rchild;
		}
		free(del);
		del = NULL;
		del_p = NULL;
	}
	return 1;
} 

void InOrderTraverse(BiTree T)  //二叉树中序遍历 
{
	if(T)
	{	
		InOrderTraverse(T->lchild);
		printf("%d  ",T->num);
		InOrderTraverse(T->rchild);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	BiTree T = NULL;
	int i = 0;
	printf("原始数据：");
	for(i=0;i<n;i++)
	{	
		int e;
		scanf("%d",&e);
		InsertBiTree(&T,e);
		printf("%d ",e);
	}
	printf("\n中序遍历结果：");
	InOrderTraverse(T);
	scanf("%d",&n);
	printf("\n删除结点后结果：");
	if(DeleteBiTree(&T,n))
	{
		InOrderTraverse(T);
		printf("\n");
	}
	else
		printf("没有%d结点。\n",n);
	
	return 0;
}
