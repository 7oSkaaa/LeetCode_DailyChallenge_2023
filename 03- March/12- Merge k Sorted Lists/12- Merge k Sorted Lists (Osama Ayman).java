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
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        // divide and conquer
        return merge(lists, 0, lists.length-1);
    }
    private ListNode merge(ListNode[] lists, int lo, int hi){
        if(lo==hi) return lists[lo];
        int mid = lo+(hi-lo)/2;
        ListNode left = merge(lists, lo, mid);
        ListNode right = merge(lists, mid+1, hi);
        ListNode dummyHead = new ListNode();
        ListNode cur = dummyHead;
        while(left!=null && right!=null){
            if(left.val <= right.val){
                cur.next = left;
                left=left.next;
                cur=cur.next;
            }
            else{
                cur.next = right;
                right=right.next;
                cur=cur.next;
            }
            cur.next=null;
        }
        while(left!=null){
            cur.next = left;
            left=left.next;
            cur=cur.next;
            cur.next=null;
        }
        while(right!=null){
            cur.next = right;
            right=right.next;
            cur=cur.next;
            cur.next=null;
            
        }
        return dummyHead.next;
    }
}