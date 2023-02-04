// Author: Ahmed Hossam

class Solution {
public:
    
    // to store the answers
    vector < vector < string > > ans;
    
    // the pick up vector in the backtracking
    vector < string > level;
    
    // check the string is palindrome or not
    bool is_palindrome(string& s, int l, int r){
        while(l <= r)
            if(s[l++] != s[r--]) return false;
        return true;
    }
    
    void dfs(string &s, int start){
        // if the string is end and all of it are palindromes
        if(start >= s.size()) ans.push_back(level);
        
        // loop over the remaining indices and check if the substring is palindrome so pick it othwerwise leave it
        for(int end = start; end < s.size(); end++){
            if(is_palindrome(s, start, end)){
                level.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1);
                level.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string& s) {
        // do back tracking to get the palindrome vectors
        dfs(s, 0);
        
        return ans;
    }
};
