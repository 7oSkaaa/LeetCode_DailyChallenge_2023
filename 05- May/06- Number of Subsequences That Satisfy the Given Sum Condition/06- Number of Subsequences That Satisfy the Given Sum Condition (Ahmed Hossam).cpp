// Author: Ahmed Hossam

class Solution {
public:

    // Define a type long long as ll
    typedef long long ll;

    // Define a constant integer MOD as 1000000007
    static constexpr int MOD = 1e9 + 7;

    // A function to calculate b to the power of e in the binary form
    // and returns the result mod MOD.
    ll binPow(ll b, ll e){
        // if e is negative, return 0
        if(e < 0) return 0;

        // Initialize power to 1
        ll power = 1;

        // While e is positive
        while(e > 0){
            // If the least significant bit of e is 1, multiply power by b and take the result mod MOD
            if(e & 1) power = (power * b) % MOD;
            
            // Square b and take the result mod MOD
            b = (b * b) % MOD;
            
            // Shift e one bit to the right -> e /= 2;
            e >>= 1;
        }

        // Return the result
        return power;
    }

    // A function to count the number of non-empty subsequences of nums that sum to target
    int numSubseq(vector<int>& nums, int target) {
        // Get the size of nums
        int n = nums.size();
        
        // Sort nums in non-descending order
        sort(nums.begin(), nums.end());
        
        // Initialize ans to 0
        ll num_of_seq = 0;
        
        // For each element nums[i] in nums
        for(int i = 0; i < n; i++){
            // Find the index of the first element greater than target - nums[i]
            int idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            
            // Add 2^(idx-i-1) to ans and take the result mod MOD -> number of valid subsequences
            num_of_seq = (num_of_seq + binPow(2, idx - i - 1)) % MOD;
        }
        
        // Return num_of_seq
        return num_of_seq;
    }
};
