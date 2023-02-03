//Author: Mohamed Ibrahim

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    // Initialize an unordered_map m with a key-value pair of 0-1
    unordered_map<int, int> m;
    m[0] = 1;
    int res = 0, sum = 0;
    // Iterate through the nums array
    for (int i = 0; i < nums.size(); i++) {
        // Add the current element to the prefix sum
        sum += nums[i];
        // Calculate the modulus of the prefix sum with k
        int mod = (sum % k + k) % k;
        // Add the frequency of the modulus value from the hash map to the result
        res += m[mod];
        // Increment the frequency of the modulus value in the hash map
        m[mod]++;
    }
    // Return the final value of res as the result
    return res;
    }
};