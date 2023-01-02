// Author: Lama Salah

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map <string, char> mp1; 
        map <char, string> mp2;

        string current_word;
        int i = 0, j = 0;
        while (i < pattern.size() && j < s.size()){
            current_word = "";
            while (j < s.size() && s[j] != ' '){ 
                current_word += s[j];
                j++;
            }

            if ((mp1.count(current_word) && mp1[current_word] != pattern[i]) || (mp2.count(pattern[i]) && mp2[pattern[i]] != current_word)) return false; 
            /* Check if the mp1[current word] stores any characters before, 
               if that is true check if this character that stores in mp1[current word] is the same the current character or not
               OR
               Check if the mp2[current character] stores any words before, 
               if that is true check if the word that stores in mp2[current character] is the same the current word or not
            */

            mp1[current_word] = pattern[i];
            mp2[pattern[i]] = current_word;

            i++, j++;
        }
        
        if (i < pattern.size() || j < s.size()) return false; 
        return true;
    }
};
