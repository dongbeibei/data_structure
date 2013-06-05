#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

Queue::Queue()
{
	InitQueue();
}

Queue::~Queue()
{
	DestoryQueue();
}

bool Queue::ClearQueue()
{
	QueuePtr p,q;

	Q.rear = Q.front;
	p = Q.front->next;
	Q.front->next = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	
	return OK;
}

bool Queue::QueueEmpty()
{
	 if(Q.front == Q.rear)
	 	return OK;
	 else
	 	return ERROR;
}

int Queue::QueueLength()
{
	QueuePtr p = Q.front;
	int i = 0;

	while(p != Q.rear)
	{
		p = p->next;
		i++;
	}
	
	return i;
}

bool Queue::GetHead(QElemType &e)
{
	if(Q.rear == Q.front)
		return ERROR;

	e = Q.front->next->data;

	return OK;
}

bool Queue::EnQueue(QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		std::cout<<"malloc fail"<<std::endl;
		return ERROR;
	}

	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;

	return OK;
}

bool Queue::DeQueue(QElemType &e)
{
	if(Q.front == Q.rear)
		return ERROR;

	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if(Q.rear == p)
		Q.rear = Q.front;

	free(p);

	return OK;
}

bool Queue::QueueTraverse()
{
	QueuePtr p = Q.front->next;

	for( ; p ; p = p->next)
		visit(p->data);
	std::cout<<std::endl;

	return OK;
}


bool Queue::InitQueue()
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		std::cout<<"malloc fail, init fail"<<std::endl;
		return ERROR;
	}

	Q.front->next = NULL;

	return OK;
}

bool Queue::DestoryQueue()
{
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}

	return OK;
}

bool Queue::visit(QElemType &e)
{
	std::cout<<e<<"  ";

	return OK;
}
