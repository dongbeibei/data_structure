#include "linklist.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	LinkList test;
	ElemType e, next_e, pre_e;

	std::cout<<"length:\t"<<test.ListLength()<<std::endl;
	test.ListInsert(1, 1);
	test.ListInsert(1, 2);
	test.ListInsert(1, 3);
	test.ListTraverse();
	test.GetElem(1, e);
	std::cout<<"the first value is "<<e<<std::endl;
	test.ListDelete(2, e);
	std::cout<<"the delete vaule is "<<e<<std::endl;
	test.ListTraverse();
	test.GetElem(1, e);
	test.NextElem(e, next_e);
	std::cout<<"the value after "<<e<<" is "<<next_e<<std::endl;
	test.GetElem(2, e);
	test.PeriorElem(e, pre_e);
	std::cout<<"the value before "<<e<<" is "<<pre_e<<std::endl;

	return 0;
}
