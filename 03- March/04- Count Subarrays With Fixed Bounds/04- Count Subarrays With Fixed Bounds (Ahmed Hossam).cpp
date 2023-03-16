// Author: Ahmed Hossam

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), minPos = -1, maxPos = -1, leftBound = -1;
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            
            // the index of the last invalid bound
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            // update min position
            if (nums[i] == minK) 
                minPos = i;
            
            // update max position
            if (nums[i] == maxK)
                maxPos = i;

            // add the number of subarrays that i will be the right bound of them
            res += max(0, min(maxPos, minPos) - leftBound);
        }
        
        return res;
    }
};
