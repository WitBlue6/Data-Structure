#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREASE_SIZE 20

typedef char Elemtype;

typedef struct Stack
{
	Elemtype* top;
	Elemtype* base;
	int stacksize;
}Stack;
int InitStack(Stack &S) //��ʼ��ջ 
{
	S.base = (Elemtype*)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
	if(!S.base)
		return 0;
		
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
int Pump(Stack &S, Elemtype* e) //ѹջ 
{
	if(S.top-S.base >= S.stacksize)
		return 0;
		
	*S.top++ = *e;
	return 1;
}
int Pop(Stack &S, Elemtype* e) //��ջ 
{
	if(S.top==S.base)
		return 0;
	
	*e = *--S.top;
	return 1;
}
int GetTop(Stack &S, Elemtype* e)  //�õ�ջ��Ԫ��
{
	if(S.top==S.base)
		return 0;
	*e = *(S.top-1);
	return 1;
} 
int main()
{
	Stack S;
	InitStack(S);
	
	return 0;
}
