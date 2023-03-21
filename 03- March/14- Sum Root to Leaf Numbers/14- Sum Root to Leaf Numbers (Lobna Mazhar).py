# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.getSum(root, 0)

    def getSum(self, node: Optional[TreeNode], current: int) -> int:
        # Update current integer appending the new node's val
        current = current * 10 + node.val
        
        res = 0
        # Check if there's a left branch, update the result by its value
        if node.left: res += self.getSum(node.left, current)
        # Check if there's a right branch, update the result by its value
        if node.right: res += self.getSum(node.right, current)
        # If no left or right branches; res is 0, return the current integer as a result of root to leaf path, else return the accumulative result of the 2 branches
        return current if res is 0 else res
