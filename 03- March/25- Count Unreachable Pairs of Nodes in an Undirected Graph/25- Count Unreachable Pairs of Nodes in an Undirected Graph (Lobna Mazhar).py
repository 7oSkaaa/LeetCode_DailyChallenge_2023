# Author: Lobna Mazhar

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        parents = [i for i in range(n)]
        ranks = [1 for i in range(n)]

        # Find the parent node for the given node
        def find(node: int) -> int:
            p = node
            # Loop until the current node is the parent for itself
            while p != parents[p]:
                # Update the node's parent to be its ancestor
                parents[p] = parents[parents[p]]
                # Update the current node with its parent
                p = parents[p]
            # Return the current node which is the root for the previously given node
            return p

        # Unify two given nodes to share the same node
        def union(p1: int, p2: int):
            # Compare the ranks of the 2 parents, the one with higher rank should be the parent of the other and its rank is incremented by the other's rank
            if ranks[p1] >= ranks[p2]:
                parents[p2] = p1
                ranks[p1] += ranks[p2]
                ranks[p2] = 0
            else:
                parents[p1] = p2
                ranks[p2] += ranks[p1]
                ranks[p1] = 0

        # Loop on the edges and get the parents for the 2 computers,
        # If they have different parents, call union method to unify their parent
        for a,b in edges:
            p1, p2 = find(a), find(b)
            if p1 != p2: union(p1, p2)

        # Loop on the ranks to calculate the total unmatched pairs
        res = 0
        for rank in ranks:
            if rank > 0:
                # decrement the total count by the current rank which is the connected nodes
                n -= rank
                # increment the result by the current rank multiplied by the remaining unconnected nodes
                res += rank * n
        return res
