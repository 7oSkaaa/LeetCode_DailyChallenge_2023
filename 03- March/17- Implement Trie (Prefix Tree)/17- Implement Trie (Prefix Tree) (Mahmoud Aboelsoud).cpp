// Author: Mahmoud Aboelsoud

class Trie {
public:

    // struct node that represents a node in the trie
    // nxt is an array of 26 elements that represents the next node in the trie
    // leaf is a boolean that represents if the current node is the end of a word
    struct node{
        int nxt[26];
        bool leaf = 0;

        // constructor that initializes the nxt array with -1
        node(){
            memset(nxt, -1, sizeof(nxt));
        }
    };

    // trie is a vector of nodes that represents the trie
    vector<node> trie;

    // constructor that initializes the trie with a root node
    Trie() {
        trie.emplace_back();
    }
    
    // insert a word in the trie
    void insert(string word) {
        // v is the current node in the trie we start from the root (v = 0)
        int v = 0;

        // loop over the word
        for(auto&i: word){
            // c is the index of the next node in the nxt array
            int c = i -'a';
            // if the next node is not initialized then initialize it
            if(trie[v].nxt[c] == -1){
                // add a new node to the trie and update the nxt array of the current node to point to the new node
                trie[v].nxt[c] = trie.size();
                trie.emplace_back();
            }
            // update the current node to the next node
            v = trie[v].nxt[c];
        }

        // mark the last node as a leaf
        trie[v].leaf = true;   
    }
    
    // search for a word in the trie
    bool search(string word) {
        // v is the current node in the trie we start from the root (v = 0)
        int v = 0;

        // loop over the word
        for(auto&i: word){
            // c is the index of the next node in the nxt array
            int c = i - 'a';
            // if the next node is not initialized then the word is not in the trie
            if(trie[v].nxt[c] == -1) return false;
            // update the current node to the next node
            v = trie[v].nxt[c];
        }

        // if the last node is a leaf then the word is in the trie
        if(trie[v].leaf) return true;
        // else the word is not in the trie
        return false;
    }
    
    // search for a prefix in the trie
    bool startsWith(string prefix) {
        // v is the current node in the trie we start from the root (v = 0)
        int v = 0;
        // loop over the prefix
        for(auto&i: prefix){
            // c is the index of the next node in the nxt array
            int c = i - 'a';
            // if the next node is not initialized then the prefix is not in the trie
            if(trie[v].nxt[c] == -1) return false;
            // update the current node to the next node
            v = trie[v].nxt[c];
        }

        // if we reach this point then the prefix is in the trie
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
