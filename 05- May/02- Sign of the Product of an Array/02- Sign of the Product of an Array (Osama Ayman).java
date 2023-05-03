// Author: Osama Ayman
// Time: O(nums.length)
// Space: O(1)
class Solution {
    public int arraySign(int[] nums) {
        // count of negative numbers
        int cnt = 0;
        for(int n: nums){
            // if any number is 0, the product result is zero
            if(n == 0) return 0;
            // if the number is -ve, increase counter of negative numbers
            if(n < 0) cnt++;
        }
        // if count of negative number is odd then the sign is -ve
        // otherwise it is +ve
        return cnt%2==1 ? -1:1;
    }
}