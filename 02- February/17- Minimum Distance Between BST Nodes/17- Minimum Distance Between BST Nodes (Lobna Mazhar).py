# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        inorder = []
        # Traverse the tree in in-order form to get the list of values in an ascending sorted order
        self.inorderTraverse(root, inorder)

        # Loop on the values and get the result as the minimum difference between each 2 adjacent values
        min_diff = sys.maxsize
        for i in range(1, len(inorder)): min_diff = min(min_diff, inorder[i] - inorder[i-1])
        return min_diff

    def inorderTraverse(self, node: Optional[TreeNode], data: list[int]):
        if not node: return
        
        self.inorderTraverse(node.left, data)
        data.append(node.val)
        self.inorderTraverse(node.right, data)