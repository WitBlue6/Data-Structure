#include <stdio.h>
#include <stdlib.h>

//��غ궨��
#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)
 
typedef int Elemtype; 

typedef struct BiNode
{
	Elemtype num;
	struct BiNode *lchild;
	struct BiNode *rchild;
	
}BiNode, *BiTree;  //������ 

//����������������
/*
	��������Ŀ�꣬ pΪĿ��λ�õ�˫�׽���ַ, ����ֵΪĿ�����ַ 
	��δ������Ŀ�꣬ pΪ������λ�õ�˫�׽���ַ , ����ֵΪNULL 
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
		if LT(e,T->num)	  //Ŀ��ȸý��Ԫ��С������������ 
			return SearchBiTree(T->lchild, e, p);
		else
			return SearchBiTree(T->rchild, e, p);
	}
}

void InsertBiTree(BiTree *T, Elemtype e)  //����������������������
{	
	BiTree p = NULL;
	if(!SearchBiTree(*T, e, &p))  //����ֵΪNULL, ���в����ڸý�� 
	{
		if(!p)  //˫��ΪNULL�������ڸ����
		{
			*T = (BiTree)malloc(sizeof(BiNode));
			(*T)->num = e;
			(*T)->lchild = NULL;
			(*T)->rchild = NULL;
		} 
		else  //���ڸ��ڵ㣬��˫�׽���¸��ݴ�С��ϵ�����½�� 
		{
			BiTree newnode = (BiTree)malloc(sizeof(BiNode));
			newnode->num = e;
			newnode->lchild = NULL;
			newnode->rchild = NULL;
			if LT(e,p->num)  //e��˫�׽��Ԫ��С������������ 
				p->lchild = newnode;
			else
				p->rchild = newnode;
		}
	}
}

int DeleteBiTree(BiTree *T, Elemtype e)  //������������ɾ��
{	
	BiTree del_p = NULL; //��ɾ������˫�� 
	BiTree del = SearchBiTree(*T, e, &del_p);
	if(!del)
		return 0;  //delΪ�գ������ڴ�ɾ����� 
	if LQ(e,(*T)->num)  //ɾ������������ڵ�
	{
		//��ɾ���ڵ����������ת�Ƶ���������������������õ��ĵ�һ�������������� 
		BiTree p = del->rchild;
		if(p)  //del���������� 
		{
			while(p->lchild != NULL)
				p = p->lchild; //ģ������������� 
			
			//��ʱpָ����������������ĵ�һ����� 
			p->lchild = del->lchild;
			
			if(del_p)  //del����˫�� 
				del_p->lchild = del->rchild;
			else  //delû��˫��( delΪ���ڵ� )
			{
				//��del����������Ϊ���ڵ� 
				*T = del->rchild; 
			}
		}
		else  //û�������� 
		{
			if(del_p)  //del����˫�� 
				del_p->lchild = del->lchild;
			else  //delû����������û��˫�ף��¶�һ�� 
			{
				//��del����������Ϊ���ڵ� 
				*T = del->lchild; 
			}
		}
		free(del);
		del = NULL;
		del_p = NULL;
	} 
	else  //ɾ��������ͬ��, ת�Ƶ��������ĺ��������һ�������������� 
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

void InOrderTraverse(BiTree T)  //������������� 
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
	printf("ԭʼ���ݣ�");
	for(i=0;i<n;i++)
	{	
		int e;
		scanf("%d",&e);
		InsertBiTree(&T,e);
		printf("%d ",e);
	}
	printf("\n������������");
	InOrderTraverse(T);
	scanf("%d",&n);
	printf("\nɾ����������");
	if(DeleteBiTree(&T,n))
	{
		InOrderTraverse(T);
		printf("\n");
	}
	else
		printf("û��%d��㡣\n",n);
	
	return 0;
}
