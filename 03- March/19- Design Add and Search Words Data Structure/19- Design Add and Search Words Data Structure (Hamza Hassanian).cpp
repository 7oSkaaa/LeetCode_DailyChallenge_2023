// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;

/*
       Approach: use a trie, but the problem we will be facing is how we would deal with the
                 dots where they can match any character?
                 we can get to our prefix of the word we are giving then run a DFS to find any posible word of this length that
                can be matched with it`
*/

struct TrieNode
{
    bool isEndOfWord;
    vector<TrieNode *> children;
    TrieNode(bool isEndOfWord = false) : isEndOfWord{isEndOfWord}
    {
        children = vector<TrieNode *>(26, nullptr);
    }
};
class Trie
{

public:
    TrieNode *head;
    Trie()
    {
        this->head = new TrieNode();
    }

    void insert(string &word)
    {
        auto node = this->head;
        for (int i = 0; i < word.size(); i++)
        {
            int curr = word[i] - 'a';
            if (node->children[curr] == NULL)
            {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isEndOfWord = true;
    }

    bool search(string &word, TrieNode *node, int idx)
    {
        if (not node)
            return false;
        if (idx > word.size())
            return false;
        if (idx == word.size())
            return node->isEndOfWord;
        if (word[idx] != '.')
            return search(word, node->children[word[idx] - 'a'], idx + 1);

        for (int i = 0; i < 26; i++)
        {
            if (search(word, node->children[i], idx + 1))
                return true;
        }

        return false;
    }
    bool search(string word)
    {
        return this->search(word, head, 0);
    }
};

class WordDictionary
{
public:
    Trie trie;
    WordDictionary() {}

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};
