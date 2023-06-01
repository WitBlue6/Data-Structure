#include <stdio.h>

void Bubble_Sort_Reverse(int *arr, int len)  //冒泡排序从大到小排列 
{
	int i, j;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int n, m, i, j;
	while(scanf("%d",&n)!=EOF)
	{	
		scanf("%d",&m);
		int arr[50]={0};
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		Bubble_Sort_Reverse(arr, n);
		for(i=0;i<m;i++)
		{
			if(i==m-1)
				printf("%d\n",arr[i]);
			else
				printf("%d ",arr[i]);
		}
	}
	return 0;
}
