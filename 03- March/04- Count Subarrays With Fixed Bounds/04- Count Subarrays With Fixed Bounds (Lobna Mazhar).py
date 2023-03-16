# Author: Lobna Mazhar

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        start_index, min_index, max_index = 0, -1, -1
        res = 0
        # Loop on the numbers
        for i in range(len(nums)):
            # If the current number is out of bounds, reset the pointers starting from the next index and marking min and max indices as not found by setting them to -1
            if nums[i] < minK or nums[i] > maxK: 
                start_index = i + 1
                min_index, max_index = -1, -1
            # If the current number is equal to the minimum, update the minimum index
            if nums[i] == minK: min_index = i
            # If the current number is equal to the maximum, update the maximum index
            if nums[i] == maxK: max_index = i
            # If the 2 values min and max were found before, calculate the subarrays using the next equation
            # equation: subtracting the start index from the minimum value of the 2 indices, it will give you the count of numbers in the range but found before the index of the minimum/maximum value, add 1 to the result to count the current subarray
            if min_index > -1 and max_index > -1: res += (min(min_index, max_index) - start_index + 1)
        return res

