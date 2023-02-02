// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0,ans=0;
        for(int i=0;i<s.size();i++){
            // count ones
            one+=s[i]-'0';
            // find which is best (flip all past ones to zeros of flip all last zeros to one)
            ans=min(one,ans+'1'-s[i]);
        }
        return ans;
    }
};