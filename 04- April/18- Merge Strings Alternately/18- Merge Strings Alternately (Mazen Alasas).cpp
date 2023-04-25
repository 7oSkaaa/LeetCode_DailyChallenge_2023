//Author: Mazen Alasas
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = ""; 
        int i = 0, j = 0;   // Indicies for each word
        while(i < word1.size() || j < word2.size()) {
            i < word1.size() ? merged += word1[i] : merged; // First add one char from word1
            j < word2.size() ? merged += word2[j] : merged; // Then add one char from word2 and so on
            i++, j++;   // Move to the next char in the words
        }
        
        return merged;
    }
};
