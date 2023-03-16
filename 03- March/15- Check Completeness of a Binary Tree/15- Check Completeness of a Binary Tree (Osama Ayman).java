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
 // time: O(n), space: O(n), n is the number of nodes
 class Solution {
    public boolean isCompleteTree(TreeNode root) {
        // we will use a queue for BFS
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        // if a node is missing then all nodes that comes after must have no 
        // child
        boolean missing = false;
        while(!q.isEmpty()){
            // get number of nodes at current level
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode cur = q.poll();
                if(cur.left!=null){
                    // if a node before this is missing, return false
                    if(missing) return false;
                    q.add(cur.left);
                }
                else missing = true;
                if(cur.right!=null){
                    // if a node before this is missing, return false
                    if(missing) return false;
                    q.add(cur.right);
                }
                else missing=true;
            }
        }
        return true;
    }
}