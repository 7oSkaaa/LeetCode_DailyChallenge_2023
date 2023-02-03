// Author: Noura Algohary
/*
Kadane's Algorithm is about getting the maximum sum of a subarray
ex: nums = [1, -2, 3, -2]
working on nums[3] 
                    max
                -2  -2
            3   -2   1   max(-2, (-2 + 3))
        -2  3   -2  -2   max(-2, (-2 + 3))
    1   -2  3   -2   2   max(-2, (-2 + 4))

In this problem, we are using Kadane's algorithm with some additions to implement a circular array.
By finding the maximum value between cumulative sum of the array subtracting the min subarray sum and finding the max subarray sum.
*/
class Solution {
public:
     int KadaneAlgorithm(vector<int>nums, int sum)
    {
        int global_max = nums[0], local_max = nums[0], local_min = nums[0], global_min = nums[0];

        for(int i =1;i<nums.size();i++)
        {
            // find max subarray sum
            local_max = max(nums[i], nums[i] + local_max);

            if(local_max > global_max)
                global_max = local_max;

            // find min subarray sum
            local_min = min(nums[i], nums[i] + local_min);

            if(local_min < global_min)
                global_min = local_min;
        }
        // all values are negative
        if(global_min == sum) return global_max;  

        return max(sum - global_min, global_max);
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = INT_MIN, cum_sum = 0;

        // to find cumulative sum
        for(int num : nums)
            cum_sum += num;

        max_sum = KadaneAlgorithm(nums, cum_sum);

        return max_sum;
    }
};