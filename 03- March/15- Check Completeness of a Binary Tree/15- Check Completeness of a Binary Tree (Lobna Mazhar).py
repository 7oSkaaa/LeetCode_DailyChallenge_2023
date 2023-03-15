# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        incomplete_level, queue = False, []
        queue.append(root)

        # Perform BFS on the tree starting with a queue with the root node
        while queue:
            new_queue = []
            while queue:
                # Pick first node from the queue
                node = queue.pop(0)

                # If right child exists without a left child, incomplete tree
                if node.right and not node.left: return False
                
                # If current node has at least one child (left) and incomplete_level was found before, incomplete tree
                if node.left and incomplete_level: return False

                # If any of the children is missing, mark the incomplete_level as found
                if not node.left or not node.right: incomplete_level = True

                # Append the children to the queue
                if node.left: new_queue.append(node.left)
                if node.right: new_queue.append(node.right)

            queue = new_queue

        return True
            
