#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef struct ArcCell  //弧 
{
	int adj; //权值 
	int info; //弧的信息 
	
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph  //图 
{
	char vexs[MAX_VERTEX_NUM];  //顶点信息
	AdjMatrix arcs;  //弧的信息 
	int vexnum, arcnum;  //顶点和弧的个数 
	
}MGraph;

void CreateGraph(MGraph *G)
{
	int i, j;
	
	//初始化 
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
			
	//顶点个数 
	scanf("%d",&G->vexnum);
	getchar();
	//顶点信息 
	for(i=0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vexs[i]);
		getchar();
	}
	//弧的信息
	for(i=0;i<G->vexnum;i++)
	{
		int vextmp = 0;
		int arctmp = 0;
		while(scanf("%d",&vextmp), vextmp!=-1)
		{	
			getchar(); //读取空格 
			scanf("%d",&arctmp);
			G->arcs[i][vextmp].adj = arctmp;  //权值 
			G->arcs[i][vextmp].info = 1;  //存在连向该顶点的弧 
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
