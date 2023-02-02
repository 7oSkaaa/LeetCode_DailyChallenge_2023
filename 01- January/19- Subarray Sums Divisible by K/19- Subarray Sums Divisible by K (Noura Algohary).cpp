// Author: Noura Algohary
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mods(k);
        mods[0] = 1;  // no. of subarrays having the same remainder when divided by k
        // prefix_mod: store remainders of prefic sum
        // cnt: no.of subarrays divisable by k
        int prefix_mod = 0, cnt = 0;

        for(int num: nums)
        {
            prefix_mod = (prefix_mod + num % k + k) % k;  // add extra k and mod k to prevent the appearance of negative numbers
            cnt += mods[prefix_mod];
            mods[prefix_mod] += 1;
        }

        return cnt;
    }
};