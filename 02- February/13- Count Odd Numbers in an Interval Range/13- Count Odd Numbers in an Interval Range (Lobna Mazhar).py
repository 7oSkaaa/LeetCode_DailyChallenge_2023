# Author: Lobna Mazhar

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (1 if low % 2 != 0 or high % 2 != 0 else 0) + (high - low) // 2