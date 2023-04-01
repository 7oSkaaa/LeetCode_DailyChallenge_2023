// Author: Osama Ayman
class Solution {
    //Time: O(logn)
    //Space: o(1)
    public int search(int[] nums, int target) {
        int res=-1;
        int lo=0, hi=nums.length-1;
        while(lo<=hi){
            // finding mid index
            int mid=lo+(hi-lo)/2;
            // if target found at mid idx return it
            if(nums[mid]==target) return mid;
            // if nums[mid] is smaller than target search in the right part
            if(nums[mid]<target) lo=mid+1;
            // else search in left part
            else hi=mid-1;

        }

        return res;
    }
}