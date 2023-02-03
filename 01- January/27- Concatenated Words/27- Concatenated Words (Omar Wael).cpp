// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        set<string>s;
        // push all words into set
        for(int i=0;i<words.size();i++){
            s.insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            int n=words[i].size();
            vector<int>dp(n+1,0);
            dp[0]=1;
            for(int j=0;j<n;j++){
                // if sub string from begin of the word to index j if a concatenated word
                if(dp[j]){
                    // then search on rest of the word
                    for(int k=j+1;k<=n;k++){
                        // if you can create a substring from index j to index k 
                        if(k-j<n && s.find(words[i].substr(j,k-j))!=s.end()){
                            dp[k]=1;
                        }
                    }
                }
                // if dp[n]==1 that means that word[i] is a concatenated word
                if(dp[n]){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};