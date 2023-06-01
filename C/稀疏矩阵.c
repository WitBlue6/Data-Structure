#include <stdio.h>
#include <stdlib.h>

typedef enum Status
{
	ERROR=0,
	OK=1
}Status;

typedef int Elemtype;

typedef struct Triplet
{
	int row;
	int col;
	Elemtype value;
}Triplet;

typedef struct SpMatrix
{
	Triplet *data;
	int rows;
	int cols;
	int nums;//����Ԫ�ظ��� 
}SpMatrix;

Status InitSpMatrix(SpMatrix ** S, int rows, int cols) //��ʼ��һ��rows ��colsϡ����� 
{
	(*S) = (SpMatrix*)malloc(sizeof(SpMatrix));
	if(!(*S))
		exit(-1);
	(*S)->rows = rows;
	(*S)->cols = cols;
	(*S)->nums = 0;
	(*S)->data = NULL;
	return OK;
}
Status AddTriplet(SpMatrix **S, Triplet *T)  //�����Ԫ�� 
{
	(*S)->data = (Triplet*)realloc((*S)->data, ++(*S)->nums*sizeof(Triplet)); //���� ÿ��nums��һ 
	if(!(*S)->data)
		exit(-1);
	if(T->row <= (*S)->rows && T->col <= (*S)->cols) //����Ԫ����ӽ�ϡ����� 
	{
		(*S)->data[(*S)->nums-1].row = T->row;
		(*S)->data[(*S)->nums-1].col = T->col;
		(*S)->data[(*S)->nums-1].value = T->value;
		return OK;
	}
	else
		return ERROR;
}
Triplet* GetTriplet()  //������˻��һ����Ԫ�� 
{
	int n = 0;
	Triplet *T = (Triplet*)malloc(sizeof(Triplet));
	scanf("%d",&n);
	getchar(); 
	T->row = n;
	scanf("%d",&n);
	getchar();
	T->col = n;
	scanf("%d",&n);
	T->value = n;
	return T;
}
Status AddSpMatrix(SpMatrix* S1, SpMatrix* S2)  //������ϡ�������ӵĽ����ӡ (�����㷨���ܹ�����)
{
	//����ѭ���������Ա�row��col
	int i,j;
	int flag = 0;
	int first = 1; //�����壬���ִ�ӡ��ʽ 
	for(i=0;i<S1->nums;i++)
	{
		for(j=0;j<S2->nums;j++)
		{
			if(S1->data[i].col == S2->data[j].col && S1->data[i].row == S2->data[j].row) //S1->data[i]�ҵ���ӦԪ��
			{	
				flag = 1;
				//��ӡԪ�غ� 
				if(S1->data[i].value + S2->data[j].value)
				{	
					if(first)
					{
						printf("%d,%d,",S1->data[i].row, S1->data[i].col);
						printf("%d",S1->data[i].value + S2->data[j].value);
						first =0;
					}
					else
					{
						printf(";%d,%d,",S1->data[i].row, S1->data[i].col);
						printf("%d",S1->data[i].value + S2->data[j].value);
					}
				}
			} 
		}
		//S1->data[i]δ�ҵ���ӦԪ�أ�ֱ�Ӵ�ӡ��Ԫ�� 
		if(!flag)
		{	
			if(first)
			{
				printf("%d,%d,",S1->data[i].row, S1->data[i].col);
				printf("%d",S1->data[i].value);
				first = 0;
			}
			else
			{
				printf(";%d,%d,",S1->data[i].row, S1->data[i].col);
				printf("%d",S1->data[i].value);
			}
		} 
		flag = 0;
	} 
	//������һ�����ѭ������α����ҵ�S2��û����ӡ��Ԫ��
	//��sb������㷨��û���ܹ����� 
	for(i=0;i<S2->nums;i++)
	{
		for(j=0;j<S1->nums;j++)
		{
			if(S2->data[i].col == S1->data[j].col && S2->data[i].row == S1->data[j].row) //S2->data[i]�ҵ���ӦԪ��
			{	
				flag = 1;
			} 
		}	
		//S2->data[i]δ�ҵ���ӦԪ�أ���ӡ��Ԫ�� 
		if(!flag)
		{
			if(first)
			{
				printf("%d,%d,",S2->data[i].row, S2->data[i].col);
				printf("%d",S2->data[i].value);
				first = 0;
			}
			else
			{
				printf(";%d,%d,",S2->data[i].row, S2->data[i].col);
				printf("%d",S2->data[i].value);
			}
		} 
		flag = 0;
	} 	
	printf("\n");
}
int main()
{
	SpMatrix *S1, *S2;
	int i = 0;
	int n = 0;
	InitSpMatrix(&S1,10,10);
	InitSpMatrix(&S2,10,10);
	
	Triplet *temp;  //��ʱ����Ԫ�飬���ڴ���������Ϣ 
	do
	{
		temp = GetTriplet();
		AddTriplet(&S1,temp);
	}while(getchar()!='\n');
	
	do
	{
		temp = GetTriplet();
		AddTriplet(&S2,temp);
	}while(getchar()!='\n');
	
	AddSpMatrix(S1,S2); //������д���� 
	return 0;
}
