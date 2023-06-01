#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef struct ArcCell  //�� 
{
	int adj; //Ȩֵ 
	int info; //������Ϣ 
	
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph  //ͼ 
{
	char vexs[MAX_VERTEX_NUM];  //������Ϣ
	AdjMatrix arcs;  //������Ϣ 
	int vexnum, arcnum;  //����ͻ��ĸ��� 
	
}MGraph;

void CreateGraph(MGraph *G)
{
	int i, j;
	
	//��ʼ�� 
	for(i=0;i<MAX_VERTEX_NUM;i++)
		G->vexs[i]=-1;
	for(i=0;i<MAX_VERTEX_NUM;i++)
	{
		for(j=0;j<MAX_VERTEX_NUM;j++)
		{
			G->arcs[i][j].info = 0;
			G->arcs[i][j].adj = -1;
		}
	}
			
	//������� 
	scanf("%d",&G->vexnum);
	getchar();
	//������Ϣ 
	for(i=0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vexs[i]);
		getchar();
	}
	//������Ϣ
	for(i=0;i<G->vexnum;i++)
	{
		int vextmp = 0;
		int arctmp = 0;
		while(scanf("%d",&vextmp), vextmp!=-1)
		{	
			getchar(); //��ȡ�ո� 
			scanf("%d",&arctmp);
			G->arcs[i][vextmp].adj = arctmp;  //Ȩֵ 
			G->arcs[i][vextmp].info = 1;  //��������ö���Ļ� 
			G->arcnum++;
		}
	} 
}

void PrintGraph(MGraph G)
{
	int i, j;
	for(i=0;i<G.vexnum;i++)
	{
		printf("%c  ",G.vexs[i]);
		for(j=MAX_VERTEX_NUM-1;j>=0;j--)
		{	
			if(G.arcs[i][j].info == 1)
				printf("(%d,%d)%d  ",i,j,G.arcs[i][j].adj);
		}
		printf("\n");
	}

}

int main()
{
	MGraph G;
	CreateGraph(&G);
	PrintGraph(G);
	return 0;
}
