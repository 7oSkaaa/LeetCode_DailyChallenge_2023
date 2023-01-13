# Author: Mohamed Aly Elsayed Matar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# here we used the same preorder function we used in the previous problem (#9)
# but instad of returning an empty list when null we will append 0 to the list
# so that when comparing they wont be the same
def preorder(root:Optional[TreeNode], res:List) -> List[int]:
    if root == None:
        res.append(0)
    else:
        res.append(root.val)
        preorder(root.left, res)
        preorder(root.right, res)

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        p_res = []
        q_res = []
        preorder(p, p_res)
        preorder(q, q_res)
        if p_res == q_res:
            return True
        else:
            return False
