#include <stdio.h>
int a = 0;//ȫ�ֱ��� 

int Fuction(int n,int m)
{
	int num = 0;//����
	int count = 0;//���ֺ� 
	int tmp = 0;
	int i = 0;
	for(tmp=0;count<=n;tmp++)
	{	
		num = tmp;
		count = 0;
		for(i=0;i<m;i++)//��λ���� 
		{
			count+=num;
			num++;
		} 
		if(count==n)//�ҵ� 
		{	
			a=tmp;
			return m;//�������ֵĸ��� 
		}
	}
	//δ�ҵ�
	if(n>=m)
		Fuction(n,m+1);//�ݹ� 
	else
		return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int m = 2;//���ָ���
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
		printf("�Ҳ���\n");
	
	return 0;
}

