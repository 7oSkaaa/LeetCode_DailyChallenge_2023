// Author: Ahmed Hossam

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        // Dynamic programming array to store valid partition information
        vector < bool > dp(4);
        dp[0] = true; // Base case: an empty partition is always valid
        // Checking if first two elements are equal
        dp[2] = (dp[2] | (dp[0] & (nums[1] == nums[0])));
        
        // Loop to iterate through the array and populate dp array
        for(int i = 3, j = 2; i <= n; i++, j++) {
            // re initial the current state
            dp[i % 4] = false;

            // If the last two elements are equal, extend the valid partition
            if(nums[j] == nums[j - 1])
                dp[i % 4] = (dp[i % 4] | dp[(i - 2) % 4]);

            // If the last three elements are equal, extend the valid partition
            if(nums[j] == nums[j - 1] && nums[j] == nums[j - 2])
                dp[i % 4] = (dp[i % 4] | dp[(i - 3) % 4]);

            // If the last three elements form an increasing sequence, extend the valid partition
            if(nums[j] == nums[j - 1] + 1 && nums[j] == nums[j - 2] + 2)
                dp[i % 4] = (dp[i % 4] | dp[(i - 3) % 4]);

        }
        
        // Return whether the entire array can be partitioned into valid subsequences
        return dp[n % 4];
    }
};
