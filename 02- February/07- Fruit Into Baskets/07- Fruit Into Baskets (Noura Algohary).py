# Author: Noura Algohary
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        baskets = {}    # to store fruits by occorrance 
        res = 0
        left = 0    # left from where to start counting

        for right in range(len(fruits)):
            if fruits[right] in baskets:
                baskets[fruits[right]] += 1
            else:
                baskets[fruits[right]] = 1

            # there are two baskets, each of them can stoer only one type of fruits
            # if there is more than 2 types of fruits, the last two ones stay
            while len(baskets) > 2:
                baskets[fruits[left]] -= 1

                if(baskets[fruits[left]] == 0):
                    del baskets[fruits[left]]

                left += 1
        
            if right - left + 1 > res:
                res = right - left + 1
        
        return res
            