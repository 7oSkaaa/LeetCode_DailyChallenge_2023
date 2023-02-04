// Author: Ahmed Hossam

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // store the frequency of sum of the segments
        vector < int > freq(k);
        
        // the current sum of the segment and the number of non-empty subarrays that have a sum divisible by k.
        int current_sum = 0, ans = 0;

        // the base case if the all segment is divisible by k
        freq[0] = 1;
        
        for(auto& x : nums){
            
            // update the current sum and make it in the range of [0, k - 1]
            current_sum  = ((current_sum + x) % k + k) % k;

            // add the number of segment that i can remove the current sum to be equal to zero
            ans += freq[current_sum];

            // add one to the frequency the current sum to 
            freq[current_sum]++;
        }

        // the number of non-empty subarrays that have a sum divisible by k
        return ans;
    }
};
