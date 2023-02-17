# Author : Hazem Elakbawy

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        # Preorder : print root.value then its left node and its right node (if exists)
        # Approach :-
        # 1.append our current node
        # 2.has left child ? if so,then go to it 
        # 1,2.repeat this process till you reach your leftmost child (leaf Node) , visit it then go back
        # 3.while we go back we check our subtree
        # 3,4.has right child ? if so ,then visit it && go to  till its rightmost
        # 3,4,5.repeat this process till you reach your rightmost child (leaf Node) , visit it then our SUBTREE is done
        # go back to a BIGGER SUBTREE THEN repeat steps (3,4,5)
        li=[]
        def traverse(root):
            if root:
                li.append(root.val)
                traverse(root.left)
                traverse(root.right) 
        traverse(root)  
        return li

