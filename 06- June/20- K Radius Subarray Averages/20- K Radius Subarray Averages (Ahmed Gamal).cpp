// Author: Ahmed Gamal

// for this problem, we can use prefix sum to calculate the sum of each subarray in O(1) time
// then we can just iterate over the array and calculate the average of each subarray

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // ans[i] = average of subarray [i - k, i + k], if i - k < 0 or i + k >= nums.size() then ans[i] = -1
        // prefix[i] = sum of subarray [0, i - 1]
        vector<int> ans(nums.size(), -1);
        vector<long long> prefix(nums.size() + 1);

        // calculate prefix sum
        for(int i = 1; i < prefix.size(); i++) {
            prefix[i] += nums[i - 1] + prefix[i - 1];
        }

        // calculate the average of each subarray (from k + 1 to nums.size() - k)
        for(int i = k + 1; i + k < prefix.size(); i++) {
            ans[i - 1] = (prefix[i + k] - prefix[i - k - 1]) / (k << 1 | 1);
        }

        return ans;
    }
};