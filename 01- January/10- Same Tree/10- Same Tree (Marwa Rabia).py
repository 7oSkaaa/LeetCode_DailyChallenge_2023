# Author: Marwa Rabia 

class Solution(object):
    def isSameTree(self, p, q) -> bool:
        """
        Determines if two binary trees are the same tree.
        
        Parameters:
            p (TreeNode): the root node of a binary tree.
            q (TreeNode): the root node of a binary tree.
            
        Returns:
            bool: True if the trees rooted at p and q are the same, False otherwise.
            
        Example:
            tree1 = [1, 2, 3]
            tree2 = [1, 2, 3]
            isSameTree(tree1, tree2) -> True
            
            tree3 = [1, 2]
            tree4 = [1, None, 2]
            isSameTree(tree3, tree4) -> False
        """
        # check if both p and q are None
        if not p and not q: return True
        # If only one of p or q is None return False
        if not p or not q: return False
        if p.val != q.val: return False
        
        # the function recursively calls itself on the left and right children of p and q
        return self.isSameTree( p.left, q.left) and self.isSameTree( p.right, q.right)
