# Author: Lobna Mazhar

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        continuous_count, total = 0, 0
        # Traverse the given array
        for n in nums:
            # If the current item is 0, increment the total count by 1 for the current item, and increment the total count by the number of the continuous found zeros as each of them for a continuous subarray, then increment the continuous_count by 1 for the newly found item
            if n is 0:
                total += 1
                total += continuous_count
                continuous_count += 1
            # Else if the current item isn;t 0, reset the continuous_count to 0
            else: continuous_count = 0
        # Return the total count
        return total