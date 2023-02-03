# Author: Noura Algohary

# Kadane's Algorithm is about getting the maximum sum of a subarray
# ex: nums = [1, -2, 3, -2]
# working on nums[3] 
#                     max
#                 -2  -2
#             3   -2   1   max(-2, (-2 + 3))
#         -2  3   -2  -2   max(-2, (-2 + 3))
#     1   -2  3   -2   2   max(-2, (-2 + 4))

# In this problem, we are using Kadane's algorithm with some additions to implement a circular array.
# By finding the maximum value between cumulative sum of the array subtracting the min subarray sum and finding the max subarray sum.

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        cum_sum = 0

        # to find cumulative sum
        for num in nums:
            cum_sum += num
        
        def KadaneAlgorithm():
            local_max, global_max, local_min, global_min = nums[0], nums[0], nums[0], nums[0]

            for i in range(1, len(nums)):
                # find max subarray sum
                local_max = max(nums[i], nums[i] + local_max)
                global_max = max(local_max, global_max)

                # find min subarray sum
                local_min = min(nums[i], nums[i] + local_min)
                global_min = min(local_min, global_min)
            
            # all values are negative
            if (cum_sum == global_min):
                return global_max

            return max(global_max, cum_sum - global_min)
        
        return KadaneAlgorithm()