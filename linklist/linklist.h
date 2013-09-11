/*
 * function: the declartion of the linklist template, realize the linklist by link
 *
 * author: feng
 * time:   2013/9/10
 */


#ifndef _LINKLIST_H
#define _LINLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class LinkList
{
private:
	struct ListElement
	{
		T	m_nValue;
		struct ListElement	*m_pNext;
	};
	struct ListElement *m_head;

	// construct a new node
	void createNode(struct ListElement **pCur, T value)
	{
		try
		{
			*pCur = new ListElement;
		}
		catch(bad_alloc& bad)
		{
			cerr<<"Error: "<<bad.what()<<endl;
			exit(EXIT_FAILURE);
		}

		(*pCur)->m_nValue = value;
		(*pCur)->m_pNext = NULL;
	}

public:
	// constructor and deconstructor
	LinkList()
	{
		createNode(&m_head, T(0));
	}

	~LinkList()
	{
		cout<<"deconstructor."<<endl;
		struct ListElement *pTemp = m_head, *pNext;

		while(pTemp)
		{
			pNext = pTemp->m_pNext;
			delete pTemp;
			pTemp = pNext;
		}

		pTemp = NULL;
		pNext = NULL;
	}


	// copy constructor and copy assignment constructor
	LinkList(const LinkList<T>& listSrc)
	{
		cout<<"copy constructor:"<<endl;
		struct ListElement *pDst;

		createNode(&m_head, T(0));

		pDst = listSrc.m_head->m_pNext;
		while(pDst)
		{
			insertElement(pDst->m_nValue);
			pDst = pDst->m_pNext;
		}
	}

	LinkList<T>& operator=(const LinkList<T>& listSrc)
	{
		cout<<"copy assignment constructor:"<<endl;
		if(this == &listSrc)
			return *this;

		struct ListElement *pDst;

		createNode(&m_head, T(0));

		pDst = listSrc.m_head->m_pNext;
		while(pDst)
		{
			insertElement(pDst->m_nValue);
			pDst = pDst->m_pNext;
		}

		return *this;
	}


	// insert and delete
	bool insertElement(T value)
	{
		struct ListElement *pTemp = m_head;
		while(pTemp->m_pNext)
			pTemp = pTemp->m_pNext;

		struct ListElement *pCur;

		createNode(&pCur, value);
		pTemp->m_pNext = pCur;
	}

	bool deleteElement(T value)
	{
		struct ListElement *pTemp = m_head->m_pNext, *pPrev = m_head;

		while(pTemp)
		{
			if(pTemp->m_nValue == value)
			{
				pPrev->m_pNext = pTemp->m_pNext;
				delete pTemp;
				pTemp = NULL;
				pPrev = NULL;

				return true;
			}
			else
			{
				pPrev = pTemp;
				pTemp = pTemp->m_pNext;
			}
		}

		pTemp = NULL;
		pPrev = NULL;

		return false;
	}

	bool insertElement(struct ListElement *pCur, T value)
	{
		if(pCur == NULL)
		{
			insertElement(value);
			return true;
		}

		if(searchElement(pCur))
		{
			struct ListElement *pNext = pCur->m_pNext;
			struct ListElement *pTemp;

			createNode(&pTemp, pCur->m_nValue);

			pTemp->m_pNext = pNext;
			pCur->m_nValue = value;
			pCur->m_pNext = pTemp;

			return true;
		}
		else
		{
			cout<<"The node is not in the linklist."<<endl;

			return false;
		}
	}

	bool deleteElement(struct ListElement *pCur)
	{
		if(searchElement(pCur))
		{
			if(pCur->m_pNext != NULL)
			{
				struct ListElement *pNext = pCur->m_pNext;
				
				pCur->m_nValue = pNext->m_nValue;
				pCur->m_pNext = pNext->m_pNExt;

				delete pNext;
			}
			else
			{
				struct ListElement *pPrev = m_head;

				while(pPrev->m_pNext->m_pNext)
					pPrev = pPrev->m_pNext;

				pPrev->m_pNext = NULL;
				delete pCur;
			}

			return true;
		}
		else
		{
			cout<<"The node is not in the linklist."<<endl;

			return false;
		}
	}


	// search
	struct ListElement* searchElement(T value)
	{
		struct ListElement *pTemp = m_head->m_pNext;

		while(pTemp)
		{
			if(pTemp->m_nValue == value)
				return pTemp;
			else
				pTemp = pTemp->m_pNext;
		}

		return NULL;
	}

	bool searchElement(struct ListElement *pCur)
	{
		struct ListElement *pTemp = m_head->m_pNext;

		while(pTemp)
		{
			if(pCur == pTemp)
				return true;
			else
				pTemp = pTemp->m_pNext;
		}

		return false;
	}


	// length
	int listLength()
	{
		int i = 0;
		struct ListElement *pTemp = m_head;
		while(pTemp->m_pNext)
		{
			++i;
			pTemp = pTemp->m_pNext;
		}

		return i;
	}

	// traverse
	void traverse()
	{
		cout<<"Element in the linklist:"<<endl;
		struct ListElement *pTemp = m_head->m_pNext;

		if(pTemp == NULL)
		{
			cout<<"\tEmpty LinkList."<<endl;
			return;
		}

		while(pTemp)
		{
			cout<<pTemp->m_nValue<<"  ";
			pTemp = pTemp->m_pNext;
		}
		cout<<endl;
	}
};

#endif
