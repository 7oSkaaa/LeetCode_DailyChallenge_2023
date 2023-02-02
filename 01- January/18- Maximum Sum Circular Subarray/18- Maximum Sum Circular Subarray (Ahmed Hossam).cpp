// Author: Ahmed Hossam

class Solution {
public:

    // get the maximum subarray sum
    int Max_Subarray_Sum(vector < int >& nums){
        int max_so_far = -1e9, max_curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            // add nums[i] to the current sum
            max_curr += i;

            // update max sum with the maximum between it and current sum 
            max_so_far = max(max_so_far, max_curr);

            // if the current sum < 0 make it 0
            max_curr = max(max_curr, DEFAULT);
        }
        // maximum sum
        return max_so_far;
    }

    // get the minimum subarray sum
    int Min_Subarray_Sum(vector < int >& nums){
        int min_so_far = 1e9, min_curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            // add nums[i] to the current sum
            min_curr += i;

            // update min sum with the minimum between it and current sum 
            min_so_far = min(min_so_far, min_curr);

            // if the current sum < 0 make it 0
            min_curr = min(min_curr, DEFAULT);
        }
        // minimum sum
        return min_so_far;
    }


    int maxSubarraySumCircular(vector<int>& nums) {
        // get the summation of the vector
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // get maximum continous subarray sum
        int max_subarray_sum = Max_Subarray_Sum(nums);
    
        // get minimum continous subarray sum
        int min_subarray_sum = Min_Subarray_Sum(nums);
    
        // the answer will be the max of the maximum or total sum - minimum
        return sum - min_subarray_sum == 0 ? max_subarray_sum : max(max_subarray_sum, sum - min_subarray_sum);
    }
};
