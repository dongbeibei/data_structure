/*
 * the implementation of the class bstree
 *
 * author:	dongbeibei
 * time:		2013/6/25
 * modify:	2013/8/12
 *
 * function:	construction/destory/insert/delete/search/
 */


#include <iostream>
#include <queue>
#include "bstree.h"
using namespace std;

BSTree::BSTree()
{
	if(!init())
		cout<<"bstree init fail."<<endl;
}

BSTree::~BSTree()
{
	if(!destory(m_tree.root))
		cout<<"bstree destory fail."<<endl;
}

struct Node *BSTree::searchNode(int key)
{
	struct Node *x ;

	x = m_tree.root;
	while(x && key!=x->m_nkey)
	{
		if(key < x->m_nkey)
			x = x->leftchild;
		else
			x = x->rightchild;
	}

	return x;
}

struct Node *BSTree::minimum(struct Node *x)
{
	while(x->leftchild)
		x = x->leftchild;

	return x;
}

struct Node *BSTree::maximum(struct Node *x)
{
	while(x->rightchild)
		x = x->rightchild;

	return x;
}


bool BSTree::insertNode(int key)
{
	if(!(m_tree.root))
	{
		m_tree.root = new Node;
		//m_tree.root = (struct Node *)malloc(sizeof(struct Node));
		if(!(m_tree.root))
			return false;

		m_tree.root->m_nkey = key;

		return true;
	}

	struct Node *x, *y, *new_node;

	new_node = new Node;
	//new_node = (struct Node *)malloc(sizeof(struct Node));
	if(!new_node)
	{
		cout<<"new_node malloc fail."<<endl;
		return false;
	}
	new_node->m_nkey = key;
	new_node->parent = NULL;
	new_node->leftchild = NULL;
	new_node->rightchild = NULL;
	x = m_tree.root;
	y = NULL;
	while(x)
	{
		y = x;
		if(key < x->m_nkey)
			x = x->leftchild;
		else
			x = x->rightchild;
	}

	new_node->parent = y;
	if(key < y->m_nkey)
		y->leftchild = new_node;
	else
		y->rightchild = new_node;

	return true;
}

bool BSTree::deleteNode(int key)
{
	struct Node *del_Node, *x, *y;

	del_Node = searchNode(key);
	//cout<<"delete:\t"<<del_Node->m_nkey<<endl;
	if(!del_Node)
	{
		cout<<"the key is not in the tree."<<endl;
		return false;
	}

	if(del_Node->leftchild==NULL || del_Node->rightchild== NULL)
		y = del_Node;
	else
		y = successor(del_Node);
	if(y->leftchild)
		x = y->leftchild;
	else
		x = y->rightchild;

	if(x)
		x->parent = y->parent;
	if(y->parent == NULL)
		m_tree.root = x;
	else if(y == y->parent->leftchild)
		y->parent->leftchild = x;
	else
		y->parent->rightchild = x;

	if(y != del_Node)
	{
		del_Node->m_nkey = y->m_nkey;
	}

	delete y;

	return true;
}

struct Node *BSTree::predecessor(struct Node *x)
{
	struct Node *temp;

	if(x->leftchild)
		return maximum(x->leftchild);

	temp = x->parent;
	while(temp && x==temp->leftchild)
	{
		x = temp;
		temp = x->parent;
	}

	return temp;
}

struct Node *BSTree::successor(struct Node *x)
{
	struct Node *temp;

	if(x->rightchild)
		return minimum(x->rightchild);

	temp = x->parent;
	while(temp && x==temp->rightchild)
	{
		x = temp;
		temp = x->parent;
	}

	return temp;
}

void BSTree::preorderVisit()
{
	preVisit(m_tree.root);
}

void BSTree::levelVisit()
{
	struct Node *x = m_tree.root;
	queue<struct Node *> myqueue;

	myqueue.push(x);
	while(!myqueue.empty())
	{
		cout<<x->m_nkey<<"  ";
		if(x->leftchild)
			myqueue.push(x->leftchild);
		if(x->rightchild)
			myqueue.push(x->rightchild);
		myqueue.pop();
		x = myqueue.front();
	}
}


bool BSTree::init()
{
	m_tree.root = NULL;
	return true;
}

bool BSTree::destory(struct Node *x)
{
	if(x->leftchild)
		destory(x->leftchild);
	if(x->rightchild)
		destory(x->rightchild);

	//free(x);
	delete x;

	return true;
}

void BSTree::preVisit(struct Node *x)
{
	if(x->leftchild)
		preVisit(x->leftchild);
	cout<<x->m_nkey<<"  ";
	if(x->rightchild)
		preVisit(x->rightchild);
}
