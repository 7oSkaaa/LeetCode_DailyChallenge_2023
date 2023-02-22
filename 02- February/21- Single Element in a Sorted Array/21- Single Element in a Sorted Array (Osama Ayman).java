// Author: Osama Ayman
// The idea is that the number that is only repeated once will be in an array of odd length.
class Solution {
    public int singleNonDuplicate(int[] nums) {
        return solve(nums, 0, nums.length-1);
    }
    private int solve(int[] nums, int lo, int hi){
        if(lo==hi) return nums[lo];
        int mid = lo+(hi-lo)/2;
        // if the number at mid idx equal the number of before it
        if(nums[mid-1]==nums[mid]){
            // if the left side is odd then the result is in the left side.
            if((mid-lo+1)%2==1) return solve(nums, lo, mid);
            // else the result is in the right side.
            return solve(nums, mid+1, hi);
        }
        // if the number at mid idx equal the number after it
        if(nums[mid]==nums[mid+1]){
            // if the right side is odd then the result is in the right side.
            if((hi-mid+1)%2==1) return solve(nums, mid, hi);
            // else the result is in the left side.
            return solve(nums, lo, mid-1);
        }

        return nums[mid];
    }
}