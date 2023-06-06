#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef int KeyType; //�ؼ�������Ϊ����

typedef struct{
	KeyType key;	//�ؼ����� 
	char otherinfo;  //���������� 
}RedType; //��¼����

typedef struct{
	RedType r[MAXSIZE+1];  //r[0]����
	int length;  //˳�����	 
}SqList; 

void InsertionSort(SqList &L)  //ֱ�Ӳ������� 
{	
	int i,j;
	for(i=2;i<=L.length;++i)
	{
		if(L.r[i].key < L.r[i-1].key)
		{
			L.r[0] = L.r[i];  //����Ϊ������
			for(j=i-1;L.r[0].key<L.r[j].key;--j)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0]; 
		}
	}
}

void ShellInsert(SqList &L, int dk)  //һ��ϣ���������� 
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
void ShellSort(SqList &L, int dlta[], int t) //����Ϊdlta[]��ϣ������ 
{
	int i;
	for(i=0;i<t;++i)
		ShellInsert(L, dlta[i]); 
}

int Partition(RedType R[], int low, int high) //һ�˿�������
{
	R[0] = R[low];
	int pivotkey = R[low].key; //���� 
	while(low<high)
	{
		while(low<high && R[high].key>=pivotkey)
			--high; //������������	
		R[low]=R[high];
		while(low<high && R[low].key<=pivotkey)
			++low; //������������
		R[high]=R[low]; 
	}	
	R[low]=R[0];
	return low;
} 
void QSort(RedType R[], int low, int high) //��������
{
	if(low < high)
	{
		int pivotloc = Partition(R, low, high);
		QSort(R, low, pivotloc-1); //�Ե�����������
		QSort(R, pivotloc+1, high); //�Ը�����������	
	}
} 

int SelectMinKey(RedType R[], int i, int n)  //��R[i...n]��ѡ����Сֵ 
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
void SelectSort(RedType R[], int n)  //��ѡ������ 
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

// ���ѵ���
void Heapify(int *num, int len, int k)
{
    if (k < len)
    {
        int root = k;           // �����
        int lchild = 2*k + 1;   // ���ӽ��
        int rchild = 2*k + 2;   // �Һ��ӽ��
        // �������Һ��ӽ���е������
        if (lchild < len && num[root] < num[lchild])
        {
            root = lchild; 
        }
        if (rchild < len && num[root] < num[rchild])
        {
            root = rchild;
        }
        
        // ��������㵽�����
        if (root != k)
        {
            Swap(num, root, k);
            // ÿ�ν���������Ӱ�쵽��Ӧ���ӽ��������˳��
            // ������Ҫ�Խ�����ĺ��ӽ�������������ѵ���
            Heapify(num, len, root);
        }
    }
}

// ��������
void CreateHeap(int *num, int len)
{
    int i;
    // ���һ������±�
    int last = len - 1;   
    // ���һ�����ĸ�����±�      
    int parent = (last - 1) / 2;
    // �����һ�����ĸ���㵽����㣬���ν������ѵ���
    for (i = parent; i >= 0; i--)
    {
        Heapify(num, len, i);
    }
}

// ������
void HeapSort(int *num, int len)
{
    // �������Ѳ��������ѵ���
    CreateHeap(num, len);
    int i;
    // ����ȡ������㣨���ֵ��
    for (i = len - 1; i >= 0; i--)
    {
        // �����ѵĸ���㣨���ֵ���������һ�����
        Swap(num, i, 0);
        // ������������ĸ���㷢���˸ı䣬�ʻ���Ը���������ѵ������ѽ�����ĩβ��㲻���������
        // ����ʱ�����С�����и���㣬����ڵ���ʱֻ�迼������ӵķ�֧����
        Heapify(num, i, 0); 
    }   
}

int main()
{
	SqList L;
	L.length = 0;
	int i;
	int arr[10]={0};
	//��������� 
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
	printf("����ǰ:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
	
	InsertionSort(L);
	
	printf("\n���������:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
		
	int delt[4] = {5, 3, 2, 1};
	ShellSort(L, delt, 4);
	
	printf("\nϣ�������:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);

	QSort(L.r, 1, L.length);
	printf("\n���������:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
	
	SelectSort(L.r, L.length);
	printf("\nѡ�������:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);
		
	HeapSort(arr, L.length);
	printf("\n�������:");
	for(i=1;i<=L.length;++i)
		printf("%d ", L.r[i].key);	
	return 0;
}


