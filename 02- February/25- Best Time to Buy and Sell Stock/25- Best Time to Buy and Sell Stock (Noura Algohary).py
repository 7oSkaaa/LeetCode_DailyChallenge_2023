# Author: Noura Algohary
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left, right = prices[0], prices[0]
        profit, max_profit = 0, 0

        for price in prices:
            
            # a new min point needs a new max point in the future
            if price < left:
                left = price    
                right = price
            elif price > right:
                right = price   # record another max for the same min point
                profit = right - left   

                if profit > max_profit:
                    max_profit = profit
        
        return max_profit