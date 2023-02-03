// Author: Ahmed Gamal

class Solution {
public:

    // we want to split the string into palindromes (we want to find all possible partitions)
    // we can use backtracking to try all possible combinations since the number of combinations is small
    // we will use a vector<string> curr to store the current combination
    // we will use a vector<vector<string>> ans to store all valid combinations
    // we will use a string tmp to store the current string we are trying to add to curr
    // we will use a bool is_palindrome(string& str) function to check if a string is a palindrome
    // we will use a void partition(int st, string& s) function to try all possible combinations
    

    // check if a string is a palindrome
    bool is_palindrome(string& str){
        for(int l = 0, r = int(str.size()) - 1; l <= r; l++, r--){
            if(str[l] != str[r])
                return false;
        }
        return true;
    }

    vector<vector<string>> ans;
    vector<string> curr;

    // st is the current index in s
    // s is the string we want to partition
    void partition(int st, string& s){
        // if we reached the end of s, we can add the current combination to ans since it's a valid partition (all parts are palindromes)
        // we don't need to check if the current combination is valid since we are sure that it is
        const int n = (int)s.size();
        if(st >= n){
            ans.emplace_back(curr);
            return;
        }
        
        string tmp;

        for(int i = st; i < n; i++){
            // add the current character to tmp (the current string we are trying to add to curr)
            tmp += s[i];

            // if tmp is a palindrome, we can add it to curr and try to add the next part
            if(is_palindrome(tmp)){
                // add tmp to curr
                curr.emplace_back(tmp);
                // try to add the next part
                partition(i + 1, s);
                // remove tmp from curr before returning to the previous call in the stack
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // try to add the first part
        partition(0, s);
        
        // return the answer
        return ans;
    }
};