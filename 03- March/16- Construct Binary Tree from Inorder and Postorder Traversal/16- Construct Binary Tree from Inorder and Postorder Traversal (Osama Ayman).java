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

 // the idea lies in finding the root each time.
 // we know that the root is processed at the end in the postorder traversal.
 // so, traversing the postorder array from end to begining will give us the root when 
 // building the tree from right to left.
 class Solution {
    // idx of the root
    int postidx;
    // key is number in inorder array, val is its idx
    HashMap<Integer, Integer> hm;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        // saving the idx of each number
        hm = new HashMap<>();
        for(int i=0; i<inorder.length; i++){
           hm.put(inorder[i], i);
        }
        postidx=postorder.length-1;
        return solve(inorder, postorder, 0, inorder.length-1);
    }
    private TreeNode solve(int[] inorder, int[] postorder, int lo, int hi){
        // nothing remaining to build
        if(lo>hi) return null;
        // getting root val then decrementing it for the next call
        int rootVal = postorder[postidx--];
        // getting the mid idx
        int mid=hm.get(rootVal);
        
        TreeNode root = new TreeNode(rootVal);
        // we must build root.right first
        root.right=solve(inorder, postorder, mid+1, hi);
        // then build root.left
        root.left=solve(inorder, postorder, lo, mid-1);
        return root;

    }
    
}