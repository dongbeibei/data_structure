/*
 * The test file of the Class Queue
 */


#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

int main(void)
{
	Queue	*test = new Queue();
	QElemType e;

	std::cout<<"the length is "<<test->QueueLength()<<std::endl;
	test->EnQueue(1);
	std::cout<<"the length is "<<test->QueueLength()<<std::endl;
	test->EnQueue(2);
	std::cout<<"the length is "<<test->QueueLength()<<std::endl;
	test->EnQueue(3);
	test->EnQueue(4);
	test->EnQueue(5);

	test->GetHead(e);
	std::cout<<"the head is "<<e<<std::endl;
	test->QueueTraverse();
	std::cout<<"the length is "<<test->QueueLength()<<std::endl;
	std::cout<<"Empty: "<<test->QueueEmpty()<<std::endl;

	test->DeQueue(e);
	std::cout<<"the dequeue value is "<<e<<std::endl;
	test->QueueTraverse();

	test->ClearQueue();
	std::cout<<"Empty: "<<test->QueueEmpty()<<std::endl;
	test->QueueTraverse();

	delete test;

	return 0;
}
