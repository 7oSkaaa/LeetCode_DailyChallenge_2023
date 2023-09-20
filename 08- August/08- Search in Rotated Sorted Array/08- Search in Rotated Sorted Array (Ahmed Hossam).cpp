// Author: Ahmed Hossam

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize two pointers 'l' and 'r' to the start and end of the vector.
        int l = 0, r = nums.size() - 1;

        // Perform a binary search by narrowing down the search range until 'l' is less than or equal to 'r'.
        while(l <= r){
            // Check if the element at index 'l' is equal to the target. If so, return 'l'.
            if(nums[l] == target) return l;

            // Check if the element at index 'r' is equal to the target. If so, return 'r'.
            if(nums[r] == target) return r;

            // If neither 'l' nor 'r' elements match the target, move 'l' one step right and 'r' one step left.
            r--, l++;
        }

        // If the target element is not found in the vector, return -1.
        return -1;
    }
};
