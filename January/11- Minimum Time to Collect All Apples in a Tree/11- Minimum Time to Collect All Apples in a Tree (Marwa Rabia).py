# Author: Marwa Rabia

from typing import List
from collections import defaultdict
class Solution:
   
    def minTime(self,n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        # Create a dictionary to store the edges of the tree
        d=defaultdict(list)
        # Create a set to keep track of visited nodes
        visited = set()
        # Fill the dictionary with the edges of the tree
        for x,y in edges:
            d[x].append(y)
            d[y].append(x)

        # Define a DFS function to find the minimum time required to collect all apples
        def dfs(node: int) -> int:
            # Mark the current node as visited
            visited.add(node)
            # Initialize the number of steps taken to 0
            steps = 0
            # Visit each child node that hasn't been visited yet
            for child in d[node]:
                if child not in visited:
                    # Add the number of steps taken to collect all apples in the subtree rooted at child
                    steps += dfs(child)
            
            # If no steps were taken and the current node doesn't have an apple, return 0
            if steps == 0 and not hasApple[node]:
                return 0
            # Otherwise, return the total number of steps taken + 2 steps to move to the next node
            return steps + 2
        
        # Call the DFS function starting at the root of the tree (node 0)
        total_steps = dfs(0)
        # If total_steps is greater than 0, subtract 2 to discount the 2 extra steps required for returning from the last node.
        return max(0,total_steps-2)
