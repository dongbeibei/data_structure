/*
 * function: realize the template version of the queue
 * 
 * interface:
 *    push        put a new member in the last of the queue
 *    pop         pop the first member of the queue
 *    front       get the first member of the queue
 *    back        get the last member of the queue
 *    empty       identify the queue is empty(TRUE) or not(FALSE)
 *    size        get the number of the members in the queue
 *    display     display every member of the queue
 *
 * author: feng
 * time:   2013/9/11
 */


#ifndef _QUEUE_TEMPLATE_H
#define _QUEUE_TEMPLATE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Queue
{
private:
	// the member's structure in the queue
	struct QNode
	{
		T              m_nValue;
		struct QNode*  m_pNext;
	};

	typedef struct
	{
		QNode*    front;
		QNode*    rear;
		int       length;
	}LinkQueue;

	LinkQueue lqueue;

	void createNode(struct QNode **node, T value)
	{
		try
		{
			*node = new QNode;
		}
		catch(bad_alloc& bad)
		{
			cerr<<"ERROR: "<<bad.what()<<endl;
			exit(EXIT_FAILURE);
		}

		(*node)->m_pNext = NULL;
		(*node)->m_nValue = value;
	}

public:
	// constructor and deconstructor
	Queue()
	{
		createNode(&(lqueue.front), T(0));
		lqueue.rear = lqueue.front;
		lqueue.length = 0;
	}

	~Queue()
	{
		struct QNode *pTemp = lqueue.front, *pNext = NULL;
		while(pTemp)
		{
			pNext = pTemp->m_pNext;
			delete pTemp;
			pTemp = pNext;
		}
	}


	// copy constructor and copy assignment constructor
	Queue(const Queue<T>& pSrc)
	{
		createNode(&(lqueue.front), T(0));
		lqueue.rear = lqueue.front;
		lqueue.length = 0;
		struct QNode *pTemp = pSrc.lqueue.front->m_pNext;

		while(pTemp)
		{
			push(pTemp->m_nValue);
			pTemp = pTemp->m_pNext;
		}

		lqueue.length = pSrc.lqueue.length;
	}
	Queue<T>& operator=(const Queue<T>& pSrc)
	{
		if(this == &pSrc)
			return *this;

		createNode(&(lqueue.front), T(0));
		lqueue.rear = lqueue.front;
		lqueue.length = 0;
		struct QNode *pTemp = pSrc.lqueue.front->m_pNext;

		while(pTemp)
		{
			push(pTemp->m_nValue);
			pTemp = pTemp->m_pNext;
		}
		lqueue.length = pSrc.lqueue.length;

		return *this;
	}


	// memeber function: push, pop, front, back, empty, size
	bool push(T value)
	{
		struct QNode *pTemp = NULL;

		createNode(&pTemp, value);
		lqueue.rear->m_pNext = pTemp;
		lqueue.rear = pTemp;
		++lqueue.length;

		return true;
	}

	bool pop()
	{
		struct QNode *pTemp = lqueue.front;

		if(pTemp == lqueue.rear)
		{
			cerr<<"ERROR: The queue is empty."<<endl;
			return false;
		}

		lqueue.front = lqueue.front->m_pNext;
		delete pTemp;
		pTemp = NULL;
		--lqueue.length;

		return true;
	}

	T front()
	{
		if(lqueue.front == lqueue.rear)
		{
			cerr<<"ERROR: The queue is empty."<<endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			return lqueue.front->m_pNext->m_nValue;
		}
	}

	T back()
	{
		if(lqueue.front == lqueue.rear)
		{
			cerr<<"ERROR: The queue is empty."<<endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			return lqueue.rear->m_nValue;
		}
	}

	bool empty()
	{
		if(lqueue.front == lqueue.rear)
			return true;
		else
			return false;
	}

	int size()
	{
		return lqueue.length;
	}


	// display the queue
	void display()
	{
		if(lqueue.length == 0)
			cout<<"The queue is empty."<<endl;
		else
		{
			struct QNode* pTemp = lqueue.front->m_pNext;

			cout<<"Display the queue: ";
			while(pTemp)
			{
				cout<<pTemp->m_nValue<<"  ";
				pTemp = pTemp->m_pNext;
			}
			cout<<endl;
		}
	}
};

#endif
