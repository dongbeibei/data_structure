#ifndef __STACK_H
#define __STACK_H

#include "../base.h"

#define STACK_ININT_SIZE 100
#define STACKINCREMENT 10
#define SElemType int

typedef struct
{
	SElemType	*base;
	SElemType	*top;
	int			stacksize;
}SqStack;

class Stack
{
public:
	Stack();
	~Stack();

	bool ClearStack();
	bool StackEmpty();
	int StackLength();
	bool GetTop(SElemType &);
	bool Push(SElemType);
	bool Pop(SElemType &);
	bool StackTraverse();

private:
	bool InitStack();
	bool DestoryStack();
	bool visit(SElemType *);
	
	SqStack S;
};

#endif
