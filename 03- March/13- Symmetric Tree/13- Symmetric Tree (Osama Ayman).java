// Author: Osama Ayman
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
class Solution {
    public boolean isSymmetric(TreeNode root) {
        // We want to check the left subtree and the right subtree. 
        //The root is a node which is common, so no need to check it.
        return check(root.left, root.right);
    }
    private boolean check(TreeNode  t1, TreeNode t2){
        // if both are null, they are symmetric
        if(t1==null && t2==null) return true;
        // if one is null and the other is not, then they are not symmetric
        if(t1==null || t2==null) return false;
        // both values should be equal
        if(t1.val != t2.val) return false;
        // the left of tree1 should be equal to the right of tree2 AND
        // the right of tree1 should be equal to the left of tree2
        return check(t1.left, t2.right) && check(t1.right, t2.left);
    }
}