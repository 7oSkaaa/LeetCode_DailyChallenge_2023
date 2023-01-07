# Author: Noura Algohary
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        cnt = 0     # coutner

        costs.sort()

        for cost in costs:
            #if the coins is more than the current elemet cost, increment the counter(cnt) by one, 
            # and subtrat the cost from coins
            if coins >= cost:
                cnt += 1
                coins -= cost

            #if he can't afford the current element, then he can't the rest of the list as it's a sorted list
            else:
                return cnt
        
        return cnt
