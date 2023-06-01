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
	int nums;//非零元素个数 
}SpMatrix;

Status InitSpMatrix(SpMatrix ** S, int rows, int cols) //初始化一个rows ×cols稀疏矩阵 
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
Status AddTriplet(SpMatrix **S, Triplet *T)  //添加三元组 
{
	(*S)->data = (Triplet*)realloc((*S)->data, ++(*S)->nums*sizeof(Triplet)); //扩充 每次nums加一 
	if(!(*S)->data)
		exit(-1);
	if(T->row <= (*S)->rows && T->col <= (*S)->cols) //将三元组添加进稀疏矩阵 
	{
		(*S)->data[(*S)->nums-1].row = T->row;
		(*S)->data[(*S)->nums-1].col = T->col;
		(*S)->data[(*S)->nums-1].value = T->value;
		return OK;
	}
	else
		return ERROR;
}
Triplet* GetTriplet()  //从输入端获得一个三元组 
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
Status AddSpMatrix(SpMatrix* S1, SpMatrix* S2)  //将两个稀疏矩阵相加的结果打印 (垃圾算法，能过就行)
{
	//二重循环遍历，对比row和col
	int i,j;
	int flag = 0;
	int first = 1; //无意义，区分打印格式 
	for(i=0;i<S1->nums;i++)
	{
		for(j=0;j<S2->nums;j++)
		{
			if(S1->data[i].col == S2->data[j].col && S1->data[i].row == S2->data[j].row) //S1->data[i]找到对应元素
			{	
				flag = 1;
				//打印元素和 
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
		//S1->data[i]未找到对应元素，直接打印改元素 
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
	//又用了一遍二重循环，这次遍历找到S2中没被打印的元素
	//真sb啊这个算法，没事能过就行 
	for(i=0;i<S2->nums;i++)
	{
		for(j=0;j<S1->nums;j++)
		{
			if(S2->data[i].col == S1->data[j].col && S2->data[i].row == S1->data[j].row) //S2->data[i]找到对应元素
			{	
				flag = 1;
			} 
		}	
		//S2->data[i]未找到对应元素，打印该元素 
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
	
	Triplet *temp;  //临时的三元组，用于储存输入信息 
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
	
	AddSpMatrix(S1,S2); //哇终于写完了 
	return 0;
}
