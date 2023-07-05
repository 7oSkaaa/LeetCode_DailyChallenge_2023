// Author: Ahmed Hossam

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // n is the size of the input vector
        int n = nums.size();
        // l and r are variables used for tracking the left and right indices of the subarray
        int l = 0, r = 0;
        // maxLen is used to store the length of the longest subarray
        int maxLen = 0;
        // sum is used to keep track of the sum of the elements in the subarray
        int sum = 0;

        // Loop through the elements of the vector
        while(r < n) {
            // Add the current element to the sum
            sum += nums[r];

            // Shrink the subarray from the left until the sum is greater than or equal to the length of the subarray
            while(l < r && sum < r - l)
                sum -= nums[l++];

            // Update the maxLen if the current subarray length is greater than the previous maxLen
            maxLen = max(maxLen, r - l);

            // Move to the next element
            r++;
        }

        // Return the length of the longest subarray
        return maxLen;
    }
};
