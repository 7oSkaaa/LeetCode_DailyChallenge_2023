// Author: Ahmed Hossam

template < int Mode = 0 > struct Trie {
    // Mode [lowercase, uppercase, digits]
    static constexpr int sz[4] = {26, 26, 10};

    struct Node {

        // declare array of nodes with requires size
        Node* child[sz[Mode]];
        bool is_word;
        int freq;
 
        Node(){
            memset(child, 0, sizeof(child));
            is_word = false;
            freq = 0;
        }
    };

    // declare the base root
    Node* root;
    char DEFAULT;

    Trie(){
        root = new Node;
        DEFAULT = "aA0"[Mode];
    }
    
    // insert a word in the trie
    void insert(const string& word){
        Node* curr = root;
        for(auto& c : word){
            // if this char in this position not appeared before let's create it
            if(!curr -> child[c - DEFAULT]) 
                curr -> child[c - DEFAULT] = new Node;
            // move to the next position
            curr = curr -> child[c - DEFAULT];
            // update the frequency of the current string
            curr -> freq++;
        }
        curr -> is_word = true;
    }
    
    // search for a string in the Trie
    bool search(const string& word, int idx, Node* curr){
        // if we reach the final of the string let's return if it was a word or not
        if(idx == word.size()) return curr -> is_word;

        // if the current char is a lowercase letter
        if(word[idx] != '.'){
            // let us check if it is already found so check the next letter otherwise retrun false
		    if(!curr -> child[word[idx] - DEFAULT]) return false;
		    return search(word, idx + 1, curr -> child[word[idx] - DEFAULT]);
        }else {
            // if the current char is a wildcard
            bool answer = false;
            // let's check all the possible letters
            for(auto& node : curr -> child){
                if(node)
                    if(search(word, idx + 1, node))
                        return true;
            }
            return answer;
        }
    }

    // overloading function to the user to use
    bool search(const string& word){
        return search(word, 0, root);
    }
 
};

class WordDictionary {
public:

    // trie to store the strings
    Trie < > trie;

    WordDictionary() {
        trie = Trie < 0 > ();
    }
    
    void addWord(const string& word) {
        // add the current word to the trie
        trie.insert(word);
    }
    
    bool search(const string& word) {
        // search about this word can we got it or not
        return trie.search(word);
    }
};
