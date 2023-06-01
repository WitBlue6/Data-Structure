//ÂòÇ¦±Ê
//https://www.luogu.com.cn/problem/P1909
#include <stdio.h>
int main()
{
	int arr[3][2] ={0};
	int n;//Ç¦±Ê×ÜÁ¿ 
	scanf("%d",&n);
	int i,j;
	for(i=0;i<3;i++)
	{
		scanf("%d%d",&arr[i][0],&arr[i][1]);
	}
	int min = 0;
	if(n%arr[0][0]!=0)
		min = (n/arr[0][0]+1)*arr[0][1];
	else
		min = (n/arr[0][0])*arr[0][1];
	for(i=0;i<3;i++)
	{
		int tmp = 0;
		if(n%arr[i][0]!=0)
			tmp = (n/arr[i][0]+1)*arr[i][1];
		else
			tmp = (n/arr[i][0])*arr[i][1];
		if(tmp <= min)
		{
			min = tmp;
		}
	}
	printf("%d\n",min);
	return 0;
}
