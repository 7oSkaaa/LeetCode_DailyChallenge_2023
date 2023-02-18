# Author: Nayra Mohammed

# - All we need to do is traverse through the tree and for each node we reach swap it's left and right childs
  
class Solution:
    def invertTree(self, root):
        
        if not root: # no nodes here ? return null :Otherwise continue traversing 
            return root
        
        root.left,root.right= root.right,root.left #swap current node's child
        
        self.invertTree(root.left);self.invertTree(root.right) # continue traversing through these childs
     
        
        return root #return answer after being processed through all recursive calls
      
      
      
  
      
     
