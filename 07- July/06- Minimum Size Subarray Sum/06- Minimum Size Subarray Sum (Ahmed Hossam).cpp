// Author: Ahmed Hossam

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0; // Pointers for the left and right ends of the subarray
        int Max_length = INT_MAX; // Maximum length of subarray
        int sum = 0; // Current sum of elements in the subarray

        while (l < nums.size()) {
            // Add the next element to the sum and move the right pointer
            while (r < nums.size() && sum < target)
                sum += nums[r++];

            // Update the maximum length if the current length is smaller
            if (sum >= target)
                Max_length = min(Max_length, r - l);

            // Remove the leftmost element from the sum and move the left pointer
            sum -= nums[l++];
        }

        // Return the minimum subarray length or 0 if no such subarray exists
        return (Max_length == INT_MAX ? 0 : Max_length);
    }
};
