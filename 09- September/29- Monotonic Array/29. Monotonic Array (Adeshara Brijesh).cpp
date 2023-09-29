// Author : Adeshara Brijesh
// 896. Monotonic Array
// An array is monotonic if it is either monotone increasing or monotone decreasing.
// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
// An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true
// Explaination : [1 <= 2 <= 2 <= 3] which is absolutely true and so it is a monotone increasing.

// Example 2:
// Input: nums = [6,5,4,4]
// Output: true
// Explaination : [6 >= 5 >= 4 >= 4] which is absolutely true and so it is a monotone decreasing.

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // store the size of numbers of array in an integer.
        int n = nums.size();
        // initialize false as default
        bool increasing  = false;
        bool decreasing  = false;
        //use a for loop to check all the numbers.
        for(int i = 0; i < n-1; i++){
            //if condition meets the requirements the mark as true for both increasing and decreasing order.
            if(nums[i] < nums[i + 1]){
                increasing = true;
            }
            else if(nums[i] > nums[i + 1]){
                decreasing = true;
            }
            if(increasing && decreasing){
                return false;
            }
        }
        return true;

    }
};
