# Author: Lobna Mazhar

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
	# Do binary search to find the element that doesn't match any of its neighbor elements 
        start, end = 0, len(nums) - 1
        while start < end:
            middle = start + (end - start + 1) // 2
	    # If the middle index is even, then the side that the middle index matches, has the extra single element, else if odd, then the other side has the extra single element
            if middle % 2 == 0:
		# If it matches the next element, the update the left boundary to the middle
                if nums[middle] == nums[middle + 1]: start = middle
		# Else if it matches the previous element, then update the right boundary to the middle
                elif nums[middle] == nums[middle - 1]: end = middle
		# Else if it doesn't match any, the single element is found, return middle element
                else: return nums[middle]
            else:
		# If it matches the next element, the update the right boundary to the middle - 1
                if nums[middle] == nums[middle + 1]: end = middle - 1
		# Else if it matches the previous element, then update the left boundary to the middle + 1
                elif nums[middle] == nums[middle - 1]: start = middle + 1
		# Else if it doesn't match any, the single element is found, return middle element
                else: return nums[middle]
        return nums[start]