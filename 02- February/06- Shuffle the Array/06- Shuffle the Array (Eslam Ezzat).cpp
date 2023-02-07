// Author: Eslam Ezzat

// Time Complexity: O(N)

// Space Complexity: O(N)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>q;
        for(int i=0;i<n;i++)
        {
            q.push_back(nums[i]);
            q.push_back(nums[i+n]);
        }
        return q;
    }
};