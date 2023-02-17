# Author: Lobna Mazhar

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj_flights = {i:[] for i in range(n)}
        # Build a map for each stop which stops can be reached directly and their cost
        for start,end,cost in flights: adj_flights[start].append((end, cost))
            
        result = self.checkPath(adj_flights, src, dst, k, {})
        return result if result != sys.maxsize else -1
            
    # For each stop explore the stops that can be reached from it and calculate the total cost saving the minimum
    # Stopping the recursion the target stop is reached or the allowed k stops expires
    def checkPath(self, flights: dict, current: int, target: int, k: int, memo: dict) -> int:
        if current == target: return 0
        if k < 0: return sys.maxsize
        if (current, k) in memo: return memo[(current, k)]
    
        min_cost = sys.maxsize
        for stop, c in flights[current]:
            min_cost = min(min_cost, c + self.checkPath(flights, stop, target, k-1, memo))
        
        memo[(current, k)] = min_cost
        return min_cost
            
        
        