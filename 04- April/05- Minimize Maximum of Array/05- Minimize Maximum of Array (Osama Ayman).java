// Author: Osama Ayman
// Time: O(n)
// Space: O(1)
class Solution {
    public int minimizeArrayValue(int[] nums) {
        // first number can not be decreased any further
        int res = nums[0];
        // maintain a running sum that add all increasing number
        // once it decreases, update the result with maxOf res,average
        long sum = res;
        int n = nums.length;
        
        for(int i=1; i<n; i++){
            if(nums[i-1] <= nums[i]){
                sum += nums[i];
            }
            else {
                int tmp = (int)Math.ceil(sum/(double) i); 
                res = Math.max(res, tmp );
                sum+= nums[i]; 
            }
        }
        // update result
        int tmp = (int)Math.ceil(sum/(double) n); 
        res = Math.max(res, tmp);
        return res;
    }
}