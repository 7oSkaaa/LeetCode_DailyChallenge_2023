# Author: Lobna Mazhar

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        start, end = 0, len(nums) - 1
        while start < end:
            middle = start + (end - start + 1) // 2
            if middle % 2 == 0:
                if nums[middle] == nums[middle + 1]: start = middle
                elif nums[middle] == nums[middle - 1]: end = middle
                else: return nums[middle]
            else:
                if nums[middle] == nums[middle + 1]: end = middle - 1
                elif nums[middle] == nums[middle - 1]: start = middle + 1
                else: return nums[middle]
        return nums[start]