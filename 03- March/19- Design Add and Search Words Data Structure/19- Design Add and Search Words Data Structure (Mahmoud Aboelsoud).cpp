// Author: Mahmoud Aboelsoud

class WordDictionary {
public:
    // to solve this problem we will use trie data structure
    // we will add each word to the trie and search for the word in the trie
    // if we find the word in the trie we will return true else we will return false

    // trie node structure
    struct node {
        // each node will have 26 children (a-z)
        int nxt[26];
        // to check if the node is a leaf or not
        bool leaf;

        // constructor to initialize the node
        node(){
            // initialize the children to -1
            memset(nxt, -1, sizeof(nxt));
            // initialize the leaf to false
            leaf = false;
        }
    };

    // vector of nodes to represent the trie
    vector<node> trie;

    // constructor to initialize the trie
    WordDictionary() {
        // add the root node
        trie.emplace_back();
    }
    
    // function to add a word to the trie
    void addWord(string word) {
        // start from the root node
        int v = 0;
        // loop on the word
        for(auto&i: word){
            // get the index of the child
            int c = i - 'a';
            // if the child doesn't exist create it
            if(trie[v].nxt[c] == -1){
                trie[v].nxt[c] = trie.size();
                trie.emplace_back();
            }
            // move to the child
            v = trie[v].nxt[c];
        }
        // mark the node as a leaf
        trie[v].leaf = true;
    }

    // function to search for a word in the trie
    bool dfs(string&s, int idx, int root){
        // if we reached the end of the word
        if(idx == s.size()){
            // check if the node is a leaf or not
            // if it is a leaf return true else return false
            if(trie[root].leaf) return true;
            return false;
        }
        
        // if the current character is '.' we will loop on all the children of the current node
        if(s[idx] == '.'){
            for(int i = 0; i < 26; i++){
                // if the child exists we will call the dfs function on it and check if it returns true or false
                if(trie[root].nxt[i] != -1){
                    // if the dfs function returns true we will return true else we will continue the loop
                    if(dfs(s, idx + 1, trie[root].nxt[i])) return true;
                }
            }
        }else{
            // if the current character is not '.' we will get the index of the child and check if it exists
            int c = s[idx] - 'a';
            // if the child exists we will call the dfs function on it and return the result of the dfs function
            if(trie[root].nxt[c] != -1) return dfs(s, idx + 1, trie[root].nxt[c]);
        }

        // if we reached this point it means that we didn't find the word in the trie
        return false;
    }
    
    // function to search for a word in the trie
    bool search(string word) {
        // call the dfs function to search for the word in the trie giving it the word, the index of the first character and the root node
        return dfs(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
