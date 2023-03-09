// Author: Osama Ayman
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null) return null;
        // Floyd algo
        ListNode slow=head, fast=head, intersection=null;
        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast) {intersection=slow; break;}
        }
        // no cycle
        if(intersection==null) return null;
        // distance from the head to the start of the cycle is equal to the distance from 
        // intersection to start of the cycle
        slow=head;
        while(slow!=intersection){
            slow=slow.next;
            intersection=intersection.next;
        }
        return slow;
        
    }
}