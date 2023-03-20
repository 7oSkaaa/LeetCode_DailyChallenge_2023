// Author: Ahmed Gamal

// for this problem we just need to implement the trie data structure
// the trie data structure is a tree data structure that is used to store strings
// the trie data structure has a root node that has 26 children (one for each letter in the alphabet)
// each node has 26 children (one for each letter in the alphabet)
// each node has a boolean variable that indicates if the node is the end of a word or not

class Trie {

    // the node class that represents each node in the trie data structure
    class Node {
    public:
        // the children of the node (one for each letter in the alphabet)
        Node* children[26];

        // a boolean variable that indicates if the node is the end of a word or not
        bool is_end;

        // the constructor of the node class
        Node() {
            // initialize the children of the node to null
            for(auto& i : children) {
                i = nullptr;
            }
            // initialize the is_end variable to false
            is_end = false;
        }
    };

    // the root node of the trie data structure
    Node* root;
public:

    // the constructor of the trie data structure
    Trie() {
        // initialize the root node to a new node (the root node is a dummy node)
        root = new Node();
    }
    
    // the insert function that inserts a word in the trie data structure
    void insert(string word) {
        // start from the root node
        auto curr = root;

        // loop over the word
        for(int i = 0; i < word.size(); i++) {
            // if the current node doesn't have a child with the current letter of the word then create a new node
            if(not curr -> children[word[i] - 'a'])
                curr -> children[word[i] - 'a'] = new Node();
        
            // move to the child of the current node with the current letter of the word
            curr = curr -> children[word[i] - 'a'];
        }

        // mark the last node as the end of a word
        curr -> is_end = true;
    }
    
    // the search function that searches for a word in the trie data structure
    bool search(string word) {
        // start from the root node
        auto curr = root;

        // loop over the word
        for(int i = 0; i < word.size(); i++) {
            // if the current node doesn't have a child with the current letter of the word then return false
            if(not curr -> children[word[i] - 'a'])
                return false;
            
            // move to the child of the current node with the current letter of the word
            curr = curr -> children[word[i] - 'a'];
        }

        // return true if the last node is the end of a word and false otherwise
        return curr -> is_end;
    }
    
    // the startsWith function that searches for a prefix in the trie data structure
    bool startsWith(string prefix) {
        // start from the root node
        auto curr = root;

        // loop over the prefix
        for(int i = 0; i < prefix.size(); i++) {
            // if the current node doesn't have a child with the current letter of the prefix then return false
            if(not curr -> children[prefix[i] - 'a'])
                return false;

            // move to the child of the current node with the current letter of the prefix
            curr = curr -> children[prefix[i] - 'a'];
        }

        // since we reached the end of the prefix then return true (the prefix exists)
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */