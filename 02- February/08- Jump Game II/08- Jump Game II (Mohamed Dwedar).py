# Author: Mohamed Dwedar
class Solution:
    def jump(self, nums: List[int]) -> int:
        """
            -> if we have a position nums[i] so we have a i jumps
                2,  3,1  ,1,4
        index   0,  1,2  ,3,4
        """
        ans = 0
        current = 0
        maxi = 0
        for i in range(len(nums) - 1):
            maxi = max(maxi , i + nums[i])
            if i == current:
                ans += 1
                current = maxi
        return ans