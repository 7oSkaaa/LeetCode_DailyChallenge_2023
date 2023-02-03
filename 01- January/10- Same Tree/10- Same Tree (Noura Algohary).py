# Author: Noura Algohary
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Both nodes are NULL
        if(not p and not q):
            return True
        
        # One of the nodes is NULL
        if (not p or not q):
            return False
        
        # Both nodes exist but different numbers
        if (p.val != q.val):
            return False

        # Apply the same function on all nodes from left to right
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)