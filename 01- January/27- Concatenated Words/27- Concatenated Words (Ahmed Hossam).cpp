// Author: Ahmed Hossam

class Solution {
public:

    vector < vector < int > > dp;
    unordered_map < string, bool > exist;
    
    bool wordBreak(string& s, int l, int r) {
        // if the string become empty
        if(l > r) return true;

        // if this substring is calulated before
        int& ret = dp[l][r];
        if(~ret) return ret;

        // check the left substring and right substring
        ret = false;
        for(int i = l; i <= r; i++){

            // check the substring from l to i
            if(exist[s.substr(l, i - l + 1)] && s.substr(l, i - l + 1) != s)
                ret |= wordBreak(s, i + 1, r);

            // check the substring from i to r
            if(exist[s.substr(i, r - i + 1)] && s.substr(i, r - i + 1) != s)
                ret |= wordBreak(s, l, i - 1);
        }
        return ret;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector < string > conc_words;
        for(auto& word : words)
            exist[word] = true;
        for(int i = 0; i < words.size(); i++){
            int n = words[i].size();
            // re inital the dp
            dp = vector < vector < int > > (n, vector < int > (n, -1)); 
            // check the current word
            if(wordBreak(words[i], 0, n - 1))
                conc_words.push_back(words[i]);
        }
        return conc_words;
    }
};
