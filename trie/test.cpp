/*
 * a test for class trie
 */


#include <iostream>
#include <stdio.h>
#include "trie.h"

using namespace std;

int main(void)
{
    Trie t;

    t.insert("abc");
    t.insert("d");
    const char * c = "dda";

    t.insert(c);
    t.insert("da");

    if(t.search("da"))
    {
        printf("find\n");
    }

    t.deleteWord("dda");
    if(!t.search("dda"))
    {
        printf("not find\n");
    }

    t.deleteWord("d");
    if(!t.search("d"))
    {
        printf("not find\n");
    }

    if(t.search("da"))
    {
        printf("find\n");
    }

	return 0;
}
