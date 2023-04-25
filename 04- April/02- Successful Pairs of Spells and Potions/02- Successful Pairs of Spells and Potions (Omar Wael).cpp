// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        // sort all potions
        sort(potions.begin(),potions.end());
        int n=spells.size(),m=potions.size();
        for(int i=0;i<n;i++){
            // get minimum value will be Successful with current spell
            long long val;
            if(success%spells[i]==0){
                val=success/spells[i];
            }else{
                val=(success/spells[i])+1;
            }
            // get first index in potions store value greater than or equal to val
            // using lower bound to use less time  
            int up=lower_bound(potions.begin(),potions.end(),val)-potions.begin();
            if(up!=m && potions[up]>=val){
                ans.push_back(m-up);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
