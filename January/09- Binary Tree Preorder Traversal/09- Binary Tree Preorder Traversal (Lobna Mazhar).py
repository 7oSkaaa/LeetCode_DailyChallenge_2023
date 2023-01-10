# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
	# Pre-order tree -> Root, Left, Right for each node
        res = []
        self.exploreNode(root, res)
        return res
    
    # Use DFS to print the tree
    def exploreNode(self, node, res):
        if not node: return
        # Append the node's value (pre) then explore each child (left, right)
        res.append(node.val)
        self.exploreNode(node.left, res)
        self.exploreNode(node.right, res)