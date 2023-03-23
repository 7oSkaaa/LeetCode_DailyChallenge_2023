# Author: Lobna Mazhar

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:

        parents = [i for i in range(n + 1)]
        ranks = [1 for i in range(n + 1)]

        # Find the parent node of a node
        def find(node: int) -> int:
            p = node
            while p != parents[p]:
                parents[p] = parents[parents[p]]
                p = parents[p]
            return p
        
        # Unify the parents for 2 given nodes
        def union(p1: int, p2: int) -> int:
            # Compare the ranks of the 2 parents, the one with higher rank should be the parent of the other and its rank is incremented by the other's rank
            if ranks[p1] >= ranks[p2]:
                parents[p2] = p1
                ranks[p1] += ranks[p2]
                ranks[p2] = 0
                return p1
            else:
                parents[p1] = p2
                ranks[p2] += ranks[p1]
                ranks[p1] = 0
                return p2
        
        # Loop on the given roads
        for a,b,d in roads:
            # Get the parents for the source and destination nodes on the road
            p1, p2 = find(a), find(b)
            # If the 2 parents don't match, unify them to a one parent
            if p1 != p2: union(p1, p2)
       
        # Initialize the final result by a maximum value
        res = sys.maxsize
        # Traverse the roads one more time, for any road, if its parent is the same as the parent for the starting node, then it can be reached by the starting node, update the res by the minimum between the current distance and the res
        for a,b,d in roads:
            if find(1) == find(a):
                res = min(res, d)
        
        # Return the res as the final result
        return res

