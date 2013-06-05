/*
 * the declaration of the Class LinkList
 */


#ifndef __LINKLIST_H
#define __LINKLIST_H

#include "../base.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	/* data */
	ElemType	*elem;
	int 		length;
	int 		listsize;
}SqList;

class LinkList
{
public:
	LinkList();
	~LinkList();

	bool ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, ElemType &e);
	int LocateElem(ElemType e);
	bool PeriorElem(ElemType cur_e, ElemType &pre_e);
	bool NextElem(ElemType cur_e, ElemType &next_e);
	bool ListInsert(int i, ElemType e);
	bool ListDelete(int i, ElemType &e);
	bool ListTraverse();

private:
	bool InitList();
	bool DestoryList();
	bool compare(ElemType i, ElemType j);
	void visit(ElemType *p);
/*
	typedef struct
	{
		// data 
		ElemType	*elem;
		int 		length;
		int 		listsize;
	}SqList;
*/
	SqList L;
};

#endif