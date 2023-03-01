# Author: Lobna Mazhar

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.heapSort(nums)
        return nums

    def heapSort(self, nums):
        nLeaves = len(nums) // 2 - 1
        
        # Build max-heap
        for i in range(nLeaves, -1, -1):
            self.heapify(nums, len(nums), i)

        # Traverse the heap popping the largest element and heapify again the remaining elements
        for i in range(len(nums) - 1, 0, -1):
            nums[i], nums[0] = nums[0], nums[i]
            self.heapify(nums, i, 0)

    def heapify(self, nums, length, index):
        root = index
        # Get leaves indicies
        left, right = 2 * root + 1, 2 * root + 2

        # Change the root to the maximum value between the 2 leaves
        if left < length and nums[root] < nums[left]: root = left
        if right < length and nums[root] < nums[right]: root = right

        # If the root was changed, re-apply the process for the new root to get the maximum of the values
        if root != index:
            nums[root], nums[index] = nums[index], nums[root]
            self.heapify(nums, length, root)


