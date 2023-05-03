# Author: Noura Algohary
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        signCounter = 0

        for num in nums:
            # if one zero appears, the result is zero
            if num == 0:
                return 0
            elif num < 0:
                signCounter += 1
        
        # if negative numbers are of odd count, the result is negative
        return 1 if signCounter % 2 == 0 else -1