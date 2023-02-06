//Author: Mohamed Ibrahim
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans; // to store the answer
         for(int i = 0; i < n; i++){
             /*for each iteration we will push one from the start and one from the middle*/
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};