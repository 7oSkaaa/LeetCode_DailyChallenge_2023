// Author: Mahmoud Aboelsoud

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // we need to merge the two strings alternately
        // we can use two pointers to iterate over the two strings
        // and add the characters to the answer string
        
        // i : pointer for word1
        // j : pointer for word2
        // ans : the answer string
        int i = 0, j = 0;
        string ans;

        // we will iterate over the two strings until we reach the end of both of them
        while(i < word1.size() || j < word2.size()){
            // if we haven't reached the end of word1, add the character to the answer string
            if(i != word1.size()) ans += word1[i++];
            // if we haven't reached the end of word2, add the character to the answer string
            if(j != word2.size()) ans += word2[j++];
        }

        // return the answer string
        return ans;
    }
};
