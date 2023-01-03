// Author: Mina Magdy

class Solution {
public:
    vector<string> splitWords(string& s) {
        // Create stringstream from string s
        stringstream ss(s);
        vector<string> words;
        string tmp;
        // Getting words from stringstream as input 
        while (ss >> tmp) {
            words.push_back(tmp);
        }
        return words;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> words(splitWords(s));
        int n = pattern.size();
        // The number of pattern characters and number of words should be equal 
        if (int(words.size()) != n) return false; 
        
        map<char, string> mps;
        for (int i = 0; i < n; i++) {
            // If the char match with a word then count > 0
            if (mps.count(pattern[i])) {
                // They should be equal, the mapped word with the current word
                if (mps[pattern[i]] != words[i]) return false; 
            }
            // Map every char with corresponding word
            mps[pattern[i]] = words[i];
        }
        // If there is a word mapped with more than one different characters return false
        map<string, int> freq;
        for (auto& I : mps) {
            freq[I.second]++;
            if (freq[I.second] > 1) return false;
        }
        return true;
    }
};
