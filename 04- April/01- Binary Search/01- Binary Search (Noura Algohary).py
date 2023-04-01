# Author: Noura Algohary

# Binary Search Iteration Method
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums) - 1

        # repeat till left > right
        while low <= high:
            mid = int((low + high) / 2)

            if target == nums[mid]:
                return mid
            
            if target > nums[mid]:  # target is on the right side
                low = mid + 1
            else:   # target is on the left side
                high = mid - 1
            
        # target not found
        return -1