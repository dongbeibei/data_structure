/*
 * a test for bstree class
 *
 * author:	dongbeibei
 * time:		2013/6/25
 * modify:	2013/8/12
 */


#include <iostream>
#include "bstree.h"
using namespace std;

int main(void)
{
	BSTree *test = new BSTree;


	test->insertNode(4);
	test->insertNode(2);
	test->insertNode(8);
	test->insertNode(1);
	test->insertNode(3);
	test->insertNode(6);
	test->insertNode(9);
	test->insertNode(5);
	test->insertNode(7);

	cout<<"data:\t";
	test->preorderVisit();
	cout<<endl;

	test->deleteNode(6);
	
	cout<<"data:\t";
	test->preorderVisit();
	cout<<endl;

	cout<<"data:\t";
	test->levelVisit();
	cout<<endl;

	delete test;

	return 0;
}
