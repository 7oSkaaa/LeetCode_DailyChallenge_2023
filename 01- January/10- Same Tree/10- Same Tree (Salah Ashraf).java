/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// Author: Salah Ashraf

class Solution {
    private boolean checkTwoTrees(TreeNode tree1,TreeNode tree2){
        //If a node of the two trees is null return false
        if( (tree1 == null && tree2 != null) || (tree1!=null && tree2 ==null) )
          return false;
        //If two nodes are null return true
        else if(tree1 == null && tree2 == null){
            return true;
        }
        //If two nodes are equal check left node & right 
        else if(tree1.val==tree2.val){
            return checkTwoTrees(tree1.left,tree2.left)  && checkTwoTrees(tree1.right,tree2.right);
        }
        else if(tree1.val != tree2.val ){
            return false;
        }
      
        return true;
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return checkTwoTrees(p,q);
    }
    
}
