// Author: Osama Ayman
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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

 // convert Linked list to to array list, so it can be accessed by index.
 // The root is th middle index and recursively do it on the left and right part to get the left and right subtrees.
 // Time & Space O(n)
 class Solution {
    List<Integer> list = new ArrayList<>();
    public TreeNode sortedListToBST(ListNode head) {
        while(head!=null){
            list.add(head.val);
            head=head.next;

        }
        return solve(0,list.size()-1);
    }
    private TreeNode solve(int lo, int hi){
        if(lo > hi) return null;
        int mid = lo + (hi-lo)/2;
        TreeNode root = new TreeNode(list.get(mid));
        root.left = solve(lo, mid-1);
        root.right = solve(mid+1, hi);
        return root;
    }
}