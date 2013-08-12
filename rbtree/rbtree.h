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
	//construct
	RBTree();
	//deconstruct
	~RBTree();
	//return if the RBTree is empty or not
	bool Empty();
	//find node who's key equals to key, else find the insert point
	RBNode *find(int key);
	//insert the key to the RBTree
	bool Insert(int key);
	//insert fixup
	void InsertFixup(RBNode *node);
	//rotate left
	bool RotateLeft(RBNode *node);
	//rotate right
	bool RotateRight(RBNode *node);
	//delete the key from the RBTree
	bool Delete(int key);
	//delete fixup
	void DeleteFixup(RBNode *node);
	//predecessor node in inorder visit
	inline RBNode *InOrderPredecessor(RBNode *node);
	//successor node in inorder visit
	inline RBNode *InOrderSuccessor(RBNode *node);
	//inorder visit
	void InOrderTraverse();
	void InOrderTraverse(RBNode *node);
private:
	//disable the two other constructions
	RBTree(const RBTree& input){}
	const RBTree& operator=(const RBTree& input) {}
	//define the color
	enum COLOR{RED,BLACK};
	//define the RBNode
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

	//init the RBTree
	bool init();
	//clear the RBTree: call by desconstruct
	void clear(RBNode *node);

	//the NULL Node
	RBNode *m_nullNode;
	//the root Node
	RBNode *m_root;
};

#endif
