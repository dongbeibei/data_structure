/*
 * function: the unit test file of queueTemplate.h, test the class Queue
 *
 * author: feng
 * time:   2013/9/11
 */


#include "queueTemplate.h"

// unit test function
void test1();
void test2();
void test3();

int main(void)
{
	test1();
	cout<<endl<<endl;
	test2();
	cout<<endl<<endl;

	return 0;
}

// test the constructor and deconstructor
void test1()
{
	Queue<int> use1;
	for(int i=1 ; i<11 ; ++i)
		use1.push(i);
	use1.display();

	Queue<int> use2(use1);
	use2.display();

	Queue<int> use3;
	use3 = use1;
	use3.display();
}

// test the member function
void test2()
{
	Queue<int> use1;
	for(int i=1 ; i<11 ; ++i)
		use1.push(i);
	use1.display();

	cout<<"front: "<<use1.front()<<endl;
	cout<<"back: "<<use1.back()<<endl;
	cout<<"length: "<<use1.size()<<endl;
	use1.pop();
	use1.pop();
	use1.push(20);	
	cout<<"front: "<<use1.front()<<endl;
	cout<<"back: "<<use1.back()<<endl;
	cout<<"length: "<<use1.size()<<endl;
	use1.display();

	cout<<"Empty: "<<use1.empty()<<endl;
	for(int i=use1.size(); i>=0 ; --i)
		use1.pop();
	cout<<"Empty: "<<use1.empty()<<endl;
}
