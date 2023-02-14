// Author: Fatma Gamal Eldin Galal
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # you can get number of odd numbers in an interval by the number of all numbers in the interval
        n = high - low + 1   # number of all numbers in an interval
        if n%2 == 0:                 # 1 2 3 4 => 2 odd, 2 even
            return n//2
        elif high%2 ==1 or low%2==1: # 1 2 3 4 5 => 3 odds
            return n//2 +1
        else:                        # 2 3 4 5 6 => 2 odds
            return n//2
