# Author: Mohamed Aly Elsayed Matar

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        res = 0
        # sort the ice cream costs
        costs = sorted(costs)
        # iterate over the ice cream costs
        for i in range(len(costs)):
            # if the cost is less than or equal to the coins you have
            if costs[i] <= coins:
                # subtract the cost from the coins
                coins -= costs[i]
                #  and increment the res
                res += 1
        return res