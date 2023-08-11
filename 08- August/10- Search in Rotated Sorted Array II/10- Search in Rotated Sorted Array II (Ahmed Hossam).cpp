// Author: Ahmed Hossam

class Solution {
public:
    // Binary search function to find target in rotated sorted array
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; // Define left and right pointers
        while(l <= r){ // Continue loop as long as left pointer is less than or equal to right pointer
            int m = l + (r - l) / 2; // Calculate middle index
            if(nums[m] == target) return true; // Target found at middle index
            if(nums[l] == nums[m]) l++; // Handle duplicate values at the left end
            else if(nums[l] <= nums[m]) // If left part is sorted
                (nums[l] <= target && target <= nums[m] ? r = m - 1 : l = m + 1); // Adjust pointers based on target location in sorted portion
            else // If right part is sorted
                (nums[m] <= target && target <= nums[r] ? l = m + 1 : r = m - 1); // Adjust pointers based on target location in sorted portion
        }
        return false; // Target not found in the array
    }
};
