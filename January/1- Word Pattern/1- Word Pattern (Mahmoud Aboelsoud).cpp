// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool wordPattern(string chars, string s) {
        
        // split the string into words
        vector<string> words;
        string word = "";
        for(auto&i: s){
            if(i == ' '){
                words.push_back(word);
                word = "";
            }else
                word += i;
        }
        
        words.push_back(word);
        
        // check if the number of words doesn't match the length of characters
        if(words.size() != chars.size()) return 0;
        
        // define two maps to map the word to character and vice versa
        map<char,string> char_to_word;
        map<string, char> word_to_char;
        
        // loop on characters pattern string
        for(int i = 0; i < chars.size(); i++){
            // check if the current character already exists
            if(char_to_word.count(chars[i])){
                
                // check if the current word is mapped to a different character and return false if true
                if(char_to_word[chars[i]] != words[i]) return 0;
            
            }else{
                // map the current word to the current character
                char_to_word[chars[i]] = words[i];
            }

            // check if the current word already exists
            if(word_to_char.count(words[i])){

                // check if the current character is mapped to a different word and return false if true
                if(word_to_char[words[i]] != chars[i]) return 0;

            }else{
                // map the current character to the current word
                word_to_char[words[i]] = chars[i];
            }
        
        }
        
        return 1;
    
    }
};
