//Author: Mohamed Ibrahim

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Use a hash set to store all the words in the given list
        unordered_set<string> dict;
        vector<string> res;
        for(auto word : words) dict.insert(word);
        // Check each word in the list
        for(auto word : words) {
            // Erase the word from the hash set before checking
            dict.erase(word);
            /*If the word can be concatenated by other words in the list,
            add it to the result list*/ 
            if(check(word, dict)) res.push_back(word);
            // Insert the word back into the hash set
            dict.insert(word);
        }
        return res;
    }
    bool check(string word, unordered_set<string>& dict) {
        int n = word.size();
        /*To check if a word can be concatenated by other words in the list,
        we use a dp approach.*/
        vector<bool> dp(n + 1);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            // Check all possible substrings word[j, i)
            for(int j = 0; j < i; j++) {
                /*If the substring word[0, j) cannot be concatenated,
                skip it*/
                if(!dp[j]) continue;
                /*If the substring word[j, i) is in the hash set,
                 set dp[i] to true and break the loop*/
                if(dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        // Return the last element of the dp array
        return dp[n];
    }
};
