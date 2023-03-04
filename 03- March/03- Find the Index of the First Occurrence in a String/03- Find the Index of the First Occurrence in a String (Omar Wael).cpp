// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        // try all possible sub strings
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }
        // if not found any sub string 
        // then return -1
        return -1;
    }
};

