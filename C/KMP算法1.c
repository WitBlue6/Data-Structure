#include <stdio.h>
#include <string.h>

void Get_Next(char *T,int *next)//NEXT���� 
{	
	//ǰ׺�ǹ̶��ģ���׺����Ե� 
	
	int i = 1,j = 0;//iΪ��׺��jΪǰ׺ 
	next[1]=0;
	while( i<T[0] )
	{
		if( j==0 || T[i]==T[j] )
		{
			i++;
			j++;
			if( T[i]!=T[j] )
				next[i] = j;
			else
				next[i]=next[j];
		}
		else//����ʧ�� 
		{
			//j����
			j = next[j]; 
		}
	}
}

int Index_KMP(char* S, char* T, int pos)//�����ִ�T������S�ڵ�pos���ַ���ʼ��������λ�� 
{
	int i = pos;
	int j = 1;
	
	int next[255]={0};
	Get_Next(T,next);
	
	while( i<=S[0] && j<=T[0] )
	{
		if( j == 0 || S[i]==T[j] )
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if( j> T[0] )//�ִ�ȫ��ƥ�����
	{
		return i - T[0];
	} 
	else//ƥ��ʧ�� 
	{
		return 0;
	}
}

int main()
{	
	char strS[255]={0};
	char strT[255]={0};
	char tmp1[255] = {0};
	char tmp2[255] = {0};
	int i;
	
	printf("��������:");
	scanf("%s",tmp1);
	strS[0]=strlen(tmp1);
	for(i=1;i<=strlen(tmp1);i++)
	{
		strS[i]=tmp1[i-1];
	}
	
	printf("�����Ӵ�:");
	scanf("%s",tmp2);
	strT[0]=strlen(tmp2);
	for(i=1;i<=strlen(tmp2);i++)
	{
		strT[i]=tmp2[i-1];
	}
	
	int pos = 0;
	printf("����������ʼ��:");
	scanf("%d",&pos);
	
	printf("����ֵΪ%d\n",Index_KMP(strS,strT,pos));
	
	return 0;
}
