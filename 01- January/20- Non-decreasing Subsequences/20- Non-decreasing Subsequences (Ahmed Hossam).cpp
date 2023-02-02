// Author: Ahmed Hossam

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // to store the answer
        vector < vector < int > > inc_sub;
        
        // number of elements
        int n = nums.size();

        for(int mask = 0; mask < (1 << n); mask++){
            // pick the current sub sequence and check if it valid 
            bool is_valid = true;
            vector < int > curr;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    // check if it increasing subsequence or not
                    if(curr.empty() || curr.back() <= nums[i])
                        curr.push_back(nums[i]);
                    else
                        is_valid = false;
                }
            }

            // if it's valid subsequence so we will add it
            if(is_valid && curr.size() > 1)
                inc_sub.push_back(curr);
        }

        // delete the duplicated subsequences
        sort(inc_sub.begin(), inc_sub.end());
        inc_sub.resize(unique(inc_sub.begin(), inc_sub.end()) - inc_sub.begin());
        
        return inc_sub;
    }
};
