// Author: Osama Ayman
// Time: O(n)
// Space: O(n)
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
    // We will give a number to each node. This number represents the index of the node in a complete binary tree.
    class Pair{
        TreeNode node;
        int index;
        public Pair(TreeNode node, int index){
            this.node = node;
            this.index = index;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        // use Deque so we can get the first and last nodes in each level
        Deque<Pair> dq = new LinkedList<>();
        dq.add(new Pair(root, 1));
        int res = 0;
        while(!dq.isEmpty()){
            // update result
            res = Math.max(res, dq.peekLast().index - dq.peekFirst().index + 1);
            int size = dq.size();
            for(int i=0; i<size; i++){
                Pair cur = dq.poll();
                if(cur.node.left!=null){
                    // the left child will have index cur.index*2
                    dq.add(new Pair(cur.node.left, cur.index*2 ));
                }
                if(cur.node.right!=null){
                    // the right child will have index cur.index*2 +1
                    dq.add(new Pair(cur.node.right, cur.index*2 + 1 ));
                }
            }
        }
        return res;
    }
}