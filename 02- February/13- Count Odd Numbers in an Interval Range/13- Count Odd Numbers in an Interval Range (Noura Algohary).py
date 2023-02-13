# Author: Noura Algohary
# no. of odd numbers between 2 numbers is (high - low) / 2
# if one of them is odd, then it counts
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if(low % 2 != 0 or high % 2 != 0):
            return int((high - low) / 2) + 1
        else:
            return int((high - low) / 2)