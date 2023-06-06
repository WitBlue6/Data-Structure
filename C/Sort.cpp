#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef int KeyType; //关键字类型为整型

typedef struct{
	KeyType key;	//关键字项 
	char otherinfo;  //其他数据项 
}RedType; //记录类型

typedef struct{
	RedType r[MAXSIZE+1];  //r[0]闲置
	int length;  //顺序表长度	 
}SqList; 

void InsertionSort(SqList &L)  //直接插入排序 
{	
	int i,j;
	for(i=2;i<=L.length;++i)
	{
		if(L.r[i].key < L.r[i-1].key)
		{
			L.r[0] = L.r[i];  //复制为监视哨
			for(j=i-1;L.r[0].key<L.r[j].key;--j)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0]; 
		}
	}
}

void ShellInsert(SqList &L, int dk)  //一趟希尔插入排序 
{	
	int i,j; 
	for(i=dk+1;i<=L.length;++i)
	{
		L.r[0] = L.r[i];
		for(j=i-dk;j>0&&(L.r[0].key<L.r[j].key);j-=dk)
			L.r[j+dk]=L.r[j];
		L.r[j+dk]=L.r[0];
	}
}
void ShellSort(SqList &L, int dlta[], int t) //增量为dlta[]的希尔排序 
{
	int i;
	for(i=0;i<t;++i)
		ShellInsert(L, dlta[i]); 
}

int Partition(RedType R[], int low, int high) //一趟快速排序
{
	R[0] = R[low];
	int pivotkey = R[low].key; //枢轴 
	while(low<high)
	{
		while(low<high && R[high].key>=pivotkey)
			--high; //从右向左搜索	
		R[low]=R[high];
		while(low<high && R[low].key<=pivotkey)
			++low; //从左往右搜索
		R[high]=R[low]; 
	}	
	R[low]=R[0];
	return low;
} 
void QSort(RedType R[], int low, int high) //快速排序
{
	if(low < high)
	{
		int pivotloc = Partition(R, low, high);
		QSort(R, low, pivotloc-1); //对低子序列排序
		QSort(R, pivotloc+1, high); //对高子序列排序	
	}
} 

int SelectMinKey(RedType R[], int i, int n)  //在R[i...n]中选择最小值 
{
	int min = i;
	int j;
	for(j=i;j<=n;++j)
	{
		if(R[j].key<R[min].key)
			min=j;
	}
	return min; 
}
void SelectSort(RedType R[], int n)  //简单选择排序 
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		j = SelectMinKey(R, i, n); 
		if(i!=j)
		{
			RedType tmp = R[i];
			R[i] = R[j];
			R[j] = tmp;
		}
	}
}

void Swap(int *num, int i, int j)
{
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

// 最大堆调整
void Heapify(int *num, int len, int k)
{
    if (k < len)
    {
        int root = k;           // 根结点
        int lchild = 2*k + 1;   // 左孩子结点
        int rchild = 2*k + 2;   // 右孩子结点
        // 查找左右孩子结点中的最大结点
        if (lchild < len && num[root] < num[lchild])
        {
            root = lchild; 
        }
        if (rchild < len && num[root] < num[rchild])
        {
            root = rchild;
        }
        
        // 交换最大结点到根结点
        if (root != k)
        {
            Swap(num, root, k);
            // 每次交换都可能影响到对应孩子结点子树的顺序
            // 所以需要对交换后的孩子结点子树进行最大堆调整
            Heapify(num, len, root);
        }
    }
}

// 创建最大堆
void CreateHeap(int *num, int len)
{
    int i;
    // 最后一个结点下标
    int last = len - 1;   
    // 最后一个结点的父结点下标      
    int parent = (last - 1) / 2;
    // 从最后一个结点的父结点到根结点，依次进行最大堆调整
    for (i = parent; i >= 0; i--)
    {
        Heapify(num, len, i);
    }
}

// 堆排序
void HeapSort(int *num, int len)
{
    // 创建最大堆并进行最大堆调整
    CreateHeap(num, len);
    int i;
    // 依次取出根结点（最大值）
    for (i = len - 1; i >= 0; i--)
    {
        // 将最大堆的根结点（最大值）换到最后一个结点
        Swap(num, i, 0);
        // 交换后二叉树的根结点发生了改变，故还需对根结点做最大堆调整（已交换的末尾结点不参与调整）
        // 而此时根结点小于所有父结点，因而在调整时只需考虑最大孩子的分支即可
        Heapify(num, i, 0); 
    }   
}

int main()
{
	SqList L;
	L.length = 0;
	int i;
	int arr[10]={0};
	//程序的输入 
	for(i=1;i<=10;i++)
	{
		scanf("%d",&L.r[i].key);
		arr[i-1] = L.r[i].key;
		++L.length;
	}
//	srand((size_t)time(NULL));
//	for(i=1;i<=30;i++)
//	{
//		L.r[i].key = rand()%100;
//		++L.length;
//	}
	printf("排序前:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
	
	InsertionSort(L);
	
	printf("\n插入排序后:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
		
	int delt[4] = {5, 3, 2, 1};
	ShellSort(L, delt, 4);
	
	printf("\n希尔排序后:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);

	QSort(L.r, 1, L.length);
	printf("\n快速排序后:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
	
	SelectSort(L.r, L.length);
	printf("\n选择排序后:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
		
	HeapSort(arr, L.length);
	printf("\n堆排序后:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);	
	return 0;
}


