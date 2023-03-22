// Author: Osama Ayman
/* {0,0,0,0} size = 4;
    number of sub arrays of size 4: 1
    number of sub arrays of size 3: 2
    number of sub arrays of size 2: 3
    number of sub arrays of size 1: 4

    formula n(n+1)/2

*/
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        // count number of consecutiveZeros
        long consecutiveZeros = 0;
        long res = 0;
        for(int num: nums){
            if(num==0) consecutiveZeros++;
            else {
                // n(n+1)/2 is the number of subarrays that can be formed
                res += consecutiveZeros*(consecutiveZeros+1)/2;
                consecutiveZeros=0;
            }
        }
        // if the last elemnt is zero, then you must do this step as it will not be
        // calculated in the loop.
        res += consecutiveZeros*(consecutiveZeros+1)/2;
        return res;
    }
}