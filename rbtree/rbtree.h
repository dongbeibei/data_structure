/*
 * the declaration of the class rbtree
 *
 * author:	dongbeibei
 * time:		2013/6/26
 *
 */

#ifndef _RBTREE_H
#define _RBTREE_H

#include "../base.h"

class RBTree
{
public:
	RBTree();
	~RBTree();
	bool Empty();
	RBNode *find(int key);
	bool Insert(int key);
	void InsertFixup(RBNode *node);
	bool RotateLeft(RBNode *node);
	bool RotateRight(RBNode *node);
	bool Delete(int key);
	void DeleteFixup(RBNode *node);
	inline RBNode *InOrderPredecessor(RBNode *node);
	inline RBNode *InOrderSuccessor(RBNode *node);
	void InOrderTraverse();
	void InOrderTraverse(RBNode *node);
private:
	RBTree(const RBTree& input){}
	const RBTree& operator=(const RBTree& input) {}
	enum COLOR{RED,BLACK};
	class RBNode
	{
	public:
		RBNode()
		{
			RB_COLOR = BLACK;
			right = NULL;
			left = NULL;
			parent = NULL;
		}
		COLOR RB_COLOR;
		RBNode *right;
		RBNode *left;
		RBNode *parent;
		int key;
	};

	void clear(RBNode *node);

	RBNode *m_nullNode;
	RBNode *m_root;
};

#endif
