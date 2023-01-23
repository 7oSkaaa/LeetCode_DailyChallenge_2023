// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>path;
        rec(s,path,0);
        return ans;
    }
    void rec(string& s,vector<string>& path,int cur){
        //if we reach end of string then save the path
        if(cur==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=cur;i<s.size();i++){
            // if the sub string is palindrome then
            if(isPalindrome(s,cur,i)){
                // push the sub string into path
                path.push_back(s.substr(cur,i-cur+1));
                rec(s,path,i+1);
                path.pop_back();
            }
        }
    }
    // function to check if this substr is palindrome or not
    bool isPalindrome(string& s, int l, int r) {
        while(l<r) {
            if(s[l]!=s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};