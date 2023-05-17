// Author: Osama Ayman
// Time: O(n)
// Space: O(1)
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
    public ListNode swapPairs(ListNode head) {
        // if there the list is empty of if there is only 1 node, return it
        if(head==null || head.next == null) return head;
        ListNode pp = null, prev = head, cur = head.next, next = null;
        ListNode newHead = cur;
        while(cur!=null){
            // pp is the last node from prev iteration
            if(pp!=null) pp.next = cur;
            // save the next, so we don't lose reference to it
            next = cur.next;
            // swap
            cur.next = prev;
            prev.next = next;
            // advance the pp
            pp = prev;
            // advance the prev
            prev = next;
            // if there is no next node or only 1 node is left, break
            if(next == null || next.next == null) break;
            // advance the cur
            cur = next.next;
        }
        return newHead;
    }
}