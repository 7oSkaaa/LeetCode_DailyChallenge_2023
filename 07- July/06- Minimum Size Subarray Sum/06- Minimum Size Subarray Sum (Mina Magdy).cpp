// Author: Mina Magdy

class Solution {
public:
    // Function to find the minimum length of a subarray with sum at least equal to the target
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); // Calculate the sum of all elements in nums
        if (sum < target) // If the sum is less than the target, no subarray can satisfy the condition, so return 0
            return 0;

        int ans = nums.size(); // Initialize the minimum length of the subarray as the size of nums
        int cur = 0; // Initialize the current sum as 0
        for (int l = 0, r = 0; r < nums.size(); r++) { // Sliding window approach using two pointers, l and r
            cur += nums[r]; // Add the current element to the current sum
            while (l <= r && cur >= target) { // Shrink the window if the current sum is greater than or equal to the target
                ans = min(ans, r - l + 1); // Update the minimum length of the subarray if a smaller length is found
                cur -= nums[l++]; // Subtract the leftmost element from the current sum and move the left pointer
            }
        }
        return ans; // Return the minimum length of the subarray
    }
};
