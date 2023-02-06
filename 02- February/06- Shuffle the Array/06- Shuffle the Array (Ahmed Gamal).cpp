// Author: Ahmed Gamal

class Solution {
public:

    // simply we want to pair every element in the first half of nums with the corresponding element in the second half
    // we can do this by looping over the first half of nums and add nums[i] and nums[i + n] to the answer vector

    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.emplace_back(nums[i]);
            ans.emplace_back(nums[i + n]);
        }
        return ans;
    }
};