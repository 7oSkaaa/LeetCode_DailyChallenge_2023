# Author : Marwa Rabia 


from ast import List
from collections import defaultdict
from heapq import heappop, heappush


class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        # Create an adjacency list to represent the tree
        adj_list = defaultdict(list)
        for i, parent in enumerate(parent):
            adj_list[parent].append(i)
        
        # Initialize a variable to store the max path length
        out = [0]
        def dfs(u, p):
            # Create a heap to store the max path lengths of the children
            heap = []
            for v in adj_list[u]:
                heappush(heap, dfs(v, u))
                if len(heap) > 2: 
                    heappop(heap)
            # Update the max path length variable
            out[0] = max(out[0], sum(heap) + 1)
            # If the current node and its parent have the same character, return 0
            if s[u] == s[p]: 
                return 0
            # Return the max path length of the children + 1
            return heap[-1] + 1 if heap else 1

        dfs(0, -1)
        return out[0]
