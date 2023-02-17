// Author: Eileanora
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans;
        int sz = nums.size(); 
        // we will use two pointers to iterate one from the start and the other from the middle
        for(int i = 0 , j = sz / 2; i < sz / 2; i++ , j++) {
            // for each iteration we will push one from the start and one from the middle
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }

};