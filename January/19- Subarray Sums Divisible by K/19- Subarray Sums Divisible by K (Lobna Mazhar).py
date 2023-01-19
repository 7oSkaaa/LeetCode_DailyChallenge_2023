# Author: Lobna Mazhar

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mods = defaultdict(int)
        mods[0] = 1
        total, res = 0, 0
        for num in nums:
            # For each number, increment the total sum by that number (Prefix Sum)
            total += num
            # Increment the final result by the count of found remainders same as the current one
            res += mods[total % k]
            # Increment the count of found remainders for the current remainder by 1
            mods[total % k] += 1
        return res