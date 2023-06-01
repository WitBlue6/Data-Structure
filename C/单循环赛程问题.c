//球队公平问题
//n个球队单循环赛，如何安排使得各队比赛间隔尽可能公平
//（使比赛最小间隔尽可能大） 
#include <stdio.h>

int all[20][20][2]={0};//存放所有配对方式
int arr[1000][3]={0};//链式存储配对方式 
int num = 0;

void GetCom(int n)//获取配对方式 
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			all[i][j][0]=i+1;
			all[i][j][1]=j+2+i;
		}
	} 
	//Debug：打印所有的配对方式 
	/*
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			printf("(%d,%d) ",all[i][j][0],all[i][j][1]);
		}
		printf("\n");
	}
	*/
	int day = n*(n-1) /2;
	int count = 0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			arr[count][0]=all[i][j][0];
			arr[count][1]=all[i][j][1];
			count++;
		}
	} 
	//Debug:打印链式存储
	/*
	for(i=0;i<day;i++)
	{
		printf("(%d,%d) ",arr[i][0],arr[i][1]);
	}
	*/
}
void PrintAll(int n)//打印所有赛程序列 
{
	int i,j;
	int day = n*(n-1)/2;
	int count = 0;
	int tmp[1000][3]={0};

	while(count<day)
	{	
		if(tmp[i][2]==0)
			printf("(%d,%d) ",arr[i][0],arr[i][1]);
		arr[i][2]=1;//被占用 
		i++;

		count++;
		if(n-1>=2)
			PrintAll(n-1);
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);//球队数量
	num = n;
	GetCom(n);
	
	PrintAll(n); //打印所有赛程 
	return 0;
}
