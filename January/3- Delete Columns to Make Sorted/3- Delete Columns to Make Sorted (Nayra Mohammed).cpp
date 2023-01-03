//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;

        for(int i = 0; i < sz(strs[0]); i++) //iterate over columns
        {   bool bad = 0; 
            
            for(int j = 1; j < sz(strs); j++)// for each column check if it isnt sorted
                 bad|=(strs[j][i] < strs[j-1][i]); //if not sorted update bad = 1,otherwise it will stay still 
          
            ans += bad;
        }

        return ans;
    }
};
