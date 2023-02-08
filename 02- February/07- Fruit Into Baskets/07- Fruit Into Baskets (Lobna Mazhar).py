# Author: Lobna Mazhar

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        baskets, max_length = {}, 2
        res, max_res = 0, 0
        l, r = 0, 0
        while r < len(fruits):
            if len(baskets) < max_length or fruits[r] in baskets:
                baskets[fruits[r]] = baskets.get(fruits[r], 0) + 1
                res += 1
                r += 1
            else:
                max_res = max(max_res, res)
                while len(baskets) >= max_length:
                    baskets[fruits[l]] -= 1
                    res -= 1
                    if baskets[fruits[l]] == 0: del baskets[fruits[l]]
                    l += 1
        return max(max_res, res)

