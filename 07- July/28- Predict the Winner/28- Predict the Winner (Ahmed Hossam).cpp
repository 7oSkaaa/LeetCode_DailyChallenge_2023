// Author: Ahmed Hossam

class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int l, int r) {
        // Base case: if left pointer exceeds right pointer, return 0
        if (l > r) return 0;
        
        // Reference to the current memoization cell
        int& ret = dp[l][r];
        
        // If the result has already been calculated, return it
        if (~ret) return dp[l][r];
        
        // Calculate the maximum score difference between the first and last element
        int first = nums[l] - solve(dp, nums, l + 1, r); 
        int last = nums[r] - solve(dp, nums, l, r - 1); 
        
        // Store the maximum of the two choices in the memoization cell and return it
        return ret = max(first, last);
    }

    // Function to determine if the first player can win the game or not
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Create a memoization table with initial values as -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Check if the first player's score is greater than or equal to 0 (which means they can win)
        return solve(dp, nums, 0, n - 1) >= 0;
    }
};
