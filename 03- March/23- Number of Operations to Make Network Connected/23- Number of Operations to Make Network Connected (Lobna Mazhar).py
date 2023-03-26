# Author: Lobna Mazhar

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        parents = [i for i in range(n)]
        ranks = [1 for i in range(n)]
        available_cables = 0

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
        
        # Loop on the connections and get the parents for the 2 computers,
        # If they have different parents, call union method to unify their parent,
        # Else if they already share the same parent, then this is a redundant connection, increment the available_cables by 1 
        for a,b in connections:
            p1, p2 = find(a), find(b)
            if p1 != p2: union(p1, p2)
            else: available_cables += 1

        # Get the count of connected computers, for any computer with a rank greater than 0, then it has n computers connected to it including itself, increment the total by 1 for this parent computer
        connected_count = 0
        for rank in ranks:
            if rank > 0: connected_count += 1
        
        # If the count of the connected computers exceeds the available cables by more than one, then we can't afford connecting all of the computers together, else return the count of the connected computers - 1 as this is the minimum required to connect the computers
        return -1 if connected_count - 1 > available_cables else connected_count - 1


