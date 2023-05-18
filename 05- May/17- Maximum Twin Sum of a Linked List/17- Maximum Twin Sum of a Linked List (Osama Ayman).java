// Author: Osama Ayman
// Time: O(n)
// Space: O(n)
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
    public int pairSum(ListNode head) {
        // convert to array list, so we can use the 2-pointers technique
        List<Integer> ls = new ArrayList<>();
        ListNode cur = head;
        while(cur!=null){
            ls.add(cur.val);
            cur = cur.next;
        }
        // 2-ptrs
        int lo=0, hi=ls.size()-1, max = 0;
        while(lo<hi){
            max = Math.max(max, ls.get(lo++) + ls.get(hi--));
        }
        return max;
    }
}