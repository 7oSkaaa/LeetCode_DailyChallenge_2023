// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    If you do not know how trie works watch this (https://www.youtube.com/watch?v=-urNrIAQnNo)

    Approach:
        We will be useing nodes (like binary tree nodes) and each node will have its children of nodes (aka letters)
        as an array of length 26 which is initially set to null and when a letter is added we set
        the index of it as the node

    For More Details about Time and Space complexity of Trie
    https://iq.opengenus.org/time-complexity-of-trie/#:~:text=The%20space%20complexity%20of%20creating,of%20words%20in%20the%20trie
*/
struct TrieNode
{
    char character;
    bool isEndOfWord;
    vector<TrieNode *> children;
    TrieNode(char character, bool isEndOfWord = false) : character{character}, isEndOfWord{isEndOfWord}
    {
        children = vector<TrieNode *>(26, nullptr);
    }
};
class Trie
{
private:
    void insert(TrieNode *node, string &word, int idx)
    {
        if (idx >= word.size())
        {
            node->isEndOfWord = true;
            return;
        }
        auto possibleNode = node->children[word[idx] - 'a'];
        if (possibleNode)
            return insert(possibleNode, word, idx + 1);

        auto newNode = new TrieNode(word[idx], false);
        node->children[word[idx] - 'a'] = newNode;
        insert(newNode, word, idx + 1);
    }
    bool search(TrieNode *node, string &word, int idx)
    {
        if (idx >= word.size())
            return node->isEndOfWord;

        auto possibleNode = node->children[word[idx] - 'a'];
        if (possibleNode)
            return search(possibleNode, word, idx + 1);

        return false;
    }
    bool startsWith(TrieNode *node, string &word, int idx)
    {
        if (idx >= word.size())
            return true;

        auto possibleNode = node->children[word[idx] - 'a'];
        if (possibleNode)
            return startsWith(possibleNode, word, idx + 1);
        return false;
    }

public:
    TrieNode *head;
    Trie()
    {
        this->head = new TrieNode('>', false);
    }

    void insert(string word)
    {
        insert(head, word, 0);
    }

    bool search(string word)
    {
        return search(head, word, 0);
    }

    bool startsWith(string prefix)
    {
        return startsWith(head, prefix, 0);
    }
};