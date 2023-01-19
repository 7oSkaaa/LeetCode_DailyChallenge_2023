// Author: Mahmoud Aboelsoud

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // to find the number of subarrays that their sum is divisible by k
        // we can use the prefix sum technique
        // we can find the sum of subarray from i to j by sum[j] - sum[i-1]
        // if the sum of subarray from i to j is divisible by k
        // then sum[j] - sum[i-1] % k == 0
        // then sum[j] % k == sum[i-1] % k
        // so we can use a map to store the number of subarrays from 0 to i that their sum % k == j
        // then if had another subarray from 0 to i that their sum % k == j
        // we can add the number of subarrays from 0 to i that their sum % k == j to the answer 

        // initialize n with the size of nums

        int n = nums.size();

        // unordered_map to store the number of subarrays from 0 to i that their sum % k == j
        unordered_map<int,int> ma;
        
        // initialize sum with 0 and ans with 0
        int sum = 0, ans = 0;

        // initialize ma[0] with 1
        ma[0] = 1;
        for(int i = 0; i < n; i++){
            // add nums[i] to sum
            sum += nums[i];
            // then make sure that sum % k is positive
            sum = ((sum % k) + k) % k;
            // add the number of subarrays that we have from 0 to i - 1 that their sum % k == sum to the answer
            ans += ma[sum];
            // increase the number of subarrays that we have from 0 to i that their sum % k == sum by 1
            ma[sum]++;
        }
        // return the answer
        return ans;
    }
};
