// Author: Osama Ayman
class Solution {
    public int jump(int[] nums) {
        // dp array to save min jumps to rech each index
        int[] jumps = new int[nums.length];
        jumps[0]=0;
        // index of max reached cell in jumps dp array
        int maxReached = 0;
        int nums_idx=0;
        while(maxReached < nums.length && nums_idx<nums.length){
            int range = nums[nums_idx];
            if(range + nums_idx <= maxReached) {nums_idx++; continue;}
            for(int i=maxReached+1; i<=nums_idx+range && i<nums.length; i++){
                jumps[i]=jumps[nums_idx]+1;
            }
            maxReached = nums_idx+range;
            nums_idx++;
        }
        return jumps[jumps.length-1];
    }
}