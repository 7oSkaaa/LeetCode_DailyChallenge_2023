# Author: Lobna Mazhar

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        # Call DFS function to clone the node and its neighbors
        return self.clonedNode(node, {})

    def clonedNode(self, node, visited):
        # If the node is null, return null
        if not node: return node

        # If the node was visited before, return the cloned version of it
        if node in visited: return visited[node]

        # Create a new node (cloned node) with same original node value and an empty list
        new_node = Node(node.val, [])
        # Save the cloned node attached to the original node
        visited[node] = new_node
        # For each neighbor for the original node's neighbors
        for neighbor in node.neighbors:
            # Clone the neighbor and add it to the cloned node neighbors
            new_node.neighbors.append(self.clonedNode(neighbor, visited))
        # Return the cloned node
        return new_node
