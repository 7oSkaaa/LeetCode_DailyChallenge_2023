# Author: Noura Algohary
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1

        while(low < high):
            mid = int((low + high) / 2)

            if(mid % 2 != 0):
                mid -= 1
            
            # if the single element is on the left side 
            if nums[mid] == nums[mid + 1]:
                low = mid + 2
            else:
                high = mid
            
        return nums[high]