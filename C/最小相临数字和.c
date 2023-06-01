/*
输入一个数字n
若这个数字能由相邻数字累加得到，输出最少的序列
若不能，输出找不到
*/
#include <stdio.h>
int a = 0;//全局变量 

int Fuction(int n,int m)
{
	int num = 0;//数字
	int count = 0;//数字和 
	int tmp = 0;
	int i = 0;
	for(tmp=0;count<=n;tmp++)
	{	
		num = tmp;
		count = 0;
		for(i=0;i<m;i++)//几位数字 
		{
			count+=num;
			num++;
		} 
		if(count==n)//找到 
		{	
			a=tmp;
			return m;//返回数字的个数 
		}
	}
	//未找到
	if(n>=m)
		Fuction(n,m+1);//递归 
	else
		return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int m = 2;//数字个数
	if((m=Fuction(n,m))!=-1)
	{
		int i;
		printf("%d = %d ",n,a);
		for(i=0;i<m-1;i++)
		{
			a++;
			printf("+ %d ",a);
		}
		printf("\n");
	}
	else
		printf("找不到\n");
	
	return 0;
}

