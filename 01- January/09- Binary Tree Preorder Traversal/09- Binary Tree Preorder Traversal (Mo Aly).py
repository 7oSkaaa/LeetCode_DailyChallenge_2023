# Author: Mohamed Aly Elsayed Matar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# this is a standard method for the preorder method
# in this function we check each root
# if it's null send return an empty list else apend its value and continue
# then send the left node to the function as a root and do the same
# after that we do the same thing for the right node
# it's recursive
def preorder(root:Optional[TreeNode], res:List) -> List[int]:
    if root == None:
        return []
    else:
        res.append(root.val)
        preorder(root.left, res)
        preorder(root.right, res)

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        preorder(root, res)
        return res