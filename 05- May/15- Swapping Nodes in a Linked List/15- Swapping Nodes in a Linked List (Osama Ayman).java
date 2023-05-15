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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode cur = head, first = head;
        int size = 1;
        
        // finding linked list size
        while(cur != null){
            // first node
            if(size == k){
                first = cur;
            }
            size++;
            cur = cur.next;
        }
        int cnt = 1;
        cur = head;
        // finding second node that its value needs to be swapped with that of the
        // first node
        while(cnt <= size-k){
            
            // we have found the second node, no need to increment cur again
            if(cnt == size-k) break;
            cur = cur.next;
            cnt++;
        }
        System.out.println(first.val + " " + cur.val);
        // swapping
        int tmp = cur.val;
        cur.val = first.val;
        first.val = tmp;
        return head;
    }
}