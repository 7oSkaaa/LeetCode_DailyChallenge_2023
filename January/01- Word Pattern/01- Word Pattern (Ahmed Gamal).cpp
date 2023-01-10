// Author: Ahmed Gamal

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // use string stream to ignore spaces and manipulate the string as seperate words
        stringstream ss(s);

        // if the count of the words is not divisible by the pattern size, then it will be impossible for the string to follow the pattern
        if((count(s.begin(), s.end(), ' ') + 1) % pattern.size())
            return false;

        // two maps for the bijection mapping
        map<char, string> ctow; // character to word
        map<string, char> wtoc; // word to character

        string word; // the current word to be manipulated
        int idx = 0; // index of the character in the pattern
        while(ss >> word){ // run the loop while you have more words to manipulate in the string
            char c = pattern[idx]; 
            bool char_found = false, word_found = false; // two flags to show if the current word/character was found previously
            
            char_found |= ctow.find(c) != ctow.end();
            word_found |= wtoc.find(word) != wtoc.end();

            if(word_found){
                // if the word appeared previously and was mapped to a different character
                if(wtoc[word] != c){
                    return false;
                }
            }else if(char_found){
                // if the character appeared previously and was mapped to a different word
                if(ctow[c] != word){
                    return false;
                }
            }else{
                // if both never appeared, map them to each other
                wtoc[word] = c;
                ctow[c] = word;
            }
            
            idx++;
            idx %= pattern.size(); // cyclic tracking of the current character of the pattern
        }

        // everything is ok and we have a valid mapping
        return true;
    }
};