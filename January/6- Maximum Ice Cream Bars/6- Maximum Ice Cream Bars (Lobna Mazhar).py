# Author: Lobna Mazhar

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # Sort given costs to pick the minimum values
        costs.sort()
        index = 0
        # Loop until you finish the coins or you buy all the ice-cream bars
        while coins > 0 and index < len(costs):
            # If the cost of the current bar is affordable
            if costs[index] <= coins:
                # Deduct its price from the total coins
                coins -= costs[index]
                # Increment the index to check the next bar
                index += 1
            # Else if the current bar is out of budget, break the loop, you can't buy anymore bars
            else: break
        # return the current index which represents the number of bars you are able to buy
        return index