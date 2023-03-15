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
    // global variable to save the result
    int res=0;
    public int sumNumbers(TreeNode root) {
        solve(root, new StringBuilder());
        return res;
    }
    private void solve(TreeNode root, StringBuilder s){
        // add root.val to the cur string
        s.append(root.val);
        // if this is a leaf node, add cur string to res and return
        if(root.left==null && root.right==null){
            res += Integer.parseInt(s.toString());
            return;
        }
        
        if(root.left!=null) {
            // traverse the left subtree
            solve(root.left, s);
            // after returning from left, remove the added val, so it is not used in
            // the right subtree
            s.deleteCharAt(s.length()-1);
        }
        
        if(root.right!=null){
            // traverse the right subtree
            solve(root.right, s);
            // after returning from right, remove the added val, so it is not used 
            // in the left subtree
            s.deleteCharAt(s.length()-1);
        }
        
        
        
        
    }
}