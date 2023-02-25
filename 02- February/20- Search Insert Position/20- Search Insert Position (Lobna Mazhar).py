# Author: Lobna Mazhar

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
	# Do binary search to find the index for insertion
        start, end = 0, len(nums) - 1
        mid = -1
	# Keep looping while the left boundary is less than or equal to the right boundary
        while start <= end:
	    # Get the index of the middle element
            mid = (start + end) // 2
            # If the middle element is the same as the target, return middle index as the insertion index
            if nums[mid] == target: return mid
	    # If the middle index is less than the target, set the left boundary to the middle index + 1, else set the right boundary as the middle index - 1
            if nums[mid] < target: start = mid + 1
            else: end = mid - 1
        
	# If the last checked middle element is less than the target, then insert at a new index at middle index + 1, else return the middle index as the insertion index
        return mid + 1 if nums[mid] < target else mid