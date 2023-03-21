# Author: Noura Algohary
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isMirror(self, left_root, right_root):
        if(not left_root and not right_root):
            return True
        elif(not left_root or not right_root):
            return False
        else:
            if (left_root.val == right_root.val):
                return True and self.isMirror(left_root.left, right_root.right) and self.isMirror(left_root.right, right_root.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isMirror(root.left, root.right)