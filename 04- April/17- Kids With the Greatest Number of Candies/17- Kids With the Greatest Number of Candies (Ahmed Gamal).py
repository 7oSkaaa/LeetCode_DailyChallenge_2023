# Author: Ahmed Gamal

# for each kid check if he can have the greatest number of candies
# if he can have the greatest number of candies then return true else return false for each kid
# we can use list comprehension to do this (build a list from another list)

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        return [x + extraCandies >= max(candies) for x in candies]