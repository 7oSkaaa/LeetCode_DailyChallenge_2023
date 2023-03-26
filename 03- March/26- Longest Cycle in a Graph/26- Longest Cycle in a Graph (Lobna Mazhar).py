# Author: Lobna Mazhar

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        # For each node initialize it as not visited and count by 0
        visited_count = [(False, 0) for i in range(len(edges))]

        res = -1
        # Loop on the nodes and check the cycle length starting from each node
        for i in range(len(edges)):
            res = max(res, self.visitNodes(edges, visited_count, i, 1, set()))
        return res
            
    def visitNodes(self, edges, visited_count, node, count, visited):
        # If the node has no outgoing edge, return -1 no cycle exists
        if edges[node] is -1: return -1

        # If the node is already visited before
        if visited_count[node][0]:
            # If the visit was in the same cycle, return the current count decremented by the previous count when it was visited to get the cycle length (count of nodes visited until the node is re-visited)
            if node in visited: return count - visited_count[node][1]
            # If was visited from a previous check, return -1 no cycle
            else: return -1

        # Mark the node as visited and save the current count
        visited.add(node)
        visited_count[node] = (True, count)
        # Visit the next node with incrementing the count by 1
        return self.visitNodes(edges, visited_count, edges[node], count + 1, visited)