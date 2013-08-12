/*
 * the declaration of class bstree
 *
 * author:	dongbeibei
 * time:		2013/6/25
 * modify:	2013/8/12
 *
 * function: binary search tree
 */


#ifndef _BSTREE_H
#define _BSTREE_H

#include "../base.h"

//the structure of node in the BSTree
typedef struct Node
{
	int		m_nkey;
	struct Node	*parent;
	struct Node	*leftchild;
	struct Node	*rightchild;
}Node;

//define the BSTree: using root node
typedef struct tree
{
	struct Node *root;
}tree;

class BSTree
{
public:
	//construct
	BSTree();
	//deconstruct
	~BSTree();

	//search the node according the key
	struct Node *searchNode(int key);
	//get the min node
	struct Node *minimum(struct Node *x);
	//get the max node
	struct Node *maximum(struct Node *x);
	//insert a new node to BSTree
	bool insertNode(int key);
	//delete the node
	bool deleteNode(int key);
	//find the predecessor node
	struct Node *predecessor(struct Node *x);
	//find the successor node
	struct Node *successor(struct Node *x);

	//preorder visit the BSTree
	void preorderVisit();
	//level visit
	//	using the STL Queue
	void levelVisit();

private:
	//init the BSTree
	bool init();
	//destory the BSTree
	bool destory(struct Node *x);
	//preorder visit the BSTree
	void preVisit(struct Node *x);

	//node structure
	struct tree m_tree;
};

#endif
