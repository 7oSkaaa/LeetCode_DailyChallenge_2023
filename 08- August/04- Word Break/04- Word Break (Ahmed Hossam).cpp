// Author: Ahmed Hossam

class Solution {
public:
    unordered_map < string, bool > mp;
    
    // The wordBreak function takes a string 's' and a vector of strings 'wordDict'.
    // It returns true if the string 's' can be segmented into words from 'wordDict', false otherwise.
    bool wordBreak(string s, vector < string >& wordDict) {
        // Base case: an empty string can always be segmented (as no word is needed).
        if (s.empty()) return true;
    
        // If the result for the current 's' is already computed, return it to avoid recomputation.
        if (mp.find(s) != mp.end()) return mp[s];
        
        // Get the size of the word dictionary to use it in the loop.
        int n = wordDict.size();
        
        // Loop through the words in the dictionary to find a match with the beginning of 's'.
        for (int i = 0; i < n; i++) {
            // Check if the current word from the dictionary matches the start of 's'.
            if (wordDict[i] == s.substr(0, wordDict[i].length())) {
                // If there is a match, recursively check the rest of the string after removing the matched word.
                bool check = wordBreak(s.substr(wordDict[i].length()), wordDict);
                
                // If the rest of the string can be segmented, update the result for the current 's' to true.
                if (check)
                    return mp[s] = true;
            }
        }
        
        // If no match is found, update the result for the current 's' to false.
        return mp[s] = false;
    }
};
