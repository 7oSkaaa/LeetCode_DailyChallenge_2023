# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # Starting from the root compare the 2 children
        return self.checkSymmetric(root.left, root.right)
        
    def checkSymmetric(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        # If the 2 nodes are null, then they are symmetric
        if not left and not right: return True

        # If the 2 nodes are not null and they have the same value, they are symmetric so check their children in a mirroring way such that the left and right children should be check against each other
        if left and right and left.val == right.val:
            return self.checkSymmetric(left.left, right.right) and self.checkSymmetric(left.right, right.left)

        # If one of the 2 nodes is not null and the other one has a value, they are not symmetric
        return False