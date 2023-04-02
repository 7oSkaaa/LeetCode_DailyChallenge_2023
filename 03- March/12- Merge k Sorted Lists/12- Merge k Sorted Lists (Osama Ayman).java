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
        // if there is 1  list return it.
        if(lo==hi) return lists[lo];
        // get the mid
        int mid = lo+(hi-lo)/2;
        // recursively do the same on the left portion
        ListNode left = merge(lists, lo, mid);
        // recursively do the same on the right portion
        ListNode right = merge(lists, mid+1, hi);
        // the begining of the merged list will be the next of this dummy head
        ListNode dummyHead = new ListNode();
        ListNode cur = dummyHead;
        // if there is at least 1 node in each list, take the smallest val
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
        // if there is at least 1 node in left list only, take it
        while(left!=null){
            cur.next = left;
            left=left.next;
            cur=cur.next;
            cur.next=null;
        }
        // if there is at least 1 node in right list only, take it
        while(right!=null){
            cur.next = right;
            right=right.next;
            cur=cur.next;
            cur.next=null;
            
        }
        // return the head of the merged list
        return dummyHead.next;
    }
}
