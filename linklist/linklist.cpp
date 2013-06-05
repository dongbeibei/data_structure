#include "linklist.h"

#include <iostream>
using std::cout;
using std::endl;

LinkList::LinkList()
{
//	SqList L;

	InitList();
}
LinkList::~LinkList()
{
	DestoryList();
}

bool LinkList::ClearList()
{
	L.length = 0;

	return OK;
}

bool LinkList::ListEmpty()
{
	if(L.length == 0)
		return true;
	else
		return false;
}

int LinkList::ListLength()
{
	return L.length;
}

bool LinkList::GetElem(int i, ElemType &e)
{
	if(i<1 || i> L.length)
		return ERROR;
	
	e = *(L.elem + i - 1);

	return OK;
}

int LinkList::LocateElem(ElemType e)
{
	ElemType *p;
	int	i = 1;

	while(i<L.length && !compare(*p++, e))
		i++;
	if(i<L.length)
		return i;
	else
		return 0;
}

bool LinkList::PeriorElem(ElemType cur_e, ElemType &pre_e)
{
	ElemType *p = L.elem + 1;
	int i = 1;
	
	while(i<L.length && *p!=cur_e)
	{
		p++;
		i++;
	}
	
	if(i > L.length)
		return ERROR;
	else
	{
		pre_e = *--p;
		return OK;
	}
}

bool LinkList::NextElem(ElemType cur_e, ElemType &next_e)
{
	ElemType *p = L.elem;
	int i = 1;

	while(i<=L.length-1 && *p!=cur_e)
	{
		p++;
		i++;
	}

	if(i > L.length - 1)
		return ERROR;
	else
	{
		next_e = *++p;
		return OK;
	}
}

bool LinkList::ListInsert(int i, ElemType e)
{
	if(i<1 || i>L.length+1)
		return ERROR;

	ElemType *newbase, *p, *q;

	if(L.length >= L.listsize)
	{
		newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			return ERROR;

		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	
	q = L.elem + i - 1;
	for(p=L.elem+L.length ; p>=q ; p--)
		*(p+1) = *p;

	*q = e;
	++L.length;

	return OK;
}

bool LinkList::ListDelete(int i, ElemType &e)
{
	if(i<1 || i>L.length)
		return ERROR;

	ElemType *p, *q;

	p = L.elem + i - 1;
	q = L.elem + L.length - 1;
	e = *p;
	for(++p ; p<=q ; ++p)
		*(p-1) = *p;

	L.length--;

	return OK;
}

bool LinkList::ListTraverse()
{
	ElemType *p;
	int i;

	p = L.elem;
	for(i=1 ; i<=L.length; i++)
		visit(p++);
	std::cout<<std::endl;

	return OK;
}



bool LinkList::InitList()
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));

	if(!L.elem)
		return ERROR;

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

bool LinkList::DestoryList()
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;

	return OK;
}

bool LinkList::compare(ElemType i, ElemType j)
{
	if(i > j)
		return OK;
	else
		return ERROR;
}

void LinkList::visit(ElemType *p)
{
	std::cout<<*p<<"  ";
}