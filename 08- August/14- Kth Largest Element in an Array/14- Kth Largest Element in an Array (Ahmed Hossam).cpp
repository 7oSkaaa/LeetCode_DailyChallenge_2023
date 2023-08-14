// Author: Ahmed Hossam

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the vector in non-ascending order using the reverse iterators
        sort(nums.rbegin(), nums.rend());
        // Return the kth largest element by accessing the (k-1)th index
        return nums[--k];
    }
};
