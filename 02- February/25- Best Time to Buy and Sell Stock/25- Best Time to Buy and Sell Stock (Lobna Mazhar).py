# Author: Lobna Mazhar

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Starting with the minimum_price as the first price and the maximum_profit of 0
        minimum_price, maximum_profit = prices[0], 0
        # Check all the prices keeping track of the minimum_price found and calculating the maximum_profit that can be achieved by subtracting the minimum_price found previously from the current price
        for i in range(len(prices)):
            # maximum_profit is the max between the current maximum_profit and the new diff
            maximum_profit = max(maximum_profit, prices[i] - minimum_price)
            # minimum_price is the min between the current minimum_price and the new price
            minimum_price = min(minimum_price, prices[i])
        # Return the maximum_profit achieved
        return maximum_profit
