# Author: Noura Algohary

# ex1: 010101
#   | ones  | flips | flips after if condition
# 0 |   0   |   1   |   0
# 1 |   1   |   0   |   0
# 0 |   1   |   2   |   1
# 1 |   2   |   1   |   1
# 0 |   2   |   3   |   2
# 1 |   3   |   2   |   2


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        ones = 0
        flips = 0

        for ch in s:
            if ch == '1':
                ones += 1
            else:
                flips += 1
                if ones < flips:
                    flips = ones
        
        return flips