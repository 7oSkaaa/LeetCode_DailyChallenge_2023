// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to count the number of subarrays that have only zeros
    // so we count the number of continuous zeros and add the number of subarrays that this number of zeros can make
    // for example if we have 3 zeros then we can make 6 subarrays with them (1, 2, 3, 12, 23, 123) which is 3 * (3 + 1) / 2
    // so we add the number of subarrays that this number of zeros can make to the answer


    long long zeroFilledSubarray(vector<int>& nums) {
        // initialize the answer and the number of continuous zeros
        long long ans = 0, cnt = 0;
        // loop over the array
        for(int i = 0; i < nums.size() ; i++){
            // if the current number is zero then we increase the number of continuous zeros
            if(nums[i] == 0) cnt++;
            else{
                // if the current number is not zero then we add the number of subarrays that the number of continuous zeros can make to the answer
                ans += cnt * (cnt + 1) / 2;
                // and we reset the number of continuous zeros
                cnt = 0; 
            }
        }

        // we need to add the number of subarrays that the number of continuous zeros if these zeros are at the end of the array
        // so we add the number of subarrays that the number of continuous zeros can make to the answer
        // and we return the answer
        return ans + cnt * (cnt + 1) / 2;
    }
};
