// Author: Osama Ayman
// Time: O(nlogn)
// Space: O(n)
class Solution {
    
    public int numSubseq(int[] nums, int target) {
        int mod = (int) 1e9+7;
        // Sort the array and apply the 2-pointers strategy
        Arrays.sort(nums);
        int n = nums.length;
        // Precompute the value of 2 to the power of each value.
        int[] power = new int[n];
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0;
        int right = nums.length-1;
        int res = 0;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                // the number of subsequences is 2 ^ (right-left)
                res += power[right - left];
                res %= mod;
                left++;
            }
            else right--;
        }
        return res;
    }
}