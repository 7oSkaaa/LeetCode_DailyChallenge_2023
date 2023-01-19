// Author: Mahmoud Aboelsoud

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // to find the maximum subarray sum in a circular array we have two cases:
        // 1- the maximum subarray sum is in the middle of the array
        // 2- the maximum subarray sum is in the left part of the array starting from 0 + the maximum subarray sum in the right part of the array ending at n - 1
        // to find the maximum subarray sum in the middle of the array we can use Kadane's algorithm
        // to find the maximum subarray sum in the left part of the array starting from 0 + the maximum subarray sum in the right part of the array ending at n - 1
        // we can use prefix sum and suffix sum
        // to find the maximum subarray sum in the left part of the array starting from 0 we use prefix sum and store the maximum subarray sum starting from 0 and ending at i in mx_left_sum[i]
        // mx_left_sum[i] = max subarray sum starting between 0 and i and ending at i
        // to find the maximum subarray sum in the right part of the array ending at n - 1 we use suffix sum and store the maximum subarray sum starting from i to n - 1 in mx_right_sum[i]
        // mx_right_sum[i] = max subarray sum starting between i and n - 1 and ending at n - 1
        // to find the maximum subarray sum that is circular we combine the subarray sum from 0 to i and the maximum subarray sum from i + 1 to n - 1
        // mxsum = max(mxsum, mx_left_sum[i] + mx_right_sum[i + 1])

        // Kadane's algorithm
        // to find the maximum subarray sum in the middle of the array
        int n = nums.size();
        // mxsum is the maximum subarray sum, sum is the current subarray sum
        int mxsum = nums[0], sum = nums[0];
        for(int i = 1; i < n ; i++){
            // if the current subarray sum is negative, we can't add the next element to it
            // so we start a new subarray with the next element
            // otherwise we add the next element to the current subarray
            sum = max(sum + nums[i], nums[i]);
            // we update the maximum subarray sum
            mxsum = max(sum, mxsum);
        }

        // to find the maximum subarray sum in the right part of the array ending at n - 1
        // we use suffix sum and store the maximum subarray sum starting from i to n - 1 in mx_right_sum[i]
        vector<int> mx_right_sum(n);
        mx_right_sum[n - 1] = nums[n - 1];
        int right_sum = nums[n - 1];

        // we start from the second last element and go to the first element
        // we store the maximum subarray sum starting from i to n - 1 in mx_right_sum[i]
        // mx_right_sum[i] = max subarray sum starting between i and n - 1 and ending at n - 1
        // we use suffix sum
        for(int i = n - 2; i >= 0; i--){
            right_sum += nums[i];
            mx_right_sum[i] = max(right_sum, mx_right_sum[i + 1]);
        }

        // to find the maximum subarray sum in the left part of the array starting from 0
        // we use prefix sum but we don't store the maximum subarray sum starting from 0 to i because we caculate the maximum circular subarray sum on the fly
        // as we always take the max between the current maximum subarray sum and the sum of left subarray sum starting from 0 to i and the maximum subarray sum in the right part from i + 1 to n - 1
        
        int left_sum = 0;

        for(int i = 0; i < n - 1; i++){
            // we add the current element to the left subarray sum
            left_sum += nums[i];
            // we update the maximum circular subarray sum with the maximum between the current maximum circular subarray sum and the sum of left subarray sum starting from 0 to i and the maximum subarray sum in the right part from i + 1 to n - 1
            mxsum = max(mxsum, left_sum + mx_right_sum[i + 1]);
        }

        return mxsum;
    }
};
