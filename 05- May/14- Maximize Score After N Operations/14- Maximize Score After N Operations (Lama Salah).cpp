// Author: Lama Salah

class Solution {
public:
    // Declare the size of the list and memoization array.
    int n, memo[8][100000]; 

    int dp(int i, int mask, vector <int>& nums){
        // If we've performed all operations, return 0 - (the base-case).
        if (i > n) return 0; 

        // Get a reference to the memoized result for this i and mask and check if the result is already memoized.
        int& ans = memo[i][mask]; 
        if (~ans) return ans; 

        // Loop over all possible unremoved pairs.
        for (int k = 0; k < 2*n; k++){
            // Check if the k-th bit in the mask is 0 (the k-th integer has not been removed).
            if (!((mask >> k) & 1)){ 
                // Set the k-th bit in the mask to 1 (remove the k-th integer).
                mask |= (1 << k); 
             
                // Loop over all possible unremoved integers.
                for (int l = 0; l < 2*n; l++){
                    // check If the l-th bit in the mask is 0 (the l-th integer has not been removed).
                    if (!((mask >> l) & 1)){ 

                        // Set the l-th bit in the mask to 1 (remove the l-th integer).
                        mask |= (1 << l); 

                        // Compute the score for using the k-th and l-th integers.
                        ans = max(ans, (i* gcd(nums[k], nums[l])) + dp(i+1, mask, nums));
                        
                        // Unset the l-th bit in the mask.
                        mask ^= (1 << l);
                    }
                }

                // Unset the k-th bit in the mask.
                mask ^= (1 << k);
            }
        }

        return ans; 
    }

    int maxScore(vector<int>& nums) {
        this -> n = nums.size()/2;

        // Initialize the memo array with -1 values using the memset() function.
        memset(memo, -1, sizeof memo);
        
        // Compute the maximum score after N operations.
        return dp(1, 0, nums); 
    }
};
