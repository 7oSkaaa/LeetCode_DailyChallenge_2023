// Author: Mina Magdy

class Solution {
public:
    // Function to find the length of the longest subarray with consecutive ones
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> left(n), right(n); // Create two arrays to store the lengths of consecutive ones on the left and right sides of each index

        // Calculate the lengths of consecutive ones on the left side of each index
        for (int i = 0; i < n; i++) {
            left[i] = (nums[i] == 1 ? 1 + (i ? left[i - 1] : 0) : 0);
        }

        // Calculate the lengths of consecutive ones on the right side of each index
        for (int i = n - 1; i >= 0; i--) {
            right[i] = (nums[i] == 1 ? 1 + (i != n - 1 ? right[i + 1] : 0) : 0);
        }

        int ans = 0; // Initialize the maximum length to 0

        // Iterate over each index to find the maximum length of consecutive ones by considering the left and right sides
        for (int i = 0; i < n; i++) {
            ans = max(ans, (i - 1 >= 0 ? left[i - 1] : 0) + (i + 1 < n ? right[i + 1] : 0));
        }

        return ans; // Return the maximum length of consecutive ones
    }
};
