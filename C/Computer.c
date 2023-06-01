#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//相关宏定义
#define INIT_STACKSIZE 50

//枚举类型定义 
typedef enum Status
{
	ERROR,
	OK
}Status;

//栈数据结构定义 
typedef int Elemtype;
typedef struct  Stack  
{
	Elemtype *top;
	Elemtype *base;
	int stacksize;
}SNode, *Stack;


//初始化新栈 
Status InitStack(Stack *S)
{	
	//初始化内存空间 
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

//压栈 
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

//出栈
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

//得到栈顶元素,将其作为返回值返回
Elemtype GetTop(Stack S)
{
	if( S->top == S->base)
		return ERROR;
	else
		return *(S->top-1);
} 

//判断元素是否在运算符合集内
//在运算符合集内则返回1， 否则返回0 
int InOP(char e, char OP[])
{
	int i = 0;
	while(OP[i] != '\0')
	{
		if(e == OP[i])
			return 1;
		++i;
	}
	//退出循环则不存在 
	return 0;
} 

//比较两个运算符的优先级 
//若a优先级 小于 b优先级   返回 -1
//若a优先级 等于 b优先级   返回 0
//若a优先级 大于 b优先级   返回 1 
int OperatorPrecedence(char a, char b)
{
	//a为加减时
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
	//a为乘除时 
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
	//a为乘方时 
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

//将表达式进行运算 
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
	Stack OPTR;  //寄存运算符 
	Stack OPND;  //寄存操作数或运算结果 
	InitStack(&OPTR);
	InitStack(&OPND);
	
	//相关变量 
	char OP[20] = { '+', '-', '*', '/', '(', ')', '^', '#', '\0'};  //运算符合集
	char c = 0;  //输入字符 
	Elemtype x = 0;  //临时变量 
	int cc[10]={0};  //存放整数的各位数
	int n = 0; //整数的位数 
	int num = 0; // 临时变量 
	Elemtype a=0, b=0; //两个运算数 
	Elemtype theta = 0;  //运算符 
	int flag = 0;  //用于检测表达式是否出现运算符连乘
	 
	//将'#'作为OPTR的栈底元素 
	Push(&OPTR, (int)'#');
	
	printf("输出表达式(以#代表结束):");
	c = getchar();
	//函数主循环 
	while(c != '#' || (char)GetTop(OPTR) != '#')
	{
		//c是运算数 
		if(c>='0' && c <='9')
		{	
			//先存入临时数组，检测是否是大于等于10的整数
			cc[n] = c-'0';
			++n; //位数加一 
			c = getchar();
		}
		//c是运算符 
		else if(InOP(c, OP))
		{	
			//检测表达式合法(是否出现累赘运算符)
			if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
			{	
				if(flag==1)
				{
					printf("请输入合法表达式！\n");
					exit(-2);	
				}
				else
				{
					flag = 1;
				}
			} 
			else
				flag = 0;  //没有出现连续的运算符，重新计数
				 
			//先将前面临时存放的整数入栈
			if(n)
			{
				int i = 0;
				for(i=n-1;i>=0;i--)//计算整数值 
				{	
					if(i==n-1)
						num += cc[i];
					else
						num += cc[i]*10*(n-1-i);
					cc[i] = 0;//重新初始化临时数组 
				}
				Push(&OPND, num);//压栈
				num = 0;
				n = 0; 
			}
			
			//进行运算符操作 
			switch(OperatorPrecedence((char)GetTop(OPTR), c))
			{
				case -1:  //栈顶元素优先级低 
					Push(&OPTR, (int)c);
					c = getchar();
					break;
				case 0:  //优先级相同，脱下括号并接收下一个字符
					Pop(&OPTR, &x);
					c = getchar();
					break;
				case 1:  //退栈并将运算结果入栈
					Pop(&OPTR, &theta);
					Pop(&OPND, &b);
					Pop(&OPND, &a);
					Push(&OPND, Operate(a, (char)theta, b));
					break;			 
			}
		}
		else  //c是非法字符，程序自动结束
		{
			printf("请输入合法表达式！\n");
			exit(-2);	
		} 
	}
	
	//打印结果 
	printf("表达式结果为:%d\n", GetTop(OPND));

	return 0;
}
