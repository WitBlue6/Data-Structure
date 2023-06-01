#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct
{
	int key[MAXSIZE];
	int num[MAXSIZE];
	int len;
}List,*SqList;

int HSearch(SqList R, int target)  //哈希表遍历查找 
{
	int i, j=-1;
	for(i=0;i<R->len;i++)
	{
		if(R->num[i] == target)
		{
			j = i;
			break;
		}
	}
	if(j==-1)
		return -1;
	return R->key[j];
}

void InitList(SqList *R)
{
	(*R)->len = 0;
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		(*R)->key[i] = -1;
		(*R)->num[i] = -1;
	}
}

int main()
{
	int nums[20] = {0};
	int target = 0;
	int i = 0, j = 0, n = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&nums[i]);
	scanf("%d",&target);
	
	SqList R = (SqList)malloc(sizeof(List));
	InitList(&R);
	//创建哈希表 
	for(i=0;i<n;i++)
	{
		int H = nums[i] % n; //哈希函数 
		if(R->key[H]!=-1)   //该位置已被占 
		{	
			while(R->key[H]!=-1)
			{
				++H;
				if(H==n)
					H=0;
			}
		}
		R->key[H] = i;
		R->num[H] = nums[i];
		R->len++;
	}
	for(i=0;i<R->len;i++)
	{	
		int H = HSearch(R, target - R->num[i]);
		if(H!=-1)
		{	
			printf("%d %d\n",H, R->key[i]);
			break;
		}
		
	}
	return 0;
}
