// Author: Mahmoud Aboelsoud

class Solution {
public:
    // in this problem we need two find the words that can be concatenated from at least two other words in the list
    // so we can do that by trying to find the maximum number of words that can be concatenated to form the each word in the list
    // if the maximum number is greater than 1 then the word can be concatenated from at least two other words in the list
    // so we can use dp to solve this problem
    // dp[string] = maximum number of words that can be concatenated to form the string
    // so we itrate over the string and split it into two parts if the first part is a word then we can concatenate it with the second part
    // so we try to find the maximum number of words that can be concatenated to form the second part
    // if the second part cannot be concatenated we return -1e9 to make sure that the total number of words that can be concatenated to form the string is less than 1


    // set to store the words in the list so we can check if a word is in the list
    unordered_set<string> words_set;

    // dp to store the maximum number of words that can be concatenated to form the string
    unordered_map<string, int> dp;

    // function to find the maximum number of words that can be concatenated to form the string
    int mx(string s){
        // if the string is empty then we can't concatenate any words to form it so we return 0
        if(s.size() == 0) return 0;
        
        // if the string is in the dp then we return the value of the string in the dp to avoid re-computing
        if(dp.count(s)) return dp[s];

        // if the string is a word then we can concatenate it with 1 word so we return 1 
        // if the string is not a word then we return -1e9 to make sure that the total number of words that can be concatenated to form the string is less than 1
        int ans = (words_set.count(s) ? 1 : -1e9);
        
        // itrate over the string and split it into two parts
        for(int i = 1; i < s.size(); i++){
            // if the first part is a word we have in the list then we can concatenate it with the second part
            if(words_set.count(s.substr(0 , i)))
                // we try to find the maximum number of words that can be concatenated to form the second part and add 1 to it to concatenate the first part with it 
                ans = max(ans, 1 + mx(s.substr(i, s.size() - i)));    
        }

        // store the value of the string in the dp and return it
        return dp[s] = ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // insert the words in the list in the set
        for(auto&i: words)
            words_set.insert(i);

        // vector to store the words that can be concatenated from at least two other words in the list
        vector<string> ans;
        // itrate over the words in the list and check if the maximum number of words that can be concatenated to form the word is greater than 1
        for(auto&i: words)
            // if the maximum number of words that can be concatenated to form the word is greater than 1 then the word can be concatenated from at least two other words in the list
            // so we push it in the ans vector
            if(mx(i) > 1) ans.push_back(i);

        return ans;   
    }
};
