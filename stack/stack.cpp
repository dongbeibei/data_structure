
#include "stack.h"

#include <iostream>

Stack::Stack()
{
	InitStack();
}

Stack::~Stack()
{
	DestoryStack();
}

bool Stack::ClearStack()
{
	S.top = S.base;

	return OK;
}

bool Stack::StackEmpty()
{
	if(S.base == S.top)
		return OK;
	else
		return ERROR;
}

int Stack::StackLength()
{
	return (S.top - S.base);
}

bool Stack::GetTop(SElemType &q)
{
	if(S.base == S.top)
		return ERROR;

	q = *(S.top - 1);

	return OK;
}

bool Stack::Push(SElemType q)
{
	if(StackLength() >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(SElemType *));
		if(!S.base)
		{
			std::cout<<"realloc fail"<<std::endl;
			return ERROR;
		}

		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}

	*S.top++ = q;

	return OK;
}

bool Stack::Pop(SElemType &q)
{
	if(S.base == S.top)
		return ERROR;

	q = *(--S.top);

	return OK;
}

bool Stack::StackTraverse()
{
	SElemType	*temp;

	temp = S.top;

	for(temp-- ; temp!=S.base ; temp--)
		visit(temp);
	std::cout<<endl;

	return OK;
}

bool Stack::InitStack()
{
	S.base = (SElemType *)malloc(STACK_ININT_SIZE * sizeof(SElemType));
	if(!S.base)
	{
		std::cout<<"malloc fail, init fail"<<std::endl;
		return ERROR;
	}
	S.top = S.base;
	S.stacksize = STACK_ININT_SIZE;

	return OK;
}

bool Stack::DestoryStack()
{
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;

	return OK;
}

bool Stack::visit(SElemType *p)
{
	std::cout<<*p<<"  ";

	return OK;
}
