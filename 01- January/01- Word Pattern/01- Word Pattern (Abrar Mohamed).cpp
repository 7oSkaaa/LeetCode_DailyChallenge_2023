// Author: Abrar

class Solution {
public:
    bool wordPattern(string pattern, string str) {
 // to assign chars from the pattern to words from string.
        unordered_map<char, string> char_map;
//vise versa
        unordered_map<string, char> word_map;
  // for insertion and extraction of data to/from the string objects      
        stringstream s(str); 
// A string to store the word on each iteration.
        string word;
        int n = pattern.size(), i = 0;
        // while there is words
        while(s >> word){
            if(i == n) return false;
            char c = pattern[i];
// check if the number of words equal or not the chars of the pattern string.
            if(char_map.count(c) != word_map.count(word)) return false;
            if(char_map.count(c)){
                if( (word_map[word] != c) || (char_map[c] != word)) return false;
            } else {
                char_map.insert({c, word});
                word_map.insert({word, c});
            }
            i++;
        }
        return i == n;
    }
};
