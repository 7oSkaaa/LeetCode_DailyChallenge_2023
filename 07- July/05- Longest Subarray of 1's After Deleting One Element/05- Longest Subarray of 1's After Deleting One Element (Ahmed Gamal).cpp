// Author: Ahmed Gamal

// for this problem, we can use a sliding window approach
// we want to find the longest subarray that contains at most one zero
// to know if a subarray contains at most one zero, we can check if the number of zeros in the subarray is less than or equal to 1
// the number of ones in the subarray is equal to the sum of the subarray (since the array contains only 0s and 1s)
// so we need to number of ones to be equal to the length of the subarray or the length of the subarray - 1
// the length of the subarray denoted by l and r is r - l + 1, so we need the sum of the subarray to be equal to r - l + 1 or r - l

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // ans: the answer
        // sum: the sum of the current subarray
        int ans = 0, sum = 0;

        // l: the left pointer of the subarray
        // r: the right pointer of the subarray
        for(int l = 0, r = 0; r < nums.size(); r++) {
            // add the current number to the sum
            sum += nums[r];
            
            // if the number of zeros in the subarray is greater than 1, then we need to move the left pointer to the right
            while(sum < r - l) {
                sum -= nums[l++];
            }

            // update the answer
            if(sum >= r - l) {
                ans = max(ans, r - l + 1);
            }
        }

        return --ans;
    }
};