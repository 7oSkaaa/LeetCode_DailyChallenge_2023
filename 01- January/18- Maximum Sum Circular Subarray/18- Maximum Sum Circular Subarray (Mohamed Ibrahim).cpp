//Author: Mohamed Ibrahim

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Initialize total,mxSum,mx,mnSum and mn variables
        int total = 0,mxSum = nums[0],mx = 0,mnSum=nums[0],mn=0;
        // Iterate through the array
        for(auto &n:nums){
                // Update the current maximum sum of subarray
                mx = max(n,mx+n);
                // Update the maximum sum of subarray
                mxSum = max(mxSum,mx);
                // Update the current minimum sum of subarray
                mn = min(n,mn+n);
                // Update the minimum sum of subarray
                mnSum = min(mnSum,mn);
                // Add the current element to the total sum
                total+=n;
        }
        // Return the maximum sum of subarray, either from the non-circular array or the circular array
        return mxSum>0 ? max(mxSum,total-mnSum) : mxSum;    
    }
};
