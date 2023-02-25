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
 // Traversing the Binary Search tree in inorder will result in sorted numbers.
 // Loop over the list and find the min diff between each 2 consecutives numbers.
 class Solution {
    List<Integer> list = new ArrayList<>();
    public int minDiffInBST(TreeNode root) {
        inorder(root);
        int res = Integer.MAX_VALUE;
        for(int i=1; i<list.size(); i++){
            res=Math.min(res, list.get(i)-list.get(i-1));
        }
        return res;
    }
    private void inorder(TreeNode root){
        if(root==null) return;
        inorder(root.left);
        list.add(root.val);
        inorder(root.right);
    }
}