//��ӹ�ƽ����
//n����ӵ�ѭ��������ΰ���ʹ�ø��ӱ�����������ܹ�ƽ
//��ʹ������С��������ܴ� 
#include <stdio.h>

int all[20][20][2]={0};//���������Է�ʽ
int arr[1000][3]={0};//��ʽ�洢��Է�ʽ 
int num = 0;

void GetCom(int n)//��ȡ��Է�ʽ 
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
	//Debug����ӡ���е���Է�ʽ 
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
	//Debug:��ӡ��ʽ�洢
	/*
	for(i=0;i<day;i++)
	{
		printf("(%d,%d) ",arr[i][0],arr[i][1]);
	}
	*/
}
void PrintAll(int n)//��ӡ������������ 
{
	int i,j;
	int day = n*(n-1)/2;
	int count = 0;
	int tmp[1000][3]={0};

	while(count<day)
	{	
		if(tmp[i][2]==0)
			printf("(%d,%d) ",arr[i][0],arr[i][1]);
		arr[i][2]=1;//��ռ�� 
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
	scanf("%d",&n);//�������
	num = n;
	GetCom(n);
	
	PrintAll(n); //��ӡ�������� 
	return 0;
}
