#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int queens[20]={0};
int sum =0;
int max = 0;


void show()
{
	printf("\n\n No.%2d:\n",sum);
	int i,j;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(queens[i]==j)
				printf("%d ",j);
		}
	}
}
int check(int queen)
{
	int i,j;
	for(i=0;i<queen;i++)
	{
		if(queens[i]==queens[queen]/*检查列*/ || abs(queens[queen]-queens[i])==queen-i/*对角线*/)
		{
			return 0;
		}
	}
	return 1;
}
int EightQueen(int n)
{
	if(n<max)
	{
		int i,j;
		for(i=0;i<max;i++)
		{
			queens[n]=i;
			if(check(n))
			{
				EightQueen(n+1);
			}
		}
	}
	else
	{
		sum++;
		show();
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	max = n;
	
	EightQueen(0);
	printf("\n%d\n",sum);
	
	return 0;
}
