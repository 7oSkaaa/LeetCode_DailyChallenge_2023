# Author: Lobna Mazhar

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        nodes = [[] for i in range(n)]
        # Make list of children for each node
        for edge in edges:
            nodes[edge[0]].append(edge[1])
            nodes[edge[1]].append(edge[0])

        # Make a list for the final answer to be updated using DFS starting from node 0
        ans = [1 for i in range(n)]
        return self.dfs(nodes, 0, labels, ans, set())[1]
    
    def dfs(self, nodes, current, labels, ans, visited) -> tuple[dict, List[int]]:
        visited.add(current)
        found = defaultdict(int)
        for node in nodes[current]:
            # update the answer for each node by the found labels underneath
            if node not in visited:
                new_found, ans = self.dfs(nodes, node, labels, ans, visited)
                ans[current] += new_found[labels[current]]
                for item in new_found:
                    found[item] += new_found[item]

        # Increment the found count for the current label
        found[labels[current]] += 1
        return found, ans
