/*
 * the implement of the class rbtree
 *
 * author:	dongbeibei
 * time:		2013/6/26
 *
 * function:	construction/destory/insert/delete/search/
 */


#include "rbtree.h"

RBTree::RBTree()
{
	m_nullNode = new RBNode();
	m_root = m_nullNode;
	m_nullNode->right = m_root;
	m_nullNode->left = m_root;
	m_nullNode->parent = m_root;
	m_nullNode->RB_COLOR = BLACK;
}

RBTree::~RBTree()
{
	clear(m_root);
	delete m_nullNode;
}

bool RBTree::Empty()
{
	if(m_root == m_nullNode)
		return true;
	else
		return false;
}

//find node who's key equals to key, else find the insert point
RBNode *RBTree::find(int key)
{
	RBNode *index = m_root;
	while(index != m_nullNode)
	{
		if(key < index->key)
			index = index->left;
		else if(key > index->key)
			index = index->right;
		else
			break;
	}

	return index;
}

bool RBTree::Insert(int key)
{
	RBNode *insert_point = m_nullNode;
	RBNode *index = m_root;
	RBNode *insert_node;

	while(index != m_nullNode)
	{
		insert_point = index;
		if(key < index->key)
			index = index->left;
		else if(key > index->key)
			index = index->right;
		else
			return false;
	}

	insert_node = new RBNode();
	insert_node->key = key;
	insert_node->RB_COLOR = RED;
	insert_node->left = m_nullNode;
	insert_node->right = m_nullNode;

	if(insert_point == m_nullNode)
	{
		m_root = insert_node;
		m_root->parent = m_nullNode;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
		m_nullNode->parent = m_root;
	}
	else
	{
		if(key < insert_point->key)
			insert_point->left = insert_node;
		else
			insert_point->right = insert_node;
		insert_node->parent = insert_point;
	}

	InsertFixup(insert_node);
}

void RBTree::InsertFixup(RBNode *node)
{
	while(node->parent->RB_COLOR == RED)
	{
		if(node->parent == node->parent->parent->left)
		{
			RBNode *uncle = node->parent->parent->right;
			if(uncle->RB_COLOR == RED)
			{
				node->parent->RB_COLOR = BLACK;
				uncle->RB_COLOR = BLACK;
				node->parent->parent->RB_COLOR = RED;
				node = node->parent->parent;
			}
			else if(uncle->RB_COLOR == BLACK)
			{
				if(node == node->parent->right)
				{
					node = node->parent;
					RotateLeft(node);
				}
				else
				{
					node->parent->RB_COLOR = BLACK;
					node->parent->parent->RB_COLOR = RED;
					RotateRight(node->parent->parent);
				}
			}
		}
		else
		{
			RBNode *uncle = node->parent->parent->left;
			if(uncle->RB_COLOR == RED)
			{
				node->parent->RB_COLOR = BLACK;
				uncle->RB_COLOR = BLACK;
				uncle->parent->RB_COLOR = RED;
				node = node->parent->parent;
			}
			else if(uncle->RB_COLOR == BLACK)
			{
				if(node == node->parent->left)
				{
					node = node->parent;
					RotateRight(node);
				}
				else
				{
					node->parent->RB_COLOR = BLACK;
					node->parent->parent->RB_COLOR = RED;
					RotateLeft(node->parent->parent);
				}
			}
		}
	}

	m_root->RB_COLOR = BLACK;
}

bool RBTree::RotateLeft(RBNode *node)
{
	if(node==m_nullNode || node->right==m_nullNode)
		return false;

	RBNode *lower_right = node_right;
	lower_right->parent = node->parent;
	node->right = lower_right->left;
	if(lower_right->left != m_nullNode)
		lower_right->left->parent = node;
	if(node->parent == m_nullNode)
	{
		m_root = lower_right;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
		//m_nullNode->parent = m_root;
	}
	else
	{
		if(node == node->parent->left)
			node->parent->left = lower_right;
		else
			node->parent->right = lower_right;
	}
	node->parent = lower_right;
	lower_right->left = node;
}

bool RBTree::RotateRight(RBNode *node)
{
	if(node==m_nullNode || node->left==m_nullNode)
		return false;

	RBNode *lower_left = node->left;
	node->left = lower_left->right;
	lower_left->parent = node->parent;
	if(lower_left->right != m_nullNode)
		lower_left->right->parent = node;
	if(node->parent == m_nullNode)
	{
		m_root = lower_left;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
		//m_nullNode->parent = m_root;
	}
	else
	{
		if(node == node->parent->left)
			node->parent->left = lower_left;
		else
			node->parent->right = lower_left;
	}

	node->parent = lower_left;
	lower_left->right = node;
}

bool RBTree::Delete(int key)
{
	RBNode *delete_point = find(key);
	if(delete_point == m_nullNode)
		return false;
	if(delete_point->left!=m_nullNode && delete_point->right!=m_nullNode)
	{
		RBNode *successor = InOrderSuccessor(delete_point);
		delete_point->key = successor->key;
		delete_point = successor;
	}

	RBNode *delete_point_child;
	if(delete_point->right != m_nullNode)
		delete_point_child = delete_point->right;
	else if(delete_point->left != m_nullNode)
		delete_point_child = delete_point->left;
	else
		delete_point_child = m_nullNode;

	delete_point_child->parent = delete_point->parent;
	if(delete_point->parent == m_nullNode)
	{
		m_root = delete_point_child;
		m_nullNode->parent = m_root;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
	}
	else if(delete_point == delete_point->parent->left)
		delete_point->parent->right = delete_point_child;
	else
		delete_point->parent->left = delete_point_child;

	if(delete_point->RB_COLOR==BLACK && !(delete_point_child==m_nullNode && delete_point_child->parent==m_nullNode))
		DeleteFixup(delete_point_child);

	delete delete_point;

	return true;
}

void RBTree::DeleteFixup(RBNode *node)
{
	while(node!=m_root && node->RB_COLOR==BLACK)
	{
		if(node == node->parent->left)
		{
			RBNode *brother = node->parent->right;
			if(brother->RB_COLOR == RED)
			{
				brother->RB_COLOR = BLACK;
				node->parent->RB_COLOR = RED;
				RotateLeft(node->parent);
			}
			else
			{
				if(brother->left->RB_COLOR==BLACK && brother->right->RB_COLOR==BLACK)
				{
					brother->RB_COLOR = RED;
					node = node->parent;
				}
				else if(brother->right->RB_COLOR == BLACK)
				{
					brother->RB_COLOR = RED;
					brother->left->RB_COLOR = BLACK;
					RotateRight(brother);
				}
				else if(brother->right->RB_COLOR == RED)
				{
					brother->RB_COLOR = node->parent->RB_COLOR;
					node->parent->RB_COLOR = BLACK;
					brother->right->RB_COLOR = BLACK;
					RotateLeft(node->parent);
					node = m_root;
				}
			}
		}
		else
		{
			RBNode *brother = node->parent->left;
			if(brother->RB_COLOR == RED)
			{
				brother->RB_COLOR = BLACK;
				node->parent->RB_COLOR = RED;
				RotateRight(node->parent);
			}
			else
			{
				if(brother->left->RB_COLOR==BLACK && brother->right->RB_COLOR==BLACK)
				{
					brother->RB_COLOR = RED;
					node = node->parent;
				}
				else if(brother->left->RB_COLOR==BLACK)
				{
					brother->RB_COLOR = RED;
					brother->right->RB_COLOR = BLACK;
					RotateLeft(brother);
				}
				else if(brother->left->RB_COLOR==RED)
				{
					brother->RB_COLOR = node->parent->RB_COLOR;
					node->parent->RB_COLOR = BLACK;
					brother->left->RB_COLOR = BLACK;
					RotateRight(node->parent);
					node = m_root;
				}
			}
		}
	}

	m_nullNode->parent = m_root;
	node->RB_COLOR = BLACK;
}

inline RBNode *RBTree::InOrderPredecessor(RBNode *node)
{
	if(node == m_nullNode)
		return m_nullNode;

	RBNode *result = node->left;
	while(result != m_nullNode)
	{
		if(result->right != m_nullNode)
			result = result->right;
		else
			break;
	}

	if(result==m_nullNode)
	{
		RBNode *index = node->parent;
		result = node;
		while(index!=m_nullNode && result==index->left)
		{
			result = index;
			index = index->parent;
		}
		result = index;
	}

	return result;
}

inline RBNode *RBTree::InOrderSuccessor(RBNode *node)
{
	if(node == m_nullNode)
		return m_nullNode;

	RBNode *result = node->right;
	while(result != m_nullNode)
	{
		if(result->left != m_nullNode)
			result = result->left;
		else
			break;
	}

	if(result == m_nullNode)
	{
		RBNode *index = node->parent;
		result = node;
		while(index!=m_nullNode && result==index->right)
		{
			result = index;
			index = index->parent;
		}
		result = index;
	}

	return result;
}

void RBTree::InOrderTraverse()
{
	InOrderTraverse(m_root);
}

void RBTree::InOrderTraverse(RBNode *node)
{
	if(node == m_nullNode)
		return;
	else
	{
		InOrderTraverse(node->left);
		cout<<node->key<<endl;
		InOrderTraverse(node->right);
	}
}


void RBTree::clear(RBNode *node)
{
	if(node == m_nullNode)
		return;
	else
	{
		clear(node->left);
		clear(node->right);
		delete node;
	}
}
