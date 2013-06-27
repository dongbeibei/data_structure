/*
 * the declaration of class bstree
 *
 * author:	dongbeibei
 * time:		2013/6/25
 *
 * function: binary search tree
 */


#ifndef _BSTREE_H
#define _BSTREE_H

#include "../base.h"

typedef struct Node
{
	int		m_nkey;
	struct Node	*parent;
	struct Node	*leftchild;
	struct Node	*rightchild;
}Node;

typedef struct tree
{
	struct Node *root;
}tree;

class Bstree
{
public:
	Bstree();
	~Bstree();
	struct Node *searchNode(int key);
	struct Node *minimum(struct Node *x);
	struct Node *maximum(struct Node *x);
	bool insertNode(int key);
	bool deleteNode(int key);
	struct Node *predecessor(struct Node *x);
	struct Node *successor(struct Node *x);

	void preorderVisit();

private:
	bool init();
	bool destory(struct Node *x);
	void preVisit(struct Node *x);
	struct tree m_tree;
};

#endif
