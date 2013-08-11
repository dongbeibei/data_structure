/*
 * the declaration of the class trie
 */


#ifndef _TRIE_H
#define _TRIE_H

#include <cstring>
#include <stack>

const int branchNum = 26;

struct Trie_node
{
	bool isStr;
	Trie_node *next[branchNum];
	Trie_node():isStr(false)
	{
		memset(next, 0, sizeof(next));
	}
};

class Trie
{
public:
	Trie();
	~Trie();
	void insert(const char *word);
	bool search(const char *word);
	bool deleteWord(const char *word);

private:
	void deleteTrie(Trie_node *root);
	Trie_node *root;
};

#endif
