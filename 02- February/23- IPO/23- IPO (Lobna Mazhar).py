# Author: Lobna Mazhar

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        prev_weight = -1
        avail_profits = []
        heapq.heapify(avail_profits)
        while k:
            i = 0
            # Add all new available profits according to current weight to available profits that we can pick from
            while i < len(capital):
                if capital[i] > prev_weight and capital[i] <= w:
                    heapq.heappush(avail_profits, -profits[i])
                    del capital[i]
                    del profits[i]
                else: i += 1

            # If there are available profits to pick from, pick the highest profit and increment the total weight
            if avail_profits:
                profit = -heapq.heappop(avail_profits)
                prev_weight = w
                w += profit
                k -= 1
            else: k = 0
        return w

