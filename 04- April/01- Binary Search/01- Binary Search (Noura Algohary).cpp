// Author: Noura Algohary

// Binary Search Iteration Method
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;

        // repeat till left > right
        while(left <= right)
        {
            mid = (left + right) / 2;

            if(target == nums[mid])
                return mid;
            else if (target < nums[mid])  // target is on the left side
                right = mid - 1;
            else    // target is on the right side
                left = mid + 1;
        }

        // target not found
        return -1;
    }
};