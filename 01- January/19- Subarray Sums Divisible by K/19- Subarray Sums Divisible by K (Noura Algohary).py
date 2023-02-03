# Author: Noura Algohary
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_mod = 0  # store remainders of prefic sum
        cnt = 0     # no.of subarrays divisable by k
        mods = [0] * k   # no. of subarrays having the same remainder when divided by k
        mods[0] = 1

        for num in nums:
            prefix_mod = (prefix_mod + num % k + k) % k  # add extra k and mod k to prevent the appearance of negative numbers
            cnt += mods[prefix_mod]
            mods[prefix_mod] += 1

        return cnt