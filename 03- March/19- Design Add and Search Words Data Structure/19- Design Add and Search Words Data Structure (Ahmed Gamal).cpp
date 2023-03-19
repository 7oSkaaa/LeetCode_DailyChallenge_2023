// Author: Ahmed Gamal

// for this problem we can use trie data structure to implement the addWord and search operations
// the addWord operation is easy to implement, we just need to add the word to the trie as usual
// the search operation is a bit tricky, we need to search for the word in the trie but we need to handle the '.' character
// if the current character is not '.' we just need to search for it in the trie and move to the next character as usual
// but if the current character is '.' we need to search for all the characters in the trie and move to the next character
// since we need to try all possible paths, we can use dfs to implement this operation
// we need to return true if the word is found in the trie and false otherwise (if the word is not found or the word is found but it is not a word)
// we can use a helper function to implement the dfs

class WordDictionary {
    // trie node
    struct Node {
        // 26 children for 26 letters
        Node* children[26];

        // is the current node the end of a word
        bool is_end;

        Node() {
            // initialize all children to null
            for(auto& i : children) {
                i = nullptr;
            }

            // initialize is_end to false
            is_end = false;
        }
    };

    // root of the trie
    Node* root;
public:
    // initialize the trie with a dummy root
    WordDictionary() {
        root = new Node();
    }
    
    // add a word to the trie
    void addWord(string word) {
        // start from the root
        auto curr = root;

        // add the word to the trie
        for(int i = 0; i < word.size(); i++) {
            if(not curr -> children[word[i] - 'a'])
                curr -> children[word[i] - 'a'] = new Node();
            curr = curr -> children[word[i] - 'a'];
        }

        // mark the last node as the end of a word
        curr -> is_end = true;
    }
    
    // helper function to implement the search operation
    // we start from the current node and try to find the current suffix of the word
    // and we start from the current index in the word
    bool dfs(string& word, Node* curr, int idx = 0) {
        // if the current node is null, the word is not found
        if(not curr) {
            return false;
        }

        // if the current index is equal to the size of the word, we need to check if the current node is the end of a word
        if(idx >= word.size()) {
            return curr -> is_end;
        }

        bool ret = false;

        // if the current character is not '.', we have just one path to try
        if(word[idx] != '.') {
            ret = dfs(word, curr -> children[word[idx] - 'a'], idx + 1);
        } else {
            // if the current character is '.', we have 26 paths to try and we need to find one that returns true
            for(int i = 0; i < 26; i++) {
                ret |= dfs(word, curr -> children[i], idx + 1);
            }
        }

        // return true if the suffix is found and false otherwise
        return ret;
    }

    // search for a word in the trie
    bool search(string word) {
        return dfs(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */