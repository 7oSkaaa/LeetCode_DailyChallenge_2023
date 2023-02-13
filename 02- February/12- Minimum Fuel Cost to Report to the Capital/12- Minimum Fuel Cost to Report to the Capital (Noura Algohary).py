# Author: Noura Algohary
# depth first search to traverse all nodes
# node 0 does not count
class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        self.fuel = 0
        adj = [[] for _ in range(len(roads) + 1)]

        # make adjacency matrix
        for road in roads:
            adj[road[0]].append(road[1])
            adj[road[1]].append(road[0])
        
        def dfs(node, root):
            reps = 1

            # apply dfs for all neighbors of the node except the root
            for neighbor in adj[node]:
                if neighbor == root:
                    continue
                reps += dfs(neighbor, node) # add no. of representitives to reps of the parent node
            
            if node != 0:
                self.fuel += math.ceil(reps / seats)
            
            return reps
        
        dfs(0, -1)

        return self.fuel