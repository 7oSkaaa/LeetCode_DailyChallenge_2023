# Author: Noura Algohary
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        # a list to show the nodes that have incoming edges
        reached = [0 for i in range(n)]
        # nodes with zero incoming edges
        solution = []

        for edge in edges:
            # count how many times the node is reached
            reached[edge[1]]+=1
        
        for node in range(n):
            # is the node have a count of 0 incoming edges
            if reached[node] ==0:
                solution.append(node)

        return solution