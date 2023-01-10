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
    List<Integer>nodes=new ArrayList<Integer>();
    private void preOrder(TreeNode root){
      //1. Visit the root node.
      // 2. Traverse the left subtree in preorder.
      // 3. Traverse the right subtree in preorder.
        if(root == null)return;
        nodes.add(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        preOrder(root);
        return nodes;
    }
}
