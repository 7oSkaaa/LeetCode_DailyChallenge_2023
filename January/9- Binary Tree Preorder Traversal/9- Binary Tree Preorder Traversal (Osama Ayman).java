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
 // Author: Osama Ayman

 // preorder is you check the node itself first then the left then the right children.
 class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        solve(res, root);
        return res;
    }
    public void solve(List<Integer> res, TreeNode root){
        if(root==null) return;
        res.add(root.val);
        solve(res, root.left);
        solve(res, root.right);
    }
}