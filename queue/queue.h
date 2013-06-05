/*
 * The declaration of the Class Queue
 */


#ifndef __QUEUE_H
#define __QUEUE_H

#include "../base.h"

#define QElemType int

typedef struct QNode
{
	QElemType		data;
	struct QNode	*next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr	front;
	QueuePtr	rear;
}LinkQueue;

class Queue
{
public:
	Queue();
	~Queue();
	bool ClearQueue();
	bool QueueEmpty();
	int	QueueLength();
	bool GetHead(QElemType &);
	bool EnQueue(QElemType);
	bool DeQueue(QElemType &);
	bool QueueTraverse();

private:
	bool InitQueue();
	bool DestoryQueue();
	bool visit(QElemType &);

	LinkQueue Q;
};

#endif
