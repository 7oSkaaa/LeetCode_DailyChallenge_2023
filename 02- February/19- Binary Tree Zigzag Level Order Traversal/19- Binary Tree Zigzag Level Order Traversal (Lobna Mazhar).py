# Author: Lobna Mazhar

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        
        queue = [root]
        level, res = 0, []
        while queue:
            size = len(queue)
            level_values = []
            level += 1
            for i in range(size):
                node = queue.pop(0)
                if level % 2 == 0: level_values.insert(0, node.val)
                else: level_values.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
                    
            res.append(level_values)
        return res
        
        