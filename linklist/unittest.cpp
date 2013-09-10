/*
 * function: the unit test for linklist
 *
 * author: feng
 * time:   2013/9/10
 */


#include <iostream>
#include "linklist.cpp"

using namespace std;

// unit test function
void test_construct();
void test_copy_construct();
void test_insert_delete_search();

int main(void)
{
	test_construct();
	cout<<endl<<endl;

	test_copy_construct();
	cout<<endl<<endl;

	test_insert_delete_search();
	cout<<endl<<endl;

	return 0;
}

void test_construct()
{
	cout<<"Test construct:"<<endl;

	LinkList<int> test;
	test.traverse();
}

void test_copy_construct()
{
	cout<<"Test copy construct:"<<endl;

	LinkList<int> test1;
	for(int i=1 ; i<10 ; ++i)
		test1.insertElement(i);
	cout<<"test1, ";
	test1.traverse();

	LinkList<int> test2(test1);
	cout<<"test2, ";
	test2.traverse();

	LinkList<int> test3;
	test3 = test1;
	cout<<"test3, ";
	test3.traverse();
}

void test_insert_delete_search()
{
	cout<<"Test insert and delete method:"<<endl;

	LinkList<int> test;
	for(int i=1 ; i<=10 ; ++i)
		test.insertElement(i);
	cout<<"test, ";
	test.traverse();

	for(int i=0 ; i<5 ; ++i)
		test.deleteElement(i*2+1);
	cout<<"test, ";
	test.traverse();

	cout<<"delete 11, return result = "<<test.deleteElement(11)<<endl;
	cout<<"test, ";
	test.traverse();

	test.insertElement(test.searchElement(4), 11);
	test.insertElement(NULL, 12);
	cout<<"test, ";
	test.traverse();
}
