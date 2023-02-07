# Author: Lobna Mazhar

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        res = []
        for i in range(n):
            for j in range(i, len(nums), n): res.append(nums[j])
        return res