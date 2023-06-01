#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��غ궨��
#define INIT_STACKSIZE 50

//ö�����Ͷ��� 
typedef enum Status
{
	ERROR,
	OK
}Status;

//ջ���ݽṹ���� 
typedef int Elemtype;
typedef struct  Stack  
{
	Elemtype *top;
	Elemtype *base;
	int stacksize;
}SNode, *Stack;


//��ʼ����ջ 
Status InitStack(Stack *S)
{	
	//��ʼ���ڴ�ռ� 
	(*S) = (Stack)malloc(sizeof(SNode));
	if(!(*S))
		exit(-1); 
		
	(*S)->base = (Elemtype*)malloc(INIT_STACKSIZE*sizeof(Elemtype));
	if(!(*S)->base)
		exit(-1);
		
	(*S)->top = (*S)->base;
	(*S)->stacksize = INIT_STACKSIZE;
	
	return OK;
}

//ѹջ 
Status Push(Stack *S, Elemtype e)
{	
	if((*S)->top - (*S)->base >= (*S)->stacksize)
		return ERROR;
	else
	{
		*(*S)->top++ = e;
		return OK;
	}
}

//��ջ
Status Pop(Stack *S, Elemtype *e)
{
	if((*S)->top == (*S)->base)
		return ERROR;
	else
	{
		*e = *--(*S)->top;
		return OK;
	}
} 

//�õ�ջ��Ԫ��,������Ϊ����ֵ����
Elemtype GetTop(Stack S)
{
	if( S->top == S->base)
		return ERROR;
	else
		return *(S->top-1);
} 

//�ж�Ԫ���Ƿ���������ϼ���
//��������ϼ����򷵻�1�� ���򷵻�0 
int InOP(char e, char OP[])
{
	int i = 0;
	while(OP[i] != '\0')
	{
		if(e == OP[i])
			return 1;
		++i;
	}
	//�˳�ѭ���򲻴��� 
	return 0;
} 

//�Ƚ���������������ȼ� 
//��a���ȼ� С�� b���ȼ�   ���� -1
//��a���ȼ� ���� b���ȼ�   ���� 0
//��a���ȼ� ���� b���ȼ�   ���� 1 
int OperatorPrecedence(char a, char b)
{
	//aΪ�Ӽ�ʱ
	if( a == '+' || a == '-')
	{
		switch(b)
		{
			case '+':return 1;
			case '-':return 1;
			case '*':return -1;
			case '/':return -1;
			case '^':return -1;
			case '(':return -1;
			case ')':return 1;
			case '#':return 1;
		}
			
	} 
	//aΪ�˳�ʱ 
	else if( a == '*' || a == '/')
	{
		switch(b)
		{
			case '+':return 1;
			case '-':return 1;
			case '*':return 1;
			case '/':return 1;
			case '^':return -1;
			case '(':return -1;
			case ')':return 1;
			case '#':return 1;
		}
	}
	//aΪ�˷�ʱ 
	else if( a == '^')
	{
		switch(b)
		{
			case '+':return 1;
			case '-':return 1;
			case '*':return 1;
			case '/':return 1;
			case '^':return 1;
			case '(':return -1;
			case ')':return 1;
			case '#':return 1;
		}
	}
	else if( a == '(')
	{
		switch(b)
		{
			case '+':return -1;
			case '-':return -1;
			case '*':return -1;
			case '/':return -1;
			case '^':return -1;
			case '(':return -1;
			case ')':return 0;
		}
	}
	else if( a == ')')
	{
		switch(b)
		{
			case '+':return 1;
			case '-':return 1;
			case '*':return 1;
			case '/':return 1;
			case '^':return 1;
			case ')':return 1;
			case '#':return 1;
		}
	}
	else // a == '#'
	{
		switch(b)
		{
			case '+':return -1;
			case '-':return -1;
			case '*':return -1;
			case '/':return -1;
			case '^':return -1;
			case '(':return -1;
			case '#':return 0;
		}
	}
}

//�����ʽ�������� 
Elemtype Operate(Elemtype a, char theta, Elemtype b)
{
	switch(theta)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return pow(a,b);
	}
}

int main()
{
	Stack OPTR;  //�Ĵ������ 
	Stack OPND;  //�Ĵ�������������� 
	InitStack(&OPTR);
	InitStack(&OPND);
	
	//��ر��� 
	char OP[20] = { '+', '-', '*', '/', '(', ')', '^', '#', '\0'};  //������ϼ�
	char c = 0;  //�����ַ� 
	Elemtype x = 0;  //��ʱ���� 
	int cc[10]={0};  //��������ĸ�λ��
	int n = 0; //������λ�� 
	int num = 0; // ��ʱ���� 
	Elemtype a=0, b=0; //���������� 
	Elemtype theta = 0;  //����� 
	int flag = 0;  //���ڼ����ʽ�Ƿ�������������
	 
	//��'#'��ΪOPTR��ջ��Ԫ�� 
	Push(&OPTR, (int)'#');
	
	printf("������ʽ(��#�������):");
	c = getchar();
	//������ѭ�� 
	while(c != '#' || (char)GetTop(OPTR) != '#')
	{
		//c�������� 
		if(c>='0' && c <='9')
		{	
			//�ȴ�����ʱ���飬����Ƿ��Ǵ��ڵ���10������
			cc[n] = c-'0';
			++n; //λ����һ 
			c = getchar();
		}
		//c������� 
		else if(InOP(c, OP))
		{	
			//�����ʽ�Ϸ�(�Ƿ������׸�����)
			if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
			{	
				if(flag==1)
				{
					printf("������Ϸ����ʽ��\n");
					exit(-2);	
				}
				else
				{
					flag = 1;
				}
			} 
			else
				flag = 0;  //û�г�������������������¼���
				 
			//�Ƚ�ǰ����ʱ��ŵ�������ջ
			if(n)
			{
				int i = 0;
				for(i=n-1;i>=0;i--)//��������ֵ 
				{	
					if(i==n-1)
						num += cc[i];
					else
						num += cc[i]*10*(n-1-i);
					cc[i] = 0;//���³�ʼ����ʱ���� 
				}
				Push(&OPND, num);//ѹջ
				num = 0;
				n = 0; 
			}
			
			//������������� 
			switch(OperatorPrecedence((char)GetTop(OPTR), c))
			{
				case -1:  //ջ��Ԫ�����ȼ��� 
					Push(&OPTR, (int)c);
					c = getchar();
					break;
				case 0:  //���ȼ���ͬ���������Ų�������һ���ַ�
					Pop(&OPTR, &x);
					c = getchar();
					break;
				case 1:  //��ջ������������ջ
					Pop(&OPTR, &theta);
					Pop(&OPND, &b);
					Pop(&OPND, &a);
					Push(&OPND, Operate(a, (char)theta, b));
					break;			 
			}
		}
		else  //c�ǷǷ��ַ��������Զ�����
		{
			printf("������Ϸ����ʽ��\n");
			exit(-2);	
		} 
	}
	
	//��ӡ��� 
	printf("���ʽ���Ϊ:%d\n", GetTop(OPND));

	return 0;
}
