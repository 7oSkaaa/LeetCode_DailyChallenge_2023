// Author : Omar Waael

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        // loop by columns
        for(int i=0;i<strs[0].size();i++){
            // loop by words
            for(int j=0;j<strs.size()-1;j++){
                // check if the current letter of jth word is lexicographically greater than the current letter of j+1th word
                if(strs[j][i]>strs[j+1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};