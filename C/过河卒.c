#include <stdio.h>
int n,m; //B坐标 
int nn,mm; //马 坐标 
int map[21][21]={0};//地图标记 
long long dp[21][21]={0};//结果 

void Defense()//将马防守的点标记 
{	
	map[nn][mm]=1;
	if(nn-1>=0)
	{	
		if(mm-2>=0)
			map[nn-1][mm-2]=1;
		if(mm+2<=m)
			map[nn-1][mm+2]=1;
		if(nn-2>=0)
		{
			if(mm-1>=0)
				map[nn-2][mm-1]=1;
			if(mm+1<=m)
				map[nn-2][mm+1]=1;
		}
	}
	if(nn+1<=n)
	{
		if(mm-2>=0)
			map[nn+1][mm-2]=1;
		if(mm+2<=m)
			map[nn+1][mm+2]=1;
		if(nn+2<=n)
		{
			if(mm-1>=0)
				map[nn+2][mm-1]=1;
			if(mm+1<=m)
				map[nn+2][mm+1]=1;
		}
	}
}
long long Get_Dp(int x, int y)
{	
	dp[0][0]=1;
	int i,j;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{	
			if(i!=0||j!=0)
			{
				if(i>0&&j>0)
					dp[i][j] = dp[i-1][j]+dp[i][j-1];
				
				else if(i>0&&j==0)
					dp[i][j] = dp[i-1][j];
				
				else if(i==0&&j>0)
					dp[i][j] = dp[i][j-1];
				
			}
			if(map[i][j]==1)
				dp[i][j]=0;	
		}
	}
	return dp[x][y];
}


int main()
{
	scanf("%d%d%d%d",&n,&m,&nn,&mm);
	Defense();//马控制不能走的位置
	printf("%lld\n",Get_Dp(n,m));
	return 0;
}
