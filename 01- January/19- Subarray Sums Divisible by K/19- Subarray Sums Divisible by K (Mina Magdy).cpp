// Author: Mina Magdy

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // mod vector to take the frequency of mod of k for the current prefix sum
        vector<int> mod(k);
        // initialize mod[0] = 1 in case if the current prefix is already divisible by k
        mod[0] = 1;
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // fixing the mod operation and take the current prefix sum
            sum = ((sum + nums[i] % k) + k) % k;
            // add 'mod[sum]' and then increment the frequency of mod of 'k'
            ans += mod[sum]++;
        }
        return ans;
    }
};

/*

the idea is for all 0 <= i < n:

we have the current prefix (let's call it 's'),
and we are searching for a previous prefixes (let's call it 'p') that:

`s - p === 0 (mod k)`

initializing mod[0] = 1 this means that:
`s === 0 (mod k)` 

to get all previous prefixes that fulfills the first equation.
we just incremeant the current prefix 's'
so when we take the frequency of mod['s'] we are searching for all 'p' that fulfills the first equation

*/
