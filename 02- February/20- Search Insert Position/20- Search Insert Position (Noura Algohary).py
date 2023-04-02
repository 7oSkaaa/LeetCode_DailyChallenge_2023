# Author: Noura Algohary
# bisect_left returns the first occurrence of a num in nums vector or the position where it shour be if not exist 
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = bisect_left(nums, target)
        return low