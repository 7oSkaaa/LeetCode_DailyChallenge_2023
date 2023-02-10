// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        int n=ideas.size();
        // vector to count number of ideas to each letter
        vector<vector<long long>> cnt(26,vector<long long>(26,0));
        unordered_map<string,bool>mp;
        // add all ideas
        for(auto it:ideas){
            mp[it]=true;
        }
        for(int i=0;i<n;i++){
            // save current suffix
            string tmp=ideas[i].substr(1);
            // get the first char
            int idx=ideas[i][0]-'a';
            // try to swab all 26 letters with current suffix
            for(int j=0;j<26;j++){
                // get current letter
                char ch=j+'a';
                // create the new idea
                string cur=ch+tmp;
                // check if it already exist or not
                if(mp.find(cur)==mp.end()){
                    // if not increare the count of the first letter and j th letter by one
                    cnt[idx][j]+=1;
                }
            }
        }
        // calculate answer
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i!=j && cnt[i][j]){
                    ans+=cnt[i][j]*cnt[j][i];
                }
            }
        }
        return ans;
    }
};