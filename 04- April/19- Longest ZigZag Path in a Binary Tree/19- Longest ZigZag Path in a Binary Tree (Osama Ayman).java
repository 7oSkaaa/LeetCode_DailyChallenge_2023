// Author: Osama Ayman
// Time: O(n)
// Space: O(1) not counting the call stack size
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
    // global res
    int res = 0;
    public int longestZigZag(TreeNode root) {
        solve(root, null);
        return res;
    }
    private int solve(TreeNode cur, TreeNode parent){
        // base case: no more nodes to traverse
        if(cur==null) return 0;
        
        // start a zigzag traversal to the left
        int left = solve(cur.left, cur);
        // start a zigzag traversal to the right
        int right = solve(cur.right, cur);

        // if we are in the root node, there is no parent to return cur result to.
        if(parent==null) return 0;

        // if we are coming to this node from left, then increase the right counter
        if(parent.left == cur) right++;
        
        // else if we are coming to this node from right, increase left counter
        else left++;
        
        // curMax of this node is the max of left traversal and right traversal
        int curMax = Math.max(left, right);
        // update global res if curMax from this node is greater
        res = Math.max(res, curMax);
        // the value returned to the parent depends on whether we are coming from left 
        // or right.
        return parent.left==cur ? right:left;
    }
}