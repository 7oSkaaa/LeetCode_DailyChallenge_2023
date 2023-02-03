# Author: Lobna Mazhar

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = set()
        self.getSubsequence(nums, 0, [], res)
        return res

    def getSubsequence(self, nums, index, current, res):
        # Check for the base case where the current index exceeds the size of the array
        if index == len(nums):
            # If the length of the current subsequence is more than or equal to 2 then add it to the final result
            if len(current) >= 2: res.add(tuple(current))
            return

        # If no subsequence elements were added yet or if the current element is greater than or equal to the last element in the current subsequence, take the current element within the subsequence and check the next index
        if len(current) == 0 or nums[index] >= current[-1]:
            self.getSubsequence(nums, index + 1, current + [nums[index]], res)
        # Ignore the current element and check the next index to be added to the subsequence
        self.getSubsequence(nums, index + 1, current, res)
