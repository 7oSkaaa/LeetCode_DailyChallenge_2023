# Author: Noura Algohary
class Solution:
    def tribonacci(self, n: int) -> int:
        t0, t1, t2 = 0, 1, 1

        if n < 2:
            return n
        elif n == 2:
            return 1
        
        for i in range(2, n):
            t3 = t0 + t1 + t2
            t0 = t1
            t1 = t2
            t2 = t3
        
        return t3