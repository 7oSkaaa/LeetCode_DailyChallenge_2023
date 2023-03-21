// Author: Mohamed Ashraf

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // n is a count the Zeros for subarray
        long long ans = 0 , n = 0;
        for(auto i: nums){
            // count Zeros for subarray
            if(i == 0) n++;
            // if the element not zero 
            // plus the summation rule for (n) to (ans)
            else{
                ans += n*(n+1) / 2;
                n = 0;
            }
        }
      
        //  this line if the last element equal zero
        // we need to plus to ans
        ans += n*(n+1) / 2;

        return ans;
    }
};
