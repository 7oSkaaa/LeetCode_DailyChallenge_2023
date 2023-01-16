# Author: Lobna Mazhar

class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        # Make a list of children for each node by looping on the parents and add current index as a child to the current parent
        nodes = [[] for i in range(len(parent))]
        for i in range(1, len(parent)): nodes[parent[i]].append(i)

        # Calculate each node's path starting from node 0 as the parent
        return self.getPathSize(nodes, 0, s, 0)[1]

    def getPathSize(self, nodes, current, s, max_path) -> tuple[int, int]:
        # Keep track for the longest 2 paths for each node, in case that node will be the parent node in the longest path 
        path1, path2 = 0, 0
        for node in nodes[current]:
            # Get the path length for each child for the current node
            new_path, max_path = self.getPathSize(nodes, node, s, max_path)
            # If the current child has a different label than the current node, check its path if it's more than the longest calculated paths for that node
            if s[current] != s[node]:
                # If the new_path is longer than path1, update path2 by path1 and path1 by the new_path, this keeps path1 as the longer path always.
                if new_path > path1:
                    path2, path1 = path1, new_path
                # Else if new_path is longer than path2 then update path2 by new_path
                elif new_path > path2:
                    path2 = new_path
                # Update the max_path by assuming the current node as the parent for the longest path, add the 2 longest paths values and 1 for the current node, compare it to the max_path
                max_path = max(max_path, (path1 + path2 + 1))

        # Add the current node to the path length and return it
        path1 += 1
        max_path = max(max_path, path1)
        return path1, max_path



