# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # If the inorder array is empty, return an empty tree
        if len(inorder) == 0: return None
        # If the inorder array has 1 element, return it as the only node (root)
        if len(inorder) == 1: return TreeNode(inorder[0])
        
        # Mark the root as the last node in the postorder array (left,right,parent)
        root = TreeNode(postorder[-1])
        # Traverse the inorder array to find the left subtree which will be all the nodes before the root node (the last node in the post order)
        for i in range(len(inorder)):
            # If current node is the root
            if inorder[i] == postorder[-1]:
                # Build the left subtree using the inorder and postorder nodes right before the root using the current index i
                root.left = self.buildTree(inorder[:i], postorder[:i])
                # Build the right subtree using the inorder nodes right after the root using the current index i and the postorder nodes from index i to the end
                root.right = self.buildTree(inorder[i+1:], postorder[i:-1])
        return root