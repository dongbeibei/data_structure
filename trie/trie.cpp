/*
 * the implementation of the class trie
 */

#include "trie.h"
#include <iostream>

using namespace std;

Trie::Trie()
{
	root = new Trie_node();
}

Trie::~Trie()
{
	deleteTrie(root);
}

void Trie::insert(const char *word)
{
	Trie_node *location = root;

	while(*word)
	{
		if(location->next[*word-'a'] == NULL)
		{
			Trie_node *tmp = new Trie_node();
			location->next[*word-'a'] = tmp;
		}
		location = location->next[*word-'a'];
		word++;
	}
	location->isStr = true;
}

bool Trie::search(const char *word)
{
	Trie_node *location = root;
	while(*word && location)
	{
		location = location->next[*word-'a'];
		word++;
	}

	return (location!=NULL && location->isStr);
}

bool Trie::deleteWord(const char *word)
{
	Trie_node *current = root;
	std::stack<Trie_node*> nodes;

	while(*word!='\0' && current!=0)
	{
		nodes.push(current);
		current = current->next[*word-'a'];
		word++;
	}

	if(current && current->isStr)
	{
		current->isStr = false;
		while(nodes.size() != 0)
		{
			char c = *(--word);
			current = nodes.top()->next[c-'a'];

			bool isNotValid = true;
			for(int i=0 ; i<26 ; ++i)
			{
				if(current->next[i]!=0 && i!=(c-'a'))
					isNotValid = false;
			}
			if(current->isStr==0 && isNotValid)
				delete current;
			else
				break;
			nodes.top()->next[c-'a'] = 0;
			nodes.pop();
		}
		return true;
	}
	else
		return false;
}

 
void Trie::deleteTrie(Trie_node *root)
{
	for(int i=0 ; i<branchNum ; i++)
	{
		if(root->next[i] != NULL)
			deleteTrie(root->next[i]);
	}

	delete root;
}
