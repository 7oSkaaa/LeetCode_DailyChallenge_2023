# Author: Noura Algohary

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # Preorder binary tree traversal is root -> left -> right

        pre = []

        if root:
            # first, the root value is added to the list
            pre += [root.val]
            # second, the left branch must be completed
            pre += self.preorderTraversal(root.left)
            # finally, the right branch
            pre += self.preorderTraversal(root.right)
        
        # return the new order(preorder)
        return pre