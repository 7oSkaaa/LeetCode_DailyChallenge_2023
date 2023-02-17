# Author: Lobna Mazhar

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        nodes = [[] for i in range(n)]
        # Make list of children for each node
        for edge in edges: 
            nodes[edge[0]].append(edge[1])
            nodes[edge[1]].append(edge[0])

        return self.calculate(nodes, 0, hasApple, set())
        
    # DFS each node to get its apples' paths length
    def calculate(self, nodes, index, hasApple, visited):
        visited.add(index)
        res = 0
        # For each child calculate the length
        for node in nodes[index]:
            if node not in visited:
                res += self.calculate(nodes, node, hasApple, visited)

        # If current index is not the start and it has apples or a previously counted apples, add this path (2 way) to the total result
        if index != 0 and (hasApple[index] or res != 0): 
            res += 2

        return res