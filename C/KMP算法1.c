#include <stdio.h>
#include <string.h>

void Get_Next(char *T,int *next)//NEXT数组 
{	
	//前缀是固定的，后缀是相对的 
	
	int i = 1,j = 0;//i为后缀，j为前缀 
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
		else//发生失配 
		{
			//j回溯
			j = next[j]; 
		}
	}
}

int Index_KMP(char* S, char* T, int pos)//返回字串T在主串S在第pos个字符开始索引到的位置 
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
	if( j> T[0] )//字串全部匹配完成
	{
		return i - T[0];
	} 
	else//匹配失败 
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
	
	printf("输入主串:");
	scanf("%s",tmp1);
	strS[0]=strlen(tmp1);
	for(i=1;i<=strlen(tmp1);i++)
	{
		strS[i]=tmp1[i-1];
	}
	
	printf("输入子串:");
	scanf("%s",tmp2);
	strT[0]=strlen(tmp2);
	for(i=1;i<=strlen(tmp2);i++)
	{
		strT[i]=tmp2[i-1];
	}
	
	int pos = 0;
	printf("输入索引开始处:");
	scanf("%d",&pos);
	
	printf("索引值为%d\n",Index_KMP(strS,strT,pos));
	
	return 0;
}
