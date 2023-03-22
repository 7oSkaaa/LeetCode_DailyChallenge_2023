//Author: Sara Hamza

class Solution {
public:
    /* Note :
        if there is n contiguous sequence of zeros of length n
        then the number of subarrays in this contiguous sequence is
        n = 1: subarrays => [0] | No of subarrays => 1
        n = 2: subarrays => [0], [0], [0, 0] | No of subarrays => 3
        subarrays => [0], [0], [0], [0, 0], [0, 0], [0, 0, 0] | 
                     No of subarrays => 6
                     
        and so on.
        So, the formula of subarrays No = n * (n - 1) / 2;
    */

    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        // zerosNo : indicates how many zeros are in the subarray
        long long ans = 0, zerosNo = 0;
        
        for (int i = 0; i < n; ++i) {
            // count the number of contiguous zeros
            if(nums[i] == 0) {
                ++zerosNo;
            }
            // calculate the number of subarrays from the number of contiguous zeros
            else {
                ans += zerosNo * (zerosNo + 1) / 2;
                zerosNo = 0;  // reset the counter
            }
        }
        // keep updating the answer if there is still a contiguous sequence of zeros
        ans += zerosNo * (zerosNo + 1) / 2;

        return ans;
    }
};